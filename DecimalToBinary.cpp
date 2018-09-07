#include<stdio.h>

int main ()
{
	double mod, result, binario, temp, c;
	int a,b;

	result = sizeof(mod);

	printf("\n Enter the number you want to transform to binary:");
	scanf("%d",&a);

	binario=0;
	result=-1;
	c=1;
	b=a;
	if(b%2==1)
	{
		binario=binario+1;
	}
	while(result!=0)
	{
	result=a/2;
	a=a/2;
	mod=a%2;
	c=c*10;
	binario=binario+ c*mod;
	}

	printf("\n From decimal to binary: %f", binario);

	getchar();
	getchar();

	return 0;
	}