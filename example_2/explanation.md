# Example 02 – open() System Call

## Purpose
To demonstrate how to create a file and write data into it using `open()` with flags.

## System Calls / Functions Used
- `open()` – opens or creates a file.
- `write()` – writes data to file descriptor.
- `close()` – closes the file descriptor.

## How It Works
The program creates a new file named `test.txt` using `open()` with the `O_CREAT` flag.  
It writes a message into the file and then closes the file descriptor.

## How to Compile and Run
