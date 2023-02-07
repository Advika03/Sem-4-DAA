#include<stdio.h>
#include<math.h>

int main()
{

    printf("\tIndex\tn\tn^3\t2^n\t2^2^n\t3/2 ^n\te^n\tln n\troot log2 n\tn log2n\t2^log2n");
    for(int k=0;k<=100;k++)
    {
        printf("\n");

        printf("\t%d",k);

        //1.function: n
        //printf("\t%d",k);

        //2. function: n^3
        //printf("\t%.2lf",pow(k,3));

        //3. function: 2^n
        //printf("\t%.2lf",pow(2,k));

        //4. function: 2^ 2^n
        printf("\t%.2lf",pow(2,pow(2,k)));

        //5. function: 3/2 ^n
        //printf("\t%.2lf",pow((1.5),k));

        //6. function: e^n
        //printf("\t%.2lf",pow((exp(1)),k));

        //7. function: ln n
        //printf("\t%.2lf",log(k));

        //8. function: root log2 n
        //printf("\t%.2lf",pow((log2(k)),(0.5)));

        //9. function: n log2 n
        //printf("\t%.2lf",k*log2(k));

        //10. function: log(log(n))
        //printf("\t%.2lf",log2(log2(k)));

    }
    printf("\n");
     fact(20);

    return 0;
}

int fact(int n)
{
    for(int k=0;k<=n;k++)
    {
        int f=1;
        for(int j=k;j>0;j--)
        {
            if(j==0)
                f=1;
                else if(j!=0)
            f=f*j;
        }
        printf("\n %d",f);
    }
}
