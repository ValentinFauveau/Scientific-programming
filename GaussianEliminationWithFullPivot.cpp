#include <stdio.h>
# include <math.h>
//Gaussian elimination with full pivot//

int main()
{
	double temp[20][20]={0};
	double vect[7]={0}, vect2[3]={0}, vect3[4]={0};
	double temp1=0.0, temp2=0.0, temp3=0.0, temp4=0.0;
	int i, j, k, l, m, n, o, p, q, r, fila=0, col=0, filycol, coltotal;
	int variables[20]={0};
	int vec;

	//Instructions for the user//
	
	printf("Enter the value of rows and columns of the square matrix");
	scanf("%d",&filycol);
	printf("\nEnter the number of vectors you want to solve: ");
	scanf("%d",&vec);
	printf("\nEnter the values of the matrix:");
	for(i=0;i<filycol;i++)
	{
		for(j=0;j<filycol;j++)
		{
			scanf("%lf",&temp[i][j]);
		}
	}
	for(i=0;i<vec;i++)
	{
	printf("\nEnter the vector values %d:", i);
	for(j=0;j<filycol;j++)
	{
		scanf("%lf",&temp[j][i+filycol]);
	}
	}
	for(i=0;i<filycol;i++)
		{
			temp[i][filycol+vec+i]=1.0;
		}

	for(i=0;i<filycol;i++)
	{
		variables[i]=1+i;
	}

	coltotal=(filycol+vec+filycol);

	//The matrix is shown//
	
	for(i=0;i<filycol;i++)
	{
		for(j=0;j<coltotal;j++)
		{
			printf(" %.0f ",temp[i][j]);
		}
		printf("\n");
	}

	//A complete tour is made to find the diagonal of the matrix//
	for(i=0;i<filycol;i++)
	{
		        fila=i;
		        col=i;
				temp3=temp[i][i];
				
				//We use this loop to find the largest absolute value to place it on the diagonal of the matrix//
				for(n=i;n<filycol;n++)
				{
					for(p=i;p<filycol;p++)
					{
					if(abs(temp[n][p])>abs(temp3))
					{
						temp3=temp[n][p];
						fila=n;
						col=p;
					}
					}
				}

						//This cycle performs the row change//
						for(o=0;o<coltotal;o++)
						{
							vect[o]=temp[fila][o];
							temp[fila][o]=temp[i][o];
							temp[i][o]=vect[o];
						}

						//This cycle performs the column changes and row changes of the variables//
						for(q=0;q<filycol;q++)
						{
							vect2[q]=temp[q][col];
							temp[q][col]=temp[q][i];
							temp[q][i]=vect2[q];
						}
						temp4=variables[i];
						variables[i]=col+1;
						variables[col]=temp4;

	//This conditional verifies that the variables are independent//
		if(temp[i][i]!=0)
		{
	//Here the reduction of the matrix is carried out//
				temp1=temp[i][i];
				for(m=0;m<coltotal;m++)
				temp[i][m]= temp[i][m]/temp1;
				
				for(l=0;l<filycol;l++)
				{
					if(l!=i)
					{
						temp2=temp[l][i];
					for(k=0;k<coltotal;k++)
					{
						temp[l][k]= temp[l][k]-(temp[i][k]*temp2);
					}
					}
				}

	}
	}

	// The reduced matrix, the results of the vectors and the identity matrix are shown//
	printf("\n");

	for(i=0;i<filycol;i++)
	{
		for(j=0;j<coltotal;j++)
		{
			printf("%.3f    ",temp[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<vec;i++)
	{
		printf("\n\nFor vector %d: ", i+1);
		for(j=0; j<filycol;j++)
		{
	    printf("\nThe result of the variable x%d is: %.3f", variables[j], temp[j][filycol+i]);
		}
	}

	getchar();
	getchar();

	return 0;
}