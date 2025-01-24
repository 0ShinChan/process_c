#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SIZE 100

int matrix[MAX_SIZE][MAX_SIZE];
int rows, cols;
bool is_symmetric = true;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread for input
void* input_thread(void* arg) {
    printf("Enter matrix dimensions (rows columns): ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("Matrix must be square for symmetry check!\n");
        is_symmetric = false;
        return NULL;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return NULL;
}

// Thread for symmetry check
void* symmetry_thread(void* arg) {
    pthread_mutex_lock(&mutex);
    
    if (!is_symmetric) {
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    // Check symmetry
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                is_symmetric = false;
                break;
            }
        }
        if (!is_symmetric) break;
    }
    
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t input_tid, symmetry_tid;

    // Create input thread
    if (pthread_create(&input_tid, NULL, input_thread, NULL) != 0) {
        perror("Failed to create input thread");
        return 1;
    }

    // Wait for input thread to complete
    pthread_join(input_tid, NULL);

    // Create symmetry check thread
    if (pthread_create(&symmetry_tid, NULL, symmetry_thread, NULL) != 0) {
        perror("Failed to create symmetry thread");
        return 1;
    }

    // Wait for symmetry thread
    pthread_join(symmetry_tid, NULL);

    // Print result
    printf("Matrix is %ssymmetric\n", is_symmetric ? "" : "not ");

    return 0;
}
