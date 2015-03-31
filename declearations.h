#ifndef DECLEARATIONS_H
#define DECLEARATIONS_H
#include "header.h"
struct ScullDev 
{
struct ScullQset *qset;
struct cdev c_dev;
int qset_size;
int quantum_size; 
int device_size;
int data_size;
};

struct ScullQset
{
struct ScullQset *next;
void **data;
};
//Prortotypes
extern int Majorno,Minorno;
extern dev_t dev;
extern int count;
extern struct ScullDev *sculldev;
extern int qset_size;
extern int quantum_size; 
extern int device_size;
extern int data_size;
extern struct ScullDev *sculldev;
extern struct file_operations fops;
int dev_open (struct inode *, struct file *);
int dev_close (struct inode *, struct file *);
ssize_t write_dev(struct file *,const char __user *,size_t count,loff_t *);
ssize_t read_dev(struct file *,char __user *,size_t count,loff_t *);
struct ScullQset *create_scull(int count);
struct ScullQset *create_scull(int count);
struct ScullQset *create_scullqset(int count);
int create_qset(int count,struct ScullQset*);
int create_quantums(int count,struct ScullQset*);
#endif

