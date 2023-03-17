#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

void main(){
  int sock_id, temp_id;
  char buffer[100];
  struct sockaddr_in client;
  
  sock_id = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_id == -1){
    printf("Error in socket creation\n");
  }
  client.sin_port = 3003;
  client.sin_addr.s_addr = INADDR_ANY;
  client.sin_family = AF_INET;
  printf("Enter message: ");
  fgets(buffer, 100, stdin);
  temp_id = sendto(sock_id, buffer, 100, 0, (struct sockaddr*)&client, sizeof(client));
  if (temp_id == -1){
    printf("Error in sending\n");
  }
  close(sock_id);
}
