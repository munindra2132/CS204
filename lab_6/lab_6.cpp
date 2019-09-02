#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct mps
{  
	long long int id,cf=0;
};


std::vector< mps> var;

void entri(long long int s,long long int b)
{  int l=0;
      
        if(var.size()==0)
        {
        	mps d;
        	d.id=s;
        	d.cf=b;
        	var.push_back(d);
        }
        else
        {
        	for(long long int k=0;k<var.size();k++)
        	{
        		if(var[k].id==s)
        			{
        				var[k].cf=var[k].cf+b;
        				l++;
        			}	
        	}
        	if(l==0)
        	{
        		mps d;
        	d.id=s;
        	d.cf=b;
        	var.push_back(d);
        	}
        }
} 

void srchmx()
{  
	long long int key;
	long long int max=0;
	int  j=0;
	if(var.size()!=0)
	{
		for(long long int k=0;k<var.size();k++)
        	{
        		if(var[k].cf>=max)
        			{   max=var[k].cf;
        				key=var[k].id;
        		        j++;
        		     }   
        	}
	    
	 }
	 else
	 {
	 	cout<<"No data avalailabe\n";
	 }  
	 if(j!=0)
	 cout<<key<<endl;
	 var.clear() ;
}
int main()
{
	long long int n,q,a,s,b;
	cin>>n>>q;
   while(q--)
   {
     cin>>a;
     if(a==1)
        {          
          cin>>s>>b;
          //cout<<"*";
          entri(s,b);
        }
      else
      	 {
      	 	if(a==2)
      	 	{
               srchmx();
              
      	 	}
      	 }
   }
   return 1;
}
