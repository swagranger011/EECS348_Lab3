/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: abhisht01
 */
#include <stdio.h>
#include <stdlib.h>

void highToLow(float mySales[12], char myMonth[11][10])
{
	char u;
	float a;

	printf("\nSales Report (Highest to Lowest)\n Month \t Sales \n\n");

	for (int i = 0; i < 12; i++)
	{
		for (int j = i; j < 12; j++)
		{
			if (mySales[i] < mySales[j])
			{
				for (int k = 0; k < 10; k++)
				{
					u = myMonth[i][k];
					myMonth[i][k] = myMonth[j][k];
					myMonth[j][k] = u;
				}
				
				a = mySales[i];
				mySales[i] = mySales[j];
				mySales[j] = a;
			}

		}

		printf("%-12s \t $ %5.2f \n", myMonth[i], mySales[i]);
	}
}

void sixMonthAvg(float mySales[12], char myMonth[11][10])
{
	float sixMonthTotal, average;
	printf("\nSix-Month Moving Average Report:\n\n");

	for (int i = 0; i < 7; i++)
	{
		sixMonthTotal = 0.0;
		for(int j = 0; j < 6; j++)
		{
			sixMonthTotal += mySales[i+j];
			average = sixMonthTotal / 6.0;
		}
		printf("%-12s\t - \t %-12s \t $ %5.2f \n", myMonth[i], myMonth[i+5], average);
	}
}

void minAndMax(float mySales[12], char myMonth[11][10])
{
	float min = mySales[0], max = mySales[0], total; //More variables

	for(int i = 0; i < 12; i++)
	{
		if (mySales[i] < min) //Sets the min
		{
			min = mySales[i];
		}

		if (mySales[i] > max) // Sets the max
		{
			max = mySales[i];
		}

		total += mySales[i];
	}
	printf("\nSales summary:\n");
	printf("Minimum sales: $ %5.2f\t", min);
	printf("(%s)\n", myMonth[0]);
	printf("Maximum sales: $ %5.2f\t", max);
	printf("(%s)\n", myMonth[11]);
	printf("Average sales: $ %5.2f\n", total/12.0);
}

void sales(float mySales[12], char myMonth[11][10])
{
	printf("Monthly sales report for 2022: \n\n Month\t\t Sales\n\n");

	for (int i = 0; i < 12; i++)
	{
		printf("%-12s\t", myMonth[i]);
		printf("$%5.2f \n", mySales[i]);
	}
}

int main()
{
	FILE *input;
	FILE *months;
	//reads the files
	input = fopen("input.txt", "r");
	months = fopen("months.txt", "r");
	//Variables
	char myMonth[11][10];
	float mySales[12];

	if (input == NULL)
	{
		printf("Error reading File\n");
		exit(0);
	}
	else if (months == NULL)
	{
		printf("Error reading File\n");
		exit(0);
	}
	
	for (int i = 0; i < 12; i++)
	{
		fscanf(input, "%f", &mySales[i]);
		fscanf(months, "%s", &myMonth[i]);
	}	
	

sales(mySales, myMonth);
minAndMax(mySales, myMonth);
sixMonthAvg(mySales, myMonth);
highToLow(mySales, myMonth);


	fclose(input);
	fclose(months);
	return 0;
}
