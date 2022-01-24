#define START   0
#define FOUR    1
#define THREE   2
#define TWO     3
#define END     4
int transition[5][6]={
    {START,END,TWO,THREE,FOUR,END},
    {END,THREE,END,END,END,END},
    {END,TWO,END,END,END,END},
    {END,START,END,END,END,END},
    {END,END,END,END,END,END}
};

int get_status(int a){
    a %= 256;
    if(a < 128)
        return 0;
    if(a >= 128 && a <192)
        return 1;
    if(a >= 192 && a < 224)
        return 2;
    if(a >= 224 && a < 240)
        return 3;
    if(a >= 240 && a < 248)
        return 4;
    return 5;
}

bool validUtf8(int* data, int dataSize){
    int status = START;
    for(int i = 0; i < dataSize; i++){
        status = transition[status][get_status(data[i])];
        if(status == END)
            return false;
    }
    if(status != START)
        return false;
    else
        return true;
}
//只能说，自动机太难了？
//只能说，实在是不熟悉怎么写自动机吧。自动机的几种状态自己也找不太齐全，然后就变成了现在这个样子，要看别人画的自动机图片才能做，那可不行啊
//但是还是要说，自动机写的真的爽啊，简单干脆，没有乱七八糟的条件判断，太清爽了