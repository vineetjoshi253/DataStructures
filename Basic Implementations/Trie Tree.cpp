#include<bits/stdc++.h>
using namespace std;

//Trie Tree Node
struct node
{
	struct node* children[26];
	bool isEndofWord; 
};

//Utility function to create new Trie Node
struct node* getNode()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->isEndofWord=false;
	
	for(int i=0;i<26;i++)
	{
		temp->children[i]=NULL;
	}
	
	return temp;
}

//Function to insert node in Trie Tree.
void insert(struct node* root,string key)
{
	struct node*crawler=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!crawler->children[index])
			crawler->children[index]=getNode();
			
		crawler=crawler->children[index];
	}
	
	crawler->isEndofWord=true;
}

//Function to search for a word in Trie Tree.
bool search(struct node *root,string key)
{
	struct node *crawler=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!crawler->children[index])
			return false;
		
		crawler=crawler->children[index];
	}
	
	if(crawler->isEndofWord)
		return true;
	else 
		return false;
		
}


int main()
{
	string keys[]={"the", "a", "there", "answer", "any", "by", "bye", "their", "hello" };
	int n=9;
	
	struct node*root=getNode();
	for(int i=0;i<n;i++)
	{
		insert(root,keys[i]);
	}
	
	// Search for different keys 
    search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : cout << "No\n";
	
}
