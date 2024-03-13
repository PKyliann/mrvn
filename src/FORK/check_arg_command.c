/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** check_arg_command.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

char *check_var(char *val, int *warning)
{
    if (strlen(val) == 1) {
        my_printf("$: Command not found.\n"); *warning = 84;return NULL;
    }
    global_t *sh = getstruct();
    llenv_s *tmp_env = *sh->env_ll;
    char *value = strdup(val); char *cpy_var = strcat(&value[1], "=");
    for (; tmp_env; tmp_env = tmp_env->next) {
        if (strncmp(tmp_env->data, cpy_var, strlen(cpy_var)) == 0) {
            return &tmp_env->data[strlen(cpy_var)];
        }
    }
    lvar_t *tmp_var = *sh->vars_ll;
    for (; tmp_var; tmp_var = tmp_var->next) {
        if (strncmp(tmp_var->name, cpy_var, strlen(tmp_var->name)) == 0) {
            return tmp_var->value;
        }
    }
    my_printf("%s: Undefined variable.\n", val);
    *warning = 84;
    return NULL;
}

char **cut_array(char **array)
{
    char **tmp = array;
    char *buff = my_concat_strings(tmp);
    char **new = my_str_to_words_array(buff);
    return new;
}

char *rm_dquotes(char *str, global_t *sh)
{
    int len_quotes = 0; int w = 0; int z = 0;
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '"')
            len_quotes++;
    int len = strlen(str) - len_quotes;
    char *dest = malloc(sizeof(char) * (len + 1));
    for (; str[w] != '\0'; z++, w++) {
        if (str[w] == '"')
            w++;
        dest[z] = str[w];
    }
    dest[z] = '\0';
    return dest;
}

void condition_val(char *val, char **tmp, int *check)
{
    if (val == NULL) {
        return;
    }else {
        *tmp = strdup(val);
        *check += 1;
    }
}

char **check_param_array(global_t *sh)
{
    int check = 0; char **tmp = dup_array(sh->shell_array); int warning = 0;
    for (int i = 0; tmp[i]; i++) {
        if (contain_dollar(tmp[i]) == 1) {
            char *val = check_var(tmp[i], &warning);
            condition_val(val, &tmp[i], &check);
        }
        if (check_alias_var(tmp[i], sh) != -1) {
            char *var = replace_alias_str(sh, i);
            tmp[i] = var; check = 1;
        }
        if (check_dquotes(tmp[i], sh) == 1) {
            tmp[i] = rm_dquotes(tmp[i], sh);
            check = 1;
        }
    }
    if (warning == 84)
        return NULL;
    if (check != 0)
        tmp = cut_array(tmp);
    return tmp;
}
