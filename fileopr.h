#ifndef FILEOPR_H
#define FILEOPR_H
 
struct file_operations fops =
{
	owner:THIS_MODULE,
	open:dev_open,
	release:dev_close,
	write:write_dev,
	read:read_dev
};
#endif
