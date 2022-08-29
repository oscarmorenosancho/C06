/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/26 13:49:46 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				result;
	unsigned int	i;

	result = 0;
	i = 0;
	while (s1[i] && s2[i] && result == 0)
	{
		result = s1[i] - s2[i];
		i++;
	}
	if (result == 0)
		result = s1[i] - s2[i];
	return (result);
}

int	ft_partition(char **arr, int start, int end)
{
	int	i;
	int	j;
	char	*pivot;
	char	*aux;

	pivot = arr[end];
	i = (start - 1);
	j = start;
	while (j <= end - 1)
	{
		if ( ft_strcmp (arr[j], pivot) < 0)
		{
			i++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
		}
		j++;
	}
	aux = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = aux;
	return (i + 1);
}

void	ft_quick_sort(int **arr, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = ft_partition(arr, start, end);
		ft_quick_sort(arr, start, p_index - 1);
		ft_quick_sort(arr, p_index + 1, end);
	}
}
    
int main(int argc, char **argv)
{
    int len;
    int i;
    int j;
    char *arr[100];

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            arr[i - 1] = argv[i];
            i++;
        }
        i = 0;
        ft_quick_sort(arr, 0, argc - 1);       
        while (i < argc - 1)
        {
            j = 0;
            while (arr[i][j])
                j++;
            len = ft_strlen(arr[i]);
            write(1, arr[i], j);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}