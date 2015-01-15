#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,tearDown,fixtureSetup,fixtureTearDown,test_function_should_be_behave_like_forEach_for_integer,test_find_all_the_sqrt_of_number_using_forEach,test_function_should_be_behave_like_forEach_for_charecter,test_function_should_be_behave_like_forEach_for_string,test_filter_function_gives_all_number_greater_than_2,test_filter_function_gives_all_prime_number,test_for_filter_function_for_charecter,test_for_filter_function_for_string,test_for_map_function_for_finding_cube_root,test_for_map_function_for_adding_2_in_each_element,test_for_map_function_for_get_double_for_element;
Test test[] = {"test_function_should_be_behave_like_forEach_for_integer",test_function_should_be_behave_like_forEach_for_integer,"test_find_all_the_sqrt_of_number_using_forEach",test_find_all_the_sqrt_of_number_using_forEach,"test_function_should_be_behave_like_forEach_for_charecter",test_function_should_be_behave_like_forEach_for_charecter,"test_function_should_be_behave_like_forEach_for_string",test_function_should_be_behave_like_forEach_for_string,"test_filter_function_gives_all_number_greater_than_2",test_filter_function_gives_all_number_greater_than_2,"test_filter_function_gives_all_prime_number",test_filter_function_gives_all_prime_number,"test_for_filter_function_for_charecter",test_for_filter_function_for_charecter,"test_for_filter_function_for_string",test_for_filter_function_for_string,"test_for_map_function_for_finding_cube_root",test_for_map_function_for_finding_cube_root,"test_for_map_function_for_adding_2_in_each_element",test_for_map_function_for_adding_2_in_each_element,"test_for_map_function_for_get_double_for_element",test_for_map_function_for_get_double_for_element};
char testFileName[] = {"arrayFunctionTest.c"};
void _setup(){/*CALL_SETUP*/}
void _tearDown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("\t%s\n",name);
	_setup();
		test();
	_tearDown();
	if(!currentTestFailed) passCount++;	
}

int main(){
	int i,total = sizeof(test)/sizeof(Test);
	fixtureSetup();
	testCount=0,passCount=0;
	printf("********* Starting tests of %s\n\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();
	return 0;
}