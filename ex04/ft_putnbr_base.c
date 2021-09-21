#include <unistd.h>
#include <stdio.h>

int check_same(char *base)    // 진법에 동일한문자 오는지 확인  ex " 01234557"
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

int check_sign(char *base)      // + 나 - 가 있는지 확인.
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

int str_len(char *base)             // 진수 길이 확인.
{
    int i;

    i = 0;
    while(base[i])
    {
        i++;
    }
    return (i);
}

void ft_print(int nbr, char *base, int base_len)    // 출력
{
    if (nbr >= base_len)
    {
        ft_print(nbr / base_len, base, base_len);
        ft_print(nbr % base_len, base, base_len);
    }
    else
    {
        write(1, &base[nbr], 1);
    }
}
void ft_putnbr_base(int nbr, char *base)
{
    int i;
    int j;
    int base_len;

    base_len = str_len(base);
    if (check_same(base) || check_sign(base) || !*base || base_len == 1)       // 예외처리 리턴0
        return ;
    if (nbr == -2147483648)                 // 인트형 최솟값왓을때
    {
        write(1, "-", 1);
        ft_print(-(nbr / base_len), base, base_len);
        ft_print(-(nbr % base_len), base, base_len);
    }
    else if (nbr < 0)                   // 음수
    {
        write(1, "-", 1);
        nbr *= -1;
        ft_print(nbr, base, base_len);
    }
    else
    {
        ft_print(nbr, base, base_len);          //양수
    }
}


int main(void)
{
    int i = 0;
    char *str = "0123456789";

    ft_putnbr_base(-2147483648, str);
    write(1, "\n", 1);
    i++;
}