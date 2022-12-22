#include "TV.h"

void TV::Print() const 
{
	Device::Print();
	if (onOff)
		cout << "Current TV channel " << currentlyChannel << '/' << allChannels << endl;
}
void TV::ChangeChannel(int channel)
{
	if (onOff)
	{
		cout << "The device is turned off.\n";
		return;
	}
	if (channel <= 0)
		currentlyChannel = 1;
	else if (allChannels <= channel)
		currentlyChannel = allChannels;
	else
		currentlyChannel = channel;
}