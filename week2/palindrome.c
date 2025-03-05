#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool isPalindrome(char *s);

int main(int argc, char *argv[]) {
	if (argc == 2) {
		if (isPalindrome(argv[1])) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}

static bool isPalindrome(char *s) {

	int left = 0;						// 1
	int right = strlen(s) - 1;          // 1
	while (left < right) {              // n/2
		if (s[left] != s[right]) {      		// 1
			return false;                       // -
		}
		left++;                                 // 1
		right--;                                // 1
	}
	
	return true;                        // 1
}

// 3 + n/2 * (3)
// 3*n/2 + 3
// O(n)
