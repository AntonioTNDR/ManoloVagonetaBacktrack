/*
    DYNAMICAL PROGRAMMING ASSIGNMENT
    - David García Guirado - 55052860Z
    - Jorge García Marín - 49314477Q
    - Antonio Tendero Beltrán - 49428050S
*/

#include <stdio.h>

void backtrack(int weights[], int sol[], int totalW[],  int nElements);
const int CAP = 20;

int main() {
    int sol[100];
    int totalW[4];
    int nElements = 0;
    int value;
    int weights[100];

    // Initialize the arrays
    for (int i = 0; i < 4; i++) {
        totalW[i] = 0;
    }
    for (int i = 0; i < 20; i++) {
        sol[i] = 0;
    }

    printf("Enter weight for each item:\n");
    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        weights[nElements] = value;
        nElements++;
    }

    backtrack(weights, sol, totalW, nElements);
}

void backtrack(int weights[], int sol[], int totalW[], int nElements){
    int reached = 1, nLaps = 0;
    for (int i = 0; i < nElements;) {
        nLaps++;
        sol[i]++;
        if (sol[i] == 4) {
            if (i == 0) {
                printf("---A solution cannot be reached---");
                i = nElements;
                reached = 0;
                continue;
            }
            else { //BT condition
                sol[i] = 0;
                i--;
                totalW[sol[i]] -= weights[i];
                continue;
            }
        }
        if (totalW[sol[i]] + weights[i] > CAP) { // dead node condition
            continue;
        }
        totalW[sol[i]] += weights[i];
        if (i == nElements - 1) { printf("---A solution can be reached---\n"); }
        i++;
    }
    if (reached) { //solution node
        printf("\n");
        for (int i = 0; i <nElements; ++i) {
            printf("Item:%d(weight %d)--Lorry:%d\n", i + 1, weights[i], sol[i]);
        }
        printf("\n");
        for (int i = 1; i < 4; ++i) {
            printf("Lorry %d->%d kilos\n",i,totalW[i]);
        }
    }
    printf("\nNumber of laps: %d", nLaps);
}
