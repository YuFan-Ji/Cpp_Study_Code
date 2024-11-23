#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "fingerprint_db.txt"
#define FINGERPRINT_SIZE 64
#define MAX_USERS 20

// ����ṹ��洢�û���Ϣ
typedef struct {
    char username[50];
    char fingerprint[FINGERPRINT_SIZE + 1];
} User;

// ���ݿ�ṹ
User database[MAX_USERS];
int userCount = 0;

// ��ʼ�����ݿ��ļ�������ļ������ڣ������ļ����������û���
void initializeFile() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("���ݿ��ļ������ڣ����ڴ��������Ĭ���û�...\n");
        file = fopen(FILENAME, "w");
        if (!file) {
            printf("�޷��������ݿ��ļ���\n");
            exit(1);
        }
        fprintf(file, "alice 0011001100110011001100110011001100110011001100110011001100110011\n");
        fprintf(file, "bob   1111111111111111111111111111111111111111111111111111111111111111\n");
        fprintf(file, "carol 0000000000000000000000000000000000000000000000000000000000000000\n");
        fclose(file);
        printf("���ݿ��ļ��Ѵ��������Ĭ�����ݡ�\n");
    }
    else {
        fclose(file);
    }
}

// ���ļ��������ݿ�
void loadDatabase() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("�޷��������ݿ��ļ���\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", database[userCount].username, database[userCount].fingerprint) == 2) {
        userCount++;
        if (userCount >= MAX_USERS) break; // ��ֹ��������
    }
    fclose(file);
}

// �������ݿ⵽�ļ�
void saveDatabase() {
    FILE* file = fopen(FILENAME, "w");
    if (!file) {
        printf("�޷��������ݿ⣡\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s\n", database[i].username, database[i].fingerprint);
    }
    fclose(file);
}

// ����ָ��ƥ��
int findFingerprint(const char* fingerprint, int* index) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(database[i].fingerprint, fingerprint) == 0) {
            *index = i;
            return 1; // �ҵ�ƥ��ָ��
        }
    }
    return 0; // δ�ҵ�
}

// �û����봦��
void handleInput() {
    char username[50];
    char fingerprint[FINGERPRINT_SIZE + 1];

    printf("�������û�����ָ���������ո�ָ���ָ��64λ����\n");
    scanf("%s %s", username, fingerprint);

    if (strlen(fingerprint) != FINGERPRINT_SIZE) {
        printf("ָ�Ƴ��ȱ���Ϊ64λ��\n");
        return;
    }

    int index;
    if (findFingerprint(fingerprint, &index)) {
        if (strcmp(database[index].username, username) == 0) {
            printf("��֤�ɹ�\n");
        }
        else {
            printf("ָ���Ѵ��ڣ����û�����ƥ��\n");
        }
    }
    else {
        if (userCount >= MAX_USERS) {
            printf("���ݿ��������޷�������û���\n");
            return;
        }
        strcpy(database[userCount].username, username);
        strcpy(database[userCount].fingerprint, fingerprint);
        userCount++;
        printf("���û���ӳɹ�\n");
    }
}

int main() {
    // ��ʼ���ļ����������ݿ�
    initializeFile();
    loadDatabase();

    char choice;
    do {
        handleInput();
        printf("�Ƿ������(y/n)��");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // �������ݿ⵽�ļ�
    saveDatabase();
    return 0;
}
