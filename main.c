#include <stdio.h>

const char* last8toStr(int x)
{
	enum { SIZE = 8 };
	static int count = 0;

	static int arr[SIZE] = { 0 };
	static char s[SIZE * 12] = { 0 }; // 10 for max number len + 1 for sign + 1 for space

	if (count < SIZE)
	{
		arr[count++] = x;
	}
	else
	{
		for (int i = 1; i < SIZE; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[SIZE - 1] = x;
	}

	for (int i = 0; i < SIZE * 12; i++)
	{
		s[i] = '\0';
	}

	int n = 0;

	int max_index = (SIZE > count) ? count : SIZE;

	for (int i = 0; i < max_index; i++)
	{
		int number = arr[i];
		char buff[12] = { 0 };
		int number_len = 0;

		if (number == 0)
		{
			buff[number_len++] = '0';
		}
		else
		{
			if (number < 0)
			{
				buff[number_len++] = '-';
				number = -number;
			}

			int temp = number;
			int digits = 0;

			while (temp > 0)
			{
				digits++;
				temp /= 10;
			}

			temp = number;

			for (int j = digits - 1; j >= 0; j--)
			{
				buff[number_len + j] = '0' + (temp % 10);
				temp /= 10;
			}
			number_len += digits;
		}

		for (int j = 0; j < number_len; j++)
		{
			s[n++] = buff[j];
		}

		if (i < max_index - 1)
		{
			s[n++] = ' ';
		}
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