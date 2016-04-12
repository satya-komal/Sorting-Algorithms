#include <iostream>
using namespace std;
#include<cmath>
#include<string>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include "time.h"

void Insertion_Sort(int*& arr,int size);
void Counting_Sort(int *&arr,int size);
void Merge_Sort(int*& arr,int start,int size,int n);
void merge(int*& Arr, int startIndex, int end,int n);
void RandomizedQuick_Sort(int *&arr,int p,int r,int n);
int PARTITION(int *&a,int p,int r,int n);
int R_PARTITION(int *&input,int p,int r,int n);

void isort(int a);
void csort(int a);
void msort(int a);
void rsort(int a);

void rand_gen(int*&arr,int a);
void rand_gen_15(int*&arr,int b);
void print(int *&Arr,int n);

int main(){
	srand(time(NULL));
	cout<<"Choose one of the following algorithm names followed by the Input size"<<endl;
	cout<< "1.Type i for Insertion Sort"<<endl;
	cout<< "2.Type c for Counting Sort"<<endl;
	cout<< "3.Type m for Merge Sort"<<endl;
	cout<< "4.Type r for RandomizedQuick Sort" <<endl;
	cout<< "5.Type q to quit" <<endl;

	string name;
	cin>> name;
	int n;


	if (name=="i") {
		cout<<"Type the size of the input size"<<endl;
		cout<<"NOTE: Input size has to be >=1 and <=1000"<<endl;
		cin>>n;
		isort(n);
	}

	else if (name=="c"){
		cout<<"Type the size of the input size"<<endl;
		cout<<"NOTE: Input size has to be >=1 and <=1000"<<endl;
		cin>>n;
		csort(n);
        }
	else if (name=="m"){
		cout<<"Type the size of the input size"<<endl;
		cout<<"NOTE: Input size has to be >=1 and <=1000"<<endl;
		cin>>n;
		msort(n);
	}
	else if (name=="r"){
		cout<<"Type the size of the input size"<<endl;
		cout<<"NOTE: Input size has to be >=1 and <=1000"<<endl;
		cin>>n;
		rsort(n);
	}
	else if (name == "q"){
	exit(0);
	}
	
	else {
		cout<<"Enter the correct Algorithm name, input size as specified"<<endl;
		main();
	}
	return 0;
}

void Insertion_Sort(int*& arr,int size){
	
	if (size<=20) {
	//Prints the no of stars equal to the random no if input size <=20
	print(arr,size);
	}
	cout<<endl;
	int i, j, tmp;
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
		if(size<=20){
		print(arr,size);       //Prints the sorted no's after swapping 
		cout<<endl;
		}
		
	}
	cout<<"The sorted no's are"<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<",";     // Prints the sorted no's after implementing insertion sort
	}
	cout<<endl;
	cout<<endl;
	main();
}

void Counting_Sort(int *&arr,int size){
    //Prints the no of stars equal to the random no if input size <=20
    if(size<=20){
    print(arr,size);
    }
    cout<<endl;
      int max= arr[0];
 for (int i=0;i<size;i++)
    {
      if ( arr[i]>max) max=arr[i];
    }
int *CountArr = new int[max+1];
      for (int i=0;i<max+1;i++)
    {
      CountArr[i]=0;
    }

    for (int i=0;i<size;i++)
    {
        CountArr[arr[i]]++;
    }

    int outputindex=0;
    for (int j=0;j<max+1;j++)
    {
        while (CountArr[j]--)
            arr[outputindex++] = j;
            if(size<=20){
            print(arr,size);    //Prints the no's after each iteration
            cout<<endl;
            }
            
    }
    cout<<"The sorted no's are"<<endl;
    for(int i=0;i<size;i++){
    cout<<arr[i]<<",";        // prints the no's after the counting sort is implemented
    }
    cout<<endl;
    cout<<endl;
	    main();
}

void Merge_Sort(int*& arr,int start,int size,int n){

int midIndex;

//Check for base case
if (start < size)
{
//First, divide in half
midIndex = floor((start + size)/2);

//First recursive call 
Merge_Sort(arr, start, midIndex,n);

//Second recursive call 
Merge_Sort(arr, midIndex+1, size,n);

//The merge function
merge(arr, start, size,n);

}

}
void merge(int*& input, int p, int r,int n)
{
 
int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;

    // Temp array
    int temp[r-p+1];

    // Merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= r )
        if ( input[i2] < input[i3] )
            temp[i1++] = input[i2++];
        else
            temp[i1++] = input[i3++];

    // Merge the remaining elements in left array
    while ( i2 <= mid )
        temp[i1++] = input[i2++];

    // Merge the remaining elements in right array
    while ( i3 <= r )
        temp[i1++] = input[i3++];

    // Move from temp array to master array
    for ( int i = p; i <= r; i++ ){
        input[i] = temp[i-p]; 
         if(n<=20){
         print(input,n);
	 cout<<endl;
	 }
    	} 
}

void RandomizedQuick_Sort(int *&arr,int p,int r,int n)
    {
        int q;
        if(p<r)
        {
         q=R_PARTITION(arr,p,r,n);
         RandomizedQuick_Sort(arr,p,q-1,n);
         RandomizedQuick_Sort(arr,q+1,r,n);
        }
    }

 int R_PARTITION(int *&input,int p,int r,int n)
 {
        int i=p+rand()%(r-p+1);
        int temp;
        temp=input[r];
        input[r]=input[i];
        input[i]=temp;
        return PARTITION(input,p,r,n);
  }

 int PARTITION(int *&a,int p,int r,int n)
 {
        int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j]<=x)
            {

                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;
        if(n<=20){
        print(a,n);    //prints the no's after each iteration.
        cout<<endl;
        //cout<<r+1;
        }
        return i+1;
  }
void isort(int a){
	if(a>=1 && a<=1000){
	    if(a<=20){
		int*array =new int[a];
		rand_gen_15 (array,a);    //generates no's less than 20
		Insertion_Sort(array,a );
		}
	   else if(a>20){
	   int*array =new int[a];
		rand_gen (array,a);       // //generates no's less than 100
		Insertion_Sort(array,a );
	   }
	}
	else {
		cout<<"You entered wrong input size"<<endl;
		cout<<"Enter again"<<endl;
		cin>> a;
		isort(a);
	}
}

void msort(int a){
	if(a>=1 && a<=1000){
	   if(a<=20){
		int*array =new int[a];
		rand_gen_15 (array,a);
		cout<<endl;
		print(array,a);
		int b=a;
		Merge_Sort(array,0,a-1,b );
		cout<<"The sorted no's are"<<endl;
		for(int i=0;i<a;i++){
		cout<<array[i]<<",";
		}
		cout<<endl;
		cout<<endl;
		main();
		}
	  else {
		int*array =new int[a];
		rand_gen (array,a);
		cout<<endl;
		Merge_Sort(array,0,a-1,a);
		cout<<"The sorted no's are"<<endl;
                for(int i=0;i<a;i++){
		cout<<array[i]<<",";
		}
		cout<<endl;
		cout<<endl;
		main();
		}		
			}
	else {
		cout<<"You entered wrong input size"<<endl;
		cout<<"Enter again"<<endl;
		cin>> a;
		msort(a);
	}
}
void csort(int a){
	if(a>=1 && a<=1000){
	 if(a<=20){
		int*array =new int[a];
		rand_gen_15 (array,a);
		Counting_Sort(array,a );
		}
	 else if (a>20){
	        int*array =new int[a];
		rand_gen (array,a);
		Counting_Sort(array,a );
	 }
	}
	else {
		cout<<"You entered wrong input size"<<endl;
		cout<<"Enter again"<<endl;
		cin>> a;
		csort(a);
	}
}
void rsort(int a){
	if(a>=1 && a<=1000){
	       if(a<=20){
		int*array =new int[a];
		rand_gen_15 (array,a);
		cout<<endl;
		print(array,a);
		cout<<endl;
		RandomizedQuick_Sort(array,0,a-1,a );
		cout<<"The sorted no's are"<<endl;
		for(int i=0;i<a;i++){
		cout<<array[i]<<",";
		}
		cout<<endl;
		cout<<endl;
		main();
		}
		else {
		int*array =new int[a];
		rand_gen (array,a);
		cout<<endl;
		RandomizedQuick_Sort(array,0,a-1,a );
		cout<<"The sorted no's are"<<endl;
		for(int i=0;i<a;i++){
		cout<<array[i]<<",";
		}
		cout<<endl;
		cout<<endl;
		main();
		}
	}
	else {
		cout<<"You entered wrong input size"<<endl;
		cout<<"Enter again"<<endl;
		cin>> a;
		rsort(a);
	}
}

//generates random no's less than 100
void rand_gen(int*&arr,int b){
	cout<<"The random no's generated are"<<endl;
	for(int i=0;i<b;i++){
		arr[i]  =rand()%100;
		cout<<arr[i]<<",";
	}
	cout<<endl;
}

//generates random no's less than 16
void rand_gen_15(int*&arr,int b){
	cout<<"The random no's generated are"<<endl;
	for(int i=0;i<b;i++){
		arr[i]  =rand()%16;
		cout<<arr[i]<<",";
	}
	cout<<endl;
}

//prints the '*'s equal to the no 
void print(int *&Arr,int n){
       
       for(int i=0;i<n;i++){
		 for(int j=0;j<Arr[i];j++){
		 cout<<"*";
		 }
	 cout<<endl;
	}
}









