#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;


string findLargestConcat (vector<string> &f  ) {
   vector<string> concatnumbers ;
   sort ( f.begin( ) , f.end( ) ) ;
   do {
      ostringstream numberstream ;
      for ( string i : f ) 
	 numberstream << i ;
      concatnumbers.push_back( numberstream.str( ) ) ;
   } while ( next_permutation( f.begin( ) ,f.end( ) )) ;
   return *( max_element( concatnumbers.begin( ) , concatnumbers.end( ) ) ) ;
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
			int k=0;
			while(k<c.size())
			{
				if(c[k]=='0')
					c.erase(k);
				k++;
			}
			cin>>c;
			vec.push_back(c);
        }
        cout<<findLargestConcat(vec);
	}
	return 1;
}
