/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:08:16 by argharag          #+#    #+#             */
/*   Updated: 2025/04/06 14:16:55 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static void	ft_free(char ***back, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		if ((*back)[i] != NULL)
			free((*back)[i]);
		(*back)[i] = NULL;
		i++;
	}
	free(*back);
	*back = NULL;
}

static char	*word_dup(char const *s, char c)
{
	char	*back;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	back = (char *)malloc((len + 1) * sizeof(char));
	if (back == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		back[i] = s[i];
		i++;
	}
	back[i] = '\0';
	return (back);
}

static char	**allocate_words(char const *s, char c, int word_count)
{
	char		**back;
	int			i;
	const char	*word_start;

	back = (char **)malloc((word_count + 1) * sizeof(char *));
	if (back == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s != '\0' && *s != c)
			s++;
		back[i] = word_dup(word_start, c);
		if (back[i] == NULL)
		{
			ft_free(&back, i);
			return (NULL);
		}
		i++;
	}
	back[i] = NULL;
	return (back);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	word_count = ft_word(s, c);
	return (allocate_words(s, c, word_count));
}
/*
int main()
{
	char c[] = "         split        this for   me  !          ";
	char **back = ft_split(c,' ');
	if (!back)
		printf("OK\n");
	int i = 0;
	
	while (i < ft_word(c, ' '))
	{
		printf("%s |", back[i]);
		i++;
	}
	printf("\n%s", back[i]);
	i = 0;
	while (back[i])
	{
		free(back[i]);
		i++;
	}
	free(back);
}*/
