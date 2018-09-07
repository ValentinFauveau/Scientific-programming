#include<stdio.h>

int f_MatTrans(int varint[10][10], int a, int b);
int f_MatScalarSum(int varint[10][10], int a, int b, int escalar);
int f_MatScalarDiff(int varint[10][10], int a, int b, int escalar);
int f_MatScalarProd(int varint[10][10], int a, int b, int escalar);
int f_MatScalarDiv(int varint[10][10], int a, int b, int escalar);
void f_MatElemProd(int varint[10][10], int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);
void f_MatElemDiv(int varint[10][10], int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);
int f_MatDeterm(int varint[10][10]);
void f_MatInv(int varint[10][10],float varint3[10][10], int a, int b);
void f_MatSum(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);
void f_MatDiff(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);
void f_MatProd(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);
void f_MatDiv(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d);

int main()
{

	int i, j, i2, j2, k, l, escalar, escalar2, escalar3, escalar4, prueba;
	int matriz[10][10];
	int mat2[10][10];
	float matResult[10][10];

	printf("Enter the number of rows:");

	scanf("%d",&i);

	printf("\n\nEnter the number of columns:");

	scanf("%d",&j);

	printf("\n\nEnter the values of the matrix:");

	for (k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			scanf("%d",&matriz[k][l]);
		}
	}

	printf("\n");

	printf("\nMatrix:\n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}
	
	f_MatTrans(matriz, i,j);

	printf("\nMatrix transpose\n");

	for(k=0;k<j;k++)
	{
		for(l=0;l<i;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Enter the scalar that you want to add to all the elements of the matrix:");
	scanf("%d",&escalar);

	f_MatScalarSum(matriz, i, j, escalar);

	printf("\nNew matrix %d:\n", escalar);

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Enter the scalar that you want to subtract from all the elements of the matrix:");
	scanf("%d",&escalar2);

	f_MatScalarDiff(matriz, i, j, escalar2);

	printf("\nNew matrix %d:\n", escalar2);

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Enter the scalar that you want to multiply to all the elements of the matrix:");
	scanf("%d",&escalar3);

	f_MatScalarProd(matriz, i, j, escalar3);

	printf("\nNew matrix %d:\n", escalar3);

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Enter the scalar that you want to divide to all the elements of the matrix:");
	scanf("%d",&escalar4);

	f_MatScalarDiv(matriz, i, j, escalar4);

	printf("\nNew matrix %d:\n", escalar4);

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}
	
	printf("\n\nEnter the number of rows of the second matrix:");

	scanf("%d",&i2);

	printf("\n\nEnter the number of columns in the second matrix:");

	scanf("%d",&j2);

	printf("\n\nEnter the values of the second matrix:");

	for (k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			scanf("%d",&mat2[k][l]);
		}
	}

	printf("\nMatriz 2:\n");

	for(k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			printf(" %d ",mat2[k][l]);
		}
		printf("\n");
	}
	
	printf("\nMultiplication of matrices element-wise:\n");
	printf("\nMatrix 1: \n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\nMatrix 2: \n");

	for(k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			printf(" %d ",mat2[k][l]);
		}
		printf("\n");
	}

	f_MatElemProd(matriz, mat2, matResult, i, j, i2, j2);

	printf("\n\nNew matrix:\n");

	if(matResult[0][0]!=0.1)
	{
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %.0f ",matResult[k][l]);
		}
		printf("\n");
	}
	}

	printf("\n\nDivision of matrices element-wise:\n");
	printf("\nMatrix 1: \n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\nMatrix 2: \n");

	for(k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			printf(" %d ",mat2[k][l]);
		}
		printf("\n");
	}

	f_MatElemDiv(matriz, mat2, matResult, i, j, i2, j2);

	printf("\n\nNew matrix:\n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			
			printf(" %.2f ",matResult[k][l]);
		}
		printf("\n");
	}

		prueba=f_MatDeterm(matriz);

	printf("\n\nDeterminant of matrix 1: %d\n\n", prueba);

	f_MatInv(matriz, matResult, i, j);

	printf("\n\nInverse matrix:\n", prueba);

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %.2f ",matResult[k][l]);
		}
		printf("\n");
	}

	printf("\n\nMultiplication of matrices:\n");
	printf("\nMatrix 1: \n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\nMatrix 2: \n");

	for(k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			printf(" %d ",mat2[k][l]);
		}
		printf("\n");
	}

	f_MatProd(matriz, mat2, matResult, i, j, i2, j2);

	printf("\n\nNew matrix:\n");
	if(matResult[0][0]!=0.1)
	{
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %.0f ",matResult[k][l]);
		}
		printf("\n");
	}
	}

	printf("\nDivision of matrices:\n");
	printf("\nMatrix 1: \n");

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %d ",matriz[k][l]);
		}
		printf("\n");
	}

	printf("\nMatrix 2: \n");

	for(k=0;k<i2;k++)
	{
		for(l=0;l<j2;l++)
		{
			printf(" %d ",mat2[k][l]);
		}
		printf("\n");
	}

	f_MatDiv(matriz, mat2, matResult, i, j, i2, j2);

	printf("\n\nNew matrix:\n");
	if(matResult[0][0]!=0.1)
	{
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf(" %.02f ",matResult[k][l]);
		}
		printf("\n");
	}
	}

	getchar();
	getchar();
	getchar();

	return 0;
}

int f_MatTrans(int varint[10][10], int a, int b)
{

	int i, j;
	int mat[10][10];

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			mat[j][i]=*(varint[i]+j);
		}
	}
	for (i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			*(varint[i]+j)=mat[i][j];
		}
	}
	return 0;
}

int f_MatScalarSum(int varint[10][10], int a, int b, int escalar)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			*(varint[i]+j)=*(varint[i]+j)+escalar;
		}
	}
	return 0;
}

int f_MatScalarDiff(int varint[10][10], int a, int b, int escalar)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			*(varint[i]+j)=*(varint[i]+j)-escalar;
		}
	}
	return 0;
}

int f_MatScalarProd(int varint[10][10], int a, int b, int escalar)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			*(varint[i]+j)=*(varint[i]+j)*escalar;
		}
	}
	return 0;
}

int f_MatScalarDiv(int varint[10][10], int a, int b, int escalar)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			*(varint[i]+j)=*(varint[i]+j)/escalar;
		}
	}
	return 0;
}

void f_MatElemProd(int varint[10][10], int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			varint3[i][j]=(float)*(varint[i]+j)*(float)(*(varint2[i]+j));
		}
	}
	if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]= 0.1;
	}
}

void f_MatElemDiv(int varint[10][10], int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if((*(varint2[i]+j))!=0)
			{
				varint3[i][j]=(float)varint[i][j]/(float)varint2[i][j];
			}
			else *(varint[i]+j)=0;
		}
	}

	if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]=0;
	}
}

int f_MatDeterm(int varint[10][10])
{
	int temp1, temp2, temp3, temp4, temp5, temp6;
	int determinante;

	         temp1=(*(varint[0]))*(*(varint[1]+1))*(*(varint[2]+2));
             temp2=(*(varint[0]+1))*(*(varint[1]+2))*(*(varint[2]));
             temp3=(*(varint[0]+2))*(*(varint[1]))*(*(varint[2]+1));
             temp4=(*(varint[0]+2))*(*(varint[1]+1))*(*(varint[2]));
             temp5=(*(varint[0]+1))*(*(varint[1]))*(*(varint[2]+2));
             temp6=(*(varint[0]))*(*(varint[1]+2))*(*(varint[2]+2));


	determinante=temp1+temp2+temp3-temp4-temp5-temp6;

	return determinante;
}

void f_MatInv(int varint[10][10],float varint3[10][10], int a, int b)
{
	int i, j, mat[10][10];
	float temp[10][10];

	int temp1, temp2, temp3, temp4, temp5, temp6;
	float determinante;

	temp[0][0]=varint[1][1]*varint[2][2]-varint[1][2]*varint[2][1];
	temp[0][1]=-(varint[1][0]*varint[2][2]-varint[1][2]*varint[2][0]);
	temp[0][2]=varint[1][0]*varint[2][1]-varint[1][1]*varint[2][0];
	temp[1][0]=-(varint[0][1]*varint[2][2]-varint[0][2]*varint[2][1]);
	temp[1][1]=varint[0][0]*varint[2][2]-varint[0][2]*varint[2][0];
	temp[1][2]=-(varint[0][0]*varint[2][1]-varint[0][1]*varint[2][0]);
	temp[2][0]=varint[0][1]*varint[1][2]-varint[0][2]*varint[1][1];
	temp[2][1]=-(varint[0][0]*varint[1][2]-varint[0][2]*varint[1][0]);
	temp[2][2]=varint[0][0]*varint[1][1]-varint[0][1]*varint[1][0];

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			mat[j][i]=temp[i][j];
		}
	}
	for (i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			temp[i][j]=mat[i][j];
		}
	}
	
	         temp1=varint[0][0]*varint[1][1]*varint[2][2];
             temp2=varint[0][1]*varint[1][2]*varint[2][0];
             temp3=varint[0][2]*varint[1][0]*varint[2][1];
             temp4=varint[0][2]*varint[1][1]*varint[2][0];
             temp5=varint[0][1]*varint[1][0]*varint[2][2];
             temp6=varint[0][0]*varint[1][2]*varint[2][2];

	determinante=temp1+temp2+temp3-temp4-temp5-temp6;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			varint3[i][j]=(float)(temp[i][j]/determinante);
		}
	}

}

void f_MatSum(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			varint3[i][j]=(float)*(varint[i]+j)+(float)(*(varint2[i]+j));
		}
	}
	if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]= 0.1;
	}

}

void f_MatDiff(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j;

	for (i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			varint3[i][j]=(float)*(varint[i]+j)-(float)(*(varint2[i]+j));
		}
	}
	if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]= 0.1;
	}

}

void f_MatProd(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j, k, l, temp;

	temp=0;

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			temp=0;
			for(k=0;k<a;k++)
			{
					temp=temp+varint[i][k]*varint2[k][j];
			}
			varint3[i][j]=(float)temp;
		}
	}

		if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]= 0.1;
	}
}

void f_MatDiv(int varint[10][10],int varint2[10][10], float varint3[10][10], int a, int b, int c, int d)
{
	int i, j, k, l;
	float temp;

	temp=0;
	

	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			temp=0;
			for(k=0;k<a;k++)
			{
				temp=temp+varint[i][k]/varint2[k][j];
			}
			varint3[i][j]=temp;
		}
	}

		if(a!=c || b!=d)
	{
		printf("\n ERROR");
		varint3[0][0]= 0.1;
	}
}