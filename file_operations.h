struct file_operations fops=
{
	open:openMyCDD,
	release:closeMyCDD,
	read:readMyCDD,
	write:writeMyCDD,
	llseek:lseekMyCDD
};
