#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

int glob = 0;
pthread_mutex_t lock;
pthread_barrier_t barr;

void *sayhi( void *param)
{
    long myid;
    int tmp, slp;
    myid = (long)  param;
pthread_barrier_wait( &barr );
    printf("hi from %ld\n", myid);

    printf("   %ld global in %d\n", myid, glob);
pthread_barrier_wait( &barr );
    //glob = glob + 1;

    pthread_mutex_lock(&lock);

    slp = rand() % 4;
    sleep(slp);
    tmp = glob;
    tmp = tmp + 1;
    slp = rand() % 4;
    sleep(slp);
    glob = tmp;

    pthread_mutex_unlock(&lock);

    printf("   %ld global out %d\n", myid, glob);
pthread_barrier_wait( &barr );
    pthread_exit(NULL); 
}


int mainAssignment2()
{
    pthread_t tids[NUM_THREADS];
    long t;
    void *status;
    pthread_mutex_init( &lock, NULL);
    pthread_barrier_init( &barr, NULL, NUM_THREADS);

    srand( time(NULL) );

    printf("In main: time to build threads\n");
    glob = 20;
    for (t=0; t<NUM_THREADS; t++)
    {
        printf("In main: creating thread %ld\n", t);
        pthread_create( &tids[t], NULL, sayhi, (void *) 1000+t  );
    }

    printf("In main: all threads created\n");

    for (t=NUM_THREADS-1; t >= 0; t--)
    {
        pthread_join( tids[t], &status );
        printf("Main: joined %ld\n", t);
    }

    printf("In main:  all threads joined\n");
    printf("Global at end is %d\n", glob);

//  pthread_exit( NULL );
    
    return 0;
}