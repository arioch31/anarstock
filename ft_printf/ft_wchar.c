
#include "libft.h"

long int  ft_wctolint(wchar_t wc)
{
  if (wc < 0x80) 
    return ((int)wc);
  if (wc < 0x1000)
      return (0xc080 +((wc / 0x40) * 0x100) + (wc % 0x40));
  if (wc < 0x20000)
    return (0xe08080 +(wc / 0x1000)* 0x10000  + (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
  else
    return (0xf0808080 + ((wc % 0x200000) / 0x40000) * 0x1000000 + ((wc % 0x40000) / 0x1000) * 0x10000 
      + (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
}

int   ft_writewc(wchar_t wc)
{
      long long   tmp;
      char        part1, part2, part3, part4;
      int         i;

      i = 0;
      tmp = ft_wctolint(wc);
      part1 = (char)(tmp / 0x1000000);
      part2 = (char)(tmp % 0x1000000 / 0x10000);
      part3 = (char)(tmp % 0x10000 / 0x100);
      part4 = (char)(tmp % 0x100);
     if (part1)
        write(1, &part1, 1); 
      if (part2)
        write(1, &part2, 1);
      if (part3)
        write(1, &part3, 1);
      if (part4)
        write(1, &part4, 1);
      i = !!part1 + !!part2 + !!part3 + !!part4;
      return (i);
}

char  *ft_wctostr(wchar_t wc)
{
  char  *res;
  char  c;
  int   i;
  long long   tmp;

  i = 0;
  tmp = ft_wctolint(wc);
  res = ft_strnew(4);
  c = (char)(tmp / 0x1000000);
  if (c)
    res[i++] = c;
  c = (char)(tmp % 0x1000000 / 0x10000);
  if (c)
    res[i++] = c;
  c = (char)(tmp % 0x10000 / 0x100);
  if (c)
    res[i++] = c;
  c = (char)(tmp % 0x100);
  if (c)
    res[i++] = c;
  return (res);
}

char  *ft_strwctostr(wchar_t *wc)
{
  char  *str;

  while (*wc)
  {
    str = ft_strjoin(str, ft_wctostr(*wc));
    wc++;
  }
  return (str);
}

int   ft_writeswc(wchar_t *wc)
{   
  int i;

  i = 0;
   while (*(wc + i))
    {
      ft_writewc(*(wc + i));
      i++;
    }
    return (i);
}