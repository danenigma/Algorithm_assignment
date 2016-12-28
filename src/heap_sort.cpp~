/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#include"../include/sort.h"
#include<stdio.h>
void heap_sort::sort(int* A,int length) {
		heap new_heap;
		new_heap = heap_sort::build_max_heap(A,length);
	
	for(int i = length-1;i>=1;i--){

		        swap(new_heap.nodes,0,i);
			new_heap.heap_size=new_heap.heap_size-1;		
			max_heapify(new_heap, 0);
	}
	
}
void heap_sort::max_heapify(heap A, int i) {
    int left, right, largest, temp;

    while(1) {
        left  = LEFT(i);
        right = RIGHT(i);

        if (left < A.heap_size && A.nodes[left] > A.nodes[i])
            largest = left;
        else
            largest = i;

        if (right < A.heap_size && A.nodes[right] > A.nodes[largest])
            largest = right;

        if (largest == i)
            return;

        temp = A.nodes[i];
        A.nodes[i] = A.nodes[largest];
        A.nodes[largest] = temp;

        i = largest;
   }
    
}

heap heap_sort::build_max_heap (int* A,int length){

	heap result;
	result.nodes = A;
	result.heap_size = length;
	for(int i = length/2;i>=0;i--)heap_sort::max_heapify(result, i);
return result;
}
