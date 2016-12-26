#include "../include/sort.h"
void merge_sort::merge(int* A, int p, int q, int r) {

    int i,j,k=0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1];
    int R[n2];

    for (i=0; i<n1; i++) L[i] = A[p + i];
    for (j=0; j<n2; j++) R[j] = A[q + j + 1];

    for(i=0, j=0,k= p; k<= r; k++) {
        if (i == n1) {
            A[k] = R[j++];
        } else if (j == n2) {
            A[k] = L[i++];
        } else if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }

}

void merge_sort::m_sort(int* A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
       merge_sort::m_sort(A, p, q);
       merge_sort::m_sort(A, q + 1, r);
       merge_sort::merge(A, p, q, r);
    }
}
void merge_sort::sort(int* A,int length){

	merge_sort::m_sort(A,0,length-1);

}
