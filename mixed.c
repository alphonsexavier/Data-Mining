#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int delta1[10][10],delta2[10][10],delta3[10][10],d1[10][10],d2[10][10],r=0,c=0,n=0,i=0,j=0,a[10],b[10],e[10],f[10],t,min,max;
    float e1[10],min1,max1,d3[10][10],total[10][10];
    char ch;
    FILE *ptr;
    ptr=fopen("mixed.txt","r");
    if(ptr==NULL)
    {
        printf("\nNot able to open file");
    }
    else
    {
        ch=getc(ptr);
        while(ch!='$')
        {
            if(ch=='\n')
                ++r;
            ch=getc(ptr);
        }
        printf("\n%d",r);
        rewind(ptr);

        ch=getc(ptr);
        while(1)
        {
            if(ch=='\t')
                ++c;
            if(ch=='\n')
                break;
            ch=getc(ptr);
        }
        c=c+1;
        printf("\n%d",c);

// asymmetric binary delta values
/*
        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            a[i]=(int)ch-48;
            printf("%d",a[i]);
            while(ch!='\n')
                ch=getc(ptr);
                ++i;
            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    delta1[i][j]=1;
                else
                {
                    if((a[i]==0)&&(a[j]==0))
                        delta1[i][j]=0;
                    else if((a[i]==1)&&(a[j]==0))
                        delta1[i][j]=1;
                     else if((a[i]==0)&&(a[j]==1))
                        delta1[i][j]=1;
                     else
                        delta1[i][j]=1;

                }
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",delta1[i][j]);
            }
        }

printf("\n");
*/

// symmetric binary delta values

        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            a[i]=(int)ch-48;
            printf("%d",a[i]);
            while(ch!='\n')
                ch=getc(ptr);
                ++i;
            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    delta1[i][j]=1;
                else
                {
                    if((a[i]==0)&&(a[j]==0))
                        delta1[i][j]=1;
                    else if((a[i]==1)&&(a[j]==0))
                        delta1[i][j]=1;
                     else if((a[i]==0)&&(a[j]==1))
                        delta1[i][j]=1;
                     else
                        delta1[i][j]=1;

                }
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",delta1[i][j]);
            }
        }

printf("\n");

// Categorical delta values
        i=0;
        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            if(ch=='\t')
            {
                ch=getc(ptr);
                b[i]=(int)ch-97;
                printf("\n%d",b[i]);
                while(ch!='\n')
                    ch=getc(ptr);
                ++i;
            }
            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    delta2[i][j]=1;
                else
                {
                    if((a[i]==0)&&(a[j]==0))
                        delta2[i][j]=1;
                    else if((a[i]==1)&&(a[j]==0))
                        delta2[i][j]=1;
                     else if((a[i]==0)&&(a[j]==1))
                        delta2[i][j]=1;
                     else
                        delta2[i][j]=1;

                }
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",delta2[i][j]);
            }
        }

printf("\n");

//Ordinal delta values
            i=0;
            t=0;
        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            if(ch=='\t')
            {
                ++t;
            }
            if(t==2)
            {
                ch=getc(ptr);
                e[i]=(int)ch-48;
                printf("\n%d",e[i]);
                while(ch!='\n')
                    ch=getc(ptr);
                ++i;
                t=0;
            }

            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    delta3[i][j]=1;
                else
                {
                    if((a[i]==0)&&(a[j]==0))
                        delta3[i][j]=1;
                    else if((a[i]==1)&&(a[j]==0))
                        delta3[i][j]=1;
                     else if((a[i]==0)&&(a[j]==1))
                        delta3[i][j]=1;
                     else
                        delta3[i][j]=1;

                }
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",delta3[i][j]);
            }
        }

printf("\n");

//Binary d values

        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            a[i]=(int)ch-48;
            printf("%d",a[i]);
            while(ch!='\n')
                ch=getc(ptr);
                ++i;
            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    d1[i][j]=0;
                else
                {
                    if((a[i]==0)&&(a[j]==1))
                        d1[i][j]=1;
                    else if((a[i]==1)&&(a[j]==0))
                        d1[i][j]=1;
                    else if((a[i]==1)&&(a[j]==1))
                        d1[i][j]=0;
                    else
                        d1[i][j]=0;
                }
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",d1[i][j]);
            }
        }

//Categorical d value
        i=0;
        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            if(ch=='\t')
            {
                ch=getc(ptr);
                b[i]=(int)ch-97;
                printf("\n%d",b[i]);
                while(ch!='\n')
                    ch=getc(ptr);
                ++i;
            }
            ch=getc(ptr);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    d2[i][j]=0;
                else
                {
                    if(b[i]==b[j])
                    {
                          d2[i][j]=0;
                    }
                    else
                    {
                        d2[i][j]=1;
                    }
                }
            }
        }

         for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%d",d2[i][j]);
            }
        }

//Ordinal d values

            i=0;
            t=0;
        rewind(ptr);
        ch=getc(ptr);
        while(ch!='$')
        {
            if(ch=='\t')
            {
                ++t;
            }
            if(t==2)
            {
                ch=getc(ptr);
                e[i]=(int)ch-48;
                printf("\n%d",e[i]);
                while(ch!='\n')
                    ch=getc(ptr);
                ++i;
                t=0;
            }

            ch=getc(ptr);
        }
        n=i;
        max=e[0];
        for(i=0;i<n;i++)
        {
            if(e[i]>max)
            {
                max=e[i];
            }
        }
        printf("\n%d",max);

        for(i=0;i<n;i++)
        {
            e1[i]=(float)(e[i]-1)/(float)(max-1);
        }

        min1=e1[0];
        for(i=0;i<n;i++)
        {
            if(e1[i]<min1)
            {
                min1=e1[i];
            }
        }
        printf("\n%f",min1);

        max1=e1[0];
        for(i=0;i<n;i++)
        {
            if(e1[i]>max1)
            {
                max1=e1[i];
            }
        }
        printf("\n%f",max1);

        for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i==j)
                    d3[i][j]=0;
                else
                {
                        printf("\n%f\t%f",e1[i],e1[j]);
                          d3[i][j]=(float)(e1[i]-e1[j])/(max1-min1);
                          if(d3[i][j]<0)
                            d3[i][j]=d3[i][j]*-1;
                         printf("\t%f",d3[i][j]);
                }
            }
        }

         for(i=0;i<r;i++)
        {
            printf("\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%f",d3[i][j]);
            }
        }


         for(i=0;i<r;i++)
        {
            for(j=0;j<=i;j++)
            {
                total[i][j]=(float)delta1[i][j]*d1[i][j]+(float)delta2[i][j]*d2[i][j]+(float)delta3[i][j]*d3[i][j]/delta1[i][j]+delta2[i][j]+delta3[i][j];
            }
        }

        for(i=0;i<r;i++)
        {
            printf("\n\n\n\n");
            for(j=0;j<=i;j++)
            {
                printf("\t%f",total[i][j]);
            }
        }









    }
}
