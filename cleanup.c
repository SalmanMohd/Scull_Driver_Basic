#include"header.h"
#include"declearations.h"
static void __exit cleanup(void)
{       
	int i;
	#ifdef DEBUG
	printk(KERN_INFO "START_CLEAN_UP %s\n",__func__);
	#endif
	for(i=0;i<count;i++)
{
	cdev_del(&sculldev[i].c_dev);
}
        kfree (sculldev);
	unregister_chrdev_region(dev,count);

	#ifdef DEBUG
	printk(KERN_INFO "FINISH_CLEAN_UP %s\n",__func__);
	#endif

}

module_exit(cleanup); 
