#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t barr;

void *Serial(void *arg)
{
    printf ("Serial initialization started\n");
    sleep(2);
    printf ("Serial : initialized completed\n");
    printf ("Serial : started\n");
}
 
void *Ethernet(void *arg)
{
    printf ("Ethernt initialization started\n");
    sleep(10);
    printf ("Ethernt: initialized completed\n");
    printf ("Ethernet : started\n");
}

void *Lcd(void *arg)
{
    printf ("Lcd initialization started\n");
    sleep(7);
    printf ("Lcd : initialized completed\n");
    printf ("Lcd : started\n");
}

void *Adc(void *arg)
{
    printf ("Adc initialization started\n");
    sleep(3);
    printf ("Adc : initialized completed\n");
    printf ("Adc : started\n");
}

int main(int argc, char const *argv[])
{
    pthread_t serial,ethernet,lcd,adc;
    pthread_barrier_init(&barr, NULL, 4);
    pthread_create(&serial, NULL, Serial, NULL);
    pthread_create(&ethernet, NULL, Ethernet, NULL);
    pthread_create(&lcd, NULL, Lcd, NULL);
    pthread_create(&adc, NULL, Adc, NULL);
    
    pthread_join(serial,NULL);
    pthread_join(ethernet,NULL);
    pthread_join(lcd,NULL);
    pthread_join(adc,NULL);

    pthread_barrier_destroy(&barr);

  return 0;
}
    
