
//Written by Hugh Mc Keeney 


//using dynamic memory allocation to create arrays, prompting the user for the type of array (either int or float), the size of the array,
//the contents of the array and then asking them if they want to add more to the array. After all values have been entered,
//the program calculates the average of the contents of the array

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int type, quantity, *array, i, additional, count=0;
	float *arrayf;
	double average, sum = 0;
	
	
	printf("If you wish to create an array of integers enter 1, if you wish to create an array of floats enter 2\n");
	scanf("%d", &type);
	
	// if the user entered 1 they wish to create an array of integers
	if(type == 1)
	{
		printf("Enter the number of integers you wish to enter in your array\n");
		scanf("%d", &quantity);
		array =(int*)calloc(quantity, sizeof(int)); //using calloc to create the array I need of the desired size
		
		if(array == NULL)
		{
			printf("cannot be created\n"); // troubleshooting 
		}
		else
		{
			//scanning into the array
			printf("Enter the elements of your array\n");
			for( i=0; i<quantity; i++)
			{
				scanf("%d",&*(array+i));
				count++; //count is used to keep track of where I am for when I want to add more elements later on
			}
			
			//printing out the elements entered 
			printf("The elements of your array are\n");
			for(i = 0; i<quantity; i++)
			{
				printf("%d\n", *(array+i));
				sum += *(array+i);	
			}
			
			//calculating the average of the numbers entered 
			average = sum / quantity;
			printf("The average of the elements is\n");
			printf("%.2lf\n", average);
		}
		
		//asking the user if they wish to enter more elements
		printf("Do you want to enter more elements, type 1 for yes, 2 for no\n");
		scanf("%d", &type);
		
		// if the user enters 1 they wish to add more elements 
		if(type == 1)
		{
			printf("How many more elements do you wish to enter?\n");
			scanf("%d", &additional);
			quantity += additional; //calculating the new size of the array 
			array =(int*)realloc(array, quantity); //adding the required amount of extra space into the array
			
			
			printf("Enter the elements of your array\n");
			for( i = count; i<quantity; i++) //count is used here so the computer knows where to start entering elements into the array again
											//the rest of this is the same as above
			{
				scanf("%d",&*(array+i));
				sum += *(array+i);	
			}
			printf("The elements of your array are\n");
			for(i = 0; i<quantity; i++)
			{
				printf("%d\n", *(array+i));
			}
			average = sum / quantity;
			printf("The average of the elements is\n");
			printf("%.2lf\n", average);
		}
			
	}
	
	//if the user did not enter 1 the wanted to create an array of floats 
	else
	{
		//this is the same as the integer version above 
		printf("Enter the number of floats you wish to enter in your array\n");
		scanf("%d", &quantity);
		arrayf =(float*)calloc(quantity, sizeof(int));
		
		if(arrayf == NULL)
		{
			printf("cannot be created\n");
		}
		else
		{
			printf("Enter the elements of your array\n");
			for( i=0; i<quantity; i++)
			{
				scanf("%f",&*(arrayf+i));
				count++;
			}
			printf("The elements of your array are\n");
			for(i = 0; i<quantity; i++)
			{
				printf("%f\n", *(arrayf+i));
				sum += *(arrayf+i);
			}
			average = sum / quantity;
			printf("The average of the elements is\n");
			printf("%.2lf\n", average);
		}
		
		
		printf("Do you want to enter more elements, type 1 for yes, 2 for no\n");
		scanf("%d", &type);
		if(type == 1)
		{
			printf("How many more elements do you wish to enter?\n");
			scanf("%d", &additional);
			quantity += additional;
			arrayf =(float*)realloc(arrayf, quantity);
			
			
			printf("Enter the elements of your array\n");
			for( i = count; i<quantity; i++)
			{
				scanf("%f",&*(arrayf+i));
				sum += *(arrayf+i);	
			}
			printf("The elements of your array are\n");
			for(i = 0; i<quantity; i++)
			{
				printf("%f\n", *(arrayf+i));
			}
			average = sum / quantity;
			printf("The average of the elements is\n");
			printf("%.2lf\n", average);
		}
	}
	return 0;
}
	
		