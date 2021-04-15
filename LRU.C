#include<stdio.h>
#define MAX 30
int seq[MAX], f, n, eindex[MAX];
int checkexistence(int a, int b[MAX]);
int spacecheck(int x[MAX]);
int lru(int frame[MAX], int count);
void insert(int u, int frame[MAX], int v);
void replacer(int frame[MAX], int olde, int newe);
int main()
{
    int i,j,frame[MAX],count=0;
    float hit=0,miss=0,hit_ratio=0,miss_ratio=0;
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
        frame[i] = -1;
    }
    printf("\n-1 represents empty space\n\n");
    for (i=0;i<n;++i)
    {
        if (checkexistence(seq[i], frame))
        {
            eindex[seq[i]] = i;
            for (j=0;j<f;++j)
            {
                printf("%d\t", frame[j]);
            }
            printf("HIT");
            hit++;
        }
        else if (spacecheck(frame))
        {
            eindex[seq[i]] = i;
            insert(seq[i], frame, -1);
            for (j=0;j<f;++j)
            {
                printf("%d\t", frame[j]);
            }
            printf("MISS");
            miss++;
        }
        else
        {
            int replace = lru(frame, count);
            replacer(frame, replace, seq[i]);
            eindex[seq[i]] = i;
            for (j=0;j<f;++j)
            {
                printf("%d\t", frame[j]);
            }
            printf("MISS");
            miss++;
        }
        count++;
        printf("\n");
    }
    hit_ratio = hit / n;
    miss_ratio = miss / n;
    printf("\nHIT RATIO : %.2f", hit_ratio);
    printf("\nMISS RATIO : %.2f", miss_ratio);
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
    int i,flag = 0;
    for (i=0;i<f;++i)
    {
        if (x[i] == -1)
        {
            flag = 1;
            break;            
        }
    }
    return flag;
}

void insert(int u, int frame[MAX], int v)
{
    int i;
    for (i=0;i<f;++i)
    {
        if (v == frame[i])
        {
            frame[i] = u;
            break;
        }
    }
}

int lru(int frame[MAX], int count)
{
    int i,j,minindex=MAX,minimum;
    for (i=0;i<f;++i)
    {
        for (j=count-1;j>=0;--j)
        {
            if (frame[i] == seq[j] && eindex[seq[j]] < minindex)
            {
                minindex = eindex[seq[j]];
                minimum = seq[j];
            }
        }
    }
    return minimum;
}

void replacer(int frame[MAX], int olde, int newe)
{
    int i;
    for (i=0;i<f;++i)
    {
        if (frame[i] == olde)
        {
            frame[i] = newe;
            break;
        }
    }
}
