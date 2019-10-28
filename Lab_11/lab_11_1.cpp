#include<bits/stdc++.h>
#define lli long long int
using namespace std;


bool colorit(lli **d, lli *c, lli p, lli m, lli t)
{
  if(c[p]!=-1 && c[p]!=t)
  	return false;

  c[p]=t;
   bool ans = true; 
    for(lli i=0;i<m;i++){ 
        if(d[p][i]){ 
            if(c[i] == -1) 
                ans &= colorit(d,c,i,m,1-t); 
                  
            if(c[i] !=-1 && c[i] != 1-t) 
                return false; 
        } 
        if (!ans) 
            return false; 
    } 
      
    return true; 
}


bool bipartite(lli **d,lli m)
{
  lli c[m];
  for(lli i=0;i<m;i++)
  	c[i]=-1;
   lli p=0;
   return colorit(d,c,p,m,1);
}


int main()
{
	lli n,m;
	cin>>n>>m;
	lli **d=new lli*[n];
	for(lli i=0;i<n;i++)
	{
		d[i]=new lli[n];
		for(lli j=0;j<n;j++)
			d[i][j]=0;
	}
	for(lli i=0;i<m;i++)
     {
     	lli s,e;
     	cin>>s>>e;
     	d[s-1][e-1]++;
     	d[e-1][s-1]++;
     }

     if(bipartite(d,m))
     {
     	cout<<"Yes"<<endl;
     }
     else
     	cout<<"No"<<endl;

	return 0;
}
