//Given a BST, count subtrees in it whose nodes lie within a given range.
#include<iostream>
#include<stdbool.h>
using namespace std;


struct Node{
    int val;
    Node*left;
    Node* right;
    Node(int key){
        val=key;
        left=right=NULL;

    }
};
bool countsubtrees(Node *root,int low,int high,int &count){
    if(!root) return true;
    bool leftcall=countsubtrees(root->left,low,high,count);
   bool rightcall=countsubtrees(root->right,low,high,count);
if(leftcall and rightcall and (root->val>=low and root->val<=high)){
    count++;
    return true;
}
return false;
 }

int main(){
    Node*a=new Node(40);
    Node*b=new Node(25);
    Node*c=new Node(50);
    Node*d=new Node(20);
    Node*e=new Node(30);
    Node*f=new Node(45);
    Node*g=new Node(60);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    int count = 0;
 countsubtrees(a,25,35,count);
 cout<<count<<endl;

 return 0;

}
