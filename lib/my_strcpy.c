/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** 1st prg day 6
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
