#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

int main(void)
{

int my_dev = open("/dev/aht10_dev", 0);

char bufferRead[6]={0};
uint32_t data_humedity=0;

if (my_dev < 0) 
{
 perror("Fail to open device file: /dev/mydev.");
} 
else 
{

 read(my_dev,bufferRead,6);
 data_humedity=(((uint32_t)bufferRead[1]<<16) | ((uint16_t)bufferRead[2]<<8) | (bufferRead[3]))>>4; 
 close(my_dev);
}
return 0;


}

