#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/input.h>

int main(int argc, char **argv)
{
    int tp_fd  = -1 ;
    int tp_ret = -1 ;
    int touch_x,touch_y ;
    struct input_event imx6ull_ts ;  
    //1、打开触摸屏事件节点
    tp_fd = open("/dev/input/event2",O_RDONLY);
    if(tp_fd < 0)
    {
       printf("open /dev/input/event2 fail!\n");
       return -1 ;
    }
    while(1)
    {  
	     //2、获取触摸屏相应的事件，并打印出当前触摸的坐标
         read(tp_fd ,&imx6ull_ts ,sizeof(imx6ull_ts));  
         switch(imx6ull_ts.type)
	 {  
	    case EV_ABS:  
		 if(imx6ull_ts.code == ABS_MT_POSITION_X)  
		    touch_x = imx6ull_ts.value ;
		 if(imx6ull_ts.code == ABS_MT_POSITION_Y) 
		    touch_y = imx6ull_ts.value ;
		 break ;
		 defalut:  
		 break ;  
	 }     	
	 printf("touch_x:%d touch_y:%d\n",touch_x,touch_y);
	 usleep(100);
    }	
    close(tp_fd);
    return 0;
}





















