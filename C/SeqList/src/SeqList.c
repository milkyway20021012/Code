#include "../include/SeqList.h"
// 对数据的管理 -- 增删查改
// 初始化顺序表
void SLInit(SL *ps)
{
    // 不能传入空的结构体指针
    assert(ps);
    ps->a = (SLDatatype *)malloc(sizeof(SLDatatype) * 4);
    if (ps->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    ps->capacity = 4;
    ps->size = 0;
}
// 顺序表的销毁
void SLDestroy(SL *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}
// 打印
void SLPrint(SL *ps)
{
    assert(ps);
    for (int i = 0; i < ps->size; ++i)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}
// 检查空间
bool CheckSize(SL *ps)
{
    assert(ps);
    return ps->size == ps->capacity;
}
// 尾插
void SLPushBack(SL *ps, SLDatatype x)
{
    assert(ps);
    if (CheckSize(ps))
    {
        SLDatatype *tmp = (SLDatatype *)realloc(ps->a, sizeof(SLDatatype) * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    ps->a[ps->size++] = x;
}
// 头插
void SLPushFront(SL *ps, SLDatatype x)
{
    assert(ps);
    if (CheckSize(ps))
    {
        SLDatatype *tmp = (SLDatatype *)realloc(ps->a, sizeof(SLDatatype) * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    // 挪动数据
    for (int i = ps->size; i > 0; --i)
    {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[0] = x;
    ++ps->size;
}

// 头删
void SLPopFront(SL *ps)
{
    assert(ps);
    assert(ps->size != 0);
    for (int i = 0; i < ps->size - 1; ++i)
    {
        ps->a[i] = ps->a[i + 1];
    }
    --ps->size;
}
// 尾删
void SLPopBack(SL *ps)
{
    assert(ps);
    assert(ps->size != 0);
    --ps->size;
}
// 顺序表查找
int SLFind(SL *ps, SLDatatype x)
{
    assert(ps);
    for (int i = 0; i < ps->size - 1; ++i)
    {
        if (ps->a[i] == x)
        {
            return i;
        }
    }
    return 0;
}
// 在pos位置插入数据
void SLInsert(SL *ps, int pos, SLDatatype x)
{
    assert(ps);
    if (CheckSize(ps))
    {
        SLDatatype *tmp = (SLDatatype *)realloc(ps->a, sizeof(SLDatatype) * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    for (int i = ps->size - 1; i >= pos; --i)
    {
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[pos] = x;
    ++ps->size;
}
// 删除顺序表在pos位置的数据
void SLErase(SL *ps, int pos)
{
    assert(ps);
    assert(ps->size != 0);
    for (int i = pos - 1; i < ps->size - 1; ++i)
    {
        ps->a[i] = ps->a[i + 1];
    }
    --ps->size;
    // 0 1 2 3 4 5 6 7
}