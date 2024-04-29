# ManoloVagonetaBacktrack
Venga vamos un último esfuerzo que el fin de la lobotomía no está lejos


Formal description key elements:
DATA:One dimensional tuple with N elements(array size) S(i)==j, ith element
EXHAUSTIVITY: j ranges from 0 to 4 -> 0:not decided, 1:lorry 1, 2:lorry 2, 3:lorry 3, 4:Backtracking. Sums[3]:array with the elem. A[N]:original array.
//Nodes identifying, conditions/actions
BT NODE:(S(i)==4){S(i)=0;i--;Sums[S[i]]-=A[i];}
DEAD NODE:(Sums[S[i]-1]+A[i]>20Tm;){}
LIVE NODE:(!DEAD NODE){Sums[S[i]-1]+=A[i];}
SOL NODE:(i==last) && (LIVE NODE) {printf("Solution found");}
