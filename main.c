#include <stdio.h>
#include <stdlib.h>
const int n=4;
void pr(float a[][n+1])
{
    int i, j, k, p;
    float c;
     for (k=0; k<n-1; k++)
    {
        if (a[k][k]==0)
        {
            p=k+1;
            while (a[p][k]==0) p++;
            for (j=k; j<n+1; j++)
            {
                c=a[p][j];
                a[p][j]=a[k][j];
                a[k][j]=c;
            }
        }
        for (i=k+1; i<n; i++)
            for (j=n; j>=k; j--) a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];
    }
for (j=n-1; j>0; j--)
   {
  for (i=j-1; i>=0; i--)
  {
       a[i][n]=a[i][n]-a[i][j]*a[j][n]/a[j][j];
        a[i][j]=0;
    }
    }
}
//***************************************************************************
//***************************************************************************
void obr(float a[][2*n])
{
    int i, j, k, p,t;
    float c;
     for (k=0; k<n-1; k++)
    {
        if (a[k][k]==0)
        {
            p=k+1;
            while (a[p][k]==0) p++;
            for (j=k; j<2*n; j++)
            {
                c=a[p][j];
                a[p][j]=a[k][j];
                a[k][j]=c;
            }
        }
        for (i=k+1; i<n; i++)
            for (j=2*n-1; j>=k; j--) a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];
    }
for (j=n-1; j>0; j--)
   {
  for (i=j-1; i>=0; i--)
  {
       for (t=n; t<2*n;t++) a[i][t]=a[i][t]-a[i][j]*a[j][t]/a[j][j];
        a[i][j]=0;
    }
    }
    for (i=0; i<n; i++)
    {
        for (j=n; j<2*n; j++) a[i][j]=a[i][j]/a[i][i];
    }
}
//***************************************************************************
//***************************************************************************
int main()
{
    float a[n][n+1], b[n][2*n], jo[n][n], c;
    int  i, j, k, p, f;
    printf("enter the job number (5 or 6)\n");
    scanf("%d", &f);
    if (f==5)
    {
        printf("enter extended system matrix\n");
        for (i=0; i<n; i++)
            for (j=0; j<n+1; j++) scanf("%f", &a[i][j]);
        pr(a);
        printf("\n");
        for (i=0; i<n; i++) printf("%8.1f ", a[i][n]/a[i][i]);
    }
    else if(f==6)
    {
        printf("enter the matrix\n");
       for (i=0; i<n; i++)
           for (j=0; j<n; j++)
           {
               scanf("%f", &b[i][j]);
               a[i][j]=b[i][j];
               jo[i][j]=0;
           }
       for (i=0; i<n; i++)
            for (j=n; j<2*n; j++)
                if (i==j-n) b[i][j]=1;
                else b[i][j]=0;
        obr(b);

        for (i=0; i<n; i++)
        {
        printf("\n");
        for (j=n; j<2*n; j++) printf("%6.1f", b[i][j]);
        }

        for (i=0; i<n; i++)
           for (j=0; j<n; j++)
            for (k=0; k<n; k++) jo[i][j]=jo[i][j]+b[i][k+n]*a[k][j];
            printf("\nCheck\n");
        for (i=0; i<n; i++)
        {
        printf("\n");
        for (j=0; j<n; j++) printf("%6.1f", jo[i][j]);
        }
    }
    return 0;
}
