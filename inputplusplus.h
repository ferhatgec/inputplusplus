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
#define INPUT_PP_APOSTROPHE 39
#define INPUT_PP_BEGIN_BRACKETS 40
#define INPUT_PP_END_BRACKETS 41
#define INPUT_PP_ASTERISK 42
#define INPUT_PP_PLUS_SIGN 43
#define INPUT_PP_COMMA 44
#define INPUT_PP_HYPHEN 45
#define INPUT_PP_DOT 46
#define INPUT_PP_SLASH 47

#define INPUT_PP_NUMBER_ZERO 48
#define INPUT_PP_NUMBER_ONE 49
#define INPUT_PP_NUMBER_TWO 50
#define INPUT_PP_NUMBER_THREE 51
#define INPUT_PP_NUMBER_FOUR 52
#define INPUT_PP_NUMBER_FIVE 53
#define INPUT_PP_NUMBER_SIX 54
#define INPUT_PP_NUMBER_SEVEN 55
#define INPUT_PP_NUMBER_EIGHT 56
#define INPUT_PP_NUMBER_NINE 57

#define INPUT_PP_COLON 58
#define INPUT_PP_SEMICOLON 59
#define INPUT_PP_LESS_THAN_SIGN 60
#define INPUT_PP_EQUALS_SIGN 61
#define INPUT_PP_GREATER_THAN_SIGN 62
#define INPUT_PP_QUESTION_MARK 63
#define INPUT_PP_AT_SIGN 64
#define INPUT_PP_CAPITAL_LETTER_A 65
#define INPUT_PP_CAPITAL_LETTER_B 66
#define INPUT_PP_CAPITAL_LETTER_C 67
#define INPUT_PP_CAPITAL_LETTER_D 68
#define INPUT_PP_CAPITAL_LETTER_E 69
#define INPUT_PP_CAPITAL_LETTER_F 70
#define INPUT_PP_CAPITAL_LETTER_G 71
#define INPUT_PP_CAPITAL_LETTER_H 72
#define INPUT_PP_CAPITAL_LETTER_I 73
#define INPUT_PP_CAPITAL_LETTER_J 74 
#define INPUT_PP_CAPITAL_LETTER_K 75
#define INPUT_PP_CAPITAL_LETTER_L 76
#define INPUT_PP_CAPITAL_LETTER_M 77
#define INPUT_PP_CAPITAL_LETTER_N 78
#define INPUT_PP_CAPITAL_LETTER_O 79
#define INPUT_PP_CAPITAL_LETTER_P 80
#define INPUT_PP_CAPITAL_LETTER_Q 81
#define INPUT_PP_CAPITAL_LETTER_R 82
#define INPUT_PP_CAPITAL_LETTER_S 83
#define INPUT_PP_CAPITAL_LETTER_T 84
#define INPUT_PP_CAPITAL_LETTER_U 85
#define INPUT_PP_CAPITAL_LETTER_V 86 
#define INPUT_PP_CAPITAL_LETTER_W 87
#define INPUT_PP_CAPITAL_LETTER_X 88
#define INPUT_PP_CAPITAL_LETTER_Y 89
#define INPUT_PP_CAPITAL_LETTER_Z 90

#define INPUT_PP_BEGIN_SQUARE_BRACKETS 91
#define INPUT_PP_BACK_SLASH 92
#define INPUT_PP_END_SQUARE_BRACKETS 93
#define INPUT_PP_CIRCUMFLEX 94
#define INPUT_PP_UNDER_BAR 95
#define INPUT_PP_GRAVE_ACCENT 96


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
