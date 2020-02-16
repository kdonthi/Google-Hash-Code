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

	FILE *fileobject = fopen("a_example.in", "r");
	fscanf(fileobject, "%lu", &maxslices);
	fscanf(fileobject, "%lu", &pizzatypes);

	//pizzatypes = 10; //we need the amount, if it is not an array of chars XD
	long *pizzaslices = malloc(sizeof(long) * pizzatypes);
	long j;
	long holdpizzaslices;

	j = 0;
	holdpizzaslices = 0;
	while (j < pizzatypes)
	{
		fscanf(fileobject, "%lu", &holdpizzaslices);
		pizzaslices[j] = holdpizzaslices;
		j++;
	}

	j = 0;
	while (j < pizzatypes)
	{
		printf("%lu", pizzaslices[j]);
		j++;
	}
	/*pizzaslices[0] = 4;
	pizzaslices[1] = 14;
	pizzaslices[2] = 15;
	pizzaslices[3] = 18;
	pizzaslices[4] = 29;
	pizzaslices[5] = 32;
	pizzaslices[6] = 36;
	pizzaslices[7] = 82;
	pizzaslices[8] = 95;
	pizzaslices[9] = 95;*/
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
	long max = 0;
	long maxindex = -1;
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
	FILE *towrite = fopen("writeto.txt", "w");
	fprintf(towrite, "%lu", max);
	fprintf(towrite, "\n");
	while (i <= maxindex + 1)
	{
		fprintf(towrite,"%lu ", answers[maxindex][i]);
		i++;
	}
	printf("\n");
}




