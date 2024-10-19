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
        free(splited);
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
    if (!numbers)
        return (NULL);
    while (av[i] && num_index < nbrs_size)
    {
        splited = ft_split(av[i], ' ');
        if (!splited)
        {
            free(numbers);
            return (NULL);
        }
        j = 0;
        while (splited[j])
        {
            if (num_index < nbrs_size)
                numbers[num_index++] = ft_strdup(splited[j]);
            else
                break ;
            j++;
        }
        ft_freestr(splited);
        free(splited);
        i++;
    }
    numbers[num_index] = NULL;
    return (numbers);
}