#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int track1=0;
    int track2=0;
    int res;
    while(t>0)
    {
     int n;
     cin>>n;
     int a[n];

int after1=0;
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }



for (int i = 0; i < n; i++)
    {
        if(a[i]==1)
        {
            after1=i;
        }
    }

     for(int i=0;i<n;i++)
     {
         track1=0;
    track2=0;
         if(a[i]==0)
         {
             for (int j = i; (a[j] != 1 && j!=0);j--)
            {
               ++track2;
           
              
            }

             for (int j = i; (a[j] != 1 && j!=n-1) ;j++)
            {
               ++track1;
           
              
            }
             if(i>=after1)
            {
                track1=INT_MAX;
            }
            
        }
        res+=min(track1,track2);
         



     }
       cout<<res<<endl;

        t--;
    }
    return 0;
}
