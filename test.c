/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:18:05 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/07 14:23:31 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct {
    int cash;
} Bank;

static Bank the_bank;

void* customer(void* arg) 
{
    arg = NULL;
    for (int i = 0; i < 1000; i++) {
        the_bank.cash += 10; // Data race occurs here
    }
    return NULL;
}

int main() {
    the_bank.cash = 0;
    pthread_t tids[32];

    for (int i = 0; i < 32; i++) {
        pthread_create(&tids[i], NULL, customer, NULL);
    }

    for (int i = 0; i < 32; i++) {
        pthread_join(tids[i], NULL);
    }
    
    printf("Total: %d\n", the_bank.cash);
    return 0;
}
// #include <stdio.h>
// #include <pthread.h>

// int shared_variable = 0;
// pthread_mutex_t mutex;

// void* increment(void* arg) 
// {
//     arg = NULL;
//     for (int i = 0; i < 1000000; i++) {
//         pthread_mutex_lock(&mutex);
//         shared_variable++;
//         pthread_mutex_unlock(&mutex);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t thread1, thread2;

//     pthread_mutex_init(&mutex, NULL);

//     pthread_create(&thread1, NULL, increment, NULL);
//     pthread_create(&thread2, NULL, increment, NULL);

//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);

//     pthread_mutex_destroy(&mutex);

//     printf("Shared variable value: %d\n", shared_variable);

//     return 0;
// }