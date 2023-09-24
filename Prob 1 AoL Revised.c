#include <stdio.h>

int main()
{
	int N;
	do //validating input, array size must be greater than 2
	{
		printf("Matrix Size (N): ");
		scanf("%d", &N);
		getchar();
		
		if(N <= 2)
		{
			printf("Invalid! Note: (N > 2)\n");
		}
		printf("\n");
	}
	while(N <= 2);
	
	int array[N][N];
	int i, j;
	printf("Insert matrix's elements:\n");
	for(i = 0; i < N; i++) //inputting array's elements
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	
	int C; //calculating centroid coordinate(C)
	if(N % 2 == 0) //if size is an even number
	{
		C = N/2; //formula: (N / 2) + 1 - 1
	}
	else //if size is an odd number
	{
		C = ((N + 1)/2) - 1; //subtract by 1 because coordinate start from 0,0 at the top lestmost matrix
	}
	printf("Centroid at (%d,%d)\n", C, C);
	int centroid = array[C][C]; //assigning centroid value to be compared afterward
	//printf("Centroid value: %d\n", centroid);
	
	int count = 0;
	int rekamBaris[N*N + 1], rekamKolom[N*N + 1];
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(array[i][j] == centroid && (i != C || j != C))
			{
				rekamBaris[count] = i;
				rekamKolom[count] = j;
				count++;
				//printf("Same value coordinate(s): %d,%d\n", i, j);
			}
		}
	}
	//printf("Amount of all same element: %d\n", count);
	
	printf("\nNearest same elements is at: ");
	if(count == 0) //if there is no same value detected, then no nearest element available
	{
		printf("no nearest element.\n");
	}
	else
	{
		//oversimplified distance math formula between 2 distinct points
		int rekamJarak[N*N + 1];
		for(i = 0; i < count; i++)
		{
			int A = C - rekamBaris[i];
			int B = C - rekamKolom[i];
		
			int jarak = A*A + B*B; //before 'root square' value
			rekamJarak[i] = jarak; //save the value with the same order relative to the same value coordinate(s)
		}
	
		int smallest = rekamJarak[0];
		for(i = 0; i < count; i++) //search for the smallest value (closest same value point)
		{
			if(rekamJarak[i] < smallest)
			{
				smallest = rekamJarak[i];
			}
		}
		
		for(i = 0; i < count; i++)
		{
			if(rekamJarak[i] == smallest) //print the coordinate(s) that correspond to the closest distance
			{
				printf("(%d,%d) ", rekamBaris[i], rekamKolom[i]);
			}
		}
	}
	return 0;
}
