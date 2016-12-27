/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#include "../include/generate_array.h"
#include "../include/sort.h"
#include <random>
/*GENERATE RANDOM ARRAY AND SORT IT ACCORDING TO THE PRESORTEDNESS PARAMETER*/

int* generate_array(int size,float presortedness){

	int * A ;
	A = malloc (sizeof(int) * size);
	
	int presortedness_index = (int)(presortedness*size);
	
	for(int i=0;i<size;i++)
		A[i] = std::rand();
	
	quick_sort q;
	q.q_sort(A,0,presortedness_index);

	
return A;
	

}

