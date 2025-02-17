
obj-m = usb.o 

usb.ko:usb.c 
	make -C /lib/modules/$$(uname -r)/build M=$$(pwd) modules	

clean:
		make -C /lib/modules/$$(uname -r)/build M=$$(pwd) clean

.PHONY: clean		
