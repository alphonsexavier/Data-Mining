#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("frequent3.txt","r");
    fp2=fopen("frequent1.txt","r");
    fp3=fopen("frequent2.txt","r");
    int i,j,n=3,z,flag=1,supl,sups,cnt=2,MCT;
    char str[5][50],subset[5][50],temp[50],tempstr[25],mystr[50];
    printf("\n FREQUENT THREE ITEM SET :");
    for(i=0;i<n;i++)
    {
        fscanf(fp1,"%s",&str[i]);
        printf("%s, ",str[i]);
    }
    fscanf(fp1,"%d",&supl);
    printf("SUPPORT COUNT =%d",supl);
    for(i=0;i<n;i++)
        strcpy(subset[i],str[i]);
    for(z=0;z<cnt;z++)
    {
        strcpy(temp,str[z]);
        strcat(str[z]," ");
        strcat(str[z],str[z+1]);
        strcpy(subset[i],str[z]);
        strcpy(str[z],temp);
        i++;
    }
    strcpy(temp,str[0]);
    i=5;
    strcpy(subset[i],str[0]);
    strcat(subset[i]," ");
    strcat(subset[i],str[2]);
    strcpy(tempstr,subset[i]);
    printf("\n\n\n SUBSETS OF FREQUENT THREE ITEM SETS:\n");
    for(j=0;j<=i;j++)
        printf("%s\n",subset[j]);
    printf("\n");
    printf("\n ENTER THE MINIMUM CONFIDENCE THRESHOLD ");
    scanf("%d",&MCT);
    printf("\n");
    strcpy(mystr,subset[5]);
    strcpy(str[0],temp);
    for(i=0;i<3;i++)
    {
        if(strcmp(subset[i],str[i])==0)
        {
            printf("%s      ->",subset[i]);
            for(j=0;j<3;j++)
            {
                if(i!=j)
                    printf(" %s",str[j]);            }
            while(1)
            {
                fscanf(fp2,"%s",temp);
                if(strcmp(temp,subset[i])==0)
                {
                    break;
                }
            }
            fscanf(fp2,"%d",&sups);
            float conf=(supl/(float)sups)*100;
            printf("\t %f",conf);
            if(conf>=MCT)
                    printf("\t STRONG RULE");
            if(i!=2)
                printf("\n");
        }
    }
    strcpy(str[0],temp);
    strcpy(subset[5],tempstr);
    strcpy(str[0],"HOTDOGS");
    supl=2;
    strcpy(subset[5],mystr);
    int var=0;
    z=0;
    j=3;
    cnt=2;
    strcpy(str[0],"HOTDOGS");
    strcat(subset[5],str[2]);
    for(;z<3;)
    {
        for(var=0;;)
       {
           fscanf(fp3,"%s",&temp);
           var++;
           fscanf(fp3,"%s",&tempstr);
           var++;
           if(var==2)
                fscanf(fp3,"%s",&mystr);
           if((((strcmp(tempstr,subset[z])==0)&&strcmp(temp,subset[1])==0))||((strcmp(temp,subset[z])==0)&&(strcmp(tempstr,subset[1])==0)))
           {
                printf("\n%s->     %s",subset[j],str[cnt]);
                cnt=cnt-2;
                strcpy(str[0],"HOTDOGS");
                j++;
                fscanf(fp3,"%d",&sups);
                float conf=(supl/(float)sups)*100;
                printf("\t%f",conf);
                if(conf>=MCT)
                    printf("\t STRONG RULE");
                z++;
                rewind(fp3);
                break;
            }
            if(strcmp(tempstr,"END")==0||strcmp(temp,"END")==0)
                break;
       }
       z++;
    }
    z=0;
    var=0;
    rewind(fp3);
    cnt=0;
    for(;z<3;)
    {
        for(var=0;;)
        {
           fscanf(fp3,"%s",&temp);
           var++;
           fscanf(fp3,"%s",&tempstr);
           var++;
           if(var%2==0)
                fscanf(fp3,"%d",&sups);
           if((((strcmp(tempstr,subset[cnt])==0)&&strcmp(temp,subset[2])==0))||((strcmp(temp,subset[cnt])==0)&&(strcmp(tempstr,subset[2])==0)))
           {
                printf("\n%s->     %s",subset[5],str[1]);
                cnt=cnt-2;
                float conf=(supl/(float)sups)*100;
                printf("\t%f",conf);
                if(conf>=MCT)
                    printf("\t STRONG RULE");
                rewind(fp3);
                z++;
                flag=1;
                break;
            }
            if(strcmp(tempstr,"END")==0||strcmp(temp,"END")==0)
                break;
            if(flag=1)
                break;
       }
       z++;
    }
    printf("\n");
}

