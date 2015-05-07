#ifndef C_SORTINGTREE_H_INCLUDED
#define C_SORTINGTREE_H_INCLUDED

#define ASSERT_MODE

#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif




typedef struct BiTreeNode{
    int value;
    struct BiTreeNode*left;
    struct BiTreeNode*right;
}BiTreeNode;


BiTreeNode*create_sortingtree();
void destroy_sortingtree(BiTreeNode**);
void remove_sortingtree(BiTreeNode**);
void insert_sortingtree(BiTreeNode**,int);
void _insert_sortingtree(BiTreeNode**,BiTreeNode*,int);
void search_sortingtree(BiTreeNode**,int(*predict)(int),BiTreeNode**);
void asc_scan_sortingtree(BiTreeNode**,void(*op)(int));
void desc_scan_sortingtree(BiTreeNode**,void(*op)(int));

BiTreeNode*create_sortingtree(){
    BiTreeNode*root=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    root->value=0;
    root->left=NULL;
    root->right=NULL;
    return root;
}


void remove_sortingtree(BiTreeNode**node){
    if((*node)->left!=NULL)remove_sortingtree(&((*node)->left));
    if((*node)->right!=NULL)remove_sortingtree(&((*node)->right));
    free(*node);
    *node=NULL;
}


/*void destroy_sortingtree(BiTreeNode**root){
    remove_sortingtree(root);
    free(*root);
    *root=NULL;
}*/


void asc_scan_sortingtree(BiTreeNode**node,void(*op)(int)){
    if((*node)->left!=NULL)asc_scan_sortingtree(&((*node)->left),op);
    op((*node)->value);
    if((*node)->right!=NULL)asc_scan_sortingtree(&((*node)->right),op);
}

void desc_scan_sortingtree(BiTreeNode**node,void(*op)(int)){
    if((*node)->right!=NULL)desc_scan_sortingtree(&((*node)->right),op);
    op((*node)->value);
    if((*node)->left!=NULL)desc_scan_sortingtree(&((*node)->left),op);
}


void search_sortingtree(BiTreeNode**node,int(*predict)(int),BiTreeNode**ret){
    if((*node)->left!=NULL)search_sortingtree(&((*node)->left),predict,ret);
    if(predict((*node)->value)!=0)*ret=*node;
    if((*node)->right!=NULL)search_sortingtree(&((*node)->right),predict,ret);
}


void insert_sortingtree(BiTreeNode**root,int v){
    BiTreeNode*newNode=(BiTreeNode*)malloc(sizeof(BiTreeNode));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->value=v;
    _insert_sortingtree(root,newNode,v);
}


void _insert_sortingtree(BiTreeNode**node,BiTreeNode*n,int v){
    if((*node)==NULL)(*node)=n;
    else{
        if(v<(*node)->value)_insert_sortingtree(&((*node)->left),n,v);
        if(v>(*node)->value)_insert_sortingtree(&((*node)->right),n,v);
    }
}

#endif // C_SORTINGTREE_H_INCLUDED
