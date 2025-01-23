#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 3
#define TOTAL_ITEMS 30

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0, out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t empty, full;

void* producer(void* arg) {
    int item;
    int id = *(int*)arg;
    
    for(int i = 0; i < TOTAL_ITEMS/NUM_PRODUCERS; i++) {
        item = rand() % 100;  // Generate random item
        
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        
        printf("Producer %d produced item %d (count: %d)\n", id, item, count);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        
        sleep(1);  // Simulate production time
    }
    
    return NULL;
}

void* consumer(void* arg) {
    int item;
    int id = *(int*)arg;
    
    for(int i = 0; i < TOTAL_ITEMS/NUM_CONSUMERS; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        
        printf("Consumer %d consumed item %d (count: %d)\n", id, item, count);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        
        sleep(2);  // Simulate consumption time
    }
    
    return NULL;
}

int main() {
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];
    
    srand(time(NULL));
    
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    
    // Create producers
    for(int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }
    
    // Create consumers
    for(int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }
    
    // Wait for all threads to complete
    for(int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }
    
    for(int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }
    
    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
