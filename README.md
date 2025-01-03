# Character-Device-Driver-1
Emblogic
Overview

This project demonstrates the development and functionality of a Linux character device driver. The driver manages interactions between the kernel and a user-space application by implementing user interactions such as open, read, write, lseek, and close. As of now, the open and close operations have been implemented, while skeletons for the remaining operations have been designed and are pending implementation of the actual routines.

The project highlights how system calls in a user-space application are translated into kernel-level operations through the driver, facilitating controlled interaction with the device. This setup provides a hands-on experience with Linux kernel modules and the inner workings of character device drivers.

Workflow

Application Flow

System Call:

The application issues the open() system call.

The kernel discovers the file to open.

File Identification:

The open() system call determines that the file is a device file by checking the dev_t field in struct inode.

If this field is non-zero (contains major and minor numbers), it is confirmed as a device file.

Kernel Data Structures:

Locates the struct inode representation of the file.

Determines the device type and references the character device representation (struct cdev).

File Operations:

References to struct file_operations are retrieved from both inode and cdev.

Device ID comparisons between inode and cdev ensure consistency.

Driver Routine Execution:

The open() system call is mapped to the driver routine openMyCDD.c.

The driver routine initializes device parameters and performs the required operations.

Driver Routine (openMyCDD.c)

container_of():

Creates references to:

File system.

cdev (character device structure).

Device (user-defined device description structure in declarations.h file).

Returns a special pointer capable of accessing kernel, user, and I/O space references.
