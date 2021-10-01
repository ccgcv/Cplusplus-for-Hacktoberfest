#include <bits/stdc++.h>
using namespace std;

class BSTnode{
    private:
    int data;
    BSTnode* left;
    BSTnode* right;
    BSTnode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    friend class BST;
};

class BST{
    BSTnode * root;
    public:
    BST(){
        root=NULL;
    }

    void insert(int data){
        BSTnode *ptr=new BSTnode(data);

        if(root==NULL){
            root=ptr;
            return;
        }

        BSTnode * temp=root;
        while(1){
            if(temp->data > data){
                if(temp->left==NULL){
                    temp->left=ptr;
                    return;
                }else{
                    temp=temp->left;
                }
            }else{
                if(temp->right==NULL){
                    temp->right=ptr;
                    return;
                }else{
                    temp=temp->right;
                }

            }

        }

    }

    private:
    BSTnode* insert_rec(BSTnode*root,int data){
        if(root==NULL){
            BSTnode* ptr=new BSTnode(data);
            return ptr;
        }
        if(root->data < data){
            root->right=insert_rec(root->right,data);
        }else{
            root->left=insert_rec(root->left,data);
        }
        return root;
    }

    public:
    void insert_rec(int data){
        this->root=insert_rec(this->root,data);
    }

    private:

    void inorder(BSTnode * root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);      
        }
    }

    public:
    void inorder(){
        inorder(root);
        cout<<endl;

    }

    private:

    void postorder(BSTnode * root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right); 
            cout<<root->data<<" ";     
        }
    }

    public:
    void postorder(){
        postorder(root);
        cout<<endl;
    }

    private:

    void preorder(BSTnode * root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);      
        }
    }

    public:
    void preorder(){
        preorder(root);
        cout<<endl;
    }

    

    void inorder_2(){
        stack <BSTnode*> stk;
        BSTnode* temp=root;
        while( temp!=NULL || !stk.empty()){
            while(temp!=NULL){
                stk.push(temp);
                temp=temp->left;   
            }
            temp=stk.top();
            cout<<temp->data<<" ";
            stk.pop();
            temp=temp->right;     
        }
        cout<<endl;
    }

    void preorder_2(){
        stack <BSTnode*> stk;
        BSTnode* temp=root;
        while(!stk.empty() || temp!=NULL){
            while(temp!=NULL){
                stk.push(temp);
                cout<<temp->data<<" ";
                temp=temp->left;   
            }
            temp=stk.top();
            stk.pop();
            temp=temp->right;              
        }
        cout<<endl;
    }

    void postorder_2(){
        stack <BSTnode*> stk;
        stack <int> values;
        BSTnode* temp=root;
        while(!stk.empty() || temp!=NULL){
            while(temp!=NULL){
                stk.push(temp);
                temp=temp->right;   
            }
            temp=stk.top();
            values.push(temp->data);
            stk.pop();
            temp=temp->left;              
        }
        while(!values.empty()){
            cout<<values.top()<<" ";
            values.pop();
        }
        cout<<endl;

    }

    private:
    int height(BSTnode * root){
        if(root==NULL){
            return 0;
        }

        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);

    }
    public:
    void height(){
        cout<<"Hieght of the tree is:- ";
        cout<<height(root)<<endl;
    }

    private:
    BSTnode * insert_bs(int data,BSTnode * root){
        if(root==NULL){
            BSTnode * ptr=new BSTnode(data);
            return ptr;
        }
        cout<<"You want to insert in the right or left of "<<root->data<<" :- "<<endl;
        char i;
        cout<<"l/r :- "<<endl;
        cin>>i;
        if(i=='l'){
            root->left=insert_bs(data,root->left);
        }else{
            root->right=insert_bs(data,root->right);
        }

        
        return root;

    }
    public:


    void insert_bs(int data){
        this->root=insert_bs(data,root);
    }

    private:
    BSTnode * mirror(BSTnode * root){
        if(root==NULL){
            return NULL;
        }
        BSTnode * copytree=new BSTnode(root->data);
        copytree->left=mirror(root->left);
        copytree->right=mirror(root->right);

        swap(copytree->left,copytree->right);

        return copytree;
    }

    public:
    void mirror(){
        BSTnode * cloneroot=mirror(root);
        cout<<"As we can observe that inorder traversal of mirror tree is mirror of the main tree."<<endl;
        cout<<"INORDER Traversal of Mirror tree:- "<<endl;
        inorder(cloneroot);
        cout<<endl;

        cout<<"INORDER Traversal of Main tree:- "<<endl;
        inorder(root);
        cout<<endl;

    }

    private:
    BSTnode * clone(BSTnode * root){
        if(root==NULL){
            return NULL;
        }
        BSTnode * copytree=new BSTnode(root->data);
        copytree->left=clone(root->left);
        copytree->right=clone(root->right);

        return copytree;
    }

    public:
    void clone(){
        BSTnode * cloneroot=clone(root);
        cout<<"Traversal of Cloned tree:- (1.Inorder 2.Postorder 3.Preorder)"<<endl;
        inorder(cloneroot);
        cout<<endl;
        postorder(cloneroot);
        cout<<endl;

        preorder(cloneroot);
        cout<<endl;

        cout<<"Traversal of Main tree:- (1.Inorder 2.Postorder 3.Preorder)"<<endl;
        inorder(root);
        cout<<endl;

        postorder(root);
        cout<<endl;

        preorder(root);
        cout<<endl;


    }

    bool checktrees(BSTnode *root1,BSTnode * root2){
        if(root1==NULL && root2==NULL){
            return 1;
        }

        if(root1!=NULL && root2!=NULL){
            bool a= (root1->data==root2->data);
            bool b=checktrees(root1->left,root2->left);
            bool c=checktrees(root1->right,root2->right);

            return (a && b && c);
        }


    return 0;

    }

    void checktrees(BST t1){
       bool eq= checktrees(root,t1.root);
       if(eq){
           cout<<"YES they are identical"<<endl;
       }else{
           cout<<"NO they are not identical"<<endl;
       }
    }

    private:
    BSTnode * search_bst(BSTnode * parent,int value){
        if(parent==NULL){
            return NULL;
        }
    
        if(parent->left==NULL && parent->right==NULL){
            return NULL;
        }

        if(parent->left!=NULL && parent->left->data==value){
            return parent;
        }
        if(parent->right!=NULL && parent->right->data==value){
            return parent;
        }
        if(parent->data > value){
           return search_bst(parent->left,value);
        }

        return search_bst(parent->right,value);
    }
    public:
    void search_bst(int value){
        if(root->data==value){
            cout<<"Value is present"<<endl;
            cout<<"Parent of key is:- "<<root->data<<endl;

            return;
        }
        BSTnode* chk=search_bst(root,value);
        if(chk==NULL){
            cout<<"Sorry the value is not present"<<endl;
        }else{
            cout<<"Value is present"<<endl;
            cout<<"Parent of key is:- "<<chk->data<<endl;
        }
    }


    void lever_order(){
        queue <BSTnode *> pendingNodes;
        pendingNodes.push(root);
        while (pendingNodes.size() != 0) {
		BSTnode* front = pendingNodes.front();
		pendingNodes.pop();
        cout<<front->data<<" ";
		 
		if (front->left !=NULL) {
			pendingNodes.push(front->left);
		}
		if (front->right !=NULL) {
			pendingNodes.push(front->right);
		}
        
	    }
    
	    return ;
    }
    private:
    BSTnode* helper_del(int key,BSTnode * root){
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return root;
        }
        BSTnode* parentptr=search_bst(root,key);
        BSTnode* keyptr=NULL;
        if(parentptr==NULL){
                if(root->data!=key){
                    cout<<"Element is not present in the BST"<<endl;
                    return root;
                }
                
                keyptr=root;
                if(root->left==NULL && root->right==NULL){
                    cout<<"Now the tree is empty"<<endl;
                    return NULL;
                }
                else if(root->left!=NULL && root->right==NULL){
                    return root->left;
                }
                else if(root->right!=NULL && root->left==NULL){
                    return root->right;
                }else{
                    goto last;
                }

        }

        if(parentptr->left!=NULL && parentptr->left->data==key){
            keyptr=parentptr->left;
        }else{
            keyptr=parentptr->right;
        }

        if(keyptr->left==NULL && keyptr->right==NULL){
            
            if(parentptr->left->data==key){
                parentptr->left=NULL;
            }
            else{
                parentptr->right=NULL;
            }
            free( keyptr);
        }
        else if(keyptr->left!=NULL && keyptr->right==NULL){
            
            if(parentptr->left->data==key){
                parentptr->left=keyptr->left;
            }
            else{
                parentptr->right=keyptr->left;
            }
            free( keyptr);
        }
        else if(keyptr->left==NULL && keyptr->right!=NULL){
            
            if(parentptr->left->data==key){
                parentptr->left=keyptr->right;
            }
            else{
                parentptr->right=keyptr->right;
            }
            free (keyptr);
        }
        else{
            last:

            BSTnode* temp=keyptr->right;
            if(temp->left==NULL){
                keyptr->data=temp->data;
                keyptr->right=temp->right;
                free(temp);
            }else{
                BSTnode* pt=temp;
                while(temp->left!=NULL){
                    pt=temp;
                    temp=temp->left;
                }
                pt->left=temp->right;
                keyptr->data=temp->data;
                free(temp);
            }
        }

        return root;
        
    }
    public:
    void delete_bst(int key){
        root=helper_del(key,root);
        cout<<"Inorder after deleting:-"<<endl;
        inorder(root);
        cout<<endl;
    }

    private:

    BSTnode * mininorder(BSTnode*root){

        BSTnode * rtr=root;

        while(rtr->left!=NULL){
            rtr=rtr->left;
        }

        return rtr;
    }
    BSTnode * delete_rec(int key,BSTnode * root){
        if(root==NULL){
            return root;
        }

        if(key< root->data){
            root->left=delete_rec(key,root->left);
        }
        else if(key> root->data){
            root->right=delete_rec(key,root->right);
        }
        else{

            if(root->left==NULL){
                BSTnode* newrt=root->right;
                free(root);
                return newrt;
            }
            else if(root->right==NULL){
                BSTnode* newrt=root->left;
                free(root);
                return newrt;
            }else{
                BSTnode * replc=mininorder(root->right);
                root->data=replc->data;
                root->right=delete_rec(replc->data,root->right);
            }

        }

        return root;
    }

    public:
    void delete_rec(int key){
        root=delete_rec(key,root);
        cout<<"Inorder after deleting:-"<<endl;
        inorder(root);
        cout<<endl;
    }

    int search(int arr[], int strt, int end, int value){  
        int i;  
        for (i = strt; i <= end; i++)  
        {  
            if (arr[i] == value)  
                return i;  
        }

        return -1;  
    }

 
    BSTnode* buildTree(int in[], int pre[], int inStrt, int inEnd)  
    {  
        static int preIndex = 0;  
    
        if (inStrt > inEnd)  
            return NULL;  
    
          
      	BSTnode *tNode = new BSTnode(pre[preIndex++]);
        if (inStrt == inEnd)  
            return tNode;  
    
        int inIndex = search(in, inStrt, inEnd, tNode->data);  
    
    
        tNode->left = buildTree(in, pre, inStrt, inIndex - 1);  
        tNode->right = buildTree(in, pre, inIndex + 1, inEnd);  
    
        return tNode;  
    }
     
    void tree_making(){
        int no;
        cout<<"Enter no of elements:-";
        cin>>no;
        cout<<"Enter inorder display:- "<<endl;
        int inord[no];
        for(int i=0;i<no;i++){
            cin>>inord[i];
        }

        cout<<"Enter preorder display:- "<<endl;
        int preord[no];
        for(int i=0;i<no;i++){
            cin>>preord[i];
        }

        BSTnode* newtree=buildTree(inord,preord,0,no-1);
        cout<<"Inorder of new tree made:-"<<endl;
        inorder(newtree);
        cout<<endl;


    }

    



};


int main(){

    BST tree;

   

    cout<<"-=-=-=-=-=- BST OPERATIONS -=-=-=-=-"<<endl;
    
            int len;
            cout<<"Enter no of values you want to insert:- ";
            cin>>len;
            while(len--){
            int x;
            cout<<"Enter value you want to insert:- ";
            cin>>x;
            tree.insert(x);

            }
            cout<<"1.INORDER display"<<endl;
            cout<<"2.POSTORDER dsiplay"<<endl;
            cout<<"3.PREORDER dsiplay"<<endl;
            cout<<"4.Display hieght of tree"<<endl;
            cout<<"5.Delete a node in tree"<<endl;
            cout<<"6.Mirror a tree"<<endl;
            cout<<"7.Create a clone of tree"<<endl;
            cout<<"8.Search a value in tree"<<endl;
            cout<<"9.Level order traversal"<<endl;
            cout<<"10.Delete recursive"<<endl;
            cout<<"11.Check if trees are equal"<<endl;
            cout<<"12.Make BST from inorder and preorder display"<<endl;
            cout<<"13.EXIT"<<endl;

            
            while(1){
                int choose;
                cout<<"Enter your choice:- "<<endl;
                cin>>choose;
                if(choose==1){
                    cout<<"Recursive:- "<<endl;
                    tree.inorder();
                    cout<<endl;
                    cout<<"Iterative:- "<<endl;
                    tree.inorder_2();
                }
                else if(choose==2){
                    cout<<"Recursive:- "<<endl;
                    tree.postorder();
                    cout<<endl;
                    cout<<"Iterative:- "<<endl;
                    tree.postorder_2();
                }
                else if(choose==3){
                    cout<<"Recursive:- "<<endl;
                    tree.preorder();
                    cout<<endl;
                    cout<<"Iterative:- "<<endl;
                    tree.preorder_2(); 
                }
                else if(choose==4){
                    tree.height();
                }
                else if(choose==5){
                    int key;
                    cout<<"Enter the key you want to delete:-"<<endl;
                    cin>>key;
                    tree.delete_bst(key);
                }
                else if(choose==6){
                    tree.mirror();
                }
                else if(choose==7){
                    tree.clone();
                }
                else if(choose==8){
                    cout<<"Enter value you want to search:- "<<endl;
                    int sr;
                    cin>>sr;
                    tree.search_bst(sr);
                }
                else if(choose==9){
                    cout<<"Level order is:- "<<endl;
                    tree.lever_order();
                    cout<<endl;
                }
                 else if(choose==10){
                    int key;
                    cout<<"Enter the key you want to delete:-"<<endl;
                    cin>>key;
                    tree.delete_rec(key);
                }
                else if(choose==11){
                    BST chkeq;
                    int len;
                    cout<<"Enter no of values you want to insert:- ";
                    cin>>len;
                    while(len--){
                    int x;
                    cout<<"Enter value you want to insert:- ";
                    cin>>x;
                    chkeq.insert(x);

                    }
                    tree.checktrees(chkeq);
                }
                else if(choose==12){
                    
                    tree.tree_making();

                }
                else{
                    break;
                }

            }


  
    
    return 0;
}