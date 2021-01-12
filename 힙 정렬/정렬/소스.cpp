#include <queue>
#include <functional>
using namespace std;

void heapSortDec(int a[], int n) {
	priority_queue<int> maxHeap;

	for (int i = 0; i < n; i++)
		maxHeap.push(a[i]);

	for (int i = 0; i < n; i++) {
		a[i] = maxHeap.top();
		maxHeap.pop();

	}
}

void heapSortInc(int a[], int n) {
	priority_queue<int, vector<int>,greater<int>> minHeap;

	for (int i = 0; i < n; i++)
		minHeap.push(a[i]);

	for (int i = 0; i < n; i++) {
		a[i] = minHeap.top();
		minHeap.pop();

	}
}


void main() {

	int data[10];

	for (int i = 0; i < 10; i++) data[i] = rand() % 100;

	printf("\n정렬 전:");
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);

	heapSortDec(data, 10);
	printf("\n정렬 후:");
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);
}