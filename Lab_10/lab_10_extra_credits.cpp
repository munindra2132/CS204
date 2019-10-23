#include <bits/stdc++.h> 
using namespace std; 
  

int COUNT; 
  

bool is_valid(int x, int y, int key, int **in, int **v, int n, int m) 
{ 
    if (x < n && y < m && x >= 0 && y >= 0) { 
        if (v[x][y] == false && in[x][y] == key) 
            return true; 
        else
            return false; 
    } 
    else
        return false; 
} 
  

void breadthfs(int x, int y, int i, int j, int **in,int **r, int** v,int n, int m) 
{ 
    
    if (x != y) 
        return; 
  
    v[i][j] = 1; 
    COUNT++; 
    int x_move[] = { 0, 0, 1, -1 }; 
    int y_move[] = { 1, -1, 0, 0 }; 
  
     
    for (int u = 0; u < 4; u++) 
        if (is_valid(i + y_move[u], j + x_move[u], x, in,v,n,m)) 
            breadthfs(x, y, i + y_move[u], j + x_move[u], in,r,v,n,m); 
} 
  

void reset_v(int n, int m, int **v) 
{ 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            v[i][j] = 0; 
} 
   
void reset_r(int key, int **in, int **r, int **v, int n, int m) 
{   
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (v[i][j] && in[i][j] == key) 
                r[i][j] = v[i][j]; 
            else
                r[i][j] = 0; 
        } 
    } 
} 

int compute(int **in,int n, int m) 
{ 
    int current_max = INT_MIN; 
    int **r=new int*[n];
   for(int i=0;i<n;i++)
    r[i]=new int[m];
int **v=new int*[n];
   for(int i=0;i<n;i++)
    v[i]=new int[m];
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            reset_v(n,m,v); 
            COUNT = 0; 
  
            if (j + 1 < m) 
                breadthfs(in[i][j], in[i][j + 1], i, j, in,r,v,n,m); 
  
    
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                reset_r(in[i][j], in, r,v,n,m); 
            } 
            reset_v(n,m,v); 
            COUNT = 0; 
  
           
            if (i + 1 < n) 
                breadthfs(in[i][j], in[i + 1][j], i, j, in,r,v,n,m); 
  
      
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                reset_r(in[i][j], in,r,v,n,m); 
            } 
        } 
    } 
    for(int i=0;i<n;i++)
        delete [] r[i],v[i];
    delete [] r, v;
    return current_max;
} 

int main() 
{ 
   int n,m,k;
   cin>>n>>m>>k;
   int **in=new int*[n];
   for(int i=0;i<n;i++)
    in[i]=new int[m];
   
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>in[i][j];
   
    // function to compute the largest 
    // connected component in the grid 
    cout<<compute(in,n,m)<<endl; 
    for(int i=0;i<n;i++)
        delete [] in[i];
    delete [] in;
    return 0; 
} 
