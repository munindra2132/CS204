#include<bits/stdc++.h>
using namespace std;


int main()
{  std::vector<string> v;
	int n;
	cin>>n;
	set<string> rev;
	bool t=false;
	while(n--)
	{
		string g;
		cin>>g;
		bool b=false;
	    for(int i=0;i<g.length();i++)
	    {
	    	if(g[i]!=g[g.length()-1-i])
	    	{
              b=true;
              break;
	    	}
	    }
	    if(b)
	    {
		    set<string>::iterator it = rev.find(g);
		    if(it==rev.end()){
		    	reverse(g.begin(),g.end());
		    	rev.insert(g);
		    }
		    else{
               cout<<"Yes"<<endl;
               return 0;
		    }

	   }
	}
	cout<<"No"<<endl;
	return 0;
}