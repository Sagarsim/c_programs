#include<stdio.h>
#include<stdlib.h>
//#include<queue> for levelorder
struct node{
int data;
struct node* left;
struct node* right;

}*tree;

struct node *getnewnode(int val){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}

void add(struct node **tr,int val){
struct node* new1=(struct node*)malloc(sizeof(struct node));
new1=*tr;
if(new1==NULL){
    *tr=getnewnode(val);
    return;
}
if(val <= new1->data){
    add(&(new1->left),val);
}
else{
    add(&(new1->right),val);
}
}

int search(struct node *tr2,int val){

if(tr2 == NULL){
    return 0;
}
else if(tr2->data == val){
    return 1;
}
else if(val<=tr2->data){
    return search(tr2->left,val);
}
else{
    return search(tr2->right,val);
}
}

int find_min(struct node *tr3){
if(tr3 == NULL){
    printf("Error! Tree is empty...");
    return -1;
}
else if(tr3->left == NULL){
    return tr3->data;
}
else {
    return find_min(tr3->left);
}
}


int find_max(struct node *tr4){
if(tr4 == NULL){
    printf("Error! Tree is empty...");
    return -1;
}
else if(tr4->right == NULL){
    return tr4->data;
}
else {
    return find_max(tr4->right);
}
}






/*void levelorder(node *root){
if(root==NULL)return;
queue<node*> Q;
Q.push(root);
while(!Q.empty()){
    node* current = Q.front();
    printf("%d ",current->data);
    if(current->left!=NULL) Q.push(current->left);
    if(current-!=NULL) Q.push(current->right);
    Q.pop();
}
}*/
void preorder(struct node *tr5){
if(tr5==NULL) {return;}
printf("%d ",tr5->data);
preorder(tr5->left);
preorder(tr5->right);
}

void inorder(struct node *tr6){
if(tr6==NULL) {return;}
inorder(tr6->left);
printf("%d ",tr6->data);
inorder(tr6->right);
}


void postorder(struct node *tr7){
if(tr7==NULL) {return;}
postorder(tr7->left);
postorder(tr7->right);
printf("%d ",tr7->data);
}



int main()
{
    tree=NULL;
    add(&tree,48);
    add(&tree,58);
    add(&tree,23);
    add(&tree,38);
    add(&tree,28);
    add(&tree,68);
    add(&tree,33);
    add(&tree,8);
    add(&tree,53);
    add(&tree,63);
    add(&tree,5);

    if(search(tree,5)==1)
    {
        printf("Element found\n\n");
    }
    else{
        printf("Element not found\n\n");
    }

printf("Inorder-> ");
inorder(tree);
printf("\n\nPreorder-> ");
preorder(tree);
printf("\n\nPostorder-> ");
postorder(tree);
printf("\nMax:-%d ",find_max(tree));
printf("\nMin:-%d ",find_min(tree));

}
