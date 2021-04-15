#include<stdio.h>
#define MAX 30
int claim[MAX][MAX], allo[MAX][MAX], curr_need[MAX][MAX];
int resource[MAX], avail[MAX];
int i,j,k,p,r,sum[MAX],done[MAX],n,id=0,z=0,over[MAX];
void cal_cn();
void print_cn();
void check(int id);
int summation(int x);

int main()
{
    printf("\n-----------------------------------");
    printf("\nEnter the number of processes : ");
    scanf("%d", &p);
    printf("Enter the number of resources : ");
    scanf("%d", &r);
    printf("\nEnter the claim matrix\n");
    for (i=0;i<p;++i)
    {
        for (j=0;j<r;++j)
        {
            scanf("%d", &claim[i][j]);
        }
    }
    printf("\nEnter the allocation matrix\n");
    for (i=0;i<p;++i)
    {
        for (j=0;j<r;++j)
        {
            scanf("%d", &allo[i][j]);
        }
    }
    printf("\nEnter the resource vector\n");
    for (i=0;i<r;++i)
    {
        scanf("%d", &resource[i]);
    }
    for (i=0;i<r;++i)
    {
        avail[i] = resource[i] - summation(i);
    }
    printf("\nAvailable Vector\n");
    for (i=0;i<r;++i)
    {
        printf("%d ", avail[i]);
    }
    printf("\n");
    cal_cn();
    while (z < p)
    {
        for (int count=0;count<p;++count)
        {
            if (done[count])
            {
                continue;
            }
            else
            {
                check(count);
            }
        }
    }
    printf("\n\nFinal Available Vector\n");
    for (i=0;i<r;++i)
    {
        printf("%d ", avail[i]);
    }
    printf("\n\nSafe Sequence : ");
    for (i=0;i<p;++i)
    {
        printf("P%d ", over[i]);
    }
    return 0;
}

void cal_cn()
{
    for (i=0;i<p;++i)
    {
        for (j=0;j<r;++j)
        {
            curr_need[i][j] = claim[i][j] - allo[i][j];
        }
    }
    print_cn();
}

void print_cn()
{
    printf("\nCurrent Need\n");
    for (i=0;i<p;++i)
    {
        for (j=0;j<r;++j)
        {
            printf("%d ", curr_need[i][j]);
        }
        printf("\n");
    }
}

int summation(int x)
{
    for (j=0;j<p;++j)
    {
        sum[x] += allo[j][x];
    }
    return sum[x];
}

void check(int id)
{
    int flag = 0;
    for (i=0;i<r;++i)
    {
        flag = (curr_need[id][i] <= avail[i])?1:0;
        if (flag == 0)
        {
            break;
        }
    }
    if (flag == 1)
    {
        for (k=0;k<r;++k)
        {
            avail[k] += allo[id][k];
        }
        printf("\nPASS %d\n", z+1);
        printf("Available Vector : ");
        for (k=0;k<r;++k)
        {
            printf("%d ", avail[k]);
        }
        over[z] = id;
        z++;
        done[id] = 1;
    }
}
