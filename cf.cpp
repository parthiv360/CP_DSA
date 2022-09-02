#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

int i, j, coeff[10][10], n, fx[10], nmax, k;

float x[10];

printf("**Program to find solution of system of linear equation using Gauss Seidal Method**\n\n");

// Entering the number of equations

printf("Enter the number of equations:");

scanf("%d", &n);

// Entering the coefficients of the equations

for (i = 1; i <= n; i++)

{

    printf("Enter the coefficients of equation %d :", i);

    for (j = 1; j <= n; j++)

    {

        scanf("%d", &coeff[i][j]);
    }
}

printf("-------------------------------------------------------\n");

// Enter the value of f(x) equivalent to the equation

for (i = 1; i <= n; i++)
{

    printf("Enter the value of f(x) for equation %d :", i);

    scanf("%d", &fx[i]);
}

printf("-------------------------------------------------------\n");

// Entering the maximum number of iterations

printf("Enter the maximum number of iterations :");

scanf("%d", &nmax);

printf("\n");

printf("Iter\t");

for (i = 1; i <= n; i++)

{

    printf("  x%d\t\t", i);
}

printf("\n");

// Initialization of Gauss Seidal Method

// Calculating the value of the variables

for (i = 1; i <= n; i++)

{

    x[i] = 0;
}

for (k = 1; k <= nmax; k++)

{

    printf("%d\t", k);

    for (i = 1; i <= n; i++)
    {

        x[i] = fx[i];

        for (j = 1; j <= n; j++)
        {

            if (j != i)

            {

                x[i] = x[i] - coeff[i][j] * x[j];
            }
        }

        x[i] = x[i] / coeff[i][i];

        printf("%f\t", x[i]);
    }

    printf("\n");
}

// Printing the solution

printf("-------------------------------------------------------\n");

printf("The Solution of linear equations using Gauss Seidal Method\n ");

for (i = 1; i <= n; i++)
{

    printf("-------------------------------------------------------\n");

    printf("\t X%d = %f\n", i, x[i]);
}

getch();

return 0;
}