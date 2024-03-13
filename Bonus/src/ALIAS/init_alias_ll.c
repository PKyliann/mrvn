/*
** EPITECH PROJECT, 2023
** B-PSU-200-NCE-2-1-42sh-mathis.gheri
** File description:
** init_alias_ll.c
*/

#include "../../include/minishell.h"
#include "../../my_printf/my/include/my_printf.h"

void create_alias_var(llenv_s *env_ll)
{
    char *filepath = getcwd(NULL, 0);
    filepath = my_strcat(filepath, "/save/alias");
    char *save = my_strcat("setenv ", "ALIASPOTAT ");
    save = my_strcat(save, filepath);
    char **savepath = my_str_to_words_array(save);
    my_setenv(savepath, &env_ll);
}

void create_load_alias(global_t *sh, alias_t **alias)
{
    create_alias_var(*sh->env_ll);
    char *filepath = NULL;
    llenv_s *head = (*sh->env_ll);
    for (; head; head = head->next) {
        if (strncmp(head->data, "ALIASPOTAT=", 11) == 0) {
            filepath = &head->data[11];
            break;
        }
    }
    char **alias_data = load_file_line(filepath);

    if (alias_data == NULL) {
        sh->alias = alias;
        return;
    }
    create_ll_alias(alias, alias_data);
    sh->alias = alias;
}
