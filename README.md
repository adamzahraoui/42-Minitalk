# Minitalk
A simple message communication program using Unix signals (SIGUSR1 and SIGUSR2).

Project Description
Minitalk consists of a server and a client that communicate using signals. The client sends a string to the server, which then reconstructs and displays the message.

How It Works
The server prints its process ID (PID) when started.

The client sends a message to the server, encoding each character as a series of signals.

The server receives the signals, decodes them, and prints the final message.

Features
Signal-based communication between two processes.

Converts characters to binary and transmits them bit by bit.

Error handling for invalid PIDs and incorrect usage.

## Usage
### 1. Compile the project
```bash
make
```

### 2. Start the server
```bash
./server
```
This will output the server's PID.

### 3. Send a message using the client
```bash
./client <server_pid> "Your message"
```

Example:
```bash
./client 12345 "Hello, Minitalk!"
```

### Files
server.c - Receives signals and reconstructs the message.

client.c - Sends messages bit by bit using signals.

minitalk.h - Header file with function prototypes.

Makefile - Compiles the project.

Notes
The server must be running before sending messages.

Uses usleep() to manage signal timing.

The program only supports ASCII characters.
