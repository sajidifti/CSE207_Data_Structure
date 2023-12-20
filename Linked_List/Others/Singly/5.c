#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Insufficient Memory, Exiting program.....\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element %3d: ", i + 1);
        scanf("%d", (arr + i));
    }

    int m = DeleteDuplicate(n, arr);

    printf("Array elements are:");
    for (i = 0; i < m; i++)
        printf("%3d ", *(arr + i));

    return 0;
}

int DeleteDuplicate(int n, int *p)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(p + i) == *(p + j))
            {
                for (k = j; k < n; k++)
                {
                    *(p + k) = *(p + k + 1);
                }
                n--;
                j--;
            }
        }
    }
    return n;
}
