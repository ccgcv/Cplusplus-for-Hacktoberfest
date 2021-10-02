/*
// NSL -> Nearest smaller element to the left
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  stack<int>st;
  vector<int>vec(n);

  for(int i=0;i<n;i++){
    if(st.empty()){
      vec[i] = -1;
    }else if(st.top()<arr[i]){
      vec[i] = st.top();
    }else{
      while(!st.empty()&&st.top()>=arr[i]){
        st.pop();
      }
      if(st.empty()){
        vec[i] = -1;
      }else{
        vec[i] = st.top();
      }
    }
    st.push(arr[i]);
  }

  for(int i=0;i<n;i++){
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  return 0;
}