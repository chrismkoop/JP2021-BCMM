#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void){

}

unsigned int *gpio;
int openpins(void){
        int fdgpio = open("/dev/gpiomem", O_RDWR);
    if (fdgpio<0){
        printf("Could not open /dev/gpiomem";)
        return -1;
    }
    gpio = 
        (unsigned int *)mmap(
            0, 
            4096,
            PROT_READ+PROT_WRITE,
            MAP_SHARED,
            fdgpio,
            0
        );
}

long readpin(int pin){
    return (gpio[13] & (1 << pin));
}

long setpins(int pin){
    gpio[7] = 1 << pin;
}

long clrpins(int pin){
    gpio[10] = 1 << pin;
}

int setmode(int pin, int mode){
    int pinbank = (int) pin / 10;
    gpio[pinbank] = mode << (pin * 3);
}
