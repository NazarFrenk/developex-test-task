#include <stdio.h>

const char* last8toStr(int x)
{
	enum { SIZE = 8 };
	static int count = 0;

	static int arr[SIZE] = { 0 };
	static char s[SIZE] = { 0 };

	if (count < SIZE)
	{
		arr[count++] = x;
	}
	else
	{
		memmove(arr, arr + 1, (SIZE - 1) * sizeof(int));
		arr[SIZE - 1] = x;
	}

	int n = 0;

	int max_index = (SIZE > count) ? count : SIZE;

	for (size_t i = 0; i < max_index; i++)
	{
		n += sprintf(&s[n], "%d ", arr[i]);
	}

	return s;
}

int main()
{
	int input = 0;
	const char* output;

	printf("> ");
	while (scanf("%d", &input))
	{
		output = last8toStr(input);
		printf(": %s\n> ", output);
	}

	return 0;
}