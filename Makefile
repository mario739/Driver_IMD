ifneq ($(KERNELRELEASE),)
obj-m := aht10_driver.o
else
KDIR := /home/mario/Documents/buildroot/output/build/linux-custom

all:
	 $(MAKE) -C $(KDIR) M=$$PWD
endif
