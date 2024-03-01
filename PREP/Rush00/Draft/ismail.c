#include <unistd.h>
void premiere_ligne(int x)
{
    int compteur = 0;
    if (x>=1)
    {write (1, "A", 1);
    compteur++;}
    while (compteur < x-1)
    {
        write (1,"B",1);
        compteur++;
        
    }
    if (x>1)
    {
        write (1,"C",1);
        
    }
    
}

int main()
{
    premiere_ligne(0);
    return 0;
}
