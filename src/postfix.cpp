//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <map>
#include "postfix.h"
#include "MyStack.h"

std::string infix2prefix(std::string init_string) {
  std::map<char, int> op_w = {{'(', 0}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3}};
  MyStack<char> stack((int)init_string.length());
  std::string postfix_string = "";

  for (int i = 0; i < init_string.length(); i++) {
    // space handler
    if (init_string[i] == ' '){
      if (postfix_string[postfix_string.length() - 1] != ' ')
        postfix_string += " ";
      continue;
    }

    auto priority = op_w.find(init_string[i]);
    // just a number
    if (priority == op_w.end()) {
      postfix_string += init_string[i];
      continue;
    }

    // operation
    if (stack.isEmpty() || op_w[init_string[i]] == 0 || op_w[init_string[i]] > op_w[stack.get()]) {
      // push to stack
      stack.push(init_string[i]);
      continue;
    }

    if (op_w[init_string[i]] == 1) {
      // found closing bracket
      while (!stack.isEmpty() && stack.get() != '(') {
        if (postfix_string[postfix_string.length() - 1] != ' ')
          postfix_string += " ";

        postfix_string += stack.pop();
      }
      stack.pop();
    } else {
      // another operation
      while (!stack.isEmpty() && op_w[stack.get()] >= op_w[init_string[i]]) {
        if (postfix_string[postfix_string.length() - 1] != ' ')
          postfix_string += " ";

        postfix_string += stack.pop();

      }
      stack.push(init_string[i]);
    }
  }

  while (!stack.isEmpty()) {
    if (postfix_string[postfix_string.length() - 1] != ' ')
      postfix_string += " ";
    
    postfix_string += stack.pop();
  }

  return postfix_string;
}
