struct file_operations fops=
{
	open:openMyCDD,
	release:closeMyCDD
};
