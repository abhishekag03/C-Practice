#include <stdio.h>

int N;      //initializing the size for the temporary matrix to be passed in the function

// float determinant(float matrix[N][N],int r,int c, int x);

float determinant(float matrix[N][N],int x){          //a recursive function which returns the value of the determinant of a matrix
	if (x==1){															  //a base condition when the matrix is 1*1 
		return matrix[0][0];
	}

	else if (x==2){
		float ans=0;
		ans=matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];		//anoter base condition with the matrix as 2*2
		return ans;
	}

	else{
		float ans=0;
		int sign=-1;														//sign variable keeps a track of the sign, alternating everytime
		float temp[N][N];
		int col=0;
		for (int i=0;i<x;i++){
			int r=0;
			float elem = matrix[0][i];								//the element whose co-factor we are calculating
			for (int j=0;j<x;j++){
				int c=0;
				if (j==0){
					continue;
				}
				for (int k=0;k<x;k++){
					if (k==i){
						continue;
					}
					temp[r][c]=matrix[j][k];
					c++;
				}
				r++;
			}
			sign=sign*-1;
			ans=ans+(sign*elem*determinant(temp,x-1));			//adding the elements by multiplying with the cofactor keeping a check on the sign too
		}
		return ans;
	}

}


void main() {
	int n;	
	scanf ("%d",&n);														//taking the size of the matrix as input
	N=n-1;																	//size of the temporary matrix to be passed in the function 
	float matrix[n][n];														//matrix to store the input
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			// printf("%s\n","input pls" );
			scanf("%f",&matrix[i][j]);
		}
	}

	float cofactor[n][n];													//cofactor matrix which has the cofactors of each element at the same place
	int sign=1;
	float temp[n-1][n-1];

	int r=0;
	int c=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			r=0;c=0;
			for (int k=0;k<n;k++){
				c=0;	
				if (k==i){													//copying the elements from the matrix to a temporary matrix excluding the row and coulmn of the element currently under consideration
					continue;
				}
				for (int l=0;l<n;l++){
					if (l==j){
						continue;
					}
					temp[r][c]=matrix[k][l];
					// printf("%f ",temp[r][c] );
					c++;
				}	
				// printf("\n");
				r++;
			}
			if ((i+j)%2==1){
				sign=-1;
			}
			cofactor[i][j]=determinant(temp,n-1)*sign;				//storing the elements in the cofactor matrix along with the sign
			sign=1;
			// for (int y=0;y<n-1;y++){
			// 	for (int z=0;z<n-1;z++){
			// 		printf("%f ",temp[y][z] );
			// 	}
			// 	printf("\n");
			// }

		}


	}

			
	
	float transpose[n][n];
	int sign1=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			// printf("%f%s",cofactor[i][j]," ");
			// if ((i+j)%2==1){										//interchanging the rows and columns of the co-factor matrix to get the adjugate matrix
			// 	sign1=-1;
			// }
			transpose[j][i]=cofactor[i][j]*(sign1);
			sign1=1;
		}
		// printf("\n");
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%g%s",transpose[i][j]," ");						//a loop to print the adjugate matrix
			// transpose[j][i]=cofactor[i][j];
		}
		printf("\n");
	}	
}

// for (int oo=0;oo<n-1;oo++){
			// 	for (int o=0;o<n-1;o++){
			// 		printf("%f",temp[oo][o] );
			// }
			// printf("\n");
			// }
		// printf("%s\n","temp printed" );

		
	
	// for (int i=0;i<n;i++){													//copying the elements from the matrix to a temporary matrix excluding the row and coulmn of the element currently under consideration
	// 	for (int j=0;j<n;j++){
	// 		int r=0;
	// 		for (int k=0;k<n;k++){
	// 			int c=0;
	// 			if (k==i){
	// 				continue;
	// 			}
	// 			for (int h=0;h<n;h++){
	// 				if (h==j){
	// 					continue;
	// 				}
	// 				temp[r][c]=matrix[k][h];
	// 				c++;
	// 			}
	// 			r++;
	// 		}
	// 	for (int o=0;o<n-1;o++){
	// 		for (int oo=0;oo<n-1;oo++){
	// 			printf("%f",temp[i][j] );
	// 		}
	// 		printf("\n");
	// 	}
		// printf("%s\n","temp printed" );
		// // printf("%f\n", determinant(temp,i,j,n-1));
		// cofactor[i][j]=sign*determinant(temp,n-1);				//calculating the determinant of the temporary matrix and storing it in the cofactor matrix
		// }
		