#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// There are at least 6 bugs relating to memory on this page.
// Find them all!

// Vec is short for "vector", a common term for a resizable array.
// For simplicity, our vector type can only hold ints.
typedef struct {
  int* data;     // Pointer to our array on the heap
  int  length;   // How many elements are in our array
  int  capacity; // How many elements our array can hold
} Vec;

Vec* vec_new() {
  Vec vec; // 버그 1. 로컬 변수로 vec을 만들었으므로 scope가 끝나면 없는 걸 리턴.
  vec.data = NULL; // Rust: NULL이란 키워드가 없음. 대신 Option<T> 사용.
  vec.length = 0;
  vec.capacity = 1;
  return &vec; // 메모리 공간 중 스택 상의 없는 주소를 리턴하게 됨. 
}

void vec_push(Vec* vec, int n) {
  if (vec->length == vec->capacity) {
    int new_capacity = vec->capacity * 2;
    int* new_data = (int*) malloc(new_capacity);

    for (int i = 0; i < vec->length; ++i) {
      new_data[i] = vec->data[i];
    }

    vec->data = new_data; //버그? 기존의 vec->data가 가리키고 있는 곳을 free하지 않았음. 
    vec->capacity = new_capacity;
  }

  vec->data[vec->length] = n; // 버그. 최초에 데이터를 넣는 경우 vec.data가 NULL이라 세그폴트.
  ++vec->length;
}

void vec_free(Vec* vec) {
  free(vec); // 버그 2. vec을 먼저 free했으므로 vec->data 는 이미 말이 안 되는 상태.
  free(vec->data);
}

void main() {
  Vec* vec = vec_new();
  vec_push(vec, 107);

  int* n = &vec->data[0]; // 버그.
  vec_push(vec, 110); // 바로 윗 줄에서 vec->data가 free된 상태이므로 원하는 value 안 나옴.
  printf("%d\n", *n);

  free(vec->data);
  vec_free(vec); // 버그. vec->data를 이중으로 free하게 됨. 
}