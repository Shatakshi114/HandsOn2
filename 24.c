#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    int msgid;
    key_t key;
    key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT| IPC_EXCL| 0744);
    printf("Key value = %d\n", key);
    printf("Key value in hex = 0x%0x\n", key);
    printf("Message queue id = %d\n", msgid);
}
