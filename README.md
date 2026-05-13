*This activity has been created as part of the 42 curriculum by ytrabels.*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from a file descriptor. Each successive call to the function advances through the file, returning the next line (including the terminating `\n` character), until there is nothing left to read — at which point it returns `NULL`.

The goal of this project is to implement reliable line-by-line reading from any file descriptor (regular files, standard input, etc.) while learning how to use **static variables** in C to persist state between function calls.

---

## Instructions

### Compilation

The project requires the `-D BUFFER_SIZE=n` flag to define the read buffer size at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The project must also compile without the flag (a default value is defined in the header):

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

### Files

| File | Role |
|---|---|
| `get_next_line.c` | Main function: `get_next_line(int fd)` |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Header file with prototype and `BUFFER_SIZE` default |

### Usage example

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## Algorithm

### Overview

The function uses a **static buffer** to persist unread data between calls. On each call, it:

1. Initializes the buffer on the first call by calling `read()` to fill it.
2. Scans the buffer character by character, appending each character to the current line being built (`write_realloc_line`).
3. If a `\n` is found, the line is complete: the remainder of the buffer (after the `\n`) is saved into a new buffer for the next call (`set_new_buf`), and the line is returned.
4. If the end of the buffer is reached without finding `\n`, a new `read()` is issued and the process continues.
5. When `read()` returns 0 (EOF) and the line is non-empty, the partial line is returned. On the next call, `NULL` is returned.

### Justification

This approach reads **as little as possible** per call — it stops as soon as a newline is found rather than reading the whole file upfront. The static buffer acts as a "leftovers" store: any bytes read past the `\n` are saved and consumed first on the next call, avoiding redundant `read()` calls and correctly handling any `BUFFER_SIZE` value (1, 42, 9999, or 10 000 000).

The character-by-character append via `write_realloc_line` (which grows the line string by 1 byte at each step using `malloc` + copy) avoids any fixed-size line buffer, making the function correct regardless of line length. The trade-off is O(n²) time for very long lines, but it keeps the implementation simple and norm-compliant.

---

## Resources

- [C static variables — cppreference](https://en.cppreference.com/w/c/language/storage_duration)
- [read() system call — man7.org](https://man7.org/linux/man-pages/man2/read.2.html)
- [File descriptors explained](https://www.bottomupcs.com/file_descriptors.xhtml)
