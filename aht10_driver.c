#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>



#define DEVICE_NAME "aht10_dev"

static struct i2c_client  *aht10_i2c_client;


static int aht10_dev_open(struct inode *inode, struct file *file)  {
    
    pr_info("open device \n");
    return 0;
}

static int aht10_dev_close(struct inode *inode, struct file *file)  {
    
    pr_info("close device \n");
    return 0;
}

static ssize_t aht10_dev_read (struct file *file, char __user *buffer, size_t len, loff_t *offset) {
    
    i2c_master_recv(aht10_i2c_client,buffer,len);
    return 0;
}

static ssize_t aht10_dev_write (struct file *file, const char __user *buffer, size_t len, loff_t *offset){

    i2c_master_send(aht10_i2c_client,buffer,len);
    return 0;

}

static const struct file_operations aht10_dev_fops = {
        .owner = THIS_MODULE,
        .open = aht10_dev_open,
        .release = aht10_dev_close,
        .write = aht10_dev_write ,
        .read = aht10_dev_read
};

static struct miscdevice aht10_miscdevice = {		
        .minor = MISC_DYNAMIC_MINOR,
        .name = DEVICE_NAME,
        .fops = &aht10_dev_fops,
};


static int aht10_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    pr_info("Hello! device probed!\n");
    
    int ret_val;
    aht10_i2c_client=client;
    
    ret_val = misc_register(&aht10_miscdevice);

    if (ret_val != 0) 
    {
        pr_err("could not register the misc device mydev");
	    return ret_val;
    }
        pr_info("mydev: got minor %i\n",aht10_miscdevice.minor);
        return 0;
	return 0;
}
static int aht10_i2c_remove(struct i2c_client *client)
{
    pr_info("good bye reader! Removing me\n");

    pr_info("Hello world exit\n");
    /* unregister the device with the Kernel */
    misc_deregister(&aht10_miscdevice);
	return 0;
}




static const struct of_device_id aht10_of_match[] = {
	{ .compatible = "aht10_dev",},
	{ }
};
MODULE_DEVICE_TABLE(of, aht10_of_match);

static struct i2c_driver aht10_i2c_driver = {
	.probe= aht10_i2c_probe,
    .remove= aht10_i2c_remove,
	.driver = {
		.name	= "aht10_driver",
		.of_match_table = aht10_of_match,
	},
};

module_i2c_driver(aht10_i2c_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mario Aguilar <fernandoaguilar731010@gmail.com>");
MODULE_DESCRIPTION("Driver para sernsor de temperatura y humendad AHT10");

