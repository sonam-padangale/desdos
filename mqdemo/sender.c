#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main(int argc, char const *argv[])
{ 
    mqd_t mqfd;

    struct mq_attr cdacmq_attr;

    cdacmq_attr.mq_flags=0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    mqfd = mq_open("/cdacmq", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);

    mq_send(mqfd,"cdac\n", 5, 0);

    mq_close(mqfd); 
    return 0;
}