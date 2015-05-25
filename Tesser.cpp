#include<bits/stdc++.h>

using namespace std;

int main()
{
string pat;
int t,i,n,len,m,l,j,flag;
cin>>t;

while(t--)
{
cin>>n;
long long int arr[n];
char str[n];

for(i=0;i<n;i++)
cin>>arr[i];

for(i=0;i<n-1;i++)
{
if(arr[i+1]>arr[i])
str[i]='G';

else if(arr[i+1]<arr[i])
str[i]='L';

else
str[i]='E';
}

cin>>pat;

m=pat.length();
l=n-1;

int lps[m];
lps[0]=0;
i=1;len=0;
while(i<m)
{
if(pat[i]==pat[len])
{
len++;
lps[i]=len;
i++;
}
else
{
if(len!=0)
len=lps[len-1];

else
{
lps[i]=0;
i++;
}

}
}
i=0;j=0;flag=0;
while(i<l)
{
    if(pat[j]==str[i])
    {
        i++;j++;
    }
    if(j==m)
       {
           flag=1;
           cout<<"YES"<<endl;
           break;
       }
    if(i<l && pat[j]!=str[i])
    {
        if(j!=0)
        j=lps[j-1];

        else
            i++;
    }
}
if(flag!=1)
    cout<<"NO"<<endl;
}
}
