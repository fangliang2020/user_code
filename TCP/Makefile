ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
PATH=$PATH:/home/oliver/rv1126/prebuilts/gcc/linux-x86/arm/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin

all:server client
server:server_line.c
	$(CROSS_COMPILE)gcc -o $@ $^ 
client:client_line.c
	$(CROSS_COMPILE)gcc -o $@ $^
clean:
	rm server client -f
