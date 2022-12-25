/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:06:28 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/25 16:07:04 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**ft_split(char *s, char c)
{
	char	**answer;
	int 	i;
	int		j;
	int		k;

	if (!s)
		return NULL;
	answer = malloc(sizeof(char *) * (c_words(s, c) + 1));
	if (!answer)
		return (NULL);
	i = 0;
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
		//protect_later mem_free()
		j = 0;
		while (s[i] != c && s[i])
			answer[k][j++] = s[i++];
		answer[k++][j] = '\0';
	}
	answer[k] = NULL;
	return (answer);
}

char	*ft_strdup(char *s)
{
	char	*answer;
	int		i;

	i = 0;
	while (s[i++]);
	answer = malloc(sizeof(char) * (i + 1));
	if (!answer)
		return (NULL);
	i = -1;
	while (s[++i])
		answer[i] = s[i];
	answer[i] = '\0';
	return (answer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i++]);
	while (s2[j++]);
	answer = malloc(sizeof(char) * (i + j + 1));
	if (!answer)
		return NULL;
	i = -1;
	j = 0;
	while (s1[++i])
		answer[i] = s1[i];
	while (s2[j])
		answer[i++] = s2[j++];
	answer[i] = '\0';
	return (answer);
}

int	ft_cmp(char *a, char *b, int n)
{
	int i;

	i = 0;
	while (*a && *b && *a == *b)
		i++ , a++ , b++;
	if (i == n)
		return (1);
	return (0);
}

char	*ft_get_cmd_path(char **env, char *f)
{
	char	*a;
	char	**b;
	int		i;

	i = -1;
	b = NULL;
	while (env[++i])
		if (ft_cmp(env[i], "PATH=", 5))
			b = (ft_split(env[i] + 5, ':'));
	i = -1;
	while (b && b[++i])
	{
		a = b[i];
		b[i] = ft_strjoin(b[i], "/");
		free (a);
		a = b[i];
		b[i] = ft_strjoin(b[i], f);
		free (a);
	}
	a = NULL;
	i = -1;
	while (b[++i] && !a)
	{	if (!(access(b[i],F_OK)))
			a = ft_strdup(b[i]);	
			}
	ft_mem_free(b);
	printf("%s\n",a);
	return (a);
}
