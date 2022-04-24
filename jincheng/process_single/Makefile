ARCH=arm
CC=arm-linux-gnueabihf-gcc
PATH=$PATH:/home/oliver/rv1126/prebuilts/gcc/linux-x86/arm/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin
CFLAGS = -Wall  -O0

all:send_single
send_single:send_single.c
	$(CC)	$(CFLAGS)	-o	$@	$<

clean:
	rm  7th*