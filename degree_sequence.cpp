#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,e[10],m,max,temp;
    cout<<"\nEnter the number of degrees";
    cin>>n;
    cout<<"\nEnter the degree sequence";
    for(i=0;i<n;i++)
    {
        cin>>e[i];
    }

m=e[0];

for(i=0;i<n;i++)
{
    if(e[0]== 0)
    {
        cout<<"\nIt is graphical";
    }
    for(j=0;j<m;j++)
    {
        e[j]=e[j+1]-1;
        cout<<e[j];
        if(e[j]<0)
        {
            cout<<"\nIt is not graphical";
            break;
        }
    }

    n=n-1;
    cout<<n;
    for(j=m;j<n;j++)
    {
        e[j]=e[j+1];
        cout<<e[j];
    }

    cout<<"\n";
    for(j=0;j<n;j++)
    {
     //   cout<<e[j];
    }


    max=e[0];

    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            if(e[k]<e[j])
            {
                temp=e[k];
                e[k]=e[j];
                e[j]=temp;
            }

        }
    }

    cout<<"\n";
    for(j=0;j<n;j++)
    {
        cout<<e[j];
    }

    m=e[0];
}

    return 0;
}


