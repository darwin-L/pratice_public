/*
 * @Author:darwin.lang
 * @Date:2022-03-16 23:37:01
 * @LastEditors:darwin.lang
 * @LastEditTime:2022-04-19 22:55:06
 * @Description:
 */
// https://eli.thegreenplace.net/2012/07/12/computed-goto-for-efficient-dispatch-tables
// 比較這個和用map去做stratege的brenchmark

#include <iostream>
using namespace std;
#define DISPATCH() goto *dispatch_table[code[pc++]]
int interp_cgoto(unsigned char* code, int initval) {
    /* The indices of labels in the dispatch_table are the relevant opcodes
    */
    static void* dispatch_table[] = {
        &&do_halt, &&do_inc, &&do_dec, &&do_mul2,
        &&do_div2, &&do_add7, &&do_neg};


    int pc = 0;
    int val = initval;

    DISPATCH();
    while (1) {
        do_halt:
            return val;
        do_inc:
            val++;
            DISPATCH();
        do_dec:
            val--;
            DISPATCH();
        do_mul2:
            val *= 2;
            DISPATCH();
        do_div2:
            val /= 2;
            DISPATCH();
        do_add7:
            val += 7;
            DISPATCH();
        do_neg:
            val = -val;
            DISPATCH();
    }
}

int main(void){
    interp_cgoto((unsigned char *)"do_inc",1);
    return 0;
}
