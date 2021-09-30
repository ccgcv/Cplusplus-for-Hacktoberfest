//Implementation of Huffman Coding, Das here :D
#include <bits/stdc++.h>
using namespace std;

class huffmanNode{
    public:

    char data;
    int freq;
    huffmanNode * left;
    huffmanNode * right;

    huffmanNode(char data,int freq){
        this->data=data;
        this->freq=freq;
        this->left=NULL;
        this->right=NULL;
    }

 };


 
struct helper {
 
    bool operator()(huffmanNode* h1, huffmanNode* h2)
    {
        return (h1->freq > h2->freq);
    }
};

priority_queue<huffmanNode*, vector<huffmanNode*>, helper> pq;

map <char,int> freq;
void readinput(string inp){

   for(int i=0;i<inp.size();i++){
     freq[inp[i]]+=1;
   }
   
   cout<<"Frequency of characters are:- "<<endl;
   for(auto z:freq){
    cout<<z.first<<" "<<z.second<<endl;
  }
}


void pushnodes(){
  for(auto z:freq){
    huffmanNode* a=new huffmanNode(z.first,z.second);
    pq.push(a);
  }
}

void maketree(){

  while(pq.size()!=1){ 
    huffmanNode * left=pq.top();
    pq.pop();
    huffmanNode * right=pq.top();
    pq.pop();
    huffmanNode * parent=new huffmanNode('#',left->freq+right->freq);
    parent->left=left;
    parent->right=right;
    pq.push(parent);
  }
}

map<char,string> codes;

void getcodes(huffmanNode * root,string str){
  if(root==NULL){
    return;
  }

  if(root->data!='#'){
    codes[root->data]=str;
  }

  getcodes(root->left,str+"0");
  getcodes(root->right,str+"1");

}

string output(string inp,string out){
  cout<<"The codes for the characters are:- "<<endl;
  for(auto z:codes){
    cout<<z.first<<" "<<z.second<<endl;
  }
  cout<<endl;
  for(int i=0;i<inp.size();i++){
    out+=codes[inp[i]];
  }
  cout<<"Encrypted code will be: ";
  cout<<out<<endl;
  return out;
}

string decode(huffmanNode * root,string out){
  string ans="";
  huffmanNode * curr=root;
  for(int i=0;i<out.size();i++){
    if(out[i]=='0'){
      curr=curr->left;
    }else{
      curr=curr->right;
    }

    if(curr->left==NULL && curr->right==NULL){
      ans+=curr->data;
      curr=root;
    }
  }
  return ans;
}

void level_wise_print(){
  
   queue <huffmanNode *> pendingNodes;
        pendingNodes.push(pq.top());
        while (pendingNodes.size() != 0) {
          int n=pendingNodes.size();

          while(n>0){
              huffmanNode* front = pendingNodes.front();
	          	pendingNodes.pop();
                 cout<<front->data<<":"<<front->freq<<" ";
          
	          	if (front->left !=NULL) {
	          		pendingNodes.push(front->left);
	          	}
	          	if (front->right !=NULL) {
	          		pendingNodes.push(front->right);
	          	}
              n--;   
          }
          cout<<endl;
        
        }
	    return ;
}

int main(){
  string inp;
  cout<<"Enter string: ";
  cin>>inp;
  string out="";
  readinput(inp);
  pushnodes();
  maketree();
  getcodes(pq.top(),"");
  out=output(inp,out);
  string ans=decode(pq.top(),out);
  cout<<"Decoded string is: ";
  cout<<ans<<endl;
  cout<<"\nLevel wise print is:\n"<<endl;
  level_wise_print();
  return 0;
}

