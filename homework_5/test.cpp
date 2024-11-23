#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "fingerprint_db.txt"
#define FINGERPRINT_SIZE 64
#define MAX_USERS 20

// 定义结构体存储用户信息
typedef struct {
    char username[50];
    char fingerprint[FINGERPRINT_SIZE + 1];
} User;

// 数据库结构
User database[MAX_USERS];
int userCount = 0;

// 初始化数据库文件（如果文件不存在，创建文件并填充测试用户）
void initializeFile() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("数据库文件不存在，正在创建并填充默认用户...\n");
        file = fopen(FILENAME, "w");
        if (!file) {
            printf("无法创建数据库文件！\n");
            exit(1);
        }
        fprintf(file, "alice 0011001100110011001100110011001100110011001100110011001100110011\n");
        fprintf(file, "bob   1111111111111111111111111111111111111111111111111111111111111111\n");
        fprintf(file, "carol 0000000000000000000000000000000000000000000000000000000000000000\n");
        fclose(file);
        printf("数据库文件已创建并填充默认数据。\n");
    }
    else {
        fclose(file);
    }
}

// 从文件加载数据库
void loadDatabase() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("无法加载数据库文件！\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", database[userCount].username, database[userCount].fingerprint) == 2) {
        userCount++;
        if (userCount >= MAX_USERS) break; // 防止超出限制
    }
    fclose(file);
}

// 保存数据库到文件
void saveDatabase() {
    FILE* file = fopen(FILENAME, "w");
    if (!file) {
        printf("无法保存数据库！\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s\n", database[i].username, database[i].fingerprint);
    }
    fclose(file);
}

// 查找指纹匹配
int findFingerprint(const char* fingerprint, int* index) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(database[i].fingerprint, fingerprint) == 0) {
            *index = i;
            return 1; // 找到匹配指纹
        }
    }
    return 0; // 未找到
}

// 用户输入处理
void handleInput() {
    char username[50];
    char fingerprint[FINGERPRINT_SIZE + 1];

    printf("请输入用户名和指纹特征（空格分隔，指纹64位）：\n");
    scanf("%s %s", username, fingerprint);

    if (strlen(fingerprint) != FINGERPRINT_SIZE) {
        printf("指纹长度必须为64位！\n");
        return;
    }

    int index;
    if (findFingerprint(fingerprint, &index)) {
        if (strcmp(database[index].username, username) == 0) {
            printf("验证成功\n");
        }
        else {
            printf("指纹已存在，但用户名不匹配\n");
        }
    }
    else {
        if (userCount >= MAX_USERS) {
            printf("数据库已满，无法添加新用户！\n");
            return;
        }
        strcpy(database[userCount].username, username);
        strcpy(database[userCount].fingerprint, fingerprint);
        userCount++;
        printf("新用户添加成功\n");
    }
}

int main() {
    // 初始化文件并加载数据库
    initializeFile();
    loadDatabase();

    char choice;
    do {
        handleInput();
        printf("是否继续？(y/n)：");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // 保存数据库到文件
    saveDatabase();
    return 0;
}
