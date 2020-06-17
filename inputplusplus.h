/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef INPUT_PLUS_PLUS_H
#define INPUT_PLUS_PLUS_H

#ifndef _TERMIOS_H
#include <termios.h>
#endif
#ifndef _STDIO_H
#include <stdio.h>
#endif

#define INPUT_PP_SPACE 32
#define INPUT_PP_EXCLAMATION_MARK 33
#define INPUT_PP_QUOTATION_MARK 34
#define INPUT_PP_NUMBER_SIGN 35
#define INPUT_PP_DOLLAR_SIGN 36
#define INPUT_PP_PERCENT_SIGN 37
#define INPUT_PP_AMPERSAND 38

namespace inputplusplus {
	int CharInput() {
	        struct termios t;
        	int c;
        	tcgetattr(0,&t);
        	t.c_lflag&=~ECHO+~ICANON;
        	tcsetattr(0,TCSANOW,&t);
        	fflush(stdout);
        	c=getchar();
        	t.c_lflag|=ICANON+ECHO;
        	tcsetattr(0,TCSANOW,&t);
        	return c;
	}
	
	int EchoCharInput() {
	        struct termios t;
        	int c;
        	tcgetattr(0,&t);
        	t.c_lflag&=~ECHO+~ICANON;
        	tcsetattr(0,TCSANOW,&t);
        	fflush(stdout);
        	c=getchar();
        	t.c_lflag|=ICANON+ECHO;
        	tcsetattr(0,TCSANOW,&t);
        	return c;
	}
	
	bool GetInput(int ascii) {
		if(CharInput() == ascii) {
			return true;
		} else {
			return false;
		}
	}
	
	bool EchoGetInput(int ascii) {
		if(EchoCharInput() == ascii) {
			return true;
		} else {
			return false;
		}
	}
	
}

#endif // INPUT_PLUS_PLUS_H
