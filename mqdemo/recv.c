#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main(int argc, char const *argv[])
{ 
    struct mq_attr cdacmq_attr;
    mqd_t mqfd;
    char buff[128];
    int prio;

    cdacmq_attr.mq_flags=0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    mqfd = mq_open("/cdacmq", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);
    
    mq_receive(mqfd, buff, 128, &prio);
    printf("Received: %s\n", buff);

    mq_close(mqfd);
    return 0;
} 