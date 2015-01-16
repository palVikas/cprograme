int forEach_for_integer(int *array, int length, void (*function )(int ,int,int*));
int forEach_for_charecter(char *array, int length, void (*function) (char,int));
int forEach_for_string(char **array, int length, void (*function )(char*,int));
int filter_for_integer(int *array,int length,int (*function)(int ,int), int **result_array);
int filter_for_charecter(char *array,int length,int(*function)(char,int),int **result_array);
int filter_for_string(char **array,int length,int(*function)(char*,int),char ***result_array);
int* map_for_integer(int *array,int length,int (*function)(int,int,int*));
char* map_for_charecter(char *array,int length,int(*function)(char , int,char*));



