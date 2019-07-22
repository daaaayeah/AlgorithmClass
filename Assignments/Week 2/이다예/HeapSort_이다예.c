#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void downHeap(int *arr, int i, int N);

int main() {
	int N, *arr = NULL;
	int i, index;

	scanf("%d", &N);
	index = N;
	arr = (int *)malloc(sizeof(int) * (N + 1));
	if (arr == NULL) return -1;
	for (i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	for (i = N / 2; i >= 1; i--)
		downHeap(arr, i, N);
	for (i = 1; i <= N; i++) {
		printf("%d\n", arr[1]);
		arr[1] = arr[index--];
		downHeap(arr, 1, index);
	}

	free(arr);
}

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void downHeap(int *arr, int i, int N) {
	int left = i * 2;
	int right = left + 1;

	if (left > N) return;
	else if (left < N) {
		if (arr[left] < arr[right]) {
			if (arr[i] > arr[left]) {
				swap(&arr[i], &arr[left]);
				downHeap(arr, left, N);
			}
			else return;
		}
		else {
			if (arr[i] > arr[right]) {
				swap(&arr[i], &arr[right]);
				downHeap(arr, right, N);
			}
			else return;
		}
	}
	else {
		if (arr[i] > arr[left]) {
			swap(&arr[i], &arr[left]);
			downHeap(arr, left, N);
		}
		else return;
	}
}