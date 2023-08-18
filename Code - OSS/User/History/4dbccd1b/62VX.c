#include <stdlib.h>
#include <stdio.h>

typedef struct ret
{
    char *str;
    int lp;
}   t_ret;

int ft_strlen(char *str)
{
    int i = 0;
    while (*str)
    {
        i++;
        str++;
    }
    return i;
}

int add_word(char *s, t_ret *ret, int loc)
{
    int i = 0;
    int val;
    while(s[loc - i] == ' ' && loc - i > 0)
        i++;
    while(s[loc - i] != ' ' && loc - i > 0)
        i++;
    val = i;
    if (i == ' ')
        i--;
    while (i > 0)
    {
        ret->str[ret->lp] = s[loc - i];
        i--;
        ret->lp++;
    }
    ret->str[ret->lp++] = ' ';
    return val;
}

char * reverseWords(char * s){
    int size = ft_strlen(s);
    char *str = malloc(size);
    t_ret ret;
    ret.str = str;
    ret.lp = 0;

    while (size > 0)
    {
        size -= add_word(s, &ret, size);
    }
    ret.str[ret.lp] = 0;
    return ret.str;
}

int main ()
{
    char str[] = "hello world";
    char *ret = reverseWords(str);
    printf("%s\n", ret);
}