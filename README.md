<div align="center">
  
  ![get_next_linee](https://raw.githubusercontent.com/xSilverWasHere/42-project-badges/refs/heads/main/covers/cover-get_next_line-bonus.png)
</div>

# 📄 get_next_line – Line-by-Line File Reader in C

The `get_next_line` project is a fundamental exercise in low-level file I/O, aiming to implement a function that reads from a file descriptor one line at a time. It introduces the powerful concept of **static variables** and explores memory management, buffer handling, and edge-case control.

---

## 📚 Project Overview

**Objective:**  
Create a function `get_next_line(int fd)` that reads from a given file descriptor and returns a single line, including the newline character `\n`, if present.

**Bonus Objective:**  
Extend the function to handle **multiple file descriptors simultaneously**, without interfering with each file's read state.

**Language:** C  
**Norm Compliance:** Mandatory (`-Wall -Wextra -Werror`)  
**Library Output:** None — `libft` is **not** allowed in this project.

---

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

Returns:

    A line of text including the \n character (if found), or

    NULL when EOF is reached or on error.

Behavior:

    Successive calls will read and return the next line.

    Efficient use of memory and read system calls is expected.

    The function must be robust even when BUFFER_SIZE is 1 or very large.

## ⚙️ Compilation

To define the read buffer size, compile with the -D BUFFER_SIZE flag:

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
## ✨ Bonus Features

✅ Implemented according to the subject’s bonus requirements:

| Feature                          | Status |
| -------------------------------- | ------ |
| One static variable              | ✅      |
| Multiple file descriptor support | ✅      |
| Bonus files with `_bonus` suffix | ✅      |

## 🎯 What I Learned

This project strengthened my understanding of:

   - File I/O using read()
   - Persistent internal state with static variables
   - Efficient string operations in C
   - File descriptor management and system-level constraints
   - Writing modular and maintainable C code under strict constraints
