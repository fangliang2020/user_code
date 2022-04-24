ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
PATH=$PATH:/home/oliver/rv1126/prebuilts/gcc/linux-x86/arm/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin

all:
	$(CROSS_COMPILE)gcc -o show_ascii show_ascii.c
clean:
	rm -rf *.o show_ascii