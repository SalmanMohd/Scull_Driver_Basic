#include"declearations.h"
#include"header.h"

int dev_close(struct inode *inodep, struct file *filep)
{
	#ifdef DEBUG
	printk(KERN_INFO "START: %s \n",__func__);
        #endif

	#ifdef DEBUG
	printk(KERN_INFO "END: %s \n",__func__);
	#endif
	return 0;
} 
