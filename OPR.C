#include<stdio.h>
#define MAX 30
int seq[MAX],f,n,eindex[MAX];
int checkexistence(int a, int b[MAX]);
int spacecheck(int x[MAX]);
void replacer(int storage[MAX], int olde, int newe);
int opr(int storage[MAX], int count);
int main()
{
    int i,j,storage[MAX],count=0;
    float hit=0,miss=0,hit_ratio,miss_ratio;
    printf("\nEnter the number of frames : ");
    scanf("%d", &f);
    printf("Enter the number of pages : ");
    scanf("%d", &n);
    printf("Enter the page reference string : ");
    for (i=0;i<n;++i)
    {
        scanf("%d", &seq[i]);
    }
    for (i=0;i<f;++i)
    {
        storage[i] = -1;
    }
    printf("\n-1 represents empty space\n\n");
    for (i=0;i<n;++i)
    {
        if (checkexistence(seq[i], storage))
        {
            for (j=0;j<f;++j)
            {
                printf("%d\t", storage[j]);
            }
            printf("HIT\n");
            hit++;
        }
        else if (spacecheck(storage))
        {
            storage[i] = seq[i];
            for (j=0;j<f;++j)
            {
                printf("%d\t", storage[j]);
            }
            printf("MISS\n");
            miss++;
        }
        else
        {
            int replace = opr(storage, count);
            replacer(storage, replace, seq[i]);
            for (j=0;j<f;++j)
            {
                printf("%d\t", storage[j]);            
            }
            printf("MISS\n");
            miss++;
        }
        count++;
    }
    hit_ratio = hit / n;
    miss_ratio = miss / n;
    printf("\nHIT RATIO : %.2f\nMISS RATIO : %.2f", hit_ratio, miss_ratio);
    return 0;
}

int checkexistence(int a, int b[MAX])
{
    int i,flag=0;
    for (i=0;i<f;++i)
    {
        if (a == b[i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int spacecheck(int x[MAX])
{
    int i,flag=0;
    for (i=0;i<f;++i)
    {
        if (-1 == x[i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int opr(int storage[MAX], int count)
{
    int i,j,index=0,maximum,a=0,future[MAX];
    for (i=0;i<f;++i)
    {
        future[storage[i]] = 0;
    }
    for (i=n-1;i>count;--i)
    {
        eindex[seq[i]] = i;
    }
    for (i=0;i<f;++i)
    {
        for (j=n-1;j>count;--j)
        {
            if (storage[i] == seq[j])
            {
                future[storage[i]] = 1;
                if(eindex[seq[j]] > index)
                {
                    index = eindex[seq[j]];
                    maximum = seq[j];
                    a++;
                }
            }
        }
    }
    if (a==0)
    {
        maximum = storage[f-1];
    }
    for (i=0;i<f;++i)
    {
        if (!future[storage[i]])
        {
            maximum = storage[i];
        }
    }
    return maximum;
}

void replacer(int storage[MAX], int olde, int newe)
{
    int i;
    for (i=0;i<f;++i)
    {
        if (storage[i] == olde)
        {
            storage[i] = newe;
            break;
        }
    }
}
