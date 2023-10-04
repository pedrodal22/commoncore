int main(int argc, char **argv)
{
    int i;
    int a = 0;
    int b = 0;
    i = 0;

    while(*argv[i] != '\0')
    {
        if (*argv[i] >= 65 && *argv[i] <= 122)
        {
            return (1);
        } else
        {
            return (0);
        }
        i++;
    }
}