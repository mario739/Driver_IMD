#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>



#define AHT10_ADDRESS_SLAVE                  0x38
#define AHT10_CMD_INITIALIZE                 0xE1
#define AHT10_CMD_TRIGGER_MEASUREMENT        0xAC
#define AHT10_CMD_SOFT_RESET                 0xBA  
#define AHT10_CMD_DATO_0                     0X33
#define AHT10_CMD_DATO_1                     0X00

int main(void)
{

int my_dev = open("/dev/aht10_dev", 0);
uint8_t cmd[3] = {AHT10_CMD_TRIGGER_MEASUREMENT,AHT10_CMD_DATO_0,AHT10_CMD_DATO_1};
char bufferRead[6]={0};
uint32_t data_humedity=0;

if (my_dev < 0) 
{
 perror("Fail to open device file: /dev/mydev.");
} 
else 
{

write(my_dev,cmd,3);
read(my_dev,bufferRead,6);
data_humedity=(((uint32_t)bufferRead[1]<<16) | ((uint16_t)bufferRead[2]<<8) | (bufferRead[3]))>>4;

 printf("humedity %u\n",data_humedity);
 printf("hola\n");
 close(my_dev);
}
return 0;


}

