#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main() {
    
    
    int n[] = {1,2,3,4,5,6,7,8,9,10};

    int v;


    // Test old binsearch
    clock_t time1 = clock();
    v = binsearch2(9, n, sizeof(n)/sizeof(n[0]));
    clock_t time2 = clock();

    printf("Old Binsearch Position: %d\n", v);
    printf("Elapsed: %f ms\n\n", ((double)(time2-time1)/CLOCKS_PER_SEC)*1000);


    // Test new binsearch
    clock_t time3 = clock();
    v = binsearch(9, n, sizeof(n)/sizeof(n[0]));
    clock_t time4 = clock();

    printf("New Binsearch Position: %d\n", v);
    printf("Elapsed: %f ms\n\n", ((double)(time4-time3)/CLOCKS_PER_SEC)*1000);
}

int binsearch(int x, int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;

    while ((mid = (low + high)/2) && x != v[mid] && low <= high) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}

int binsearch2(int x, int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high)/2;
        if (x > v[mid]) {
            low = mid + 1;
        } else if (x < v[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}