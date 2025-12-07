# Example 03 – lseek() System Call

## Purpose
To demonstrate repositioning the file offset using `lseek()`.

## System Calls / Functions Used
- `open()`
- `lseek()`
- `read()`
- `write()`
- `close()`

## How It Works
The program opens a file and moves the file pointer 5 bytes from the beginning using `SEEK_SET`.  
Then it reads the rest of the file and prints it to the terminal.

## How to Compile and Run
