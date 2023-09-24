#include <stdio.h>

int hitungZero(int size, int matrix[][size])
{
	int onoffon, count, k, l;
	int save = 0;
	for(k = 0; k < size; k++)
	{
		onoffon = 0, count = 0;
		for(l = 0; l < size; l++)
		{
			if(matrix[k][l] == 1)
			{
				onoffon++;
				//printf("onoff: %d\n", onoffon);
			}
			if(onoffon == 1 && matrix[k][l] == 0)
			{
				count++;
				//printf("Count: %d ", count);
			}
		}
		
		if(onoffon == 2)
		{
			save = save + count;
		}
	}
	return save;
}

int main()
{
	int N;
	printf("Matrix size: ");
	scanf("%d", &N);
	getchar();
	
	int array_one[N][N], array_two[N][N];
	int i, j;
	
	printf("Matrix 1:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &array_one[i][j]);
		}
	}
	int area_one = hitungZero(N, array_one);
	//printf("Area 1: %d\n", area_one);
	
	printf("\nMatrix 2:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &array_two[i][j]);
		}
	}
	int area_two = hitungZero(N, array_two);
	//printf("Area 2: %d\n", area_two);

	if(area_one == area_two)
	{
		printf("\nObject 1 and object 2 has the same size\n");
	}
	else if(area_one > area_two)
	{
		printf("\nObject 1 is bigger\n");
	}
	else
	{
		printf("\nObject 2 is bigger\n");
	}
	
	return 0;
}
