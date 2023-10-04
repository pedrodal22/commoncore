int main(int argc, char **argv)
{
    int i;
    int a = 0;
    int b = 0;
    i = 0;

    while(*argv[i] != '\0')
    {
        if (*argv[i] >= 48 && *argv[i] <= 57)
        {
            return (1);
        } else
        {
            return (0);
        }
        i++;
    }
}