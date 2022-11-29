#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3868185, "module_layout" },
	{ 0xf93983f6, "i2c_del_driver" },
	{ 0xf4cb7bdc, "i2c_register_driver" },
	{ 0xa0b3694, "misc_register" },
	{ 0x97e696e1, "i2c_transfer_buffer_flags" },
	{ 0x7f4482b1, "misc_deregister" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Caht10_dev");
MODULE_ALIAS("of:N*T*Caht10_devC*");

MODULE_INFO(srcversion, "5F1F8C0F7B38A8D905715BA");
