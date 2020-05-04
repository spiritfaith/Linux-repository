#include <stdio.h>

void merge(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void insertion_sort(int a[], int n);
void bubble_sort(int a[], int n);
void pointer_size(void);

int b[8];

// feature: if sorted, then only one pass
void insertion_sort(int a[], int n) {
	int k = 1;	// initial: k = 1
	// loop invariant: a[0 ... k - 1] is sorted.
	for (k = 1; k < n; k++) {
		int key = a[k];
		// insert a[k] into the sorted sequence a[0 ... k - 1].
		int j = k - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void bubble_sort(int a[], int n) {
	int i, j;
	// loop invariant: a[n - i ... n - 1] are top i elements.
	for (i = 0; i < n - 1; j++)
		if (a[j - 1] > a[j]) {
			int t;
			t = a[j - 1], a[j - 1] = a[j], a[j] = t;
		}
}

void qsort(int v[], int left, int right) {
	int i, last;
	if (left >= right) /* do nothing if arrays contains */
		return;
	swap(v, left + (right - left) / 2, right);
// left + (right - left) / 2 = (left + right) / 2 = mid
// a[mid] <> a[right]
last = i = right;
// loop invariant: v[left ... last - 1] < pivot
// v[last, ..., i - 1] >= pivot
for (; i < right; i++) /* partition */
	if (v[i] < v[right])
		swap(v, last++, i);
swap(v, last, right);
qsort(v, left, last - 1);
qsort(v, last + 1, right);
}


int main()
