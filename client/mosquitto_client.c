/*
 * mosqitto_client.c
 *
 *  Created on: 2016Äê6ÔÂ12ÈÕ
 *      Author: Administrator
 */

#include <stdio.h>
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

char * test_sub[] = {
	"mosquitto_client",
	"-h", HOST_IP,
	"-p", HOST_PORT,
	"-t", TOPIC_01,
	"--cafile", CA_FILE_PATH,
	"--cert", CERT_FILE_PATH,
	"--key", KEY_FILE_PATH,
	"-u", USER_NAME,
	"-P", USER_PASSWD,
	"-i", CLIENT_ID,
	
};

int main(int argc, char *argv[])
{
	printf("test001\n");

	main_mosquitto_sub(19, test_sub);
//main_mosquitto_sub(argc, char *argv[]);
//main_mosquitto_pub(int argc, char *argv[]);



	printf("test002\n");
	return 0;
}
