/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:42:39 by kwiessle          #+#    #+#             */
/*   Updated: 2016/04/05 11:52:11 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*init_ptr(void)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(2048);
	while (i < 2049)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void	brainfuck(char *str)
{
	char	*ptr;
	int		i;
	int		loop;

	ptr = init_ptr();
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			ptr++;
		if (str[i] == '<')
			ptr--;
		if (str[i] == '+')
			(*ptr)++;
		if (str[i] == '-')
			(*ptr)--;
		if (str[i] == '.')
			write(1, ptr, 1);
		if (str[i] == '[')
		{
			if (*ptr == 0)
			{
				loop = 0;
				while (str[i])
				{
					if (str[i] == '[')
						loop++;
					if (str[i] == ']')
						loop--;
					if (loop == 0)
						break;
					i++;
				}
			}
		}
		if (str[i] == ']')
		{
			if (*ptr > 0)
			{
				loop = 0;
				while (str[i])
				{
					if (str[i] == ']')
						loop++;
					if (str[i] == '[')
						loop--;
					if (loop == 0)
						break;
					i--;
				}
			}
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
