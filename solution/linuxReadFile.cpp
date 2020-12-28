#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd,nread;
    char buf[1];
    int n=1;
    fd = open("leetcode/solution/ValidParenthess.cpp",O_APPEND|O_RDONLY);
   while (n > 0){
    n = read(fd, &buf, 1);
    if (write(STDOUT_FILENO, buf, n) != n)
        break;
   }
    close(fd);
    return 1;
}