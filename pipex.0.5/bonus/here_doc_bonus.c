/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:50:37 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/31 11:50:41 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_stdin_to_file(int fd, char *limit)
{
	char	*t;
	int		b;

	limit = ft_strjoin(limit, "\n");
	if (!limit)
		return (0);
	t = malloc(sizeof(char) * (ft_strlen(limit) + 1));
	if (!t)
	{
		free (limit);
		return (0);
	}
	if (!ft_sub_s_to_f(fd, limit, t, ""))
	{
		free(t);
		free(limit);
		return (0);
	}
	free(limit);
	return (1);
}

int	ft_check_join(char **s, char *t)
{
	char	*t2;

	t2 = *s;
	*s = ft_strjoin(t2, t);
	if (*t2)
		free(t2);
	if (!(*s))
		return (0);
	return (1);
}

int	ft_sub_s_to_f(int fd, char *limit, char *t, char *s)
{
	int		b;

	b = read(0, t, ft_strlen(limit));
	while (b > 0)
	{
		t[b] = '\0';
		if (!ft_check_join(&s, t))
			return (0);
		if (ft_find(s, '\n'))
		{
			if (ft_cmp(s, limit, ft_strlen(limit)))
			{
				free(t);
				return (1);
			}
			write(fd, s, ft_strlen(s));
			free(s);
			s = "";
		}
		b = read(0, t, ft_strlen(limit));
	}
	return (0);
}
