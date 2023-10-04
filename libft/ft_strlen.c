int main(int argc, char **argv)
{
    int i;
    i = 0;

    while(*argv[i] != '\0')
    {
        i++;
    }
    return (i);
}