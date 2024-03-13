/*
** EPITECH PROJECT, 2022
** getnbr
** File description:
** dunno atm
*/

int my_getnbr(char *str)
{
    int nb = 0; int number = 1; int i = 0;
    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            number = number * - 1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb = nb + str[i] - 48;
        } else {
            return (nb * number);
        }
    }
    return (nb * number);
}
