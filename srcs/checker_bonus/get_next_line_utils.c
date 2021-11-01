/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:55:29 by malatini          #+#    #+#             */
/*   Updated: 2021/06/14 13:44:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus/checker_bonus.h>

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, t_mem *mem)
{
	char	*single;
	size_t	i;
	size_t	j;
	size_t	l;

	single = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if ((!s1 && !s2) || !(single))
		error(mem, 1, NULL, NULL);
	i = 0;
	j = 0;
	l = ft_len(s1);
	while (i < l)
	{
		single[i] = s1[i];
		i++;
	}
	l = ft_len(s2);
	while (j < l)
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	free(s1);
	return (single);
}

void	check_line(char *line, t_mem *mem)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
		{
			free(line);
			error(mem, 1, NULL, NULL);
		}
		i++;
	}
}
