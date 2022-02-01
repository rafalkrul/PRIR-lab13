#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>



double leibnizPi(float n) {
    double pi=1.0;
    int i;
    int N;
    for (i=3, N=2*n+1; i<=N; i+=2)
        pi += ((i&2) ? -1.0 : 1.0) / i;
    return 4*pi;

}

int
main(int argc, char *argv[])
{
    #pragma omp parallel
    double leib;

    int thread_id = omp_get_num_threads() ;
    int thread = omp_get_thread_num();

    leib = leibnizPi(1000);

    printf("Wynik przybli�enia pi = %f , W�tek $d of %d",leib,thread, thread_id );

    return 0;
}
