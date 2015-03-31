#include "header.h"
#include "declearations.h"
#include "fileopr.h"
dev_t dev;
dev_t new_dev;
int major_num,minor_num,count,quantum_size,qset_size,data_size,device_size;
struct ScullDev *sculldev;
void init_default(void)
{
	major_num=MAJORNO;
	minor_num=MINORNO;
	count= COUNT;
	quantum_size=QUANTUM_SIZE;
	qset_size=QSET_SIZE;
	device_size= DEVICE_SIZE;
	data_size= DATA_SIZE;
}


static int __init initialization (void)
{	int ret,i,ma,mi;
	#ifdef DEBUG
	printk(KERN_INFO "start function %s\n",__func__);
	#endif
	init_default();
	ret = alloc_chrdev_region(&dev,minor_num,count,Dev_Name);	
        printk(KERN_INFO "major num = %d\n,Count= %d\n",MAJOR(dev),count);
if(ret < 0)
	{
	printk(KERN_ERR "Device Registration failed \n");
	goto ERR;
	}
	sculldev = kmalloc(sizeof(struct ScullDev) * count,GFP_KERNEL);
if(!sculldev)
	{
	printk(KERN_ERR "kmalloc failed\n");
	goto ERR;	
	}
	memset (sculldev,'\0',sizeof(struct ScullDev) * count);
        ma = MAJOR(dev);	
	for(i=0;i<count;i++)
	{
		mi= MINOR(dev+i);
		new_dev=MKDEV(ma,mi);
	        cdev_init(&sculldev[i].c_dev,&fops);
		sculldev[i].c_dev.owner= THIS_MODULE;
		sculldev[i].c_dev.ops= &fops;
		sculldev[i].qset_size=qset_size;
		sculldev[i].quantum_size=quantum_size;
		sculldev[i].device_size=device_size;
		sculldev[i].data_size=data_size;
		
            ret=cdev_add(&sculldev[i].c_dev,new_dev,1);
if(ret < 0)
	{
	printk(KERN_ERR "Device addition to cdev failed \n");
	goto ERR;
	}
	#ifdef DEBUG
	printk(KERN_INFO "Major No=%d Minor No=%d \n",MAJOR(sculldev[i].c_dev.dev),MINOR(sculldev[i].c_dev.dev));
	#endif	
}
	#ifdef DEBUG
	printk(KERN_INFO "end function %s\n",__func__);
	#endif
	return 0;

ERR : return -1;

}
MODULE_LICENSE("GPL");
module_init(initialization);
