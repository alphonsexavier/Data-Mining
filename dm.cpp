#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
    static int i=0,j=0,cnt=0,temp1=0,temp2=0,k=0;
    int n=6,tids[10],lcount,flag=0;
    string items[10][10],item1,item2,items3[10][10];
    string subset[10][10];
    ifstream obj("l23.txt");
    ifstream obj2("l2.txt");
    if(!obj)
        cout<<"\n ERROR IN FILE CREATION ";
    else
    {
        for(;;)
        {
                for(;;)
                {
                        obj>>items[i][cnt];
                        if(items[i][cnt]=="$"||items[i][cnt]=="!")
                        {
                                //lcount[k]=items[i][cnt];
                                        temp2=cnt-1;
                                        ++k;
                                        break;
                        }
                        ++cnt;
                }

                if(items[i][cnt]=="$")
                {
                        temp1=i;
                        break;
                }
                else
                        i++;
        }

        for(i=0;i<=temp1;i++)
        {
                obj>>items[i][j];
		                for(;j<temp2;j++)
                {
                    cout<<i<<"\t"<<j<<"\t"<<items[i][j]<<"\n";
                        if(items[i][j]=="$"||items[i][j]=="!")
                        {
                                //lcount=items[i-1][j-1];
                                break;
                        }
                        if(j==0||j==1)
                        {
                                item1=items[i][j];
                                item2=items[i][j+1];
                                cout<<i<<"\t"<<j<<"\t"<<item1<<"\t"<<item2<<"\n";
                                //strcat(item1,item2);
                                //cout<<item1;
                                //subset[i][j]=item 1;
                        }
                        if(j==2)
                        {
                                item1=items[i][j-2];
                                item2=items[i][j];
                                //cout<<i<<"\t"<<j<<"\t"<<item1<<"\t"<<item2<<"\n";
                                //strcat(item1,item2);
                                //:subset[i][j]=item2;
                        }
                }
                j=0;
        }

i=0;
j=0;
for(;;)
{
    for(;;j++)
    {
        obj2>>items3[i][j];
        cout<<i<<"\t"<<j<<"\t"<<items3[i][j]<<"\n";
        if(items3[i][j]=="$")
            break;
    }
    if(items3[i][j]=="!")
        break;
    j=0;
    i++;
}




}



return 0;
}

