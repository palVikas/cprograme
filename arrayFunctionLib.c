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
// int filter_for_float(float *array,int length,int (*function)(float ,int), float **result_array){


// }

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

int filter_for_string(char **array,int length,int(*function)(char*,int),char ***result_array){
	int i,j,count=0,result_length=0;
	char *temp[length];
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		if ((*function)(array[i],i) == 1){
			temp[count] = array[i];
			count++;
		}
	}
	*result_array = (char **)malloc(sizeof(char*)*count);
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

char* map_for_charecter(char *array,int length,char(*function)(char ,int,char*)){
	int i,j;
	char *result;
	result = (char*)malloc(sizeof(char)*length);
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result[i]= (*function)(array[i],i,array);
	}
	return result;
}
char** map_for_string(char **array,int length,char* (*function)(char*,int,char**)){
	int i;
	char **result;
	result = (char**)malloc(sizeof(char*)*length);
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result[i]= (*function)(array[i],i,array);
	}
	return result;

}

int reduce_for_integer(int *array,int length,int initial_value,int (*function)(int,int,int,int*)){
	int i,j;
	int result = initial_value;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result = (*function)(array[i],result,i,array);
	}
	return result;
}

char reduce_for_charecter(char *array,int length,char initial_value,char (*function)(char,char,int,char*)){
	int i;
	char result = initial_value;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result = (*function)(array[i],result,i,array);
	}
	return result;

}

char* reduce_for_string(char **array,int length,char *initial_value,find_big_string* operate){
	int i;
	char *result;
	result = initial_value;
	if(length<=0)
		return 0;
	for(i=0;i<length;i++){
		result= operate(array[i],result,i,array);
	}
	return result;
}
