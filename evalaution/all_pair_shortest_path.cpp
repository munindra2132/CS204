#include <bits/stdc++.h> 

using namespace std; 
    
#define INF 99999  

int V;

void printSolution(int **dist);  


void farshall (int **graph)  
{  
  int **dist=new int*[V];
     for(int i=0;i<V;i++)
     {
      dist[i]=new int[V];
     }
   int i, j, k;  
    for (i = 0; i < V; i++)  
      for (j = 0; j < V; j++)  
          dist[i][j] = graph[i][j];  

    for (k = 0; k < V; k++)  
    {  
      for (i = 0; i < V; i++)  
       {  
        for (j = 0; j < V; j++)  
        {  
          if (dist[i][k] + dist[k][j] < dist[i][j])  
             dist[i][j] = dist[i][k] + dist[k][j];  
        }  
        }  
    }    

    printSolution(dist);  
}  

  


void printSolution(int **dist)  
{  

    cout<<"The following matrix shows the shortest distances between every pair of vertices \n";  

    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  

            if (dist[i][j] == INF)  
               cout<<"INF"<<"     ";  
            else
               cout<<dist[i][j]<<"     ";  

        }  

        cout<<endl;  

    }  
}  

    

int main()  
{    
     
     cin>>V;
     int **graph=new int*[V];
     for(int i=0;i<V;i++)
     {
      graph[i]=new int[V];
     }
     for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            cin>>graph[i][j];
            if(graph[i][j]==0)
                graph[i][j]=INF;
        }  


    farshall(graph);  

    return 0;  
}  
