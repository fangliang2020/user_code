ARCH=arm
CC=arm-linux-gnueabihf-gcc
PATH=$PATH:/home/oliver/rv1126/prebuilts/gcc/linux-x86/arm/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin
CFLAGS = -Wall  -O0

all:7th1 7th2
7th1:7th_shm_1.c
	$(CC)	$(CFLAGS)	-o	$@	$<
7th2:7th_shm_2.c
	$(CC)	$(CFLAGS)	-o	$@	$<
clean:
	rm  7th*