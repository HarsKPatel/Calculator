#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "calculator.h"

Calculator* create_calculator(double (**mathOpr)(int,int),int k)
{
	Calculator* c1=malloc(sizeof(Calculator));
	c1->operationCount=k;
	c1->dataLength=100;
	c1->operations=mathOpr;

	return c1;
}
bool load_calculator_data(Calculator* c1,char* k)
{
	FILE *fptr;
	fptr=fopen(k,"r");
	c1->data=malloc(sizeof(int*)*c1->dataLength);

	if (fptr==NULL)
	{
		return false;
	}
        for(int i=0;i<c1->dataLength;i++)
	{
		c1->data[i]=malloc(sizeof(int)*3);
	}
	while(1)
	{
		if(feof(fptr))
		{
			break;
		}
		for(int i=0;i<c1->dataLength;i++)
		{
			fscanf(fptr,"%d %d %d",&c1->data[i][0],&c1->data[i][1],&c1->data[i][2]);
		}
	}
	return true;

}
void run_calculator(Calculator* c1)
{
	for(int i=0;i<c1->dataLength;i++)
	{
		printf("%0.5f\n",c1->operations[c1->data[i][0]](c1->data[i][1],c1->data[i][2]));
	}
}
bool destroy_calculator(Calculator* c1)
{
	if(c1==NULL)
	{
		return false;
	}
	free(c1->data);
	free(c1);
	return true;
}
double add_calculator(int a,int b)
{
	double add= (double)a+(double)b;
	return add;
}
double sub_calculator(int a,int b)
{
	double sub=(double)a-(double)b;
	return sub;
}
double mul_calculator(int a,int b)
{
	double mult=(double)a*(double)b;
	return mult;
}
double div_calculator(int a,int b)
{
	double div=(double)a/(double)b;
	return div;
}
double mod_calculator(int a,int b)
{
	double mod=a % b;
	return mod;
}

