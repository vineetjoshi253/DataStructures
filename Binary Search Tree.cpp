#include<bits/stdc++.h>
using namespace std;


//Node of a BST.
struct node{
  int key;
  struct node *left,*right;
};

//Utility function to create a node.
struct node* newNode(int key)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	
	//		KEY <------temp
	//	   -   -
	//	  -     -
	//	NULL    NULL
		
	temp->key=key;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

//Utility function to find inorder successor.
struct node* minValue(struct node*root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

//Function to insert a new node.
struct node* insert(struct node* root,int key)
{
	if(root==NULL)	return newNode(key);
	
	else if(key<root->key)
		root->left=insert(root->left,key);
	
	else if(key>root->key)
		root->right=insert(root->right,key);
	
	return root;
}

//Function to print inorder traversal of the tree.
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);	
	}	
}

//Function to print preorder traversal of the tree.
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);	
	}	
}

//Function to print postorder traversal of the tree.
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		preorder(root->right);
		cout<<root->key<<" ";
	}	
}



//Function to search a key.
struct node* search(struct node*root,int temp)
{
	if(root==NULL ||root->key==temp)	return root;
	
	else if(temp<root->key)	
		return search(root->left,temp);
	else 
		return search(root->right,temp);
}


//Function to delete a key.
struct node* deleteNode(struct node* root,int temp)
{
	if(root==NULL)	return root;
	
	else if(temp<root->key)
		root->left=deleteNode(root->left,temp);
	else if(temp>root->key)
		root->right=deleteNode(root->right,temp);
	
	//If the key to be deleted is present in the current node.	
	else
	{
		//CASE 1: If node to be removed has zero or one child.
		if(root->left==NULL)
		{
			struct node*temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node*temp=root->left;
			free(root);
			return temp;
		}
		//CASE 2: If node to be removed has two children. 
		//In this case, replace the node with it's inorder successor (smallest in the right subtree) and delete the successor.
		else
		{
			struct node*temp=minValue(root->right);
			root->key=temp->key;
			root->right=deleteNode(root->right,temp->key);	
		}
	}
	return root;
}


int main()
{
    struct node *root=NULL;
    
	//			 50
    //		   -    -
	//		  -		 -
	//		30		 70
	//     -  -     -  -
	//    -    -   -    -
	//   20    40 60    80  
					
	int nodes[]={50,30,20,40,70,60,80};
	for(int i=0;i<7;i++)
	{
		root = insert(root, nodes[i]);		
	}	
	
	//Print the Inorder traversal of the tree.---------->
	
	//inorder(root);
	
	//Search for a key in the tree.---------->
	
	/*
	struct node *temp=search(root,100);
	if(temp==NULL)
		cout<<"Key not found";
	else 
		cout<<temp->key<<" is present in the tree."; 	
	*/
	
	//Delete a key from the tree.---------->
	
	/*
	inorder(root);
	root=deleteNode(root,20);
	cout<<endl;
	inorder(root);
	root=deleteNode(root,30);
	cout<<endl;
	inorder(root);
	root=deleteNode(root,80);
	cout<<endl;
	inorder(root);
	*/
}
