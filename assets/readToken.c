#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    int fd;
    char c;
    char str[25];
    int i;

    if (ac <= 1 )
        return (0);
    fd = open (av[1], O_RDONLY);
    if (fd <= 0)
        return (0);
    if ((read(fd, str, 25)))
    {
        i = 0;
        while (str[i])
        {
            c = str[i] - i;
            write(1, &c, 1);
            i++;
        }
        write(1, "\n", 1);
    }
    close(fd);
    return (0);
}
