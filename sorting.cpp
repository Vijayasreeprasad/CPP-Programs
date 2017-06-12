#include<iostream>
using namespace std;

//Bubble Sort
void bubblesort(int a[],int n) 
{
	bool swap;
	do
	{
		swap=false;
		for(int i=0; i<n-1; i++)
		{
			if(a[i]>a[i+1])
			{
			int temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
			swap=true;
			}
		}
	}
	while(swap);
}

void selectionsort(int a[],int n)
{
	int imin;
	for(int i=0;i<n-1;i++)
	{
		imin=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[imin])
			{
			imin=j;	
			}
		}
		int temp=a[i];
		a[i]=a[imin];
		a[imin]=temp;
	}
}


void insertionsort(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		int index=a[i];
		int j=i;
		while(j>0 && index<a[j-1])
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=index;
	}
}



int partition(int a[],int start,int end)
{
	int pindex=start;
	int pivot=a[end];
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			int temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	int temp2=a[pindex];
	a[pindex]=a[end];
	a[end]=temp2;
	return pindex;
}



void quicksort(int a[],int start, int end)
{
	if(start<end)
	{
		int pindex=partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}





void merge(int a[],int l,int m, int r)
{
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	
	for(int i=0;i<n1;i++)
	L[i]=a[l+i];
	for(int j=0;j<n2;j++)
	R[j]=a[m+1+j];
	
	int i=0,j=0,k=l;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
			
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}


void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}


void maxheapify(int a[],int i,int n)
{
	
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[largest])
	largest=l;
	
	if(r<n && a[r]>a[largest])
	largest=r;
	
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,largest,n);
	}
}



void heapsort(int a[],int n)
{
	//buildheap(a,n);
	for(int i= n/2 - 1; i>=0; i--)
	{
		maxheapify(a,i,n);
	}
	
	for(int i=n-1;i>=0;i--)
	{
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		maxheapify(a,0,i);
	}
}


void print(int a[],int n)
{
	for(int i=0;i<n;++i)
	cout<<a[i]<<" ";
}

int main()
{
	int n,sort;
	int a[50];
	cout<<"enter the length of the array"<<endl;
	cin>>n;
	cout<<endl;
	cout<<"enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
		
	do{
		cout<< endl;
		cout<< "Please enter the type of Sort "<<endl;
		cout<<"1.Bubble Sort"<<endl<<"2.Selection Sort"<<endl<<"3.Insertion Sort"<<endl<<"4.Quick Sort"<<endl<<"5.Merge Sort"<<endl<<"6.Heap Sort"<<endl<<"7.Exit"<<endl;
	   	cin>>sort;

//bool swap=false;
    switch(sort)
	{
		case 1:
		cout<<"Using Bubble Sort:"<<endl;
		bubblesort(a,n);
		print(a,n);
	//	swap=true;
		break;
		case 2:
		cout<<"Using Selection Sort:"<<endl;
		selectionsort(a,n);
		print(a,n);
		break;
		case 3: 
		cout<<"Using Insertion Sort:"<<endl;
		insertionsort(a,n);
		print(a,n);
		break;
		case 4:
		cout<<"Using Quick Sort:"<<endl;
		quicksort(a,0,n-1);
		print(a,n);
		break;
		case 5:
		cout<<"Using Merge Sort:"<<endl;
		mergesort(a,0,n-1);
		print(a,n);
		break;
		case 6:
		cout<<"Using Heap Sort:"<<endl;
		heapsort(a,n);
		print(a,n);
		break;
		case 7:
		cout<<"Exit:"<<endl;	
		exit(0);	
		break;
		default:
		cout<<"Enter the type of sort"<<endl;
	}
	
}while(1);
return 0;
}










