#include<stdio.h>
int read(int ,int ,int c[][10]);
int print(int ,int ,int c[][10]);
int add(int ,int ,int c[][10],int d[][10],int e[][10]);
int multi(int ,int ,int c[][10],int d[][10],int e[][10]);
int id(int ,int ,int c[][10]);
int check(int ,int ,int c[][10],int d[][10]);
void main()
{
    int a[10][10],b[10][10],sum[10][10],mul[10][10],c1,r1,c2,r2,idt[10][10];
    char ans;
    printf("Enter the number of columns of 1st matrix:");
    scanf("%d",&c1);
    printf("Enter the number of row of 1st matrix:");
    scanf("%d",&r1);
    printf("Enter the values of 1st matrix:\n");
    read(c1,r1,a);
    printf("\nEnter the number of columns of 2st matrix:");
    scanf("%d",&c2);
    printf("Enter the number of row of 2st matrix:");
    scanf("%d",&r2);
    printf("Enter the valurs of 2nd matrix:\n");
    read(c2,r2,b);
    id(c1,r2,idt);
    printf("To perform addition press 'y' or to perform multiplication press 'n':\n");
    scanf(" %c",&ans);
    if(ans=='y')
        {if(c1!=c2||r1!=r2)
            printf("matrix column and row are not same");
        else
            add(c1,r1,a,b,sum);
            check(c1,r1,sum,idt);}
    else
        {   if(c1!=r2)
                printf("matrix multiplication can not be performed");
            else
                multi(c1,r2,a,b,mul);
                check(c1,r2,mul,idt);
        }
}
int read(int z,int x,int c[10][10])
{
    for(int i=0;i<z;i++)
        for(int j=0;j<x;j++)
            scanf("%d",&c[i][j]);
}
int print(int z,int x,int c[10][10])
{
    for(int i=0;i<z;i++)
        for(int j=0;j<x;j++)
            printf("\n%d",c[i][j]);
}
int add(int z,int x,int c[10][10],int d[10][10],int e[10][10])
{
    for(int i=0;i<z;i++)
        for(int j=0;j<x;j++)
            e[i][j]=c[i][j]+d[i][j];
    print(z,x,e);
}
int multi(int z,int x,int c[10][10],int d[10][10],int e[10][10])
{
    for(int i=0;i<z;i++)
        {
            for(int j=0;j<x;j++)
            {    e[i][j]=0;
                for(int k=0;k<x;k++)
                    e[i][j]=e[i][j]+c[i][k]*d[k][j];
            }
           }
    print(z,x,e);
}
int id(int z,int x,int c[10][10])
{
    for(int i=0;i<z;i++)
        for(int j=0;j<x;j++)
           {    if(i==j)
                    c[i][j]=1;
                else
                    c[i][j]=0;
           }
}
int check(int z,int x,int c[10][10],int d[10][10])
{
    int flag=1;
    for(int i=0;i<z;i++)
        for(int j=0;j<z;j++)
        {
            if(c[i][j]!=d[i][j])
            {
              flag=0;
              break;
            }
        }
    if(flag==1)
        printf("\nIt is an identity matrix");
    else
        printf("\nIt is not an identity matrix");
}