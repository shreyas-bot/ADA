#include<iostream>
#include<time.h>
using namespace std;

void sel_sort(int *,int);
void desc_sel_sort(int *,int,int);

int main()
{
	int l,ch,k;
	clock_t start,end,start2,end2; 
	cout<<"\n Enter the length :";
	cin>>l;
	int a[l];
	cout<<"\n Enter the array : ";
	for(int i=0; i<l; i++)
		cin>>a[i];
	while(ch!=3)
	{
			cout<<"\n 1.Selection sort 	2.k largest element 3. Quit";
			cin>>ch;
			switch(ch)
			{
				case 1:	
				{
						start = clock(); 
						sel_sort(&a[0],l);
						end = clock();
						cout<<"\n The sorted array is:";
						for(int i=0; i<l; i++)
							cout<<a[i]<<"\t";
						double time_taken = ((double)(end - start))/CLOCKS_PER_SEC; 
    					printf("selectionsort() took %f seconds to execute \n", time_taken); 
						break;
				}
						
				case 2:
				{
						cout<<"\n Enter k :";
						cin>>k;
						start2 = clock(); 
						desc_sel_sort(&a[0],l,k);
						end2 = clock();
						cout<<"\n k largest elements are:";
						for(int i=0; i<k; i++)
							cout<<a[i]<<"\t";	
						double time_taken2 = ((double)(end2 - start2))/CLOCKS_PER_SEC; 
    					printf("selectionsort() took %f seconds to execute \n", time_taken2); 
						break;
				}						
			}
	}
	return 0;
}

void sel_sort(int *a,int l)
{
	int temp,min;
	for(int i=0; i<l-1 ; i++)
	{	
		//min = i;
		for(int j=i+1; j<l; j++)
		{
			if(a[j]<a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}			
}

void desc_sel_sort(int *a,int l,int k)
{
	int temp;
	for(int i=0; i<k ; i++)
	{	
		for(int j=i+1; j<l; j++)
		{
			if(a[j]>a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}			
}

