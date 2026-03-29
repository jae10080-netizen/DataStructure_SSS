#include <stdio.h>
#include "listS.h"

int insertElement(int L[], int n, int x) {
  int i, k = 0, move = 0;
  
  //원소의 크기를 비교하여 삽입 위치 k 찾기
  for(i = 0; i < n; i++) {
    if(L[i] <= x && x <= L[i + 1]) {
      k = i + 1;
      break;
    }
  }
  if (i == n) // 삽입 원소가 가장 큰 원소인 겨우  
    k = n;

  // 마지막 원소부터 K+1 원소까지 뒤로 자리이동
  for (i = n; i > k; i--) {
    L[i] = L[i - 1];
    move++;
  }

  L[k] = x;
  return move;
}

int deleteElement(int L[], int n, int x) {
  int i, k = n, move = 0;

  //원소의 크기를 비교하여 삭제 위치 k 찾기
  for (i = 0; i < n; i++){
    if(L[i] == x) {
      k = i;
      break;
    }
  }
  if (i == n) move = n;

  // K+1 부터 마지막 원소까지 앞으로 자리이동
  for (i = k; i < n - 1; i++){
    L[i] = L[i + 1];
    move++;
  }

  return move;
}

int main(void) {
  int list[MAX] = { 10, 20, 40, 50, 60, 70 };
  int i, move, size = 6; // size는 리스트에 있는 원소의 개수
  printf("\n삽입 전 선형 리스트 : ");
  for (i = 0; i < size; i++) printf("%3d",list[i]);
  printf("\n원소의 갯수 : %d \n", size);

  move = insertElement(list, size, 30);

  printf("\n삽입 후 선형 리스트 : ");
  for (i = 0; i <= size; i++) printf("%3d", list[i]);
  printf("\n 원소의 갯수: %d", ++size);
  printf("\n 자리 이동 횟수 : %d \n", move);

  move = deleteElement(list, size, 30);
  if(move == size) printf("\n 선형 리스트에 원소가 없어서 삭제할 수 없습니다. \n");
  else {
    printf("\n 삭제 후 선형 리스트 : ");
    for (i = 0; i < size - 1; i++) printf("%3d", list[i]);
    printf("\n원소의 갯수: %d", --size);
    printf("\n자리 이동 횟수: %d \n", move);
  }
  
  getchar(); return 0;
}

