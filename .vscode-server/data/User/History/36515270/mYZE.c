#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define f(x) ((x)*(x))

int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    double a = 0.0;     // Lower limit of integration
    double b = 1.0;     // Upper limit of integration
    int n = 1000;       // Number of trapezoids
  
    double h = (b - a) / n; // Width of each trapezoid
    double integral = (f(a) + f(b)) / 2.0;
    // Sum the areas of each trapezoid
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        integral += f(x);
    }
    integral *= h;
  
    printf("The integral from %.2f to %.2f is approximately %.16f\n", a, b, integral);
    MPI_Finalize();
    return 0;
}
