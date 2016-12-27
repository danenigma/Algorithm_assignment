/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#ifndef _SORT_H
#define _SORT_H

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

typedef struct {
    int *nodes;
    int length;
    int heap_size;
} heap;//HEAP NODE STRUCT

class Sort
{

	public:
		virtual void sort(int* A,int length){}
		inline void swap(int* A,int i,int j){

			   int temp = A[i];
			   A[i] = A[j];
			   A[j] = temp;
		}

};

class selection_sort:public Sort{

	public:
	 	void        sort(int * A,int length);
		inline int  find_min(int* A,int i,int length);
		
};


class insertion_sort: public Sort
{

	public:
	      void sort(int*A,int length);
	      	

}
;
class merge_sort:public Sort{
	public:
		 void sort(int*A,int length);
		 void merge(int* A, int p, int q, int r);
		 void m_sort(int* A, int p, int r);


};

class quick_sort:public Sort{

	public:
		int partition(int* A,int p,int r);
		void q_sort(int* A,int p ,int r);
		void sort(int* A,int length);



};


class heap_sort:public Sort{
	public:
		void        sort(int * A,int length);
		void max_heapify(heap A, int i);
		heap build_max_heap (int* A,int length);


};

#endif
