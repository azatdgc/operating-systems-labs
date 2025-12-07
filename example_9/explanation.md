# Example 09 – execl() System Call

## Purpose
To demonstrate how `execl()` replaces the current process image with a new program.

## System Calls / Functions Used
- `execl()` – executes a new program
- `printf()` – prints a message before replacement
- `perror()` – prints an error if the call fails

## How It Works
The program first prints a message and then calls:
