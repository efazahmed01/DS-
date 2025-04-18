#include <stdio.h>

int left(int i) 
{
    return 2 * i;
}

int right(int i) 
{
    return 2 * i + 1;
}

int parent(int i) 
{
    return i / 2;
}

void max_heapify(int heap[], int *sz, int i) 
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l <= *sz && heap[l] > heap[largest])
        largest = l;

    if (r <= *sz && heap[r] > heap[largest])
        largest = r;

    if (largest != i) 
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heapify(heap, sz, largest);
    }
}

void insert(int heap[], int *sz, int value) 
{
    (*sz)++;
    int i = *sz;
    heap[i] = value;

    while (i > 1 && heap[i] > heap[parent(i)]) 
    {
        int p = parent(i);
        int temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;
        i = p;
    }
}

int max(int heap[], int *sz) 
{
    if (*sz == 0) return -1; 
    int maximum = heap[1];
    heap[1] = heap[*sz];
    (*sz)--;
    max_heapify(heap, sz, 1);
    return maximum;
}

int main() {
    int n;
    scanf("%d", &n);
    int heap[n + 1]; 
    int heap_size = 0;

    for (int i = 0; i < n; i++) 
    {
        int x;
        scanf("%d", &x);
        insert(heap, &heap_size, x);
    }

    // Print the heap after insertion
    printf("Heap after insertion:\n");
    for (int i = 1; i <= heap_size; i++)
        printf("%d ", heap[i]);

    // Extract max one by one (Heap Sort)
    printf("\nExtracting all elements:\n");
    while (heap_size > 0) {
        printf("%d ", max(heap, &heap_size));
    }

    return 0;
}
