#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 10
#define MAX_COL 10

int mat[MAX_ROW][MAX_COL];

int isSqureMatrix(int row, int col){	
	if(row == col){
		return 1;
	}
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
	printf("The sum of Minor digonal is = %d\n",sum);
	return sum;
}

void sumEachRow(int row, int col){
	int i,j,sum;
	for(i=0;i<row;i++){
		sum = 0;
		for(j=0;j<col;j++){
			sum += mat[i][j];
		}
		printf("sum of row-%d = %d\n",(i+1),sum);
	}
}

void sumEachCol(int row, int col){
	int i,j,sum;
	for(i=0;i<col;i++){
		sum = 0;
		for(j=0;j<row;j++){
			sum += mat[j][i];
		}
		printf("sum of column-%d = %d\n",(i+1),sum);
	}
}

void maxEachRow(int row,int col){
	int i,j,max;
	for(i=0;i<row;i++){
		max = mat[i][0];
		for(j=1;j<col;j++){
			if(max<mat[i][j]){
				max = mat[i][j];
			}
		}
		printf("maximum of row-%d = %d\n",(i+1),max);
	}
}

void maxEachCol(int row,int col){
	int i,j,max;
	for(i=0;i<col;i++){
		max = mat[0][i];
		for(j=1;j<row;j++){
			if(max<mat[j][i]){
				max = mat[j][i];
			}
		}
		printf("maximum of column-%d = %d\n",(i+1),max);
	}
}

void minEachRow(int row,int col){
	int i,j,min;
	for(i=0;i<row;i++){
		min = mat[i][0];
		for(j=1;j<col;j++){
			if(min>mat[i][j]){
				min = mat[i][j];
			}
		}
		printf("minimum of row-%d = %d\n",(i+1),min);
	}
}

void minEachCol(int row,int col){
	int i,j,min;
	for(i=0;i<col;i++){
		min = mat[0][i];
		for(j=1;j<row;j++){
			if(min>mat[j][i]){
				min = mat[j][i];
			}
		}
		printf("minimum of column-%d = %d\n",(i+1),min);
	}
}

int main(){
	int row,col,ch;
	printf("Enter Matrix Row No : ");
	scanf("%d",&row);
	printf("Enter Matrix Col No : ");
	scanf("%d",&col);
	matrixInputAndDisplay(row,col);
	
	while(1){
		printf("\n1. Sum of Major and Minor Diagonal\n2. Sum of Each Row and Column\n3. Get Maximum of Each Row and Column\n4. Get Minimum of Each Row and Column\n5. Exit\n");
		printf("  Choise : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: //  1. Write a C program to find sum of main diagonal and minor diagonal elements of a  square matrix.
						if(isSqureMatrix(row,col)){
							sumMajorDiagonal(row);
							sumMinorDiagonal(row);
						}
						else{
							printf("Matrix is not a squre Matrix...\n");
						}
						break;
						
			case 2: //	2. Write a C program to find sum of each row and column of a matrix.
						sumEachRow(row,col);
						sumEachCol(row,col);
						break;
						
			case 3: //	3. Write a C program to find maximum element of each row and column of a matrix.
						maxEachRow(row,col);
						maxEachCol(row,col);
						break;
						
			case 4: //	4. Write a C program to find minimum element of each row and column of a matrix.
						minEachRow(row,col);
						minEachCol(row,col);
						break;
						
			case 5:		exit(0);
			
			default:    printf("Invalid Input !!!\n");
		}
	}
	
	return 0;
}
