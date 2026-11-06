# CPE2600 Lab 9 – System Calls

## Description
This lab explores Linux system calls used to retrieve system information, manage processes, and access file information.

## Programs

### info.c
Retrieves and displays system information, including:
- Current time
- Operating system information
- Number of CPUs
- Total and free physical memory

### pinfo.c
Displays information about a process, including:
- Process ID (PID)
- Process priority
- Scheduling method

If no PID is provided, the program displays information about the current process.

### pmod.c
Modifies the current process by:
- Reducing its scheduling priority by increasing its nice value by 10
- Sleeping for 1,837,272,638 nanoseconds
- Printing a goodbye message before exiting

### finfo.c
Displays information about a specified file, including:
- File type
- File permissions
- File owner ID
- File size in bytes
- Last modification date and time

## Compilation

Compile all four programs using:

```bash
make
```

To remove generated files:

```bash
make clean
```

## Execution

```bash
./info
./pinfo
./pinfo <PID>
./pmod
./finfo <filename>
```

## Environment
Developed for Linux using GCC.
