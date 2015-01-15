#include "expr_assert.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "arrayFunction.h"

void forEach_function_for_integer(int a,int index,int *b){
	 printf("integer=%d,index=%d\n", a, index);
};


void test_function_should_be_behave_like_forEach_for_integer(){
	void (*function) (int ,int,int*) ;
	int array[] ={1,3,6,8,45,23};
	int length = 6;
	function = &forEach_function_for_integer;
	assertEqual(forEach_for_integer(array,length,function),1);
};
void sqrt_function(int a,int index,int *array){
			 array[index] = sqrt(a);
}

void test_find_all_the_sqrt_of_number_using_forEach(){
	void (*function) (int ,int,int *) ;
	int array[] ={4,9,16,25,36,49};
	int length = 6;
	function = &sqrt_function;
	assertEqual(forEach_for_integer(array,length,function), 1);
	 assertEqual(array[0], 2);
	 assertEqual(array[1], 3);
	 assertEqual(array[2], 4);
	 assertEqual(array[3], 5);
	 assertEqual(array[4], 6);
	 assertEqual(array[5], 7);

}

void forEach_function_for_charecter(char a,int index){
	 printf("%c %d\n",a , index);
}

void test_function_should_be_behave_like_forEach_for_charecter(){
	void (*function) (char,int) ;
	char array[] ={'a','b','c','d','e','f'};
	int length = 6;
	function = &forEach_function_for_charecter;
	assertEqual(forEach_for_charecter(array,length,function), 1);
};

void forEach_function_for_string(char *a,int index){
		printf("%s,%d\n",a,index);
	};

void test_function_should_be_behave_like_forEach_for_string(){
	void (*function) (char*,int) ;
	char *array[] ={"heloo","hiii","nahi","nahi"};
	int length = 4;
	function = &forEach_function_for_string;
	assertEqual(forEach_for_string(array,length,function), 1);
};


int filter_function_for_integer(int a,int index){
	 	return (a>=2) ? 1 : 0 ;
};

void test_filter_function_gives_all_number_greater_than_2(){
	int *result_array;
	int (*function) (int , int );
	int array[] = {1,2,3,4,5,6};
	int length = 6;
	function = &filter_function_for_integer;
	assertEqual(filter_for_integer(array,length,function,&result_array), 1);
	assertEqual(result_array[0],2);
	assertEqual(result_array[1],3);
	assertEqual(result_array[2],4);
	assertEqual(result_array[3],5);
};

int filter_function_for_prime_number(int a,int index){
	int i,count=0;
	for(i=2;i<a;i++){
		if(a%i == 0){
			count++;
			
		}
		if(count == 0)
			return 1;
	}

};

void test_filter_function_gives_all_prime_number(){
	int *result_array;
	int (*function) (int , int );
	int array[] = {4,3,6,7,13,11,17};
	int length = 7;
	function = &filter_function_for_prime_number;
	assertEqual(filter_for_integer(array,length,function,&result_array), 1);
	assertEqual(result_array[0],3);
	assertEqual(result_array[1],7);
	assertEqual(result_array[2],13);
	assertEqual(result_array[3],11);
};

int filter_function_for_charecter(char a,int index){
		if(a > 100)
		return 1;
	 	
};

void test_for_filter_function_for_charecter(){
	int *result_array;
	int (*function) (char , int );
	char array[] = {'a','b','c','d','e','f'};
	int length = 7;
	function = &filter_function_for_charecter;
	assertEqual(filter_for_charecter(array,length,function,&result_array), 1);
	assertEqual(result_array[0],'e');
	assertEqual(result_array[1],'f');
};

int map_function_for_quberoot(int a ,int index ,int *array){
	       return  array[index] = cbrt(a);

};

void test_for_map_function_for_finding_cube_root(){
	int (*function)(int,int,int*);
	int array[] = {1,8,27,64,125,216};
	int length = 6;
	int *p;
	function = &map_function_for_quberoot;
	p=map_for_integer(array,length,function);
	assertEqual(p[0],1);
	assertEqual(p[1],2);
	assertEqual(p[2],3);
	assertEqual(p[3],4);
	assertEqual(p[4],5);
};


int map_function_adding_2(int a,int index,int *array){
		return array[index] = a+2;
};

void test_for_map_function_for_adding_2_in_each_element(){
	int (*function)(int,int,int*);
	int array[] = {5,7,13,56,34,23,65};
	int length = 7;
	int *p;
	function = &map_function_adding_2;
	p=map_for_integer(array,length,function);
	assertEqual(p[0],7);
	assertEqual(p[1],9);
	assertEqual(p[2],15);
	assertEqual(p[3],58);
	assertEqual(p[4],36);
};
