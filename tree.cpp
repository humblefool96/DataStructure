//Basic operation on BST

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

// A utility function to create a new BST node 
struct node *newNode(int data) { 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

//recursive inorder traversal
void inOrder(struct node* root){
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

//recursive preorder traverssa
void preOrder(struct node* root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

//recursive postorder traversal
void postOrder(struct node* root){
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

//level order traversal or bredth first search(iterative way)
void levelOrder(struct node* root){
	if(root == NULL)
		return;
	queue<struct node*> q;
	q.push(root);
	while(!q.empty()){
		struct node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}

//insert operation
struct node* insert(struct node* root, int data){
	if(root == NULL){
		root = newNode(data);
	}else if(data <= root->data){
		root->left = insert(root->left, data);
	}else{
		root->right = insert(root->right, data);
	}
	return root;
}

//finding min data node in a bst
struct node* findMin(struct node* root){
	while(root->left != NULL)
		root = root->left;
	return root;
}

//delte a node in bst
void deleteNode(struct node* root, int key){
	if(root == NULL)
		return;
	if(key > root->data)
		deleteNode(root->right, key);
	else if(key < root->data)
		deleteNode(root->left, key);
	else{   //found the node to be deleted
		//case 1: no child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root == NULL;
		}
		//case 2 : one child
		else if(root->left == NULL){
			struct node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			struct node* temp = root;
			root = root->right;
			delete temp;
		}
		//case 3 : two child
		else{
			struct node* temp = findMin(root->right);
			root->data = temp->data;
			deleteNode(root->right, temp->data); 
		}
	}
}

//height of a tree
int height(struct node* root){
	if(root == NULL)
		return -1;
	int lHeight = height(root->left);
	int rHeight = height(root->right);
	return max(lHeight, rHeight)+1;
}

//serach a key in tree
int search(struct node* root, int key){
	if(root == NULL)
		return -1;
	if(root->data == key)
		return root->data;
	else if(key > root->data)
		search(root->right, key);
	else
		search(root->left, key);
}

//driver function
int main(){
	struct node* root = NULL;
	root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80);
	//inOrder(root);
	//preOrder(root);
	//postOrder(root);
	int h = height(root);
	cout<<"height of bst is: "<<h<<"\n";
	int key = search(root, 110);
	cout<<key<<"\n";
	levelOrder(root);
	deleteNode(root, 70);
	levelOrder(root);
	return 0;
}
