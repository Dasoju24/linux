#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void toggle(char *p);
void main()
{
	int fd[2],ret,pid;
	char buf[20];
	ret=pipe(fd);
	pid=fork();
	if(pid!=0)
	{
		close(fd[0]);
		printf("enter the string\n");
		//scanf("%s[^\n]",buf);
		printf("input: ");
		gets(buf);
		write(fd[1],buf,strlen(buf));
		printf("parent fd[1]=%d\n\n",fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		ret=read(fd[0],buf,20);
		printf("child fd[0]=%d\n",fd[0]);
		buf[ret]='\0';
		toggle(buf);
		//printf("chid:%s\n",buf);
		printf("output: ");
		puts(buf);
		printf("\n");
		exit(1);
	}
}
void toggle(char *p)
{
	int i;
	int len=strlen(p);
	printf("length =%d\n",len);
	//for(i=0;p[i]!='\0';i++)
	for (i=0;i<len;i++)
	{
	if(p[i]==' ')
		;
	else if(('A'<=p[i])&&('Z'>=p[i]))
		p[i]=p[i]+32;
	else
		p[i]-=32;
	}
}
