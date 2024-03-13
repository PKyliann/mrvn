/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** task 16 day 6
*/

static int comparison(char c)
{
    if ( c >= 32 && c <= 126) {
        return 1;
    }
    return 0;
}

static int my_strlen(char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int my_str_isprintable(char const *str)
{
    int count = 0;
    int l = my_strlen(str);
    if (l == 0) {
        return 84;
    }
    for (int i = 0; i < l; i++) {
        if (comparison(str[i]) == 1) {
            count++;
        }
    }
    if (count == l) {
        return 1;
    }
    return 0;
}
