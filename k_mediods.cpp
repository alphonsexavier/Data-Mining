#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int r,c,i,j,n,a[10][10],b[10],temp,k,l,n1;
    float cnt=0.0,c1[10][10],d[10][10]={0.0};
    cout<<"\nEnter the no of rows:";
    cin>>r;
    cout<<"\nEnter the no of columns:";
    cin>>c;
    for(i=0;i<r;i++)
    {
        cout<<"\nEnter the "<<i+1<<" elements:";
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }


    cout<<"\nEnter the number of categories you want to enter";
    cin>>n;
    for(i=0;i<n;i++)
    {
       cout<<"\nEnter the categories you want to select";
       cin>>n1;
       for(j=0;j<n1;j++)
       {
            cin>>l;
            for(k=0;k<c;k++)
            {
                d[i][k]=d[i][k]+a[l-1][k];
            }
        }
        for(k=0;k<c;k++)
            {
                d[i][k]=d[i][k]/n1;
            }

    }



     for(i=0;i<n;i++)
     {
         temp=b[i];
         for(j=0;j<r;j++)
         {
             for(k=0;k<c;k++)
             {
                cnt=cnt+pow((d[i][k]-a[j][k]),2);
             }
             cnt=sqrt(cnt);
            c1[i][j]=cnt;
            cnt=0.0;
        }
    }

    for(i=0;i<n;i++)
    {
        cout<<"\n";
        for(j=0;j<r;j++)
        {
            cout<<c1[i][j]<<"\t";
        }
    }

    return 0;
}
