#include<iostream>
#define TRUE 1;
#define FALSE 0;
struct btree{
    struct btree *left;
    int data;
    struct btree *right;

};
void insert_bst(struct btree **root, int num){
    if(*root==NULL){
        *root=new btree;
        (*root)->left=NULL;
        (*root)->data=num;
        (*root)->left=NULL;
    }else{
        if(num<(*root)->data){
            insert_bst(&(*root)->left,num);
        }else{
            insert_bst(&(*root)->right,num);
        }
    }
}
//int *f has been used in case we don't find the number in the btree at all
//if parent is null then xaddr is that of root node
void search_bst(struct btree **root, struct btree **parent, int num, struct btree **xaddr, int *f){
    struct btree *temp = *root;
    *f = false;
    *parent = NULL;
    while(temp!=NULL){
        if(temp->data==num){
            *f=true;
            *xaddr=temp;
            return;
        }
        *parent=temp;
        if (num<temp->data)
        {
            temp=temp->left;
        }else{
            temp=temp->right;
        }
        
    }
}