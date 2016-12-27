/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/
#include"../include/sort.h"
void quick_sort::sort(int*A,int length){

	q_sort(A,0,length-1);

}	

void quick_sort::q_sort(int* A,int p ,int r){
		
		if (p<r){
			int q = partition(A, p, r);
			q_sort(A , p , q -1);
			q_sort(A , q + 1, r);
			
		}
				
	}

int quick_sort::partition(int* A,int p,int r){
		
		int x = A[r];
		int i = p-1;
		for (int j = p;j<r;j++){
			
			if(A[j] < x){
				
				i++;
				swap(A,i,j);
				
			}
			
		}
		
		swap(A,i+1,r);
		return i + 1;
	}
