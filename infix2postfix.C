#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void init_stack() { top = -1; }
int size() { return top + 1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_STACK_SIZE -1); }

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void push (Element e) {
	if (is_full())
		error("스택 포화 에러");
		
	data[++top] = e; 
}

Element pop() {
	if(is_empty())
		error("스택 공백 에러");
		
	return data[top--];
}

Element peek() {
	if(is_empty())
		error("스택 공백 에러");
		
	return data[top];
}

static int precedence(char op) {
	switch(op) {
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	
	return -1;
}

void infix_to_postfix(char expr[]) {
	int i = 0;
	char term, e;
	
	init_stack();		//스택 초기화 
	
	while(expr[i] != '\0') {		//받은 수식에 처리할 항이 남아있으면 
		term = expr[i++];			//temp = 다음에 처리할 항 
			
		switch(term) {
			case '(': push(term); break;			//왼쪽 괄호 일시 
			
			case ')':
				while (!is_empty()) {				//오른쪽 괄호 일시 
					e = pop();
					
					if (e == '(') break;
					else printf("%c", e);
				}
				break;
				
			case '+': case '-': case '*': case '/':		//연산자 일시 
				while (!is_empty()) {
					e = peek();
					
					if (precedence(term) <= precedence(e)) {
						printf("%c", e);
						pop();
					} else break;
				}
				
				push(term);
				break;
				
			default:
				printf("%c", term); break;		//피연산자 일시 
		}
	}
	
	while (!is_empty())			//남은 스택 출력 
		printf("%c", pop());
	
	printf("\n");
}

int main() {
	char expr[2][80] = {"8/2-3+(3*2)", "1/2*4*(1/4)"};

	printf("중위수식: %s ==> 후위수식:", expr[0]);
	infix_to_postfix(expr[0]);
	printf("중위수식: %s ==> 후위수식:", expr[1]);
	infix_to_postfix(expr[1]);
	
	return 0;
}