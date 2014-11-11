/* File: lab4_2.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 11.11.2014 */
#include <stdio.h>
#include <stdlib.h>

void multiple_entry_remover(int [], int *);
void print_final_list(int [], int *);

int main()
{
	int field[] = {3, -1, 3, 4, 1, 1, 1, 3, 3, 2, 2, 2, 1};
	int elements = sizeof(field)/sizeof(int);
	printf("=====================================\n");
	printf("elements = %d\n", elements);
	printf("Original array\n");
	print_final_list(field, &elements);
		// Now, all multiple-entries will be removed and the number of
		// elements will be correspondingly reduced.
	multiple_entry_remover(field, &elements);
		// Note : elements now contains ONLY the relevant number of elements
		// WITH_OUT multiple entries
	printf("=====================================\n");
	printf("Deduplicated array\n");
	print_final_list(field, &elements);
	system("pause");
	return 0;
}

void multiple_entry_remover(int field[], int *elements)
{
	int i = 0;
	int index;
	int position;
	
	while(i < *elements) // cycle 0 - select every element to compare
	{
		index = i + 1;
		while(index < *elements) // cycle 1 - compare selected element to all elements after it
		{
			if(field[index] == field[i])
			{
				position = index;
				while(position < (*elements - 1)) // cycle 2 - shift the array if sample coincides with the element at [position]
				{
					field[position] = field[position+1];
					position++;
				}
				field[position] = -1;
				(*elements)--;
				index--; // we have just shifted the array. We still need to compare the [index] element (previously [index+1]) to our [index-1](or [i]) element
			}
			index++;
		}
		i++;
	}
}
void print_final_list(int field[], int *elements)
{
	int index = 0;
	printf("{");
	while(index < *elements)
	{
		printf(" %d ", field[index]);
		index++;
	}
	printf("}\n");
}