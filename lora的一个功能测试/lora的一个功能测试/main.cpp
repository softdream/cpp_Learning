#include <iostream>

uint8_t lastBuffer[128];
uint8_t lastLength = 0;

uint8_t saveLastMessage(uint8_t *buff, uint8_t length)
{
	lastLength = 0;
	memset(lastBuffer, 0, sizeof(lastBuffer));

	if (buff == NULL) {
		return 0;
	}
	else if (length == 0) {
		return 0;
	}
	else {
		lastLength = length;
		memcpy(lastBuffer, buff, length);
		return 1;
	}
}

uint8_t messageCompare(uint8_t *buff, uint8_t length)
{
	int i = 0;
	if (buff == NULL) {
		return 0;
	}
	else if (length == 0) {
		return 0;
	}
	else if (length != lastLength) {
		return 0;
	}
	else {
		for (i = 0; i < length; i++) {
			if (buff[i] != lastBuffer[i]) {
				return 1;
				break;
			}
		}
		return 0;
	}
}


int main()
{
	uint8_t str[10] = {'H', 'e', 'l', 'l', 'o'};
	uint8_t str2[10] = { 'H', 'e', 'l', 'l', 'o' };

	std::cout<<(int)saveLastMessage( str, 5 )<<std::endl;
	std::cout << "last length: " << static_cast<int>( lastLength ) << std::endl;

	std::cout<<(int)messageCompare( str2, 5 )<<std::endl;
	return 0;
}