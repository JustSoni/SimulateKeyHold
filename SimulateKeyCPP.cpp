#include <iostream>
#include<Windows.h>

using namespace std;

int main()
{

	int key = 0;

	while (true){

		if (GetAsyncKeyState(VK_NUMPAD0)) {
			key = 0;	//Press 0 on the numpad to stop the program. 
		}

		if (GetAsyncKeyState(VK_NUMPAD1)) {
			key = 1;	//Press 1 on the numpad to start the program.
		}

		if (key == 1) {
			SHORT key;
			UINT mappedkey;
			INPUT input = { 0 };
			key = VkKeyScan('w');
			mappedkey = MapVirtualKey(LOBYTE(key), 0);
			input.type = INPUT_KEYBOARD;
			input.ki.dwFlags = KEYEVENTF_SCANCODE;
			input.ki.wScan = mappedkey;
			SendInput(1, &input, sizeof(input));
			Sleep(10);
			input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(input));
		}

	}
}
