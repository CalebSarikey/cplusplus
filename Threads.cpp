#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define LIM 99
#define SIZE 10

void function1();
void function2();
void function3();

int num1[SIZE];
int num2[SIZE];
int num3[SIZE];
int sum1;
int sum2;
int sum3;

main() {
  pthread_t thread1, thread2, thread3;
  srand((unsigned)time(NULL)); //Use once to initialize the random number seed with time.

  pthread_create(&thread1, NULL, (void*)&function1, NULL);
  pthread_create(&thread2, NULL, (void*)&function2, NULL);
  pthread_create(&thread3, NULL, (void*)&function3, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  printf("Thread1 produced: %d\n",sum1);
  printf("Thread2 produced: %d\n",sum2);
  printf("Thread3 produced: %d\n",sum3);

  int highest=0;
  int highest2=0;
  highest = sum1;
  if(sum2 > sum3) {
    highest2 = sum2;
  }
  else {
    highest2 = sum3;
  }
  if(highest2 >= highest) {
    highest=highest2;
  }

  printf("The winner is: %d\n",highest);
}

void function1() {
  for (int r = 0; r < SIZE; r++)
    num1[r] = rand()%LIM;

  for (int i = 0; i < SIZE; i++)
    sum1 += num1[i];
}

void function2() {
  for (int r = 0; r < SIZE; r++)
    num2[r] = rand()%LIM;
  for (int i = 0; i < SIZE; i++)
    sum2 += num2[i];
}

void function3() {
  for (int r = 0; r < SIZE; r++)
    num3[r] = rand()%LIM;
  for (int i = 0; i < SIZE; i++)
    sum3 += num3[i];
}
