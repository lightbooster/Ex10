//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <string>
#include "MyStack.h"
#include "postfix.h"

int main() {
    std::string s1("2 + 2");
    std::string s2 = infix2postfix(s1);
    std::cout << s2;
}
