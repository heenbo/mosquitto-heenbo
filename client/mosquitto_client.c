/*
 * mosqitto_client.c
 *
 *  Created on: 2016Äê6ÔÂ12ÈÕ
 *      Author: Administrator
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "mosquitto_client.h"

#define CA_FILE_PATH 	"/home/heenbo/work/openssl_CA/ca.crt"
#define CERT_FILE_PATH 	"/home/heenbo/work/openssl_CA/client.crt"
#define KEY_FILE_PATH 	"/home/heenbo/work/openssl_CA/client.key"
#define HOST_IP 	"192.168.199.244"
#define HOST_PORT	"8883"
#define TOPIC		"mqtt"
#define USER_NAME	"001"
#define USER_PASSWD	"001"
#define CLIENT_ID	"0001"
#define CLIENT_ID_02	"0002"

char * msg_sub_arg[] = {
	"mosquitto_sub",
	"-h", HOST_IP,
	"-p", HOST_PORT,
	"--cafile", CA_FILE_PATH,
	"--cert", CERT_FILE_PATH,
	"--key", KEY_FILE_PATH,
	"-u", USER_NAME,
	"-P", USER_PASSWD,
	"-i", CLIENT_ID,
	"-t", TOPIC,
};

char * msg_pub_arg[] = {
	"mosquitto_pub",
	"-h", HOST_IP,
	"-p", HOST_PORT,
	"--cafile", CA_FILE_PATH,
	"--cert", CERT_FILE_PATH,
	"--key", KEY_FILE_PATH,
	"-u", USER_NAME,
	"-P", USER_PASSWD,
	"-i", CLIENT_ID_02,
	"-m", "",
	"-t", TOPIC,
};

void print_msg_pub_arg(char *msg_pub_arg[])
{
	int i;
	for(i = 0; i < ARG_PUB_MAX; i ++)
	{
		printf("%s", msg_pub_arg[i]);
		if(!(i%2))
		{
			printf("\n");
		}
		else
		{
			printf("\t");
		}
	}

}
/*********************************************************
*pthread for sub
*
*
*********************************************************/
int rc_sub_thread = -1;
pthread_t pthread_sub_thread;

void * sub_thread(void *arg)
{
	main_mosquitto_sub(ARG_SUB_MAX, msg_sub_arg);

	return NULL;
}

/**********************************************************
*pub message
*
*
***********************************************************/
int pub_message(char *msg_topic, char * msg_pub)
{
	
	msg_pub_arg[ARG_PUB_MSG_VALUE] = (char *)malloc(sizeof(char)*(1+strlen(msg_pub)));

	msg_pub_arg[ARG_PUB_TOPIC_VALUE] = (char *)malloc(sizeof(char)*(1+strlen(msg_topic)));


	strcpy(msg_pub_arg[ARG_PUB_MSG_VALUE], (const char *)msg_pub);
	strcpy(msg_pub_arg[ARG_PUB_TOPIC_VALUE], (const char *)msg_topic);

	printf("msg_topic:%s line:%d\n", msg_topic, __LINE__);
	printf("msg_pub:%s line:%d\n", msg_pub, __LINE__);

	print_msg_pub_arg(msg_pub_arg);

	main_mosquitto_pub(ARG_PUB_MAX, msg_pub_arg);

	free(msg_pub_arg[ARG_PUB_MSG_VALUE]);
	free(msg_pub_arg[ARG_PUB_TOPIC_VALUE]);


	return 0;
}


int main(int argc, char *argv[])
{
	printf("test001\n");


	char *msg_pub = "hhhhhhhhhhhhhhhhhhhhhh";
	char *msg_topic1 = "mqtt";

//	rc_sub_thread = pthread_create(&pthread_sub_thread, NULL, sub_thread, NULL);
//main_mosquitto_sub(argc, char *argv[]);
//main_mosquitto_pub(int argc, char *argv[]);


	while(1)
	{
		pub_message(msg_topic1, msg_pub);
		
		printf("test while 01\n");
		sleep(2);

	}
	printf("test002\n");
	
	return 0;
}
