#include "DymArr.h"

DymArr* CreateDymArray(int size) {
	if (size <= 0) {
		printf("Error. size can`t be null\n");
		return NULL;
	}

	DymArr* Res = (DymArr*)malloc(sizeof(DymArr));

	if (Res == NULL) {
		printf("Error. not alloc memory\n");
		return NULL;
	}

	Res->CountElements = 0;
	Res->Size = size;
	Res->Data = (int*)malloc(size*sizeof(int));

	if (Res->Data == NULL) {
		printf("Error. not alloc memory\n");
		return NULL;
	}

	return Res;
}

void AddElements(DymArr* arr, int value) {
	if (arr == NULL || arr->Data == NULL) {
		printf("Error. array not alloc\n");
		return;
	}

	if (arr->CountElements == arr->Size) {
		int* NewData = (int*)realloc(arr->Data, (arr->CountElements+1)*sizeof(int));

		if (NewData == NULL) {
			printf("Error. not alloc memory\n");
			return;
		}
		arr->Data = NewData;
		arr->Data[arr->Size] = value;
		arr->Size += 1;
	}
	else {
		arr->Data[arr->CountElements] = value;
	}
	arr->CountElements += 1;
	return;
}

void PrintArr(DymArr* arr) {
	if (arr == NULL || arr->Data == NULL) {
		printf("Error. array not alloc\n");
		return;
	}

	for (int i = 0; i < arr->CountElements; i++) {
		printf("%d ", arr->Data[i]);
	}
	printf("\n");
	return;
}


void BubbleSortArr(DymArr* Arr) {
	for (int i = 0; i < Arr->CountElements - 1; i++) {
		for (int j = 0; j < Arr->CountElements - 1 - i; j++) {
			if (Arr->Data[j] > Arr->Data[j + 1]) {
				Arr->Data[j] ^= Arr->Data[j + 1] ^= Arr->Data[j] ^= Arr->Data[j + 1];
			}
		}
	}
}