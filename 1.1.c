#include <windows.h>
int main(void)
{
	int i;
	for(;;)
		for(i=0;i<830000000;i++);
		Sleep(500);

	return 0;
}
