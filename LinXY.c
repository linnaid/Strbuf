#include "strbuf.h"
// 初始化 sb 结构体，容量为 alloc
void strbuf_init(struct strbuf *sb, size_t alloc){
    sb->alloc = alloc;
    if(sb == NULL)
    return -1;
    sb->buf = (char*)malloc((alloc+1) * sizeof(char));
    if(sb -> buf == NULL)
    {
        return -1;
    }
    return;
}
// 将字符串填充到 sb 中，长度为 len，容量为 alloc
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc){
    sb->alloc = alloc;
    sb->len = len;
    for(int i = 0; i < len; i++)
    {
        sb->buf[i] = str[i];
    }
    sb->buf[len] = '\0';
    return;
}
// 释放 sb 结构体的内存
void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    sb->buf = NULL;
    return;
}
// 交换两个 strbuf
void strbuf_swap(struct strbuf *a, struct strbuf *b){
    strbuf swap;
    swap.len = a->len;
    swap.buf = a->buf;
    swap.alloc = a->alloc;
    a->alloc = b->alloc;
    a->buf = b->buf;
    a->len = b->len;
    b->alloc = swap.alloc;
    b->buf = swap.buf;
    b->len = swap.len;
    return;
}
// 将 sb 中的原始内存取出，并将 sz 设置为其 alloc 大小
char *strbuf_detach(struct strbuf *sb, size_t *sz){
    *sz = sb->alloc;
    return sb->buf;
}
// 比较两个 strbuf 的内存是否相同
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){
    if(first->alloc != second->alloc)
    return 0;
    if(strncmp(first->buf,second->buf,first->len) != 0)
    return 0;
    else
    return 1;
}
// 清空 sb
void strbuf_reset(struct strbuf *sb){
    if(sb->buf != NULL)
    sb->buf[0] = '\0';
    sb->alloc = 0;
    sb->len = 0;
    return;
}

// 确保在 len 之后 strbuf 中至少有 extra 个字节的空闲空间可用。
void strbuf_grow(struct strbuf *sb, size_t extra){
    if(sb->alloc < len + extra)
    {
        sb->alloc = sb->len + extra;
        char* sd = (char*)realloc(sb->buf,(sb->alloc + 1)*sizeof(char));
        if(sd == NULL)
        return 0;
        sb->buf = sd;
    }
    return;
}
// 向 sb 追加长度为 len 的数据 data。
void strbuf_add(struct strbuf *sb, const void *data, size_t len){
    
    return;
}
// 向 sb 追加一个字符 c。
void strbuf_addch(struct strbuf *sb, int c){
    return;
}
// 向 sb 追加一个字符串 s。
void strbuf_addstr(struct strbuf *sb, const char *s){
    return;
}
// 向一个 sb 追加另一个 strbuf 的数据。
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2){
    return;
}
// 设置 sb 的长度 len。
void strbuf_setlen(struct strbuf *sb, size_t len){
    return;
}
// 计算 sb 目前仍可以向后追加的字符串长度。
size_t strbuf_avail(const struct strbuf *sb){
    return;
}
// 向 sb 内存坐标为 pos 位置插入长度为 len 的数据 data。
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len){
    return;
}

// 去除 sb 缓冲区左端的所有空格、制表符和'\t'字符。
void strbuf_rtrim(struct strbuf *sb){
    return;
}
// 去除 sb 缓冲区右端的所有空格、制表符和'\t'字符。
void strbuf_ltrim(struct strbuf *sb){
    return;
}
// 删除 sb 缓冲区从 pos 坐标开始长度为 len 的内容。
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len){
    return;
}

// 将文件描述符为 fd 的所有文件内容追加到 sb 中。sb 增长 hint ? hint : 8192 大小。
ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint){
    return;
}
// 将文件句柄为 fp 的一行内容（抛弃换行符）读取到 sb。
int strbuf_getline(struct strbuf *sb, FILE *fp){
    return;
}
//实现字符串切割（C 系字符串函数的一个痛点）。
// /**
// * @brief 将指定长度的字符串按切割字符切割成多个 strbuf
// *
// * @param str 要切割的字符串
// * @param len 字符串的长度
// * @param terminator 切割字符
// * @param max 最大切割数量（可选）
// * @return struct strbuf** 指向 struct strbuf 的指针数组，数组的最后一个元素为 NULL
// *
// * @note 函数将字符串 str 根据切割字符 terminator 切割成多个 strbuf，并返回结果。可选参数 max 用于限定最大切割数量。
// */
struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max){
    return;
}
//实现判断一个 strbuf 是否以指定字符串开头的功能（C 系字符串函数的另一个痛点）。
// /**
// * @brief 判断目标字符串是否以指定前缀开头
// *
// * @param target_str 目标字符串
// * @param str 前缀字符串
// * @param strlen target_str 的长度
// * @return bool 前缀相同返回 true，否则返回 false
// */
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen){
    return;
}
//获取字符串从坐标 [begin, end) 的所有内容（可以分成引用和拷贝两个模式） 。
// /**
// * @brief 获取目标字符串的指定子串
// *
// * @param target_buf 目标字符串
// * @param begin 开始下标（包含）
// * @param end 结束下标（不包含）
// * @param len target_buf 的长度
// * @return char* 指向获取的子串的指针，如果参数不合法则返回 NULL
// *
// * @note 下标从0开始，[begin, end)表示左闭右开区间
// */
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len){
    return;
}