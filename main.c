#include "matrix.c"
#include <time.h>

int main(){
    srand(time(NULL));

    //here goes your code
    generateMatrix();
    printMatrix();
    hard_rotateMatrix();
    printMatrix();

    return 0;
}
