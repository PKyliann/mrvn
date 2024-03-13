/*
** EPITECH PROJECT, 2022
** unsigned display
** File description:
** yep
*/

void my_putchar(char c);

int my_put_uns(unsigned int nb)
{
    int mod;
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_uns(nb);
            my_putchar(48 + mod);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
}
