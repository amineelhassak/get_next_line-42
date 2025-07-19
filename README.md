# 📖 get_next_line

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()
[![Build](https://img.shields.io/badge/Build-Passing-success.svg)]()
[![Version](https://img.shields.io/badge/Version-1.0.0-blue.svg)]()

<div align="center">

# 📖 get_next_line

> A C library function that reads a file line by line, implemented as part of the 42 school curriculum.

[![GitHub stars](https://img.shields.io/github/stars/yourusername/get_next_line-42?style=social)](https://github.com/yourusername/get_next_line-42/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/get_next_line-42?style=social)](https://github.com/yourusername/get_next_line-42/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/get_next_line-42)](https://github.com/yourusername/get_next_line-42/issues)

</div>

---

## 📖 Description

`get_next_line` is a function that reads a file descriptor and returns a line ending with a newline character. It's designed to be memory efficient and can handle multiple file descriptors simultaneously (in the bonus version).

## 🚀 Features

- **Line-by-line reading**: Reads one line at a time from a file descriptor
- **Memory efficient**: Uses static variables to maintain state between calls
- **Configurable buffer size**: Uses `BUFFER_SIZE` macro (default: 10 bytes)
- **Error handling**: Properly handles invalid file descriptors and read errors
- **Memory management**: Properly allocates and frees memory
- **Bonus version**: Supports multiple file descriptors simultaneously

## 📁 Project Structure

```
get_next_line-42/
├── get_next_line.c          # Main function implementation (mandatory)
├── get_next_line.h          # Header file (mandatory)
├── get_next_line_utils.c    # Utility functions (mandatory)
├── get_next_line_bonus.c    # Main function implementation (bonus)
├── get_next_line_bonus.h    # Header file (bonus)
├── get_next_line_utils_bonus.c  # Utility functions (bonus)
└── README.md               # This file
```

## 🔧 Functions

### Main Function
- `get_next_line(int fd)`: Reads and returns the next line from file descriptor `fd`

### Utility Functions
- `ft_strlen(const char *s)`: Returns the length of a string
- `ft_strchr(const char *s, int c)`: Locates a character in a string
- `ft_strjoin(char const *s1, char const *s2)`: Concatenates two strings
- `ft_getline(char *save)`: Extracts a line from the saved buffer
- `ft_modifie_save(char *save)`: Updates the saved buffer after extracting a line
- `ft_strdup(const char *s1)`: Duplicates a string
- `ft_strcpy(char *dest, char *src)`: Copies a string

## 💻 Usage

### Compilation

**Mandatory version:**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c your_main.c -o your_program
```

**Bonus version:**
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line_bonus.c get_next_line_utils_bonus.c your_main.c -o your_program
```

### Example Usage

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## 🔍 How It Works

1. **Static Buffer**: Uses a static array to store unprocessed data between function calls
2. **Reading Process**: Reads from file descriptor in chunks of `BUFFER_SIZE` bytes
3. **Line Extraction**: Searches for newline characters and extracts complete lines
4. **Buffer Management**: Keeps remaining data for the next call
5. **Memory Management**: Properly allocates and frees memory for each line

### Algorithm Flow

1. Check if file descriptor is valid
2. Read data from file descriptor into buffer
3. Search for newline character in accumulated data
4. If newline found, extract the line and update buffer
5. If no newline, continue reading until EOF or newline found
6. Return the extracted line

## 🎯 Key Differences: Mandatory vs Bonus

| Feature | Mandatory | Bonus |
|---------|-----------|-------|
| Multiple file descriptors | ❌ | ✅ |
| Static array size | `OPEN_MAX` | `OPEN_MAX` |
| File descriptor validation | Basic | Enhanced |

## ⚙️ Configuration

### Buffer Size
You can modify the buffer size by defining `BUFFER_SIZE` during compilation:

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o program
```

Default buffer size is 10 bytes if not specified.

## 🧪 Testing

The function handles various edge cases:
- Empty files
- Files with no newlines
- Invalid file descriptors
- Memory allocation failures
- Multiple consecutive calls

## 📝 Notes

- The function returns `NULL` when there's nothing more to read or an error occurs
- Each call to `get_next_line` returns a new line (including the newline character)
- Memory for returned lines must be freed by the caller
- The function maintains state between calls using static variables

## 👨‍💻 Author

**amel-has** - [42 School Student](https://github.com/amel-has)

## 📄 License

This project is part of the 42 school curriculum and follows the school's coding standards and norms.

---

*This project demonstrates advanced C programming concepts including memory management, file I/O, and static variables.*
