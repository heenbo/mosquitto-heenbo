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
#include "mosquitto_client.h"

#define CA_FILE_PATH 	"/home/heenbo/work/openssl_CA/ca.crt"
#define CERT_FILE_PATH 	"/home/heenbo/work/openssl_CA/client.crt"
#define KEY_FILE_PATH 	"/home/heenbo/work/openssl_CA/client.key"
#define HOST_IP 	"192.168.199.244"
#define HOST_PORT	"8883"
#define TOPIC_01	"mqtt"
#define USER_NAME	"001"
#define USER_PASSWD	"001"
#define CLIENT_ID	"0001"
#define CLIENT_ID_02	"0002"

char * msg_sub_arg[] = {
	"mosquitto_client",
	"-h", HOST_IP,
	"-p", HOST_PORT,
	"--cafile", CA_FILE_PATH,
	"--cert", CERT_FILE_PATH,
	"--key", KEY_FILE_PATH,
	"-u", USER_NAME,
	"-P", USER_PASSWD,
	"-i", CLIENT_ID,
	"-t", TOPIC_01,
};

char * msg_pub_arg[] = {
	"mosquitto_client",
	"-h", HOST_IP,
	"-p", HOST_PORT,
	"--cafile", CA_FILE_PATH,
	"--cert", CERT_FILE_PATH,
	"--key", KEY_FILE_PATH,
	"-u", USER_NAME,
	"-P", USER_PASSWD,
	"-i", CLIENT_ID_02,
	"-m", "",
	"-t", TOPIC_01,
};

//pthread for sub
int rc_sub_thread = -1;
pthread_t pthread_sub_thread;

void * sub_thread(void *arg)
{
	main_mosquitto_sub(ARG_SUB_MAX, msg_sub_arg);

	return NULL;
}

int main(int argc, char *argv[])
{
	printf("test001\n");


	char *msg_pub = "hhhhhhhhhhhhhhhhhhhhhh";
	msg_pub_arg[ARG_PUB_MSG_VALUE] = (char *)malloc(sizeof(char)*(1+strlen(msg_pub)));
	strcpy(msg_pub_arg[ARG_PUB_MSG_VALUE], (const char *)msg_pub);
	main_mosquitto_pub(ARG_PUB_MAX, msg_pub_arg);
	free(msg_pub_arg[ARG_PUB_MSG_VALUE]);

	rc_sub_thread = pthread_create(&pthread_sub_thread, NULL, sub_thread, NULL);
//main_mosquitto_sub(argc, char *argv[]);
//main_mosquitto_pub(int argc, char *argv[]);


	while(1)
	{
		sleep(1);
	}
	printf("test002\n");
	
	return 0;
}
