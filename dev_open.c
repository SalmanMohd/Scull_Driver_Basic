#include"declearations.h"
#include"header.h"

int dev_open(struct inode *inodep, struct file *filep)
{
	struct ScullDev *lsculldev;
	#ifdef DEBUG
	printk(KERN_INFO "START: %s \n",__func__);
        #endif
	lsculldev = container_of(inodep->i_cdev,struct ScullDev,c_dev);
if(!lsculldev){
	#ifdef DEBUG
	printk(KERN_ERR "container_of failed");
	goto ERR;
	#endif
}
	filep->private_data = lsculldev;
	if((filep->f_flags & O_ACCMODE) == O_WRONLY) {
	#ifdef DEBUG
	printk(KERN_INFO "device write mode\n");
	#endif
}
	#ifdef DEBUG
	printk(KERN_INFO "END: %s \n",__func__);
	#endif
	return 0;
ERR:	printk(KERN_ERR "I am in error \n"); 	
	return -1;
} 
