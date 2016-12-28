/****************************************************************/
/* Author : Daniel Fekadu					*/
/* Date : 27/12/2016						*/
/***************************************************************/

#include <stdio.h>
#include "./include/experiment.h"




int main(){

	float presortedness = 0.0;
	
	for(int i=0;i<5;i++){//for every presortedness {0,0.25,0.5,0.75,1}
         
         experiment(0,100000,20,presortedness,2);//experiment(start=0,stop=100000,step=20,presorted,repetition=2)
         presortedness+=0.25;
 	
	}

return 0;
}
	

