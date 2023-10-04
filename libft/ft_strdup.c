int ft_len(char *str)
{
    int a;
    a = 0;

    while (str[a] != '\0')
    {
        a++;
    }
    return (a);
}

int main(int argc, char **argv)
{
    char *dup;
    int len;
    int a;
    char *str_size;

    a = 0;

    len = ft_len(argv[1]);
    str_size = (char *)malloc(len);

    while (argv[1][a] != '\0')
    {
        dup[a] = argv[1][a];
        a++;
    }
}