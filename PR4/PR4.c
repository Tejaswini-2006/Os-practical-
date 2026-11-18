
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_mutex_t fork_mutex[N];
sem_t room;

void *philosopher(void *arg)
{
    int id = *(int *)arg;

    for (int i = 1; i <= 3; i++)
    {
        printf("Philosopher %d is thinking\n", id);

        sem_wait(&room);

        pthread_mutex_lock(&fork_mutex[id - 1]);

        pthread_mutex_lock(&fork_mutex[id % N]);

        printf("Philosopher %d is eating\n", id);
        sleep(1);

        pthread_mutex_unlock(&fork_mutex[id % N]);

        pthread_mutex_unlock(&fork_mutex[id - 1]);

        sem_post(&room);

        printf("Philosopher %d finished eating\n", id);
    }

    return NULL;
}

int main()
{
    pthread_t threads[N];
    int id[N];

    sem_init(&room, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&fork_mutex[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        id[i] = i + 1;
        pthread_create(&threads[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&fork_mutex[i]);
    }

    sem_destroy(&room);

    return 0;
}




/*


Execute these commands in Ubuntu:
1. Create file
nano dining.c


2) Paste the program and save it:
- Press Ctrl + O
- Press Enter
- Press Ctrl + X




3. Compile
gcc dining.c -o dining -pthread


4. Run
./dining

*/