#include <stdlib.h>
#include <stdio.h>

void ft_strcpy(long to[], long toindex, long from[], long fromindex, long number)
{
	long i;

	i = 0;
	while ((fromindex + i) < (fromindex + number))
		to[toindex++] = from[fromindex + i++];
}

int maxslicegenerator(long pizzastochoose,long numchosen, long startindex, long pizzaslices[], long pizzatypes, long maxslices, long **answers, long additionofslices, long *maxwesee, long possibleanswers[])
{
	int i;
	if (numchosen < pizzastochoose)
	{
		while (startindex < pizzatypes - (pizzastochoose - numchosen - 1))
		{
			if (numchosen == (pizzastochoose - 1))
			{
				if (additionofslices + pizzaslices[startindex] > *maxwesee && additionofslices + pizzaslices[startindex] <= maxslices) //if correct, write it in the answers array
				{
					*maxwesee = additionofslices + pizzaslices[startindex];
					answers[pizzastochoose - 1][0] = *maxwesee;
					possibleanswers[numchosen] = startindex; //only rewrite if the highest answer!
					i = 0;
					ft_strcpy(answers[pizzastochoose - 1], 1, possibleanswers, 0, pizzastochoose); //maybe possibleanswers[]? copies the next highest answer into answers!
					
				}
				
			}
			else
			{
				possibleanswers[numchosen] = startindex;
				maxslicegenerator(pizzastochoose, numchosen + 1, startindex + 1, pizzaslices, pizzatypes, maxslices, answers, additionofslices + pizzaslices[startindex], maxwesee, possibleanswers);
			}
			startindex++;
		}

			
	}
	else
		return (0);
	return (0);
}



int main()
{
	long pizzatypes;
	long maxslices;

	pizzatypes = 5; //we need the amount, if it is not an array of chars XD
	maxslices = 17;
	long *pizzaslices = malloc(sizeof(long) * pizzatypes);
	pizzaslices[0] = 2;
	pizzaslices[1] = 2;
	pizzaslices[2] = 3;
	pizzaslices[3] = 6;
	pizzaslices[4] = 10;
	long maximumpizzas;
	long i;
	long slices;

	i = 0;
	slices = 0;
	maximumpizzas = 0;
	while (1)
	{
		slices += pizzaslices[i];
		if (slices > maxslices)
			break;
		maximumpizzas += 1;
		i++;
	}  //works
	i = 0;
	long **answers = malloc(sizeof(long*) * (maximumpizzas));
	while (i < (maximumpizzas))
	{
		answers[i] = malloc(sizeof(long) * (maximumpizzas + 1));
		i++;
	}
	i = 0;
	long possibleanswers[maximumpizzas + 1];
	while (i < (maximumpizzas + 1))
	{
		possibleanswers[i] = 0;
		i++;
	} //works
	i = 1;
	while (i <= maximumpizzas)
	{
		long additionofslices = 0;
		long *maxwesee;
		long a = 0;
		maxwesee = &a;
		maxslicegenerator(i, 0, 0, pizzaslices, pizzatypes, maxslices, answers, additionofslices, maxwesee, possibleanswers);
		
		i++;
	}
	i = 0;
	int max = 0;
	int maxindex = -1;
	while (i < maximumpizzas)
	{
		if (answers[i][0] > max)
		{
			max = answers[i][0];
			maxindex = i;
		}
		i++;
	}
	i = 1;
	printf("Max number of slices: %i\n", max);
	printf("Max index: %i\n", maxindex);
	printf("Indices: ");
	while (i <= maxindex + 1)
	{
		printf("%li ",answers[maxindex][i]);
		i++;
	}
	printf("\n");
}




