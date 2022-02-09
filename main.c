#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Napisz program, który dynamicznie alokuje tablicę (wielkość podawana jako argument programu) i wypełnia ją losowo
// generowanymi liczbami. W programie napisz funkcję, która oblicza iloczyn nieparzystych liczb naturalnych
// z wygenerowanej tablicy (tablica jako argument funkcji). Wygenerowaną talbicę oraz wynik funkcji wypisz
// na standardowe wyjście oraz do pliku (ścieżka do pliku jest podawana jako drugi argument programu)//

//tak post factum zdaje sobie sprawe, ze wystarczylo uzyc argc i argv, ale nie mam juz czasu ani sily na
// przerabianie tego programu, chociaż wiem, że nie działa poprawnie....

void printerMultiplier (int array[], const char *path) {
    int i, ratio;
    ratio = 1;
    char fileDataConverted[sizeof(*array)];
    char ratioValue[100];

    printf("\nSubsequent result of multiplication of uneven array elements: ");
    for (i = 0; i < sizeof(*array); i++) {
        if(array[i]%2 != 0) {
            ratio = ratio*array[i];
            printf("%d, ", ratio);
            sprintf(ratioValue, "%d", ratio);
            strcat(fileDataConverted, ratioValue);
        }
    }

    FILE * filePointer;

    // tutaj nie dziala przekazywanie sciezki
    filePointer = fopen(path, "w");

    fputs(fileDataConverted, filePointer);

    fclose(filePointer);
}

int main() {
    int* ptr;
    int arrayElementsNumber, i;
    char * filePath;
    filePath = "data/outputfile.txt";

    printf("Enter number of array elements:");
    scanf("%d", &arrayElementsNumber);
    printf("Entered number of elements: %d\n", arrayElementsNumber);

    ptr = (int*)malloc(arrayElementsNumber * sizeof(int));

    for (i = 0; i < arrayElementsNumber; ++i) {
        ptr[i] = rand();
    }

    printf("Subsequent elements of the array: ");
    for (i = 0; i < arrayElementsNumber; ++i) {
        printf("%d, ", ptr[i]);
    }

    printerMultiplier(ptr, filePath);

    return 0;
}