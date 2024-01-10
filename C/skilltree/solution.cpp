#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char* skill, const char* skill_tree) {
    int skill_len = strlen(skill);
    int skill_tree_len = strlen(skill_tree);
    int temp = -1; // 초기값을 -1로 설정

    for (int i = 0; i < skill_len; i++) {
        for (int j = 0; j < skill_tree_len; j++) {
            if (skill[i] == skill_tree[j]) {
                if (j < temp) {
                    return 0;
                }
                temp = j;
                break;
            }
            if (j == skill_tree_len - 1) {
                if (i == 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int solution(const char* skill, const char* skill_trees[], int skill_trees_len) {
    int answer = 0;
    for (int i = 0; i < skill_trees_len; i++) {
        if (compare(skill, skill_trees[i])) {
            answer++;
        }
    }
    return answer;
}

int main() {
    const char skill[] = "CBD";
    const char* skill_trees[] = { "BACDE", "CBADF", "AECB", "BDA" }; // 중괄호 사용
    int answer = solution(skill, skill_trees, 4); // 배열 크기 제거
    printf("%d", answer);
    return 0;
}
