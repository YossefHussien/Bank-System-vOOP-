#include <iostream>
#include "clsLoginScreen.h"

template <typename T> T myMax(T Number1, T Number2)
{
	return (Number1 > Number2) ? Number1 : Number2;
}
int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}


}