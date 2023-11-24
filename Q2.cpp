//Given a BST and two keys in it. Find the distance between two nodes with given two keys. It may
//be assumed that both keys exist in BST.
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
int rootToNode(Node*root,int k) {
    if(!root) return 0;
    if(root->val==k) return 0;
    if(root->val>k) return 1+rootToNode(root->left,k);
    return 1+rootToNode(root->right,k);
}
int distance(Node*root,int k1,int k2) {
    if(!root) return 0;
    if(root->val > k1 and root->val >k2 ) return distance(root->left,k1,k2);
    if(root->val < k1 and root->val <k2 ) return distance(root->right,k1,k2);
    if(root->val >=k1 and root->val <=k2) return rootToNode(root,k1) + rootToNode(root,k2);
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

int k1=25,k2=60;
if(k1>k2) swap(k1,k2);
cout<<distance(a,k1,k2);
return 0;
}