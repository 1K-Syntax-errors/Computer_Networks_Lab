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
  
  sock_id = socket(AF_INET, SOCK_STREAM, 0);
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
  temp_id = listen(sock_id, 1);
  if (temp_id == -1){
    printf("Error in listening\n");
  }
  len = sizeof(client);
  temp_sock_id = accept(sock_id, (struct sockaddr*)&client, &len);
  if (temp_id == -1){
    printf("Error in accepting\n");
  }
  temp_id = recv(temp_sock_id, buffer, 100, 0);
  if (temp_id == -1){
    printf("Error in receiving\n");
  }
  printf("The message received is: %s\n", buffer);
  close(sock_id);
}
