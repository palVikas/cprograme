#include "expr_assert.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "arrayFunction.h"
#include <ctype.h>

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
	return 0;
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
	free(result_array);
};

// int filter_function_for_float(float a,int index){

// }

// void test_for_filer_function_for_float(){
// 	int *result_array;
// 	int (*function) (float , int );
// 	int array[] = {4.6,3.8,6.2,7.9,13.70};
// 	int length = 6;
// 	function = &filter_function_for_float;
// 	assertEqual(filter_for_integer(array,length,function,&result_array), 1);
// 	assertEqual(result_array[0],3);
// 	assertEqual(result_array[1],7);
// 	assertEqual(result_array[2],13);
// 	assertEqual(result_array[3],11);
// 	free(result_array);
// };

int filter_function_for_charecter(char a,int index){
		return (a > 100);	 	
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
	free(result_array);
};

int filter_function_for_string(char *a ,int index){
	return (a[0]==104) ? 1 :0;
};

void test_for_filter_function_for_string(){
	int (*function) (char*,int) ;
	char **result_array;
	char *array[] ={"heloo","hiii","nahi","kabhi nii","hats"};
	int length = 5,result;
	function = &filter_function_for_string;
	result = filter_for_string(array,length,function,&result_array);
	assertEqual(result, 1);
	assertEqual(strcmp("heloo",result_array[0]),0);
	assertEqual(strcmp("hiii",result_array[1]),0);
	assertEqual(strcmp("hats",result_array[2]),0);
	assertEqual(strcmp("haus",result_array[2]),1);
}

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

int map_function_for_double(int a,int index,int *array){
	return array[index] = a*2;
};

void test_for_map_function_for_get_double_for_element(){
	int (*function)(int,int,int*);
	int array[] = {5,7,13,56,34,23,65};
	int length = 7;
	int *p;
	function = &map_function_for_double;
	p=map_for_integer(array,length,function);
	assertEqual(p[0],10);
	assertEqual(p[1],14);
	assertEqual(p[2],26);
	assertEqual(p[3],112);
};


char map_function_return_upper_charecter(char a,int index,char *array){
		return array[index] = toupper(a);
};

void test_for_map_function_for_get_upper_charecter(){
	char (*function)(char,int,char*);
	char array[] = {'a','b','c','d','e'};
	int length = 5;
	char *p;
	function = &map_function_return_upper_charecter;
	p=map_for_charecter(array,length,function);
	assertEqual(p[0],'A');
	assertEqual(p[1],'B');
	assertEqual(p[2],'C');
	assertEqual(p[3],'D');
	assertEqual(p[4],'E');
};

char map_function_for_next_charecter(char a,int index,char *array){
	return array[index] = a+2;
}


void test_for_map_function_for_get_next_charecter(){
	char (*function)(char,int,char*);
	char array[] = {'a','b','c','d','e'};
	int length = 5;
	char *p;
	function = &map_function_for_next_charecter;
	p=map_for_charecter(array,length,function);
	assertEqual(p[0],'c');
	assertEqual(p[1],'d');
	assertEqual(p[2],'e');
	assertEqual(p[3],'f');
	assertEqual(p[4],'g');
};

char* map_function_for_string(char *a,int index,char **array){
		return a;
}

void test_for_map_function_for_string(){
	char *array[]={"vikas","vijay","ajay"};
	char* (*function)(char*,int,char**);
	int length =3;
	char **p;
	function = &map_function_for_string;
	p=map_for_string(array,length,function);
	assertEqual(strcmp("vikas",p[0]),0);
	assertEqual(strcmp("vijay",p[1]),0);
	assertEqual(strcmp("ajay",p[2]),0);
	assertEqual(strcmp("vimas",p[0]),2);


}




int reduce_function(int cv,int initial_value,int index,int *array){
	return cv+initial_value;
};

void test_for_reduce_function_for_adding_cv_and_pv_value(){
	int (*function)(int,int,int,int*);
	int array[] = {5,7,13,56,34,23,65};
	int length = 7;
	int initial_value=0;
	int p;
	function = &reduce_function;
	p=reduce_for_integer(array,length,initial_value,function);
	assertEqual(p,203);
	
};

int reduce_function_for_big_number(int cv,int initial_value,int index,int *array){
		if(initial_value > cv)
			return initial_value;
		return cv;
}

void test_for_reduce_function_for_given_big_number_in_array(){
	int (*function)(int,int,int,int*);
	int array[] = {5,71,103,13,56,34,23,65,67,23,90};
	int length = 7;
	int initial_value=45;
	int p;
	function = &reduce_function_for_big_number;
	p=reduce_for_integer(array,length,initial_value,function);
	assertEqual(p,103);
	
};

char reduce_function_for_charecter(char a,char initial_value,int index,char *array){
			return a;
};

void test_for_reduce_function_for_charecter_cv_and_pv_value(){
	char (*function)(char,char,int,char*);
	char array[] = {'i','k','a','s'};
	int length = 4;
	char initial_value='v';
	char p;
	function = &reduce_function_for_charecter;
	p=reduce_for_charecter(array,length,initial_value,function);
	assertEqual(p,'s');
};
char reduce_function_to_find_big_charecter(char a,char initial_value,int index,char *array){
		if(initial_value > a)
			return initial_value;
		return a;
}

void test_for_reduce_function_for_charecter_to_give_big_charecter(){
	char (*function)(char,char,int,char*);
	char array[] = {'i','k','a','s','m','z','s','q'};
	int length = 8;
	char initial_value='e';
	char p;
	function = &reduce_function_to_find_big_charecter;
	p=reduce_for_charecter(array,length,initial_value,function);
	assertEqual(p,'z');
};

char* reduce_function_to_find_big_string(char* a,char* initial_value,int index,char** array){
		return (strlen(initial_value)> strlen(a)) ? initial_value : a;
}

void test_for_reduce_function_for_string_return_big_string(){
	char *array[] = {"heloo","syamlal","khurana","jalandharwale"};
	int length = 4;
	char *initial_value="nahii";
	char *p;
	p=reduce_for_string(array,length,initial_value,reduce_function_to_find_big_string);
	assertEqual(strcmp("jalandharwale",p),0);
};

char* reduce_function_to_find_small_string(char* a,char* initial_value,int index,char** array){
	return (strlen(initial_value)> strlen(a)) ? a : initial_value;
}

void test_for_reduce_function_for_string_return_small_string(){
	char *array[] = {"helo","syamlal","khurana","jalandharwale"};
	int length = 4;
	char *initial_value="nahii";
	char *p;
	p=reduce_for_string(array,length,initial_value,reduce_function_to_find_small_string);
	assertEqual(strcmp("helo",p),0);
	
};