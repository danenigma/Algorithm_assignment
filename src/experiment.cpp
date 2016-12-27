/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#include "../include/experiment.h"
#include "../include/generate_array.h"
#include "../include/sort.h"
#include <stdio.h>
#include <ctime>
#include <fstream>
#include <time.h>
#include <sstream>

/*      ALGORITHMS     */

selection_sort selection;
insertion_sort insertion;
merge_sort     merge;
quick_sort     quick;
heap_sort      heap_s;

Sort * algorithms[] = {&quick,&merge,&heap_s,&insertion,&selection};

clock_t start_t,stop_t;

std::ofstream my_file;
std::string path = "./report/test/presortedness_";
std::string format = ".csv";

/*************************************************************************




*/
void experiment(int start ,int stop,int step,float presortedness,int rep){
	std::ostringstream ss;
	ss << presortedness;
	std::string s(ss.str());
    	
	my_file.open(path+s+format);//dump csv
	int num_exp = step+1;//number of experiments;
	int running_time_log [rep][num_exp][5];//running time of each algorithm in each experiment
	int size;
	
	for (int k = 0;k<rep;k++){//for every repetition

		for (int i = 0;i<=step;i++){//for every experiment
			
			size = ((stop-start)/step)*i;
			int *A ;
			
			A = generate_array(size,presortedness);//generate presorted array
			
			printf("sorting rep:=%i %i\n",k,size);

			for (int j = 0;j<5;j++){//for every algorithm
			
			 int* B=malloc (sizeof(int) * size);
			 //printf("%i\n",j);
			 copy(A,B,size);
			 start_t = clock();		
			 algorithms[j]->sort(B,size);
			 stop_t  = clock();
			 running_time_log[k][i][j]=stop_t-start_t;	
			 
		
		}
			 
		
	    }
	}
	
	printf("start:= %i\t stop:=%i\t step:=%i\t presortedness:=%0.3f\n",start,stop,step,presortedness);
	
	printf("n    \tquicksort\tmergesort\theapsort\tinsertion\tselection\n");
	my_file<<"n  , quick sort , merge sort , heap sort , insertion sort , selection sort\n";
	int average_running_time[num_exp][5];
	int result[num_exp][6];

	    
	    for (int i = 0;i<=step;i++){//for every experiment

			size = ((stop-start)/step)*i;	
			for (int j = 0;j<5;j++){//for every algorithm
				int acc =0,av_rt=0;
				for (int k = 0;k<rep;k++){

				 	 acc+=running_time_log[k][i][j];
					 av_rt = acc/rep;
					 average_running_time[i][j] = av_rt;//average of the repetitions
					
			}

		}
	}

	
	        for (int i = 0;i<=step;i++){//for every experiment
			size = ((stop-start)/step)*i;
				
			for (int j = 0;j<6;j++){//for every algorithm
				if(j ==0)result[i][j] = size;
				else{
					result[i][j]=average_running_time[i][j-1];
				}

			}
		
		
		}
		for (int i = 0;i<=step;i++){//for every experiment
				
			for (int j = 0;j<6;j++){//for every algorithm
			 printf("%i\t\t",result[i][j]);	
	
		 	 my_file<<result[i][j]<<",";
		
			}
			
			printf("\n");
			my_file<<"\n";
		}
			my_file.close();
	
}
inline void copy(int *A,int* B,int length){


	for(int i=0;i<length;i++)B[i]=A[i];


}

