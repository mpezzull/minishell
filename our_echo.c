#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    char c;

    while(1)
    {
        scanf("%c", &c);
        printf("%c", c);
        sleep(1);
    }
        
    return(0);
}