#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

void main(){
  int sock_id, temp_id;
  char buffer[100];
  struct sockaddr_in client;
  
  sock_id = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_id == -1){
    printf("Error in socket creation\n");
  }
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = INADDR_ANY;
  client.sin_port = 3003;
  temp_id = connect(sock_id, (struct sockaddr*)&client, sizeof(client));
  if (temp_id == -1){
    printf("Error in connection\n");
  }
  printf("Enter the message: ");
  scanf("%[^\n]s", buffer);
  temp_id = send(sock_id, buffer, 100, 0);
  if (temp_id == -1){
    printf("Error in sending\n");
  }
  close(sock_id);
}
