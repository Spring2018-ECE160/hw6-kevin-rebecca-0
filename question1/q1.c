#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

void ranges (int x[], int npts, int *max_ptr, int *min_ptr);

void main(){
	int x[] = {1,17,8,9,6};
	int y[] = {57,94,86,32,12,10,14};
	int z[] = {9,8,2,5,6,3};
	int *max_ptrx = malloc(8);
	int *min_ptrx = malloc(8);	
        
	int *max_ptry = malloc(8);
        int *min_ptry = malloc(8);
	
	int *max_ptrz = malloc(8);
        int *min_ptrz = malloc(8);

	int npts;
	
	npts = sizeof(x)/sizeof(x[0]);
	ranges (x, npts, max_ptrx, min_ptrx);
	printf("Max: %d\nMin: %d\n", *max_ptrx, *min_ptrx);
	
	npts = sizeof(y)/sizeof(y[0]);
	ranges (y, npts, max_ptry, min_ptry);
        printf("Max: %d\nMin: %d\n", *max_ptry, *min_ptry);
	
	npts = sizeof(z)/sizeof(z[0]);
	ranges (z, npts, max_ptrz, min_ptrz);
        printf("Max: %d\nMin: %d\n", *max_ptrz, *min_ptrz);
	return;
}

void ranges (int x[], int npts, int *max_ptr, int *min_ptr){
	
	int max = x[0];
	int maxIndex = 0;
	int min = x[0];
	int minIndex = 0;
	
	for (int i = 0; i < npts; i++){
		if (x[i] > max){
			max = x[i];
			maxIndex = i;
		}
		if (x[i] < min){
			min = x[i];
			minIndex = i;
		}
	}
	
	*max_ptr = x[maxIndex];
	*min_ptr = x[minIndex];
	return;

}
