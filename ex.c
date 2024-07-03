#include <stdio.h>
#include <stdlib.h>

void AdditionnerMatrice(int **M1, int **M2, int **R, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = M1[i][j] + M2[i][j];
              }
        printf("\n");
    }
}

void AfficherM(int **M, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int l, c;
    int **M1 = (int **)malloc(l * sizeof(int *));
    int **M2 = (int **)malloc(l * sizeof(int *)), **R;
    printf("le nombre des lignes : ");
    scanf("%d", &l);
    printf("le nombre des colonnes : ");
    scanf("%d", &c);

    
    R = (int **)malloc(l * sizeof(int *));//Allocation dynamique de la mémoire pour la matrice R
    for (int i = 0; i < l; i++) {
        R[i] = (int *)malloc(c * sizeof(int));
    }
     // Remplissage de la matrice M1
    printf("les éléments de M1 sont :\n");
    for (int i = 0; i < l; i++) {
            M1[i] = (int *)malloc(c * sizeof(int));
         for (int j = 0; j < c; j++) {
            printf("M1[%d][%d] = ", i, j);
            scanf("%d", &M1[i][j]);
        }
    }
     // Remplissage  de la matrice M2
    printf("Saisir les éléments de la matrice M2 \n");
    for (int i = 0; i < l; i++) {
                M2[i] = (int *)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            printf("M2[%d][%d] = ", i, j);
            scanf("%d", &M2[i][j]);
        }
    }
    AdditionnerMatrice(M1, M2, R, l, c); // Appel de la fonction AdditionnerMatrice
    printf("la matrice M1 est :\n ");
    AfficherM(M1, l, c);                 // la matrice M1
    printf("la matrice M2 est :\n");
    AfficherM(M2, l, c);                 // la matrice M2
    printf("la somme de M1 et M2 est R \n ");
    AfficherM(R, l, c);  // la matrice R

    // Libération de la mémoire
    for (int i = 0; i < l; i++) {
        free(M1[i]);
        free(M2[i]);
        free(R[i]);
    }
    free(M1);
    free(M2);
    free(R);

    return 0;
}
