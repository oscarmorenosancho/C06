/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:35:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/30 15:52:01 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			len = ft_strlen(argv[i]);
			write(1, argv[i], len);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
