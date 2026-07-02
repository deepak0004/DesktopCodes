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

int visited[1000100],rear=-1,front=-1,N,destination,cost_cost;

struct Edge
{
    int src,dest,weight;
};

struct queue
{
    int src, weight, cost;
}queue_array[1000100];

struct Graph
{
    int V,E;
    struct Edge *edge;
};
struct subset
{
    int parent,rank;
};
struct Graph *createGraph(int V,int E)
{
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge *)malloc(graph->E*sizeof(struct Edge));
    return graph;
}

void insert(struct queue que)
{
        if(front==-1)
        {
            front=0;
        }
        else if(front>rear)
        {
            front=0;
            rear=-1;
        }
        rear++;

        queue_array[rear]=que;
        return;
}
void delete()
{
    if((front==-1) || (front>rear))
    {
        return;
    }
    else
    {
        front++;
        return;
    }
}
int front_queue()
{
    int i;
    if((front==-1) || (front>rear))
    {
         return -1;
    }
    else
    {
         return queue_array[front];
    }
}
void BFS(struct Graph *graph, int src)
{
        int i,u;
        visited[src]=1;
        //insert in queue
        queue que, cQue;
        que.src = src;
        que.weight = 0;
        que.cost = 0;
        insert(que);
        //insert(src);
        while(front_queue()!=-1)
        {
                    u=front_queue();
                    delete();
                    struct AdjListNode *temp=g->array[u].head;
                    while(temp!=NULL)
                    {
                        if(visited[temp->dest]==-1)
                        {
                            visited[temp->dest]=1;
                            cQue.src = temp->dest;
                            cQue.weight =
                            insert(temp->dest);
                        }
                        temp=temp->next;
                    }
         }
}
int FIND_(struct subset subsets[],int i)
{
    if(subsets[i].parent!=i)
    {
         subsets[i].parent=FIND_(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}
void UNION_(struct subset subsets[],int x,int y)
{
    int xroot=FIND_(subsets,x);
    int yroot=FIND_(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank)
    {
         subsets[xroot].parent=yroot;
    }
    else if(subsets[xroot].rank>subsets[yroot].rank)
    {
         subsets[yroot].parent=xroot;
    }
    else
    {
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void *a,const void *b)
{
    struct Edge *a1=(struct Edge *)a;
    struct Edge *b1=(struct Edge *)b;
    return (a1->weight-b1->weight);
}

void KruskalMST(struct Graph *graph)
{
    int V=graph->V;
    struct Edge result[V];
    int e=0;
    int i=0;
    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),myComp);
    struct subset *subsets=(struct subset *)malloc(V*sizeof(struct subset));
    int v;
    for(v=0;v<V;v++)
    {
        subsets[v].parent=v;
        subsets[v].rank=0;
    }
    while(e<(V-1))
    {
        struct Edge next_edge=graph->edge[i++];
        int x=FIND_(subsets,next_edge.src);
        int y=FIND_(subsets,next_edge.dest);
        if(x!=y)
        {
            result[e++]=next_edge;
            UNION_(subsets,x,y);
        }
    }
    struct Graph *mst_graph=createGraph(V,Ed);
    for(i = 0; i < e; i++){
        mst_graph->edge[i].src=result[i].src;
        mst_graph->edge[i].dest=result[i].dest;
        mst_graph->edge[i].weight=result[i].weight;
    }

    BFS(mst_graph, int start_node);
    BFS(mst_graph, int destination);
    //print final cost_

    for(i=0;i<e;i++)
    {
         if(result[i].src<result[i].dest)
         {
             printf("%d %d %d\n",result[i].src+1,result[i].dest+1,result[i].weight);
         }
         else
         {
             printf("%d %d %d\n",result[i].dest+1,result[i].src+1,result[i].weight);
         }
    }
    return;
}


int main()
{
    int V,test,Ed,W,i,x,y,N;
    S(test);
    while(test--)
    {
           S(N);
           S(Ed);
           V=N;
           struct Graph *graph=createGraph(V,Ed);
           rep(i,0,Ed-1)
           {
              S(x);
              S(y);
              S(W);
              graph->edge[i].src=x-1;
              graph->edge[i].dest=y-1;
              graph->edge[i].weight=W;
           }
           KruskalMST(graph);
    }
    return 0;
}
