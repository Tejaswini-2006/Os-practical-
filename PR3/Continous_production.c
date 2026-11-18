// Continuos production and consumption of products //




#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int item = 1;

    while (1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;

        printf("Producer produced: Product %d\n", item);
        fflush(stdout);

        in = (in + 1) % SIZE;
        item++;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        usleep(100000);
    }

    return NULL;
}

void *consumer(void *arg)
{
    int item;

    while (1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];

        printf("Consumer consumed: Product %d\n", item);
        fflush(stdout);

        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        usleep(150000);
    }

    return NULL;
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}







/*


Step 1: Create a C file
Enter: nano producer.c

Step 2: Save the file
After pasting the code:
1. Press Ctrl + O to save.
2. Press Enter to confirm the filename.
3. Press Ctrl + X to exit Nano.



step3: Compile 
gcc producer.c -o a -pthread

step4: run 
./a

*/
