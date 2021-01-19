//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <string>
#include "MyStack.h"
#include "postfix.h"

int main()
{
    std::string s1("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9");
    std::string s2=infix2prefix(s1);
    std::cout << s2;
}
