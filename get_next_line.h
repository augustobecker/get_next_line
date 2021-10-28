#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

  char *get_next_line(int fd);
  char *ft_strchr(const char *str, int argument);
  size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
  char	*ft_substr(char const *s, unsigned int start, size_t len);
  char	*ft_strjoin(const char *s1, const char *s2);
  char	*ft_strdup(char *src);

#endif
