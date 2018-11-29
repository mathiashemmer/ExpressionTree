#include <expressionhandler.h>

bool Queue_Start(QueueNode *begin){
    begin->c = '\0';
    begin->nextNode = nullptr;
    return true;
}

// Validade expression, including open / closed pairs of brackets
bool EvaluateExpressionString(string expression){
    int strSize = expression.length();
    const char *toValidade = expression.c_str();
    bool isOk = true;
    bool wasOp = false;
    int openClosed = 0;

    for(int i = 0; i < strSize; i++ && isOk == true){
        if(toValidade[i] == '+' || toValidade[i] == '-' || toValidade[i] == '/' || toValidade[i] == '*'){
            if(i < strSize-1){
                if(toValidade[i+1] < '0' || toValidade[i+1] > '9'){ // Operator not preceeded by operand
                    isOk = false;
                }
            }else{ // Operator on last index of expreesion
                isOk = false;
            }
            if(wasOp){ // Double operator inserted ( as in 5++4)
                isOk = false;
            }
        }
        else if(toValidade[i] == '('){
            openClosed++;
            if(i < strSize-1){
                if(toValidade[i+1] < '0' || toValidade[i+1] > '9'){ // Open brackets without precedeb by a number (as in (4+)
                    isOk = false;
                }
            }else{ // Open brackets without anoter place to close (as is 5 + ()
                isOk = false;
            }
        }
        else if(toValidade[i] == ')'){
            openClosed--;
        }
        else if(toValidade[i] < '0' || toValidade[i] > '9')
            isOk = false;
    }
    if(openClosed != 0)
        return false;
    return isOk;
}
