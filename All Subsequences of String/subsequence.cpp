#include<iostream>
using namespace std;

// Function to get suubsequence and put in the output[] array
int subsequence(string s, string output[])
{
    if(s.length()==0)
    {
        output[0]=" "; // If string length is 0 then attach empty string to the array. Note that empty string is also a subsequence
        return 1;
    }
    int subseq_size = subsequence(s.substr(1),output); // Calling recursively
    for(int i = 0; i<subseq_size; i++ ) // Add the rest of the characters to the subsequence list
    {
        output[i+subseq_size] = s[0] + output[i]; // First character of the substing added to the rest of the character one by one
    }
    return 2*subseq_size;
}

int main()
{
    string s;
    cout<<"Enter String: ";
    getline(cin,s); 
    string o[1000];
    int size = subsequence(s,o); // getting the number of subsequence of the string by calling function
    cout<<"The subsequences are: "<<endl;
    for(int j=0;j<size;j++) // Printing output[] array
    {
        cout<<o[j];
    }
}