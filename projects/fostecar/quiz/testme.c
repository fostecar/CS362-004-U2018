//Carissa Foster
//CS362
//Quiz3

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int randInt = -5;

	randInt = rand() % 9;  // returns values 0 to 8

	if (randInt == 0) {
		return '[';
	}
	else if (randInt == 1) {
		return '(';
	}
	else if (randInt == 2) {
		return '{';
	}
	else if (randInt == 3) {
		return ' ';
	}
	else if (randInt == 4) {
		return 'a';
	}
	else if (randInt == 5) {
		return 'x';
	}
	else if (randInt == 6) {
		return '}';
	}
	else if (randInt == 7) {
		return ')';
	}
	else if (randInt == 8) {
		return ']';
	}


    return '1';
}

char *inputString()
{
    // TODO: rewrite this function
	char *s;
	int randInt = -5;
	int i = -5;

	s = (char *)malloc(6 * sizeof(char));

	for (i = 0; i < 6; ++i) {
		randInt = rand() % 5; // returns values 0 to 4

		if (randInt == 0) {
			s[i] = 'r';
		}
		else if (randInt == 1) {
			s[i] = 'e';
		}
		else if (randInt == 2) {
			s[i] = 's';
		}
		else if (randInt == 3) {
			s[i] = 't';
		}
		else if (randInt == 4) {
			s[i] = '\0';
		}
		else {
			s[i] = '1';
		}

	}

    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
