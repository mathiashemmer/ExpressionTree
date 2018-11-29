#ifndef EXPRESSIONHANDLER_H
#define EXPRESSIONHANDLER_H

#include <string>

using namespace std;

struct QueueNode{
    char c;
    QueueNode *nextNode;
};

bool Queue_Start(QueueNode *begin);
bool EvaluateExpressionString(string expression);


#endif // EXPRESSIONHANDLER_H
