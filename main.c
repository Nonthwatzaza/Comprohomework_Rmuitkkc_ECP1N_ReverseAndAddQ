#include <stdio.h>
#include <stdlib.h>

// by Nonthwat zaza @ECP1N Rmuit kkc
// ReverseAndAddQ Homework code
// 80% code
int SwN,Starter,Finalnum,Num,Aws,taws,SwNtest,fixaws,semifixaws;
int Round=0;
int reverse(int N)
{
            while (N != 0)
            {
                SwN = SwN * 10;
                SwN = SwN + N%10;
                N = N/10;
            }
                return SwN;
}

int reversetest (int N)
{
            while (N != 0)
            {
                SwNtest = SwNtest * 10;
                SwNtest = SwNtest + N%10;
                N = N/10;
            }
                return SwNtest;
}

int Plus(int Num)
{
    (Finalnum = Starter+Num);
    Round++;
    return Finalnum;
}

int main()
{
    int N;
    printf("input Number : ");
    scanf("%d",&N);
    Starter = N;
    Num = reverse(N);
    Aws = Plus(Num);
    taws = reversetest(Aws);

    if (taws != Aws)
    {
        while ((taws != Aws)&&(Round<=1000))
        {
            semifixaws=reverse(Aws);
            Aws=Plus(semifixaws);
            taws = reversetest(Aws);
        }
    }

    if ((Aws>=100000)&&(Round >=1000))
    {
        printf("No palindrom found");
    }
        if (taws == Aws)
        {
            printf("reverse is %d\n", Num);
            printf("starter is %d\n", Starter);
            printf("Aws is %d\n", Aws);
            printf("taws is %d\n", taws);
            printf("round is %d\n",Round);
            printf("\n");
            printf("%d %d",Round, Aws);
        }


    return 0;
}
