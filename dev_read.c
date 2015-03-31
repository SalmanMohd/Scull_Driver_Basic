#include"header.h"
#include"declearations.h"

ssize_t read_dev(struct file *filep,char *buff,size_t count,loff_t *f_pos)
{
struct ScullDev *lsculldev;
struct ScullQset *lscullqset = NULL;
int nocpr,nocsr=0,noctr,noq=0;

	#ifdef DEBUG
	printk(KERN_INFO "START: %s \n",__func__);
	#endif

	#ifdef DEBUG
	printk(KERN_INFO "END:%s \n",__func__);
	#endif
return 0;
}
