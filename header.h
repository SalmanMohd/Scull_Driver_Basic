#ifndef HEADER_H
#define HEADER_H 

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/stat.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MOHD. SALMAN");

#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef Dev_Name
#define Dev_Name "My Char Device"
#endif

#ifndef COUNT
#define COUNT 1
#endif

#ifndef QUANTUM_SIZE 
#define QUANTUM_SIZE 8
#endif

#ifndef QSET_SIZE
#define QSET_SIZE 8
#endif

#ifndef DEVICE_SIZE
#define DEVICE_SIZE 4096
#endif

#ifndef DATA_SIZE
#define DATA_SIZE 0
#endif



#endif

