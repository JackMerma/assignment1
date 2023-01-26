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
    // here goes your code
}

// hint 100: Rotating a specific layer would just mean swapping the values in four arrays. If you were asked to swap the values in two arrays, could you do this? Can you then extend it to four arrays?
void hard_rotateMatrix(){
    //here goes your code
}
