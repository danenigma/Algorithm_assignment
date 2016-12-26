#include <stdio.h>
#include "./include/experiment.h"




int main(){
	float pre = 0.0;
	for(int i=0;i<5;i++){
		experiment(0,10000,20,pre,1);
		pre+=0.25;
	}

return 0;
}
	

