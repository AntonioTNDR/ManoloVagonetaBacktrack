#include <stdio.h>

void backtrack(int weights[], int sol[], int totalW[], const int *nElements);
const int cap = 200;
int main() {

    int sol[6];
    int totalW[4];
    int nElements = 1;
    int value;
    int count = 0;
    int weights[20];

    for (int i = 0; i < 4; i++) {
        totalW[i] = 0;
    }
    for (int i = 0; i < 20; i++) {
        weights[i] = 0;
    }

    for (int i = 0; i < 6; i++) {
        sol[i] = 0;
    }

    while(1){
        scanf("%d", &value);
        if(value == -1)
            break;
        weights[count] = value;
        nElements++;
        count++;
    }

    backtrack(weights, sol, totalW, &nElements);

}

void backtrack(int weights[20], int sol[6], int totalW[4], const int *nElements){
    int reached = 1;
    for (int i = 0; i < *nElements;) {
        sol[i]++;
        if (sol[i] == 4) {
            if (i == 0) {
                printf("---A solution cannot be reached---");
                i = 7;
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
        if (totalW[sol[i]] + weights[i] > cap) { // dead node condition
            continue;
        }
        totalW[sol[i]] += weights[i];
        if (i == 5) { printf("---A solution can be reached---\n"); }
        i++;
    }
    if (reached) { //solution node
        for (int i = 0; i < *nElements; ++i) {
            printf("Item:%d(weight %d)--Lorry:%d\n", i + 1, weights[i], sol[i]);
        }
        for (int i = 1; i < 4; ++i) {
            printf("Lorry %d->%d kilos\n",i,totalW[i]);
        }
    }
}
