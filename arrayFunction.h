typedef  char* find_big_string(char*,char*,int,char**);

int forEach_for_integer(int *array, int length, void (*function )(int ,int,int*));
int forEach_for_charecter(char *array, int length, void (*function) (char,int));
int forEach_for_string(char **array, int length, void (*function )(char*,int));
int filter_for_float(float *array,int length,int (*function)(float ,int), float **result_array);
int filter_for_integer(int *array,int length,int (*function)(int ,int), int **result_array);
int filter_for_charecter(char *array,int length,int(*function)(char,int),int **result_array);
int filter_for_string(char **array,int length,int(*function)(char*,int),char ***result_array);
int* map_for_integer(int *array,int length,int (*function)(int,int,int*));
char* map_for_charecter(char *array,int length,char(*function)(char , int,char*));
char** map_for_string(char **array,int length,char* (*function)(char*,int,char**));
int reduce_for_integer(int *array,int length,int initial_value,int (*function)(int,int,int,int*));
char reduce_for_charecter(char *array,int length,char initial_value,char (*function)(char,char,int,char*));
char* reduce_for_string(char **array,int length,char *initial_value,find_big_string* operate);



