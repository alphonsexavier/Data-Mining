#include<iostream>
using namespace std;
int check(int a[12][3],int p,int q);
int main()
{
    int v,a[12][3]={{12,1,2},{16,2,3},{12,3,4},{16,4,1},{13,4,5},{14,3,6},{14,2,7},{13,1,8},{14,5,6},{15,6,7},{14,8,7},{15,8,5}},e,i,j,temp=0,cnt=0,mst[15][15];
    int k=0,b[15]={0},c[15]={0},d[15]={0},an=0,na=0,counter1,counter2,z=1,w=0;
         for(i=0;i<12;i++)
        {
                for(j=0;j<3;j++)
                {
                        cout<<a[i][j]<<"\t";
                }
                cout<<"\n";
        }

        cout<<"\n";

    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
           if(a[i][0]<a[j][0])
           {

               temp=a[j][0];
               a[j][0]=a[i][0];
               a[i][0]=temp;//weight

                temp=a[j][1];
                a[j][1]=a[i][1];
                a[i][1]=temp;//source

                temp=a[j][2];
                a[j][2]=a[i][2];
                a[i][2]=temp;//destination
           }
        }
    }

        for(i=0;i<12;i++)
        {
                for(j=0;j<3;j++)
                {
                        cout<<a[i][j]<<"\t";
                }
                cout<<"\n";
        }


for(i=0;i<12;i++)
{
        if(cnt>1)
        {
                for(int l=0;c[l]!=0;l++)
                {
                        //cout<<"\n1:";
                        if(a[i][1]==c[l]||a[i][1]==d[l])
                        {
                           // cout<<a[i][1]<<"\t"<<a[i][2]<<"\t||"<<c[l]<<"\t"<<d[l]<<"\t"<<l;
                                ++an;
                        }
                }
                for(int m=0;d[m]!=0;m++)
                {
                        //cout<<"\n2:";
                        if(a[i][2]==d[m]||a[i][2]==c[m])
                        {
                          //  cout<<a[i][1]<<"\t"<<a[i][2]<<"\t||"<<c[m]<<"\t"<<d[m]<<"\t"<<m;
                                ++na;
                        }
                }
        counter1=a[i][1];
        counter2=a[i][2];
        cout<<"\nan:"<<an;
        cout<<"\nna:"<<na;

        if(an==2||(na==2|| an+na==2))
        {
            cout<<"hi";
            z=check(a,counter1,counter2);
        }
}

        if(cnt<=1)
        {
                b[k]=a[i][0];//weight
                c[k]=a[i][1];//source
                d[k]=a[i][2];//destination
               // cout<<"\n3."<<b[k]<<"\t"<<c[k]<<"\t"<<d[k];
        }

        if(z==1 && cnt>1)
        {
            cout<<"loos";
            for(j=0;j<3;j++)
            {
                mst[k][j]=a[i][j];
            }
        cout<<"\n";
                b[k]=a[i][0];//weight
                c[k]=a[i][1];//source
                d[k]=a[i][2];//destination
                cout<<b[k]<<"\t"<<c[k]<<"\t"<<d[k];
                w=w+b[k];
                ++k;
        }

        ++cnt;
        an=0;
        na=0;
        temp=0;
        z=0;
}


 cout<<"\n";
 for(i=0;i<k;i++)
        {
                for(j=0;j<3;j++)
                {
                        cout<<mst[i][j]<<"\t";
                }
                cout<<"\n";
        }



return 0;
}

int check(int a[12][3],int p,int q)
{
    int c,d;

    for(int i=0;i<12;i++)
    {
            if(p==a[i][1])
            {
                    c=a[i][2];
                    break;
            }
            if(p==a[i][2])
            {
                    c=a[i][1];
                    break;
            }
    }

    for(int i=0;i<12;i++)
    {
            if(q==a[i][1])
            {
                d=a[i][2];
                break;
            }
            if(q==a[i][2])
            {
                d=a[i][1];
                break;
            }
    }

    cout<<"c:"<<c<<"d:"<<d;

    for(int i=0;i<12;i++)
    {
        if(c==a[i][1]&&d==a[i][2])
            return 1;
        if(c==a[i][2]&&d==a[i][1])
            return 1;
    }
    return 0;
}






