#include "push_swap.h"

int    ft_count_each_value(char **nbrs)
{
    char    **splited;
    int total_count;
    int i;
    int j;
    total_count = 0;
    i = 1;
    while (nbrs[i]) {
        splited = ft_split(nbrs[i], ' ');
        j = 0;
        while (splited[j]) {
            total_count++;
            j++;
        }
        ft_freestr(splited);
        i++;
    }
    return (total_count);
}

char    **ft_get_each_nbr(char **av, char **numbers, int nbrs_size)
{
    char **splited;
    int num_index;
    int i;
    int j;
    num_index = 0;
    i = 1;
    numbers = malloc(sizeof(char *) * (nbrs_size + 1));
    while (av[i])
    {
        splited = ft_split(av[i], ' ');
        j = 0;
        while (splited[j])
        {
            numbers[num_index++] = splited[j];
            j++;
        }
        free(splited);
        i++;
    }
    numbers[num_index] = NULL;
    return (numbers);
}