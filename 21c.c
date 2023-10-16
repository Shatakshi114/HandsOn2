/*
============================================================================
Name : 21c.c
Author : Shatakshi Tiwari
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 8th Oct 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{

	//open clientFIFO for reading
	int fp_client = open("client",O_RDONLY);
	if(fp_client==-1)
	{
		perror("OPEN CLIENTFIFO ERROR");
		return -1;
	}
	char readbuf[100];

	//read data from clientFIFO
	read(fp_client,readbuf,sizeof(readbuf));
	printf("Message recieved from server is = %s",readbuf);

	close(fp_client);

	///////////////////////////////////////////////////////////////////////////////

	//open serverFIFO for writing
	int fp_server = open("server",O_WRONLY);
	if(fp_server==-1)
	{
		perror("OPEN SERVERFIFO ERROR");
		return -1;
	}
	//write to serverFIFO
	char msg[]="Hello Server!!\n";

	write(fp_server,msg,strlen(msg));
	printf("Message sent to server \n");
	close(fp_server);

	return 0;

}
