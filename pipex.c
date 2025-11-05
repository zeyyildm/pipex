#include "pipex.h"
#include <stdio.h>
int main(int ac, char *av[], char **env)
{
    (void)ac;
    (void)av;
    //env içinde gezip strncmp ile path= arayıp onları splitlere böl sonuna / koy sonra cmdye ekle.
    char *s = NULL;
    int i = 0;
    while(env[i])
    {
        s = get_paths(env);
        printf("%s: \n", s);
        i++;
    }
    char **tmp = get_split_paths(s);
    i = 0;
    while(tmp[i])
    {
        printf("%s :\n", tmp[i]);
        i++;
    }
    
}
