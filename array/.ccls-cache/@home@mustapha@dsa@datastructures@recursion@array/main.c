#include "array.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	struct array *arr = init_array(5, 20);
	rem(arr, arr->length-1);
	display(arr);
	printf("%d\n", search(arr, 6));
	kill_array(arr);
}
