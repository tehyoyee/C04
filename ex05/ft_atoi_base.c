#include <unistd.h>
#include <stdio.h>

int check_same(char *base)
{
    int i;
    int j;

    i = 0;
    while (base[i])
    {
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_sign(char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return (1);
        i++;
    }
    return (0);
}

int str_len(char *base)
{
    int i;

    i = 0;
    while(base[i])
    {
        i++;
    }
    return (i);
}

int find_number(char c, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int ft_print(char *str, char *base, int base_len)
{
    int result;
    int sign;
    
    sign = 1;
	result = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
    while (*str)
	{
		if (find_number(*str, base) >= 0)
			result = result * base_len + find_number(*str, base);
		str++;
	}
    return (sign * result);
}

int ft_atoi_base(char *str, char *base)
{

    int base_len;

    base_len = str_len(base);
    if (check_same(base) || check_sign(base) || !*base || base_len == 1)
        return (0);
    return (ft_print(str, base, base_len));
    
}
int main(void)
{
    printf("%d", ft_atoi_base("   -+--101", "01"));
}