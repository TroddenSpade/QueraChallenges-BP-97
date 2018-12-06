#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, n1 = 1, n2 = 1, nextTerm,result;
    int stupdnum = pow(10,9) + 7;
 
    scanf("%d", &n);
 
    for (i = 1; i <= n; ++i)
    {
        nextTerm = n1%stupdnum + n2%stupdnum;
        n1 = n2%stupdnum;
        n2 = nextTerm%stupdnum;
    }
    result = n2 %stupdnum ;
    printf("%d",result);
    return 0;
}