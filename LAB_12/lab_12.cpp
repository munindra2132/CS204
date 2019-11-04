#include<bits/stdc++.h>

using namespace std;
#define mod 1000000000 +7
class edge{
public:
	long long int  s, d, w;
};

class graph
{
public:
	int V, E;
	edge *ed;

};

graph* createGraph(int V, int E)  
{  
    graph* g = new graph;  
    g->V = V;  
    g->E = E;  
  
    g->ed = new edge[E];  
  
    return g;  
}  

class sb
{
public:
	int prt, rank;
};
int find(sb subsets[], int i)  
{  
   
    if (subsets[i].prt != i)  
        subsets[i].prt = find(subsets, subsets[i].prt);  
  
    return subsets[i].prt;  
}  
   
void Union(sb subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);   
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].prt = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].prt = xroot;   
    else
    {  
        subsets[yroot].prt = xroot;  
        subsets[xroot].rank++;  
    }  
} 
int myComp(const void* a, const void* b)  
{  
    edge* a1 = (edge*)a;  
    edge* b1 = (edge*)b;  
    return a1->w > b1->w;  
}  
  
void krsushkal(graph *g)
{
	int V=g->V;
	int e=0;
	int i=0;
    edge r[V];

    qsort(g->ed,g->E,sizeof(g->ed[0]), myComp);
    sb *subsets = new sb[( V * sizeof(sb) )];  
   for (int v = 0; v < V; ++v)  
    {  
        subsets[v].prt = v;  
        subsets[v].rank = 0;  
    }  
  while (e < V - 1 && i < g->E)  
    {  
    
        edge next_edge = g->ed[i++];  
  
        int x = find(subsets, next_edge.s);  
        int y = find(subsets, next_edge.d);  
   
        if (x != y)  
        {  
            r[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
      
    }  
  
    long long int cost=1;
    //cout<<"Following are the edges in the constructed MST\n";  
    for (i = 0; i < e; ++i)  
        cost=((cost)*(r[i].w)%mod);

    if(cost>=0)
    cout<<cost<<endl;
    else
    cout<<-1*cost<<endl;  
    return;  
}
int main()
{
	int n,m;
	cin>>n>>m;
	graph* g = createGraph(n, m); 
	for(int l=0;l<m;l++)
	{
      int i,j,k;
      cin>>i>>j>>k;
      g->ed[l].s=i;
      g->ed[l].d=j;
      g->ed[l].w=-1*k;
     }

     krsushkal(g);
	return 0;
}
