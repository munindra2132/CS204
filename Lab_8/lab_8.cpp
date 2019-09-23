#include<bits/stdc++.h>
#include<iostream> 
#include<algorithm> 
#include<climits> 
#include<math.h>
  
using namespace std; 
 
int pivot(vector<double>& vec, int pivot, int start, int end)
{
    int left = start, right = end-1;
    while(left < right)
    {
        while(vec.at(left) < pivot && left <= right) 
        	left++;
        while(vec.at(right) > pivot && right >= left) 
        	right--;
        if(left >= right) 
        	break;
        else if(vec.at(left) == vec.at(right)){ 
        	left++; 
        	continue; 
        }
        
        int temp = vec.at(left);
        vec.at(left) = vec.at(right);
        vec.at(right) = temp;
    }
    return right;
}



double MoM(vector<double>& vec, int k, int start, int end){
    
    if(end-start < 10){
        sort(vec.begin()+start, vec.begin()+end);
        return vec.at(k);
    }
    
    vector<double> medians;
    
    for(int i = start; i < end; i+=5)
    {
        if(end - i < 10){
            sort(vec.begin()+i, vec.begin()+end);
            medians.push_back(vec.at((i+end)/2));
        }
        else{
            sort(vec.begin()+i, vec.begin()+i+5);
            medians.push_back(vec.at(i+2));
        }
    }
    
    int median = MoM( medians, (int) medians.size()/2, 0, medians.size()/1);
     int piv = pivot(vec, median, start, end);
    int length = piv - start-1;
    
    if(k < length){
        return MoM(vec, k, start, piv);
    }
    else if(k > length){
        return MoM(vec, k-length, piv+1, end);
    }
    else
        return vec[k];

}

int main()
{   //vector<pair<int,int>> points;
	vector<double> dis;
	long long int cas;
	cin>>cas;
	 while(cas--)
	 {
	 	long long int k,p,q;
	 	cin>>k;
	 	while(k--)
	 	{
          cin>>p>>q;
          dis.push_back( (double) sqrt((p*p)+(q*q)) );    
	 	}
	 	if (dis.size()/2*2==dis.size())
	 	{
	      cout<<MoM(dis, ((int)dis.size()/2 -1), 0, dis.size() );
	 	}
	 	else
	 	cout<<MoM(dis, (int)dis.size()/2 , 0, dis.size() );
     }
      
     return 0;
}
