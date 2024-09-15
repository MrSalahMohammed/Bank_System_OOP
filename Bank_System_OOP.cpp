#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "../OOP_C++/clsUtils.h"
#include "clsShowLoginScreen.h"

int main()
{

    while (true)
    {

        if (!clsShowLoginScreen::Login())
            break;

    }

    system("pause>0");
    return 0;
    
}
