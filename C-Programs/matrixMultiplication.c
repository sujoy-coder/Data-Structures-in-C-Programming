#include <stdio.h>
#define SIZE 20

int mat1[SIZE][SIZE],mat2[SIZE][SIZE];


void getMatrices(int row1, int col1, int row2, int col2){
	int i,j;
	printf("Enter Matrix-A Elements : \n");
	for(i=0; i<row1; i++){
		for(j=0; j<col1; j++){
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("----------------------------------\n");
	printf("Given Matrix-A is : \n");
	for(i=0; i<row1; i++){
		for(j=0; j<col1; j++){
			printf("%d  ",mat1[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------\n");
	printf("Enter Matrix-B Elements : \n");
	for(i=0; i<row2; i++){
		for(j=0; j<col2; j++){
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("----------------------------------\n");
	printf("Given Matrix-B is : \n");
	for(i=0; i<row2; i++){
		for(j=0; j<col2; j++){
			printf("%d  ",mat2[i][j]);
		}
		printf("\n");
	}
}


void matrixMul(int row1, int col1, int row2, int col2){
	int i,j,k,result[SIZE][SIZE],sum=0;
	for (i = 0; i < row1; i++) {
      for (j = 0; j < col2; j++) {
         for (k = 0; k < col1; k++) {
            sum += mat1[i][k] * mat2[k][j];
         }
         result[i][j] = sum;
         sum = 0;
      }
   }
//   displaying result matrix...
    printf("----------------------------------\n");
	printf("The result matrix is : \n");
	for(i=0; i<row1; i++){
		for(j=0; j<col2; j++){
			printf("%d  ",result[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int i,j,row1,col1,row2,col2;
	printf("Enter Matrix Row No of Matrix-A: ");
	scanf("%d",&row1);
	printf("Enter Matrix Col No of Matrix-A: ");
	scanf("%d",&col1);
	printf("Enter Matrix Row No of Matrix-B: ");
	scanf("%d",&row2);
	printf("Enter Matrix Col No of Matrix-B: ");
	scanf("%d",&col2);
	if(col1 == row2){
//		Taking matrix input
		getMatrices(row1,col1,row2,col2);
//		calling multiplication function...
		matrixMul(row1,col1,row2,col2);
	}
	else{
		printf("Multiplication is not possible :(\n");
	}
	return 0;
}


