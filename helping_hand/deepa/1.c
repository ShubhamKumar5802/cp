#include<stdio.h>
int digit_cnt(int num) {
	int cnt = 0;
	while (num) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int power(int x, int y) {  //ignore
	if (y == 0)return 1;
	return x * power(x, y - 1);
}

int main() {
	int num;
	scanf("%d", &num);
	int num_of_digit = digit_cnt(num);
	int copy_of_num = num;
	int digit_sum = 0;
	while (copy_of_num) {
		int rem = copy_of_num % 10;  // taking the digit at once place
		copy_of_num /= 10; //removing digit from back
		digit_sum += power(rem, num_of_digit);
	}
	if (digit_sum == num) {
		printf("We got it\n");
	} else {
		printf("Fuck Off!!!\n");
	}
	return 0;
}