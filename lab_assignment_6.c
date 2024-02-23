/*Daniel Thompson*/
#include <stdio.h>
# include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	//check if low is greater that high
	if(low > high){
		return -1;
	}

	//a variable that stores the mid 
	int mid = (low + high)/2;

	// check if value is greater than the value at index mid and increment mid and assign it to low
	if( value > numbers[mid]){
		low = mid +1;
		return search(numbers, low,high, value);
	}

	// check if value is less than the value at index mid and decrement mid and assign it to high
	else if(value < numbers[mid]){
		high = mid - 1;
		return search(numbers, low, high, value);
	}

	// check if value is equal the value at index mid 
	else if(value == numbers[mid]){
			return mid;
	}

	// return if not found
	else{
		return -1;
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}