#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define rep(i,s,e) for(i=s;i<=e;i++)
#define rrep(i,s,e) for(i=s;i>=e;i--)

#define S(t) scanf("%d",&t);
#define P(t) printf("%d ",t);
#define SLL(t) scanf("%lld",&t)
#define PLL(t) printf("%lld\n",t)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int tableSize,totEle;
struct node *hashTable=NULL;

struct node
{
    int key,marker;;
    char name[1000];
};
int insertInHash(int key,char *name)
{
    int hashIndex=(key%tableSize);
    if(tableSize==totEle)
    {
        return -1;
    }
    while(hashTable[hashIndex].marker==1)   // Till the time hashTable[hashIndex].marker==0 or hashTable[hashIndex].marker=-1 is encountered, this loop will go on and on
    {
        if(hashTable[hashIndex].key==key)   // Already inserted
        {
            return -1;
        }
        hashIndex=(hashIndex+1)%tableSize;
    }
    hashTable[hashIndex].key=key;
    strcpy(hashTable[hashIndex].name,name);
    hashTable[hashIndex].marker=1;
    totEle++;
    return hashIndex;
}
int deleteFromHash(int key)
{
    int hashIndex=(key%tableSize),count=0,flag=0;
    if(totEle==0)
    {
        return -1;
    }
    while((hashTable[hashIndex].marker!=0) && (count<=tableSize))
    {
        if(hashTable[hashIndex].key==key)
        {
            hashTable[hashIndex].key=INT_MIN;
            /* set marker to -1 during deletion operation*/
            hashTable[hashIndex].marker=-1;
            strcpy(hashTable[hashIndex].name,"\0");
            totEle--;
            flag=1;
            return hashIndex;
        }
        hashIndex=(hashIndex+1)%tableSize;
        count++;
     }
     if(flag==0)
     {
         return -1;
     }
}
int searchElement(int key)
{
    int hashIndex=(key%tableSize),flag=0,count=0;
    if(totEle==0)
    {
        return -1;
    }
    while((hashTable[hashIndex].marker!=0) && (count<=tableSize))
    {
            if(hashTable[hashIndex].key==key)
            {
//                    printf("Voter ID : %d\n", hashTable[hashIndex].key);
//                    printf("Name     : %s\n", hashTable[hashIndex].name);
//                    printf("Age      : %d\n", hashTable[hashIndex].age);
                    flag=1;
                    return hashIndex;
            }
            hashIndex=(hashIndex+1)%tableSize;
            count++;
    }
    if(flag==0)
    {
        return -1;
    }
}
void display()
{
    int i;
    if(totEle==0)
    {
        printf("%d\n",-1);
    }
    for(i=0;i<tableSize;i++)
    {
        if(hashTable[i].marker==1)
        {
            printf("%d ",hashTable[i].key);
            printf("%s\n",hashTable[i].name);
        }
    }
    return;
}


int main()
{
        int key;
        char name[1000],ch[1000];
        scanf("%d",&tableSize);
        hashTable=(struct node *)calloc(tableSize,sizeof(struct node)); // Initialise the table with 0
        while(1)
        {
                        getchar();
                        scanf("%s",ch);
                        if(!strcmp(ch,"Insert"))
                        {
                            scanf("%d",&key);
                            getchar();
                            scanf("%s",name);
                            int deepak=insertInHash(key,name);
                            if(deepak!=-1)
                            {
                                printf("%d\n",deepak);
                            }
                            else // Not Inserted
                            {
                                printf("%d\n",deepak);
                            }
                        }
                        else if(!strcmp(ch,"Delete"))
                        {
                            scanf("%d",&key);
                            int deepak=deleteFromHash(key);
                            if(deepak!=-1)
                            {
                                printf("%d\n",deepak);
                            }
                            else // Not Deleted
                            {
                                printf("%d\n",deepak);
                            }
                        }
                        else if(!strcmp(ch,"Search"))
                        {
                            scanf("%d",&key);
                            int deepak=searchElement(key);
                            if(deepak!=-1)
                            {
                                printf("%d\n",deepak);
                            }
                            else // Not Searched
                            {
                                printf("%d\n",deepak);
                            }
                        }
                        else if(!strcmp(ch,"Display"))
                        {
                            display();
                        }
                        else if(!strcmp(ch,"Done"))
                        {
                            return 0;
                        }
        }
        return 0;
}
