/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#include "../include/sort.h"

inline int selection_sort::find_min(int* A,int i,int length){

	int min_index = i;
	for (int j = i ;j<length;j++)if(A[min_index]>A[j])min_index=j;
	
return min_index;
}

void selection_sort::sort(int *A,int length){
		
	int min_index;
	
	for (int i = 0;i<length;i++){
	
		min_index = i;
		for (int j = i ;j<length;j++)if(A[min_index]>A[j])min_index=j;
		selection_sort::swap(A,min_index,i); 	
	}
}

