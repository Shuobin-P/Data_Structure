/********************************************************************************
* @author: Shuobin
* @date: 2024/5/22 17:26
* @version: 1.0
* @description: KMP模式匹配算法实现
********************************************************************************/

#include "kmp.h"

/**
 * 根据substr创建对应的next数组
 * @param next kmp中的next数组，nextArc[0]不存储有效数据
 * @param nextLen next数组长度
 * @param substr 模式串 substr[0]不存储有效数据
 */
void createNextArr(int *next, int nextLen, char *substr) {
    next[0] = -1;
    next[1] = 0;
    for (int i = 2; i <= nextLen - 1; i++) {    //i就是匹配失败的下标
        int modePtr = i - 1;
        //判断从substr[1->modePtr-1]的元素与i之前modePtr-1个元素是否相同；若相同，则modePtr就是next[i]的值；若不相同，modePtr--，重复上述过程。
        //例如：
        //  modePtr=4 substr[1->3]="aba" i之前的3个元素"bab"
        //  modePtr=3 substr[1->2]="ab" i之前的2个元素"ab"
        while (modePtr > 1) {
            int mainTmpPtr = i - 1;
            int modeTmpPtr = modePtr - 1;
            bool isEqual = true;
            while (modeTmpPtr >= 1) {
                if (substr[mainTmpPtr] != substr[modeTmpPtr]) {
                    isEqual = false;
                    break;
                }
                mainTmpPtr--;
                modeTmpPtr--;
            }
            if (isEqual) {
                next[i] = modePtr;
                break;
            } else {
                modePtr--;
            }
        }
        if (modePtr == 1) {
            next[i] = 1;
        }
    }
}

int kmp(char *str, int strLen, char *substr, int subStrLen) {
    //步骤一：根据substr创建next数组
    //步骤二：根据next数组去str中寻找substr的位置
    int next[subStrLen + 1]; //nextArc[0]不存储有效数据，即从下标1开始。
    createNextArr(next, subStrLen + 1, substr - 1);
    int i = 1, j = 1;
    while (i <= strLen && j <= subStrLen) {
        //若str[i]与substr[j]匹配，
        //  则i++,j++
        //若不匹配，
        //  根据next数组，为j选择新的位置
        if (str[i - 1] == substr[j - 1]) {
            i++, j++;
        } else {
            j = next[j];
            if (j == 0) {
                i++, j++;
            }
        }
    }
    //j超出了范围，说明找到了
    if (j > subStrLen) {
        return i - subStrLen - 1;
    } else {
        return -1;
    }

}
