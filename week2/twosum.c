#include <stdbool.h>
#include <stdio.h>
#include <string.h>


static bool twoSum(int *arr, int n, int sum);

int main(int argc, char *argv[]) {
	
    int arr[5] = {1,2,3,8,7};

    printf("Is there a pair of values that adds up to 6? %s\n", twoSum(arr, 5, 6) ? "yes" : "no");

	return 0;
}

static bool twoSum(int *arr, int n, int sum) {

    for (int i = 0; i < n; i++) {                // n
        for (int j = i + 1; j < n; j++) {              // n - 1
            if (arr[i] + arr[j] == sum) {                    // 1
                return true;                                 // -
            }
        }
    }

    return false;                                // 1
}

// n * ((n-1) * 1) + 1
// n^2 - n + 1
// O(n^2)
