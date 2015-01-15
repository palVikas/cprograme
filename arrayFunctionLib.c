#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayFunction.h"

int forEach_for_integer(int *array, int length, void (*function) (int ,int,int *)){
	int i ;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		 (*function)(array[i] , i ,array);
	}
	return 1;
};

int forEach_for_charecter(char *array, int length, void (*function )(char,int)){
	int i;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		 (*function)(array[i],i);
	}
	return 1;
};

int forEach_for_string(char **array, int length, void (*function)(char*,int)){
	int i;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		 (*function)(array[i],i);
	}
	return 1;
};


int filter_for_integer(int *array,int length,int (*function)(int ,int),int **result_array){
	int i,j,count=0 ,temp[length];
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
	if ((*function)(array[i],i) == 1){
		temp[count] = array[i];
			count++;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*count);
	for(j=0;j<count;j++){
		(*result_array)[j] = temp[j];
	}
	return 1;
}

int filter_for_charecter(char *array,int length,int(*function)(char , int),int **result_array){
	int i,j,count=0 ,temp[length];
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
	if ((*function)(array[i],i) == 1){
		temp[count] = array[i];
			count++;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*count);
	for(j=0;j<count;j++){
		(*result_array)[j] = temp[j];
	}
	return 1;
}


int* map_for_integer(int *array,int length,int (*function)(int,int,int*)){
	int i,j,*result;
	result = (int*)malloc(sizeof(int)*length);
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result[i]= (*function)(array[i],i,array);

	}
	return result;
};
