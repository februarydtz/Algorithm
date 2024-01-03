/***
假设你开了间小店，不能电子支付，
钱柜里的货币只有 25 分、10 分、5 分和 1 分四种硬币，
如果你是售货员且要找给客户 41 分钱的硬币，
如何安排才能找给客人的钱既正确且硬币的个数又最少？
*/

#include<iostream>
using namespace std;

#define ONEFEN    1
#define FIVEFEN    5
#define TENFEN    10
#define TWENTYFINEFEN 25

int main()
{
    int sum_money=41;
    int num_25=0,num_10=0,num_5=0,num_1=0;

    //不断尝试每一种硬币
    while(sum_money>=TWENTYFINEFEN) { num_25++; sum_money -=TWENTYFINEFEN; }
    while(sum_money>=TENFEN) { num_10++; sum_money -=TENFEN; }
    while(sum_money>=FIVEFEN)  { num_5++;  sum_money -=FIVEFEN; }
    while(sum_money>=ONEFEN)  { num_1++;  sum_money -=ONEFEN; }

    //输出结果
    cout<< "25分硬币数："<<num_25<<endl;
    cout<< "10分硬币数："<<num_10<<endl;
    cout<< "5分硬币数："<<num_5<<endl;
    cout<< "1分硬币数："<<num_1<<endl;

    return 0;
}