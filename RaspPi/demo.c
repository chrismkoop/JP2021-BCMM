#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc == 2){
        int pin = (int)argv[0]-48;
        if (gpio_lev & (1<<pin)){
            gpio_clr |= (1<<pin);
        }else{
            gpio_set |= (1<<pin);
        }
    }
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

long readpins(void){
    return gpio[13];
}

long setpins(int pins){
    
}

long clrpins(int pins);

int setmode(int pin, bool mode){
    if (pin<9){
        gpio[0] = 
    }else{

    }
}
