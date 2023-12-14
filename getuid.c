#include<stdio.h>
#include<unistd.h>
int main()
{
uid_t uid;
printf("Before setting the uid and gid\nreal user id: %d\nreal grp id: %d\neffective user id: %d\neffective grp id:%d\n",getuid(),getgid(),geteuid(),getegid());
setuid(1003);
setgid(1002);
printf("After setting the uid and gid\nreal user id: %d\nreal grp id: %d\neffective user id: %d\neffective grp id: %d\n",getuid(),getgid(),geteuid(),getegid());
return 0;
}

