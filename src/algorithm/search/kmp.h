/********************************************************************************
* @author: Shuobin
* @date: 2024/5/22 17:26
* @version: 1.0
* @description: 模式匹配算法实现
********************************************************************************/



#ifndef DATA_STRUCTURE_KMP_H
#define DATA_STRUCTURE_KMP_H

/**
 * 查找str中是否包含有substr；如果包含有substr，则返回substr在str中的下标，如果不包含，则返回-1。
 * @param str 主串
 * @param substr 目标子串
 * @return substr在str中的位置
 */
int kmp(char *str, int strLen, char *substr, int subStrLen) ;
#endif //DATA_STRUCTURE_KMP_H
