#include<bits/stdc++.h>
using namespace std;

void heapify(int *a,int n,int i)
{
	//Initialize the current root as largest.
	int largest=i;  
	//Index of left child.
	int l=2*i+1;
	//Index of right child.
	int r=2*i+2;
	
	if(l<n && a[l]>a[largest])
		largest=l;
	
	if(r<n && a[r]>a[largest])
		largest=r;
		
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
}

int main()
{
	int arr[]={12,11,13,5,6,7};
	int n=6;
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
