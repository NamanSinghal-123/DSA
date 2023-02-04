#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    
};
struct node *newnode(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node*Insert(struct node* temp,int key){
    if(temp==NULL){
        return newnode(key);
    }
    if(key<temp->data){
        temp->left=Insert(temp->left,key);
    }
    else{
        temp->right=Insert(temp->right,key);
    }
    return temp;
}
 
void Inorder_traversal(struct node*temp){
    if(temp!=NULL){
        Inorder_traversal(temp->left);
        cout<<temp->data<<" ";
        Inorder_traversal(temp->right);
    }
}
int min(struct node *temp){
    if(temp->left!=NULL){
        return min(temp->left);
    }
    return temp->data;
}

int max(struct node *temp){
    if(temp->right!=NULL){
        return max(temp->right);
    }
    return temp->data;
}
int successor(struct node*temp){
    if(temp->right!=NULL){
        return min(temp->right);
    }
    
}
int search(struct node*root,int key){
    if(root=NULL){
        return 0;
    }
    if(root->data==key ){
        return 1;
    }
    
    if(key<root->data){
        search(root->left,key);
    }
     if(key>root->data){
        search(root->right,key);
    }
    
}
int main(){
    struct node *root=NULL;
    int val,n;
    cout<<"Enter the size of tree:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter value:"<<endl;
        cin>>val;
        root=Insert(root,val);
    }
    // cout<<"The Tree's Inorder Traversal is:"<<endl;
    // Inorder_traversal(root);

    // int value;
    // cout<<"Enter the value you want to search:"<<endl;
    // cin>>value;
    // int m=search(root,value);
    // if(m==0){
    //     cout<<" n Found";
    // }
    // else{
    //     cout<<" Found";
    // }

    //MIN
    // cout<<"The minimum element is:"<<min(root)<<endl;

    //MAX
    // cout<<"The maximum element is:"<<max(root)<<endl;
  
}