#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

//int j=0;
//string g;


int com(string a, string b )
{
	string d=a.append(b);
	string e=b.append(a);

	return d.compare(e)>0 ?1:0;
}
void Lnum(vector<string> v)
{
	sort(v.begin(),v.end(),com);
   
    for(int i=0;i<v.size();i++)
    {
    	cout<<v[i];
    }
    cout<<endl;
}
int main()
{
	long long int g;
	cin>>g;
      
	while(g--)
	{   
		std::vector<string> vec;
		long long int non;
		cin>>non;
		while(non--)
		{ 
			string c;
			cin>>c;
			vec.push_back(c);
        }
        Lnum(vec);
	}
	return 1;
}
