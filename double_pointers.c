#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	int i;
	char str1[] = "heloo";
	char *p = "heloo";
	// str1="bye";
	p="bye";
	p="new";
	printf("%s\n",p );
	for(i=0;i<3;i++){
	printf("%c\n",p[i]);
}
	return 0;
}
// int main()
// {
//    char a[100], b[100];
 
//    printf("Enter the first string\n");
//    gets(a);
 
//    printf("Enter the second string\n");
//    gets(b);
 
//    strcat(a,b);
 
//    printf("String obtained on concatenation is %s\n",a);
 
//    return 0;
// }
	// int **a;

	// a=malloc(sizeof(int *));
	// (*a)=malloc(sizeof(int));
	// **a=34;
	// printf("%d\n",a );
	// printf("%d\n",*a );


	// // printf("%d\n", **a );
	// // int **aa_ptr;
	// // aa_ptr=malloc(sizeof(int *)*2);
	// // printf("%d\n",aa_ptr );

	// // *aa_ptr = malloc(sizeof(int));
	// // printf("%d\n",*aa_ptr);


	// // aa_ptr[0][0]=34;
	// // aa_ptr[1][0]=67;

// 	// // printf("%d %d\n", *aa_ptr=34, *(aa_ptr+1) = 56);
// 	return 0;
// };