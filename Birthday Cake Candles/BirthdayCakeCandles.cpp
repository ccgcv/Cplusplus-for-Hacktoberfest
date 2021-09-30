#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> candles(n);
    for(int i = 0;i < n;i++){
        cin >> candles[i];
    }
    int max=0, c=0;
    for(int i=0;i<n;i++){
        if(candles[i]>max){
            max=candles[i];
            c=1;
        }
        else if(max==candles[i])
            c++;
    }
    cout<<c;
    return 0;

}