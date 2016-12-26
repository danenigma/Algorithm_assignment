#include "../include/sort.h"

inline int selection_sort::find_min(int* A,int i,int length){

	int min_index = i;
	for (int j = i ;j<length;j++)if(A[min_index]>A[j])min_index=j;
	
return min_index;
}

void selection_sort::sort(int *A,int length){

	for (int i = 0;i<length;i++)selection_sort::swap(A,selection_sort::find_min(A,i,length),i); 	
	
}

