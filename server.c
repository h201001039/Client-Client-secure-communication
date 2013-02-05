#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<malloc.h>
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>
//pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;
FILE *fd;
int v=0,sock;
char *s;
struct sockaddr_in *sa;
struct sockaddr_storage their_addr;
socklen_t sin_size;
int x=0,w=0,a[10];
char ip4[10][INET_ADDRSTRLEN];


void *thread_function(void *arg) {
int flag=0;
int r=*((int *) arg);
int i,z=0;
char *e;
char *to;
int c,n,b;
printf("connection:%d\n",v);
fprintf(fd,"connection:%d\n",v);

sa =(struct sockaddr_in *)&their_addr;
inet_ntop(AF_INET, &(sa->sin_addr), ip4[w], INET_ADDRSTRLEN);
printf("The IPv4 address is: %s\n", ip4[w]);
fprintf(fd,"The IPv4 address is: %s\n", ip4[w]);

e=ip4[w];

w++;
//printf("%s\n%d",e,r);
//getpeername(a[0], struct sockaddr *addr1, int *addrlen);
char l[100];

char m[100];
char *client;
//printf("connection establised with"
while(1)
{
b=recv(r,l,99,0);
printf("%s\n",l);
fprintf(fd,"MESSAGE FROM CLIENT: %s\n", l);

if(((!strcmp(l,"exit"))))
{

for(i=0;i<w;i++)
{
c=send(a[i],l,99,0);
close(a[i]);
}
fclose(fd);

exit(0);
//close(s);

}

//printf("%s\n",l);
else if(x==1)
{
//printf("a[n]=%d\n",a[n]);
//printf("got something...\n");
//pthread_mutex_lock(&mymutex);

c=send(a[n],l,99,0);
//pthread_mutex_lock(&mymutex);

}

else
{
if(!strcmp(l,"connection"))
{
fprintf(fd,"Request for connection by client\n");

printf("hey dude\n");
//pthread_mutex_lock(&mymutex);

 c=send(r,"ip addr??",30,0);
//pthread_mutex_lock(&mymutex);

}

char *to = (char*) malloc(20);
strncpy(to,l,2);
*(to+2)='\0';
//printf("%s\n",to);

if(!strcmp(to,"ip"))
{
strncpy(to,l+2,12);
client=to;
s=e;
//printf("%s\n",s);
for(i=0;i<w;i++)
{
if(!strcmp(client,ip4[i]))
{
z=1;
n=i;
printf("ip found\n");
fprintf(fd,"requested ip adress found\n");

break;
}
else z=0;
}
//printf("n above=%d\n",n);
if(z==1)
{
//printf("%d\n",a[n]);
//pthread_mutex_lock(&mymutex);

 c=send(a[n],"public key??",99,0);
//x=1;
//pthread_mutex_lock(&mymutex);

}
else
printf("errorrrrrr\n");

}
strncpy(to,l,3);
*(to+3)='\0';
//printf("%s\n",to);
if((!strcmp(to,"key")))
{
//printf("yooooooo\n");
//c=send(a[n],l,99,0);
strncpy(to,l+3,3);
//*(to+2)='\0';
//printf("%s\n",to);
for(i=0;i<w;i++)
{
if(!strcmp(s,ip4[i]))
{
flag=1;
n=i;
break;
}}
//printf("n below=%d\n",n);
if(flag==1)
{
//pthread_mutex_lock(&mymutex);

 c=send(a[n],"public key??",99,0);

c=send(a[n],l,99,0);
//pthread_mutex_lock(&mymutex);

//P++;
x=1;
}
else
printf("new errorrrrrr\n");
}}
}
}

int main(int argc, char *argv[])
{
fd=fopen("LOG_SERVER","a+");
pthread_t mythread[10];
//pthread_t mythread1[10];

struct addrinfo hints, *res, *p;
int status;

char buff[100];
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags=AI_PASSIVE;
if ((status = getaddrinfo(NULL, "3490", &hints, &res)) != 0) {
fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
return 2;
}
sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
// bind it to the port we passed in to getaddrinfo():
bind(sock, res->ai_addr, res->ai_addrlen);
listen(sock,10);
sin_size = sizeof their_addr;

while(1)
{
a[v]=accept(sock,(struct sockaddr *)&their_addr,&sin_size);
v++;
//printf("%d\n",a[v-1]);
fprintf(fd,"Creating new different thread for every client as the client request is accepted\n");

 pthread_create( &mythread[v-1], NULL, thread_function, &a[v-1]); 
}



return 0;
}

