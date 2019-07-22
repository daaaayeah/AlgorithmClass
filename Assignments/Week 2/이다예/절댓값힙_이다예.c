#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int compare_abs(int a, int b);
void upHeap(int *heap, int index);
void downHeap(int *arr, int i, int N);

int main() {
	int N, *arr = NULL, n;
	int i, index = 1;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * (N + 1));
	if (arr == NULL) return -1;
	for (i = 1; i <= N; i++) {
		scanf("%d", &n);

		if (n == 0) {
			if (index == 1) {
				printf("0\n");
				continue;
			}
			printf("%d\n", arr[1]);
			arr[1] = arr[--index];
			downHeap(arr, 1, index);
		}
		else {
			arr[index] = n;
			upHeap(arr, index++);
		}
	}

	free(arr);
}

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare_abs(int a, int b) {
	if (abs(a) < abs(b))
		return a;
	else if (abs(a) > abs(b))
		return b;
	else
		return a < b ? a : b;
}
void upHeap(int *arr, int index) {
	if (index == 1 || compare_abs(arr[index], arr[index / 2]) == arr[index / 2]) return;
	else {
		swap(&arr[index], &arr[index / 2]);
		upHeap(arr, index / 2);
	}
}
void downHeap(int *arr, int i, int N) {
	int left = i * 2;
	int right = left + 1;

	if (left > N) return;
	else if (left < N) {
		if (compare_abs(arr[left], arr[right]) == arr[left]) {
			if (compare_abs(arr[i], arr[left]) == arr[left]) {
				swap(&arr[i], &arr[left]);
				downHeap(arr, left, N);
			}
			else return;
		}
		else {
			if (compare_abs(arr[i], arr[right]) == arr[right]) {
				swap(&arr[i], &arr[right]);
				downHeap(arr, right, N);
			}
			else return;
		}
	}
	else {
		if (compare_abs(arr[i], arr[left]) == arr[left]) {
			swap(&arr[i], &arr[left]);
			downHeap(arr, left, N);
		}
		else return;
	}
}