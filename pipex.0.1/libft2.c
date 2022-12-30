#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	answer = malloc(sizeof(char) * (i + j + 1));
	if (!answer)
		return (NULL);
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
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (i == n)
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}