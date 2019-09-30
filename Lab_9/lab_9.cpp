#include<bits/stdc++.h>
#include<utility>
using namespace std;

pair<int, int > p;
int n=2*sizeof(int);
set<pair<int,int>> hull;

int finds(pair<int, int > p1, pair<int, int > p2, pair<int, int > i)
{
    int val = (i.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (i.first - p1.first); 
  
    if (val > 0) 
        return 1; 
    if (val < 0) 
        return -1; 
    return 0; 
}
int lineard( pair<int, int > p1, pair<int, int > p2, pair<int, int > i)
{
	return abs ((i.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (i.first - p1.first)); 
} 


void convexhull(std::vector<pair<int, int >> v, long long int n, pair<int, int > p1, pair<int, int > p2, int f)
{ 
  
	int c = -1; 
    int mdis = 0; 
  for (int i=0; i<n; i++) 
    { 
        int temp = lineard(p1, p2, make_pair(v[i].first,v[i].second)); 
        if (finds(p1, p2, v[i]) == f && temp > mdis) 
        { 
            c =i; 
            mdis = temp; 
        } 
    } 
    if (c == -1) 
    { 
        hull.insert(p1); 
        hull.insert(p2);
         
        return; 
    } 
   
    convexhull(v, n, v[c], p1, -finds(v[c], p1, p2)); 
    convexhull(v, n, v[c], p2, -finds(v[c], p2, p1)); 

} 
void phull(vector<pair<int,int>> v, long long int n)
{  
	//int n= v.size()/(2*sizeof(int));
	if(n<3)
	{
		cout<<"Convexhull not possible";
		return;
	}
	
	std::vector<pair<int, int >>::iterator it;
    pair<int, int > p1,p2;
    p1=make_pair(0,0);
    p2=make_pair(0,0);
	for(it=v.begin();it!=v.end();it++)
	{
		if( p1.first > it->first )
		{
         p1=make_pair(it->first,it->second);
		}
		if(p2.first < it->first)
		{
			p2=make_pair(it->first,it->second);
		}

	}
     //cout<<p1.first<<p2.first<<endl;
	convexhull(v,n,p1,p2, 1);
	convexhull(v,n,p1,p2,-1);
   cout<<hull.size()<<endl;
	while (!hull.empty()) 
    { 
        cout <<(*hull.begin()).first <<" "<<(*hull.begin()).second<<endl; 
        hull.erase(hull.begin());
    } 
	return;
}
int main()
{   
	
	long long int k,l=0;
	cin>>k;
	l=k;
    vector<pair<int, int >> h;
    long long int x,y;
	while(k--)
	{
		cin>>x>>y;
		h.push_back(make_pair(x,y));
	}
	
    phull(h,h.size());
    return 0;
}
