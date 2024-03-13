/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** 4th prg day5
*/

int my_compute_power_rec(int nb, int p)
{
    int n;
    n = nb;
    if (p == 1) {
        return n;
    }
    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    }
    return (my_compute_power_rec(n, p - 1) * nb);
}
