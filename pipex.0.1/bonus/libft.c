/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:06:28 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/28 18:58:14 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	c_words(char *str, char c)
{
	int	answer;
	int	i;
	int	j;

	i = 0;
	answer = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != c && str[i])
		{
			i++;
			j = 1;
		}
		while (str[i] == c)
			i++;
		answer += j;
	}
	return (answer);
}

char	**ft_mem_free(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free (a);
	return (NULL);
}

char	**ft_split2(char *s, char c, char **answer, int i)
{
	int	k;
	int	j;

	k = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		j = i;
		while (s[j] != c && s[j])
			j++;
		answer[k] = malloc(sizeof(char) * (j - i + 1));
		if (!answer[k])
			return (ft_mem_free(answer));
		j = 0;
		while (s[i] != c && s[i])
			answer[k][j++] = s[i++];
		answer[k++][j] = '\0';
	}
	answer[k] = NULL;
	return (answer);
}

char	**ft_split(char *s, char c)
{
	char	**answer;

	if (!s)
		return (NULL);
	answer = malloc(sizeof(char *) * (c_words(s, c) + 1));
	if (!answer)
		return (NULL);
	return (ft_split2(s, c, answer, 0));
}

char	*ft_strdup(char *s)
{
	char	*answer;
	int		i;

	i = 0;
	while (s[i])
		i++;
	answer = malloc(sizeof(char) * (i + 1));
	if (!answer)
		return (NULL);
	i = -1;
	while (s[++i])
		answer[i] = s[i];
	answer[i] = '\0';
	return (answer);
}
