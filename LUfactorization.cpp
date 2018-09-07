#include <stdio.h>
#include <math.h>

//Gaussian elimination with partial pivot//

int main()
{
	double temp[20][20]={0}, t[20][20]={0}, variables[20]={0}, L[20][20]={0}, identidad[20][20]={0};
	double vect[20]={0}, vect2[20]={0};
	double temp1=0.0, temp2=0.0, temp3=0.0, temp4=0.0, temp5=0.0, suma=0.0, determinante=1.0;
	int i, j, k, l, m, n, o, p, q, r, fila=0, col=0, filycol, coltotal;
    int vec;

	for(i=0;i<20;i++)
		identidad[i][i]=1;
	//Instructions for the user//
	
	printf("Enter the value of rows and columns of the square matrix: ");
	scanf("%d",&filycol);
	printf("\nEnter the values of the matrix:");
	for(i=0;i<filycol;i++)
	{
		for(j=0;j<filycol;j++)
		{
			scanf("%lf",&temp[i][j]);
		}
	}
	
	printf("\nEnter the vector values: ");
	for(j=0;j<filycol;j++)
	{
		scanf("%lf",&temp[j][filycol]);
	}
	

	coltotal=filycol+1;

	//The matrix is shown//
	printf("\nMatriz:\n"); 
	for(i=0;i<filycol;i++)
	{
		for(j=0;j<coltotal;j++)
		{
			printf("  %.0f  ",temp[i][j]);
		}
		printf("\n");
	}

	//A complete loop is made to find the diagonal of the matrix//
	for(i=0;i<filycol;i++)
	{
		fila=i;
		temp3=temp[i][i];

		//We use this loop to find the greatest value to place it in the column//
				for(n=i;n<filycol;n++)
				{
					if(abs(temp[n][i])>abs(temp3))
					{
						temp3=temp[n][i];
						fila=n;
					}
				}

		//This loop performs the row change//
		for(o=0;o<coltotal;o++)
		{
			vect[o]=temp[fila][o];
			temp[fila][o]=temp[i][o];
			temp[i][o]=vect[o];
		}
		for(o=0;o<coltotal;o++)
		{
			vect[o]=L[fila][o];
			L[fila][o]=L[i][o];
			L[i][o]=vect[o];
		}

		//This conditional verifies that the variables are independent//
		if(temp[i][i]!=0)
		{
			//Here the reduction of the matrix is carried out//
			temp1=temp[i][i];

			for(p=i;p<filycol;p++)
				L[p][i]=temp[p][i]/temp1;

			for(m=0;m<coltotal;m++)
				t[i][m]= temp[i][m]/temp1;

			for(l=0;l<filycol;l++)
			{
				if(l>i)
				{
					temp2=temp[l][i];
					for(k=0;k<coltotal;k++)
					{
						temp[l][k]= temp[l][k]-(t[i][k]*temp2);
					}
				}

			}

		}
	}

	// The U matrix is shown//
	printf("\nMatrix U: \n");

	for(i=0;i<filycol;i++)
	{
		for(j=0;j<coltotal-1;j++)
		{
			printf("%.3f     ",temp[i][j]);
		}
		printf("\n");
	}
	
	// The L matrix is shown//
	printf("\nMatrix L: \n");

	for(i=0;i<filycol;i++)
	{
		for(j=0;j<coltotal-1;j++)
		{
			printf("%.3f     ",L[i][j]);
		}
		printf("\n");
	}
	
	//Finally we obtain the result through a progressive substitution//

	variables[filycol-1]=temp[filycol-1][filycol]/temp[filycol-1][filycol-1];

	for(i=filycol-2;i>=0;i--)
	{
		for(j=filycol-1;j>=0;j--)
		{
			suma=suma+temp[i][j]*variables[j];
		}	
		variables[i]=(temp[i][filycol]-suma)/temp[i][i];
	    suma=0;
	}

	for(k=1;k<=filycol;k++)
	{
	printf(" \nThe value of the variable %d is: %f \n",k,variables[k-1]);
	}

	getchar();
	getchar();

	return 0;
}