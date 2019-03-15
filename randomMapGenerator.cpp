#include "terrain.h"
#include "map.h"

int main (){
    srand(time(NULL));
    Map m(13, 27);
    m.fillMatrix();
    m.placeMountains();
    m.printMatrix();
    return 0;
}