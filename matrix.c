#include <stdio.h>
#include <stdlib.h>

#define INT_MAX (int)1e4
#define N 5
#define RANDOM (rand() % 100) + 1

int m[INT_MAX][INT_MAX];

void printMatrix(){
    printf("matrix:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void generateMatrix(){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            m[i][j] = RANDOM;
}

// hint 51: Try thinking about it layer by layer. Can you rotate a specific layer?.
void easy_rotateMatrix(){
    int m2[N][N]; // matriz auxiliar

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            m2[j][N-i-1]=m[i][j]; // ya girado

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            m[i][j]=m2[i][j]; // solo copiando matriz
}

// hint 100: Rotating a specific layer would just mean swapping the values in four arrays. If you were asked to swap the values in two arrays, could you do this? Can you then extend it to four arrays?
void hard_rotateMatrix(){

    // En esta solución se usa una metodologia de bordes 
    // para voltear la imagen. Esto implica rotar un borde
    // completo de la imagen. Entonces, si las dimensiones son
    // 4x4, habrá un borde externo y un borde interno, si es de
    // 5x5, habrá un borde externo y 2 bordes internos; sin embargo,
    // el último borde sera de 1x1 por lo que solo será necesario
    // rotar 2 bordes (entonces se recorrerán n/2 bordes).
    //
    // Sobre cada borde. Si la longitud de uno de los lados de los
    // bordes es de 'k', entonces, se recorreran k-1 posiciones.
    // Entonces, si k es el iterador de bordes, se necesitará 
    // recorrer (N - 2*k - 1) posiciones.

    for(int i=0;i<N/2+N%2;i++){
        for(int j=i; j<(N-2*i-1)+i;j++){
            int is, ii, ds, di;
            is = m[i][j]; //izquierda superior
            ii = m[N-j-1][i]; // izquierda inferior
            ds = m[j][N-i-1]; // derecha superior
            di = m[N-i-1][N-j-1]; // derecha inferior

            // rotando valores
            m[i][j] = ii;
            m[N-j-1][i] = di;
            m[N-i-1][N-j-1] = ds;
            m[j][N-i-1] = is;
        }
    }
}
