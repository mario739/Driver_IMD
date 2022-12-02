#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#define AHT10_CMD_TRIGGER_MEASUREMENT  0xAC
#define HUMEDITY(A)                          (uint8_t) (A *0.000095)
#define TEMPERATURE(A)                       (int8_t) ((A *0.000191)-50) 
int main(void){
    uint8_t cmd[3] = {AHT10_CMD_TRIGGER_MEASUREMENT,0x00,0x00};
    char buffer_read[6]={0};
    uint32_t data_humedity=0;
    uint8_t humedity=0;
    uint32_t data_temperature=0;
    int8_t temperature=0;

    int my_dev = open("/dev/aht10_dev",O_RDWR);
    
    if (my_dev < 0) {
        perror("Fail to open device file: /dev/mydev.");
    } 
    else 
    {
        while (1)
        {
            write(my_dev,cmd,3);
            read(my_dev,buffer_read,6);
            data_humedity=(((uint32_t)buffer_read[1]<<16) | ((uint16_t)buffer_read[2]<<8) | (buffer_read[3]))>>4;
            humedity=HUMEDITY(data_humedity);
            data_temperature=((uint32_t)(buffer_read[3] & 0x0F)<<16) | ((uint16_t) buffer_read[4]<<8)| buffer_read[5];
            temperature= TEMPERATURE(data_temperature);
            printf("humedad %u temperature %i \n",humedity,temperature);
            sleep(1);
        }
        close(my_dev);       
    }
    return 0;
}

