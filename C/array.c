#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int arrSize = 1;
    int *arr = (int *) calloc(arrSize, sizeof(int));

    bool isRunning = true;

    while (isRunning)
    {
        int input = 0;

        printf(
            "DynarC (Dynamic Array C)\n"
        );

        printf("\n\nArray length: %d\n", arrSize);
        printf("====================\n");
        for (int i = 0; i < arrSize; i++)
            printf("[%d] %p | %d\n", i, (arr + i), *(arr + i));

        printf("====================");
        printf(
            "\nCommands:\n"
            "\t0\tExit\n"
            "\t1\tAdd number\n"
            "\t2\tIncrease size\n"
            "\t3\tDecrease size\n"
            "\t4\tUpdate at index\n"
            "\t5\tDelete at index\n"
            "\t6\tInsert at index\n"
            ">> "
        );
        scanf_s("%d", &input);

        switch (input)
        {
        case 0: isRunning = false; break;
        case 1:
            printf("Value: ");
            scanf_s("%d", &input);

            *(arr + (arrSize - 1)) = input;

            break;
        case 2:
            printf("Increase size: ");
            scanf_s("%d", &input);

            arrSize += input;
            arr = (int *) realloc(arr, sizeof(int) * arrSize);
            break;
        case 3:
            printf("Decrease size: ");
            scanf_s("%d", &input);

            if (input >= arrSize)
            {
                printf("Invalid size\n");
                break;
            }

            for (int i = (arrSize - input); i < arrSize; i++)
                *(arr + i) = 0;

            arrSize -= input;
            arr = (int *) realloc(arr, sizeof(int) * arrSize);

            break;
        case 4:
            int index;

            printf("Index: ");
            scanf_s("%d", &index);

            if ((index >= arrSize) || (index < 0))
            {
                printf("Invalid index\n");
                break;
            }

            printf("Value: ");
            scanf_s("%d", &input);

            *(arr + index) = input;
            break;
        case 5:
            printf("Index: ");
            scanf_s("%d", &input);

            if ((index >= arrSize) || (index < 0))
            {
                printf("Invalid index\n");
                break;
            }

            for (int i = input; i < (arrSize - 1); i++)
                memmove_s(arr + i, sizeof(arr + i), arr + (i + 1), sizeof(arr + (i - 1)));

            arrSize--;
            arr = (int *) realloc(arr, sizeof(int) * arrSize);

            break;
        case 6:
            printf("Index: ");
            scanf_s("%d", &input);

            if ((index >= arrSize) || (index < 0))
            {
                printf("Invalid index\n");
                break;
            }

            arrSize++;
            arr = (int *) realloc(arr, sizeof(int) * arrSize);

            for (int i = (arrSize - 1); i >= input; i--)
                memmove_s(arr + i, sizeof(arr + i), arr + (i - 1), sizeof(arr + (i - 1)));

            *(arr + input) = 0;

            break;
        }
    }
    
    free(arr);
    arr = NULL;
    
    return 0;
}
