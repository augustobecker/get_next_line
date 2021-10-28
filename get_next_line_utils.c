#include "get_next_line.h"

char	*ft_strchr(const char *str, int argument)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char)argument)
			return ((char *) &str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *) &str[i]);
	return ((void *) 0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (destsize <= 0)
		return (src_length);
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	len;
	char	*dup;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_length;
	size_t	s_length;
	char	*substr;

	if (!s)
		return (NULL);
	s_length = 0;
	while (s[s_length])
		s_length++;
	substr_length = s_length - start;
	if (s_length > start)
	{
		if (substr_length > len)
			substr = (char *) malloc(sizeof(char) * (len + 1));
		else
			substr = (char *) malloc(sizeof(char) * (substr_length + 1));
		if (!substr)
			return (NULL);
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		substr = ft_strdup("");
	return (substr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t 	s1_len;
	size_t 	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s1_len + s2_len + 1);
	return (str);
}
