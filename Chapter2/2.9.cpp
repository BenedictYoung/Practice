/*
* 题目名称：Grading
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/E9rDPSq
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int perfect, tolerance, grade1, grade2, grade3, gradeJudge;
    while (cin >> perfect >> tolerance >> grade1 >> grade2 >> grade3 >> gradeJudge) {
        double answer;
        if (abs(grade1 - grade2) <= tolerance) {
            answer = (grade1 + grade2) / 2.0;
        } else if (abs(grade1 - grade3) <= tolerance && abs(grade2 - grade3) > tolerance) {
            answer = (grade1 + grade3) / 2.0;
        } else if (abs(grade2 - grade3) <= tolerance && abs(grade1 - grade3) > tolerance) {
            answer = (grade2 + grade3) / 2.0;
        } else if (abs(grade1 - grade3) <= tolerance && abs(grade2 - grade3) <= tolerance) {
            answer = max(max(grade1, grade2), grade3);
        } else {
            answer = gradeJudge;
        }
        printf("%.1f\n", answer);
    }
    return 0;
}
