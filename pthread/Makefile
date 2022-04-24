ARCH=arm
CROSS_COMPILE=arm-linux-gnueabihf-
PATH=$PATH:/home/oliver/rv1126/prebuilts/gcc/linux-x86/arm/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin

all:pthread1 pthread2 pthread3 pthread4 pthread5 pthread6 pthread7 pthread8 pthread9 pthread10 pthread11 pthread12
pthread1:Pthread_Text1.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread2:Pthread_Text2.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread3:Pthread_Text3.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread4:Pthread_Text4.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread5:Pthread_Text5.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread6:Pthread_Text6.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread7:Pthread_Text7.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread8:Pthread_Text8.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread9:Pthread_Text9.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread10:Pthread_Text10.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread11:Pthread_Text11.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
pthread12:Pthread_Text12.c
	$(CROSS_COMPILE)gcc -o $@ $^ -lpthread
clean:
	rm server client -f
