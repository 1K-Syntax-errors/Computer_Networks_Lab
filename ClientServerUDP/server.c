#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

void main(){
  int sock_id, temp_id, temp_sock_id, len;
  char buffer[100];
  struct sockaddr_in server, client;
  
  sock_id = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_id == -1){
    printf("Error in socket creation\n");
  }
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = 3003;
  server.sin_family = AF_INET;
  temp_id = bind(sock_id, (struct sockaddr*)&server, sizeof(server));
  if (temp_id == -1){
    printf("Error in binding\n");
  }
  len = sizeof(client);
  temp_id = recvfrom(sock_id, buffer, 100, 0, (struct sockaddr*)&client, &len);
  if (temp_id == -1){
    printf("Error in receiving\n");
  }
  printf("Message received: %s", buffer);
  close(sock_id);
}
