#include"header.h"
#include"declearations.h"

ssize_t write_dev(struct file *filep,const char __user *buf,size_t count,loff_t *f_pos)
{
struct ScullDev *lsculldev;
struct ScullQset *lscullqset = NULL;
int nocpw, noctw, ret, i = 0, nocsw = 0;
int noq = 0,k;
#ifdef DEBUG
printk(KERN_INFO "START: %s \n",__func__);
#endif
lsculldev = filep->private_data;
if (!lsculldev) {
printk(KERN_ERR "device not found\n");
return -1;
}
if (count > device_size) {
printk(KERN_ERR "data too large\n");
goto ERR;
}
#ifdef DEBUG
printk(KERN_INFO "number of bytes to write=%u\n",(unsigned int)count);
#endif	
#ifdef DEBUG
printk(KERN_INFO "before write,%d bytes present in scull,offset = %d\n",data_size,(int)*f_pos);
#endif
lsculldev->qset = create_scull(count);
if (!lsculldev->qset) {
printk(KERN_ERR "error in creating scull\n");
goto ERR;
}
lscullqset = lsculldev->qset;
noq = count / quantum_size;
if (count % quantum_size)
noq++;
nocpw = count;
noctw = quantum_size;
for (k = 0; k < noq ; k++) {
ret = copy_from_user(lscullqset->data[i], buf + nocsw, noctw);
if (ret > 0) {
#ifdef DEBUG
printk(KERN_INFO "partial write ret=%d\n",ret);
#endif
}
#ifdef DEBUG
printk(KERN_INFO "data written = %s\n",(char *)lscullqset->data[i]);
#endif
nocpw = count - nocsw - noctw;
nocsw = nocsw + noctw;
//*f_pos = *f_pos + noctw;
if (nocpw < noctw)
noctw = nocpw;
#ifdef DEBUG
printk(KERN_INFO "byte_pend = %d,to_write=%d\n",nocpw,noctw);
#endif	
if (i == (qset_size-1)) {
lscullqset = lscullqset->next;
i = 0;
} else
i++;
#ifdef DEBUG
printk(KERN_INFO "quantum written=%d\n",k);
#endif
}
data_size = lsculldev->data_size= nocsw;
//filep->f_pos = *f_pos;
#ifdef DEBUG
//printk(KERN_INFO "after write,%d bytes present in scull,offset = %d\n",data_size,(int)*f_pos);
#endif
#ifdef DEBUG
printk(KERN_INFO "END: %s \n",__func__);
#endif
return nocsw;
ERR:
return -1;
} 
