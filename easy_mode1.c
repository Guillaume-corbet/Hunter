/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** option
*/

#include "main.h"

char *int_to_str(int nb)
{
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * 11);
    while (nb > 0) {
        str[a] = (nb % 10) + 48;
        nb = nb / 10;
        a = a + 1;
    }
    str[a] = '\0';
    str = my_revstr(str);
    return (str);
}

int my_getnbr_highscore(char const *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] < '0' || str[i] > '9')
            i = i + 1;
        while (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        if (str[i] < '0' || str[i] > '9') {
            return (nb * neg);
        }
    }
    return (nb * neg);
}

char *score(void)
{
    char *str;
    int fd = 0;
    char charac = 96;
    int i = 0;

    str = malloc(sizeof(char) * 10);
    fd = open("highscore", O_RDONLY);
    while (charac != '\n') {
        read(fd, &charac, 1);
        str[i] = charac;
        i = i + 1;
    }
    close(fd);
    return (str);
}

void new_highscore(char *easy)
{
    int fd = 0;
    int i = 0;

    i = my_strlen(easy);
    fd = open("highscore", O_WRONLY);
    write(fd, "easy", 4);
    write(fd, easy, i);
    write(fd, "\n", 1);
    close(fd);
}

int fonc_error(int argc, char **argv)
{
    if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '-')) {
        return (84);
    } else {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            write(1, "USAGE\n", 7);
            write(1, "      ./my_hunter x1\n\n", 22);
            write(1, "Description\n", 13);
            write(1, "            x1 = life\n", 23);
            write(1, "            This Game was created by ", 38);
            write(1, "Guillaume CORBET Tek 1 EPITECH\n", 32);
            write(1, "            You have to shoot on duck\n", 38);
            return (42);
        } else {
            return (0);
        }
    }
}