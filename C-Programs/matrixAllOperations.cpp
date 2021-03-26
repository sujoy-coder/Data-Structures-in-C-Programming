#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

int isSqureMatrix(int ,int);
void matrixInputAndDisplay(int, int);
int sumMajorDiagonal(int);
int sumMinorDiagonal(int);
void showTranspose(int, int);
int isIdentityMatrix(int);
int isSymmetric(int);
int isLowerTriangular(int);
int isUpperTriangular(int);
void copyIn1DArrayRowMajor(int, int);
void copyIn1DArrayColMajor(int, int);
int maxOfMinInRow(int, int);
int minOfMaxInCol(int, int);

int mat[MAX_ROW][MAX_COL];

int main(){
	int row,col;
	printf("Enter Matrix Row No : ");
	scanf("%d",&row);
	printf("Enter Matrix Col No : ");
	scanf("%d",&col);
	
	matrixInputAndDisplay(row,col);
	
//	if(isSqureMatrix(row,col)){
//		isIdentityMatrix(row);
//		isUpperTriangular(row);
//	}

	if(maxOfMinInRow(row,col) == minOfMaxInCol(row,col)){
		printf("The matrix has a Saddle Point\n");
		printf("Max of min in Row = %d\tMin of max in Col = %d",maxOfMinInRow(row,col),minOfMaxInCol(row,col));
	}
	else{
		printf("The matrix don't have a Saddle Point\n");
		printf("Max of min in Row = %d\tMin of max in Col = %d",maxOfMinInRow(row,col),minOfMaxInCol(row,col));
	}

	return 0;	
}




int isSqureMatrix(int row, int col){	
	if(row == col){
//		printf("----------------------------------\n");
//		printf("The matrix is a Squre Matrix...\n");
		return 1;
	}
//	printf("----------------------------------\n");
//	printf("The matrix is not a Squre Matrix...\n");
	return 0;
}

void matrixInputAndDisplay(int row, int col){

	int i,j;
	printf("Enter Matrix Elements : \n");
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	printf("----------------------------------\n");
	printf("Given Matrix is : \n");
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}
}

int sumMajorDiagonal(int size){
	int i,sum=0;
	for(i=0;i<size;i++){
		sum += mat[i][i];
	}
	printf("----------------------------------\n");
	printf("The sum of Major digonal is = %d\n",sum);
	return sum;
}

int sumMinorDiagonal(int size){
	int sum = 0,i = 0,j = size-1;
	while(i<=j){
		if(i!=j){
			sum += mat[i][j] + mat[j][i];
		}
		else{
			sum += mat[i][j];
		}
		i++;
		j--;
	}
	printf("----------------------------------\n");
	printf("The sum of Minor digonal is = %d\n",sum);
	return sum;
}

void showTranspose(int row, int col){
	int i,j;
//`	logic for displaying transpose of same matrix without using other matrix...
	printf("----------------------------------\n");
	printf("The Transpose of above matrix is : \n");
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			printf("%d  ",mat[j][i]);
		}
		printf("\n");
	}
////	get transpose matrix using another matrix
//	int transpose[MAX_ROW][MAX_COL];
//	for(i=0; i<row; i++){
//		for(j=0; j<col; j++){
//			transpose[j][i] = mat[i][j];
//		}
//	}
////	displaying transpose Matrix ...
//	printf("----------------------------------\n");
//	for(i=0; i<col; i++){
//		for(j=0; j<row; j++){
//			printf("%d  ",transpose[i][j]);
//		}
//		printf("\n");
//	}
}

int isIdentityMatrix(int size){
	int i,j;
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if((i == j) && (mat[i][j] != 1)){
				printf("----------------------------------\n");
				printf("Matrix is Not Identity Matrix !!!\n");
				return 0;
			}
			if((i != j) && (mat[i][j] != 0)){
				printf("----------------------------------\n");
				printf("Matrix is Not Identity Matrix !!!\n");
				return 0;
			}
		}
	}
	printf("----------------------------------\n");
	printf("Matrix is an Identity Matrix !!!\n");
	return 1;
}

int isSymmetric(int size){
	int i,j;
	for(i=0;i<(size-1);i++){
		j = i + 1;
		while(j<size){
			if(mat[i][j] != mat[j][i]){
				printf("----------------------------------\n");
				printf("Matrix is Not a Symmetric Matrix !!!\n");
				return 0;
			}
			j++;
		}
	}
	printf("----------------------------------\n");
	printf("Matrix is a Symmetric Matrix !!!\n");
	return 1;
}

int isLowerTriangular(int size){
	int i,j;
	for(i=0;i<(size-1);i++){
		j = i + 1;
		while(j<size){
			if(mat[i][j] != 0){
				printf("----------------------------------\n");
				printf("Matrix is Not a Lower Triangular Matrix !!!\n");
				return 0;
			}
			j++;
		}
	}
	printf("----------------------------------\n");
	printf("Matrix is a Lower Triangular Matrix !!!\n");
	return 1;
}

int isUpperTriangular(int size){
	int i,j;
	for(i=0;i<(size-1);i++){
		j = i + 1;
		while(j<size){
			if(mat[j][i] != 0){
				printf("----------------------------------\n");
				printf("Matrix is Not a Upper Triangular Matrix !!!\n");
				return 0;
			}
			j++;
		}
	}
	printf("----------------------------------\n");
	printf("Matrix is a Upper Triangular Matrix !!!\n");
	return 1;
}

void copyIn1DArrayRowMajor(int row, int col){
	int row_major[20],i,j,id;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			id = (i*col) + j;
			row_major[id] = mat[i][j];
		}
	}
	printf("----------------------------------\n");
	printf("The Matrix in Row Major 1-D array is : \n");
	for(i=0;i<(row*col);i++){
		printf("%d\t",row_major[i]);
	}
}

void copyIn1DArrayColMajor(int row, int col){
	int col_major[20],i,j,id = 0;
	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
			col_major[id] = mat[j][i];
			id++;
		}
	}
	printf("----------------------------------\n");
	printf("The Matrix in Col Major 1-D array is : \n");
	for(i=0;i<(row*col);i++){
		printf("%d\t",col_major[i]);
	}
}

int maxOfMinInRow(int row, int col){
	int max,i,j,min;
	max = mat[0][0];
	for(i=0;i<row;i++){
		min = mat[i][0];
		for(j=1;j<col;j++){
			if(mat[i][j]<min){
				min = mat[i][j];
			}
		}
		if(i != 0){
			if(max<min){
			    max = min;
		    }
		}
		else{
			max = min;
		}
	}
	return max;
}

int minOfMaxInCol(int row, int col){
	int max,i,j,min;
	min = mat[0][0];
	for(i=0;i<col;i++){
		max = mat[0][i];
		for(j=1;j<row;j++){
			if(mat[j][i]>max){
				max = mat[j][i];
			}
		}
		if(i != 0){
			if(max<min){
			    min = max;
		     }
		}
		else{
			min = max;
		}
	}
	return min;
}

