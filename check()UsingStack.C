#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // 스택 요소 저장을 위한 배열의 크기
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

// 오류 상황 처리를 위한 함수. 메시지 출력 후 프로그램 종료.
void error(char str[])
{
	printf("%s\n", str);
    exit(1);
}

// 스택의 주요 연산: 공통
void init_stack() {top = -1;} // 스택 초기화
int is_empty() { return top == -1; } // 스택이 비어있으면 TRUE를 아니면 FALSE를 반환한다.
int is_full() { return top == MAX_STACK_SIZE - 1;} // 스택이 가득 차 있으면 TRUE를 아니면 FALSE을 반환한다.
int size() { return top + 1;} // 스택 내의 모든 요소들의 개수를 반환한다.

void push (Element e) // 포화상태가 아니면 항목을 삽임함, 매개변수는 Element, 주어진 요소 X를 스택의 맨 위에 추가한다.
{
    if( is_full() )
        error ("스택 포화 에러");
    data[++top] = e;
}

Element pop () // 스택 맨 위에 있는 요소를 삭제하고 반환한다., 반환형은 Element
{
    if( is_empty() )
        error("스택 공백 에러");
    return data[top--];
}

Element peek () // 스택 맨 위에 있는 요소를 삭제하지 않고 반환한다. top이 감소하지 않음.
{
    if( is_empty())
        error ("스택 공백 에러");
    return data[top];
}

int check_matching(char expr[])
{
	int i = 0, prev;
	char ch;
	init_stack();
	while( expr[i] != '\0') 
	{
		ch = expr[i++];
        if( ch == '[' || ch == '(' || ch == '{')
            push(ch);
        else if( ch == ']' || ch == ')' || ch == '}')
        {
            if(is_empty())
                return 2;   // 조건 2 위반, 같은 타입의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 함.
            prev = pop();
            if ( (ch == ']' && prev != '[')
            ||   (ch == ')' && prev != '(')
            ||   (ch == '}' && prev != '{') ) {
                return 3;   // 조건 3 위반, 서로 다른 타입의 괄호 쌍이 서로를 교차하면 안 된다.
            }
        }
	}
    if(is_empty() == 0) return 1;   //조건 1 위반, 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 함.
    return 0;                       // 괄호 정상.
}

void main()
{
    char expr[4][80] = { "{A[(i+1)] = 0;}", "if((i == 0) && (j == 0)",
                        "A[(i+1)] = 0;", "A[i] = f();"};
    int errCode, i;

    for( i = 0; i < 4; i++)
    {
        errCode = check_matching(expr[i]);
        if (errCode == 0)
            printf(" 정상: %s\n", expr[i]);
        else
            printf(" 오류: %s (조건%d 위반)\n", expr[i], errCode);
    }

}