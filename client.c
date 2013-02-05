#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
char M[100];
FILE *fd;
pthread_mutex_t mymutex=PTHREAD_MUTEX_INITIALIZER;
int Y=0,X=0,L;
size_t strlen(const char *);
char *strrev(char *);
char *itoa(int, char *, int);
char t[100],U[100];
int C[100];
int K;
int A=0,phi,n,e,d,FLAG,sock,E,r,Z,u;
int check()
{
int i;
if(e%phi==0||phi%e==0)
FLAG=1;
else FLAG=0;
}


void encrypt()
{
int i,j;
char T[100][5];
printf("\n\tEncrypted keyword :");

    for(j=0;j<strlen(M);j++)
    {
                            M[j]=tolower(M[j]);
/*if(M[j]>=65 && M[j]<=90)
r=64;
else if(M[j]>=97 && M[j]<=122)
r=96;
else if(M[j]>=48 && M[j]<=57)
r=47;

else if(M[j]==32)
r=31;*/
//printf("\nr=%d\n",r);
                            u=M[j]-96;
                            C[j]=1;
                            for(i=0;i<E;i++)
                            C[j]=(C[j]*(u%n))%n;
                            C[j]=C[j]%n;
                            printf("%d ",C[j]);

itoa(C[j],T[j],10);
//wait(1);
}printf("\n");
    for(j=0;j<strlen(M);j++)
{
printf("I am sending%s\n",T[j]);
send(sock,T[j],5,0);
sleep(1);
}}
void decrypt()
{

int i,j;
int Z;

//printf("\ndecrypted keyword :");
/*for(j=0;j<strlen(M);j++)
{
if(M[j]>=65 && M[j]<=90)
r=64;
else if(M[j]>=97 && M[j]<=122)
r=96;
else if(M[j]>=48 && M[j]<=57)
r=47;
else if(M[j]==32)
r=31;
*/
//printf("\nr=%",r);
                            Z=1;
                            for(i=0;i<d;i++)
                            {
Z=(Z*(K%L))%L;
//printf("Z=%d\n",Z);
}                            Z=Z%L;
                            Z=Z+96;
  			printf("%c",Z);
  }
    
void *thr(void *arg) 
{

while(1)
{
//pthread_mutex_lock(&mymutex);
scanf("%s",M);
fprintf(fd,"MESSAGE SEND TO SERVER:%s\n",M);

if(((!strcmp(M,"exit"))))
{
fclose(fd);
send(sock,M,99,0);
exit(0);
}
//pthread_mutex_unlock(&mymutex);
if(A==1 && Y==1) 
encrypt();
else if(A==1 && Y==0)
{
Y=1;
send(sock,M,99,0);

}
else
send(sock,M,99,0);

}
}


int main(int argc, char *argv[])
{
fd=fopen("LOG_CLIENT","a+");
//fprintf(fd,"%d",i);
pthread_t mythread;


char *to = (char*) malloc(20);

int g,q,s;
scanf("%d%d",&g,&q);
n = g*q;
fprintf(fd,"public key n=%d\n",n);

L=n;
phi=(g-1)*(q-1);
printf("\n\tF(n)\t= %d",phi);
do
{
printf("\n\nEnter e\t: ");
scanf("%d",&e);
fprintf(fd,"public key e(input)%d\n",e);

//e++;
check();
}while(FLAG==1);
d = 1;
do
{
s = (d*e)%phi;
d++;
//printf("FGF\n");
}while(s!=1);
d = d-1;
fprintf(fd,"private key d=%d\n",d);

printf("\n\tPublic Key\t: {%d,%d}\n",e,n);
char h[5],k[5];
itoa(e, h, 10);
itoa(n, k, 10);
//printf("%d\n",num1);
int x,i;
struct addrinfo hints, *res, *p;
int status,a[10];
struct sockaddr_storage their_addr;
socklen_t sin_size;

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
connect(sock, res->ai_addr, res->ai_addrlen); 
char content[100];
pthread_create(&mythread,NULL,&thr,NULL);
while(1)
{
int o=recv(sock,t,99,0);
fprintf(fd,"MESSAGE COMIG FROM SERVER:%s\n",t);

if(((!strcmp(t,"exit"))))
{fclose(fd);
exit(0);
}
//printf(" %s\n",t);
strncpy(to,t,3);
*(to+3)='\0';
//printf("%s\n",to);
if(A==1&&X==0)
{
printf("%s\n",t);
X=1;
}
else if(A==1&&X==1)
{
K=atoi(t);
//printf("\nnumber came frm another client=%d\n",K);
decrypt();
}

else if((!strcmp(to,"key")))
{
strncpy(to,t+3,3);
//*(to+2)='\0';
int V=atoi(to);
strncpy(to,t+6,5);
int J=atoi(to);
//printf("E=V and  %s\n",t);
E=V;
n=J;
printf("\nE=%d n=%d\n",V,J);
// o=recv(sock,t,99,0);
//printf("%s\n",t);
//pthread_mutex_lock(&mymutex);
//scanf("%s",U);
//send(sock,U,99,0);
//pthread_mutex_lock(&mymutex);
A=1;

}


else

printf("%s\n",t);
}
    return 0;
}
char *itoa(int n, char *s, int b) {
static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
int i=0, sign;
if ((sign = n) < 0)
n = -n;
do {
s[i++] = digits[n % b];
} while ((n /= b) > 0);
if (sign < 0)
s[i++] = '-';
s[i] = '\0';
return strrev(s);
}
size_t strlen(const char *string) {
	const char *s;

	s = string;
	while (*s)
		s++;
	return s - string;
}

char *strrev(char *str) {
	char *p1, *p2;

	if (!str || !*str)
		return str;

	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}

	return str;
}


