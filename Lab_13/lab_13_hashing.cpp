#include<bits/stdc++.h>

using namespace std;

static bool hsh[5][10000017];
static long long pr[5];

long long ord(char ch)
{
    if(ch>='a'&&ch<='z')
    {
        return (long long)(ch-'a'+1);
    }
    else
        return (long long)(ch-'A'+27);
}

long long func(string &str,long long p,long long  m)
{
    long long sz=str.size();
    long long  s=1;
    long long ans=0;
    for(int i=0;i<sz;i++)
    {
        ans+=(s*ord(str[i]))%m;
        ans%=m;
        s*=p;
        s%=m;
    }
    return ans;
}

int main()
{   int m=10000017;
    pr[0]=53;
    pr[1]=2311;
    pr[2]=13331;
    pr[3]=123457;
    pr[4]=446141;
    long long  n;
    cin>>n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s!=t)
        {
            v.push_back(s);
            for(int  j=0;j<5;j++)
            {
                hsh[j][func(t,pr[j],m)]=true;
            }
        }
    }
    for(auto s:v)
    {
        bool flag=true;
        for(int j=0;j<5;j++)
        {
            if(hsh[j][func(s,pr[j],m)]==false) flag=false;
        }
        if(flag==true)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
