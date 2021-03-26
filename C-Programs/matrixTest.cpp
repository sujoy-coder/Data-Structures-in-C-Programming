#include <stdio.h>

int main(){
	int i,j,row,col,key,mat[10][10];
	printf("Enter Matrix Row No : ");
	scanf("%d",&row);
	printf("Enter Matrix Elements : ");
	scanf("%d",&col);
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
	
//	searching element in Matrix
//	int flag = 1
//	printf("----------------------------------\n");
//	printf("Enter Element you want to search in Matrix : ");
//	scanf("%d",&key);
//	for(i=0; i<row; i++){
//		for(j=0; j<col; j++){
//			if(mat[i][j] == key){
//				printf("%d found at Row=%d and Col=%d\n",key,(i+1),(j+1));
//				flag = 0;
//			}
//		}
//	}
//	if(flag){
//		printf("%d is not present in Matrix\n",key);
//	}

//	adding main diagonal element
//	if(row == col){
//		int sum = 0;
//		for(i=0;i<row;i++){
//		sum += mat[i][i];
//		}
//		printf("\nThe sum of Major digonal is = %d\n",sum);
//	}
//	else{
//		printf("The matrix is not squre matrix , so you can not get diagonal sum\n");
//	}

//	checking a matrix is symmetric or not
//	if(row == col){
//        int flag = 0;
//		for(i=0;i<(row-1);i++){
//		j = i + 1;
//		while(j<row){
//			if(mat[i][j] != mat[j][i]){
//				flag = 1;
//				break;
//			}
//			j++;
//		}
//		if(flag){
//			break;
//		}
//		}
//		if(flag){
//		  printf("Matrix is Not a Symmetric Matrix !!!\n");
//		}
//		else{
//			printf("Matrix is a Symmetric Matrix !!!\n");
//		}
//	}
//	else{
//		printf("The matrix is not squre matrix");
//	}

//	adding two matrix
	int mat2[10][10],row2,col2;
	printf("Enter 2nd Matrix Row No : ");
	scanf("%d",&row2);
	printf("Enter 2nd Matrix Col No : ");
	scanf("%d",&col2);
	if((row == row2)&&(col == col2)){
		printf("Enter 2nd Matrix Elements : \n");
		for(i=0; i<row2; i++){
			for(j=0; j<col2; j++){
				scanf("%d",&mat2[i][j]);
			}
		}
	printf("----------------------------------\n");
	printf("Given 2nd Matrix is : \n");
	for(i=0; i<row2; i++){
		for(j=0; j<col2; j++){
			printf("%d  ",mat2[i][j]);
		}
		printf("\n");
	}
	int result[10][10],tempSum = 0;
	for(i=0; i<row2; i++){
		for(j=0; j<col2; j++){
			tempSum = tempSum + mat[i][j] + mat2[i][j];
			result[i][j] = tempSum;
			tempSum = 0;
		}
	}
	printf("Result matrix after sum is : \n");
	for(i=0; i<row2; i++){
		for(j=0; j<col2; j++){
			printf("%d  ",result[i][j]);
		}
		printf("\n");
	}
	}
	else{
		 printf("Addition of matrix is not possible \n");
	}
	
	return 0;
}


