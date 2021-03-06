/**
* queue：先进先出的数据结构
**/

int front; //队首指针
int rear; //队尾指针

//清空（clear）
void clear() {
    front = rear = -1;
}

//获取队列内元素的个数（size）
int size() {
    return rear - front;
}

//判空（empty）
bool empty() {
    if (front == rear)
        return true;
    else
        return false;
}

//入队（push）
void push(int x) {
    q[++rear] = x;
}

//出队（pop）
void pop() {
    front++;
}

//取队首元素（get_front）
int get_front() {
    return q[front + 1];
}

//取队尾元素（get_rear）
int get_rear() {
    return q[rear];
}

//注意判空

//STL实现清空
while (!q.empty()) {
    q.pop();
}
