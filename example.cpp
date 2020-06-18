/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include "inputplusplus.h"
#include <iostream>
#include <string>

int main() {
	if(inputplusplus::EchoGetInput(INPUT_PP_SPACE) == true) {
		std::cout << "Space\n";
	}
	return 0;
}
