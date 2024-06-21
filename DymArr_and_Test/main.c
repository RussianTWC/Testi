#include "DymArr.h"
void TestCorectSort() {
	DymArr* Array = CreateDymArray(4);
	if (Array == NULL || Array->Data == NULL) {
		printf("Error. Array not alloc");
		return -1;
	}

	AddElements(Array, 17);
	AddElements(Array, 1);
	AddElements(Array, 8);

	BubbleSortArr(Array);

	_Bool res = 0;
	if (Array->Data[0] == 1 && Array->Data[1] == 8 && Array->Data[2] == 17)
		res = 1;

	sput_fail_unless(res == 1, "Test 1 Completed\n");
	Array->Data[0] = INT_MAX;
	Array->Data[1] = INT_MAX + 1;
	Array->Data[2] = INT_MAX + 2;

	BubbleSortArr(Array);

	if (Array->Data[0] == INT_MAX+1 && Array->Data[1] == INT_MAX+2 && Array->Data[2] == INT_MAX)
		res = 1;
	else
		res = 0;

	sput_fail_unless(res == 1, "Test 2 Completed\n");
}

int main() {
	
	sput_start_testing();

	sput_enter_suite("Check Correct Sort\n");
	sput_run_test(TestCorectSort);
	sput_finish_testing();
	return 0;
}