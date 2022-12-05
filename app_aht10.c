#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

/*Macros*/
#define AHT10_CMD_TRIGGER_MEASUREMENT        0xAC
#define HUMEDITY(A)                          (uint8_t) (A *0.000095)
#define TEMPERATURE(A)                       (int8_t) ((A *0.000191)-50) 

int main(void){
    
    uint8_t cmd[3] = {AHT10_CMD_TRIGGER_MEASUREMENT,0x00,0x00};
    char buffer_read[6]={0};
    uint32_t data=0;
    uint8_t humedity=0;
    int8_t temperature=0;

    int dev_aht10 = open("/dev/aht10_dev",O_RDWR);
    
    if (dev_aht10 < 0) {
        perror("Fail to open device file: /dev/aht10_dev");
    } 
    else 
    {
        while (1)
        {
            write(dev_aht10,cmd,3);
            read(dev_aht10,buffer_read,6);
            data=(((uint32_t)buffer_read[1]<<16) | ((uint16_t)buffer_read[2]<<8) | (buffer_read[3]))>>4;
            humedity=HUMEDITY(data);
            data=((uint32_t)(buffer_read[3] & 0x0F)<<16) | ((uint16_t) buffer_read[4]<<8)| buffer_read[5];
            temperature= TEMPERATURE(data);
            printf("humedad %u temperature %i \n",humedity,temperature);
            sleep(1);
        }
        //cerrar el archivo por que si no no se podra usar en otra aplicacion 
        close(dev_aht10);       
    }
    return 0;
}

