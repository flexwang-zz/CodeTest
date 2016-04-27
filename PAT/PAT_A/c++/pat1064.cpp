#include<stdio.h>
struct Node {
	int start;
	int end;
	Node(int s, int e) :
			start(s), end(e) {
	}
};

int getmidindex(int *a, int start, int end);
int main() {
	int N;
	int len = 0;
	scanf("%d", &N);
	int a[1000];
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);

		a[len++] = n;
		int tmp = n;
		int k;
		for (k = len - 2; k >= 0; k--) {
			if (a[k] < tmp) {
				break;
			} else {
				a[k + 1] = a[k];
			}
		}
		a[k + 1] = tmp;
	}

	for (int i = 0; i < N; i++) {
		//  printf("%d ", a[i]);
	}

	Node* curlayer[502];
	Node* curlayer2[502];
	int curlayersize = 0;

	curlayer[curlayersize++] = new Node(0, N - 1);
	bool firstprint = true;
	while (curlayersize > 0) {
		int curlayersize2 = 0;
		for (int i = 0; i < curlayersize; i++) {

			int midindex = getmidindex(a, curlayer[i]->start, curlayer[i]->end);
			if (firstprint) {
				firstprint = false;
			} else {
				printf(" ");
			}
			if (midindex == -1)
				continue;
			//getchar();
			//printf("%d %d ", curlayer[i]->start, curlayer[i]->end);
			printf("%d", a[midindex]);

			if (midindex > curlayer[i]->start) {
				curlayer2[curlayersize2++] = new Node(curlayer[i]->start,
						midindex - 1);
			}
			if (midindex < curlayer[i]->end) {
				curlayer2[curlayersize2++] = new Node(midindex + 1,
						curlayer[i]->end);
			}

		}
		curlayersize = curlayersize2;
		for (int i = 0; i < curlayersize; i++) {
			curlayer[i] = curlayer2[i];
		}
	}

	//getmidindex(a, 2, 2);
//  while(1);
	return 0;
}

int getmidindex(int *a, int start, int end) {
	if (start > end)
		return -1;

	if (start == end)
		return start;
	int size = 1;
	while (size < (end - start + 1)) {
		size = (size + 1) * 2 - 1;
	}
	//printf("\n%d", size);

	size = ((size + 1) / 2 - 1);
	int lastlayersize = (end - start + 1) - size;

	int midindex;
	if (lastlayersize >= (size + 1) / 2) {
		midindex = start + (size - 1) / 2 + (size + 1) / 2;
	} else {
		midindex = start + (size - 1) / 2 + lastlayersize;
	}
//  printf("%d", a[midindex]);
	return midindex;
}

