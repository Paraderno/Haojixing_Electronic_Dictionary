/*
 * Created by FallenGemini on 2022/7/13.
 * �û�����ʵ��
 */
#include "user.h"
#include "public.h"
#include "admin.h"
#include "List.h"
#include "draw.h"
#include <malloc.h>
#pragma warning(disable:4996)

int Register(AccountLinkList* aList, char* accountID, char* password) {
    Account account;
    account.type = USER;
    strcpy(account.ID, accountID);
    strcpy(account.password, password);
    InsertAccountLinkList(aList, aList->length, account);
    SaveAccountData(aList);
    return 1;
}

/** Ӣ�뺺 */
Word EnToCn(WordLinkList* wList, char* En)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������

    int pos = 1;
    for (; pos < length; pos++)
    {
        if (strcmp(currentNode->word.En, En) == 0) break;
        currentNode = currentNode->next;
    }
    if (pos == length)
    {
        printf("û���ҵ��������\n");
        sleep_second(2);
        Word NullWord = {"", ""};
        return NullWord;
    }

    printf("%-10s%-10s\n", currentNode->word.En
        , currentNode->word.Cn);
    return currentNode->word;
}

/** ����Ӣ */
void CnToEn(WordLinkList* wList, char* Cn)
{
    WordNode* currentNode = wList->next;   //ȡ����һ�����
    int length = wList->length;  //������
    int count = 0;
    int pos = 1;
    int X = 5, Y = 10;
    for (; pos <= length; pos++)
    {
        if (strstr(currentNode->word.Cn, Cn) != NULL) {
            SetPosition(X, Y);
            printf("%-15s%-15s\n",currentNode->word.En
                , currentNode->word.Cn);
            Y++;
            count++;
        }
        currentNode = currentNode->next;
    }
    if (count == 0)
    {
        SetPosition(5, 10);
        printf("û���ҵ��������\n");
        return;
    }
}

/** �ղشʻ� */
void Star(WordLinkList* wList, Word currWord) {
    WordLinkList* sList = (WordLinkList*)malloc(sizeof(WordLinkList));
    sList->length = 1;
    sList->next = (WordNode*)malloc(sizeof(WordNode));

    InsertWordLinkList(sList, sList->length, currWord);   // ��������
    SaveStarCase(sList);   // ���棨д�룩�ղؼ�
}

/** �����ղؼ� */
void StarCase(int choice) {
    WordLinkList* sList = (WordLinkList*)malloc(sizeof(WordLinkList));
    sList->length = 1;
    sList->next = (WordNode*)malloc(sizeof(WordNode));

    LoadStarCase(sList);
    // ��ʾ�ղؼ�����
    PrintWordLinkList(sList);
    
    if (choice == 1) { // ɾ������
        printf("������Ҫɾ����Ӣ�ĵ��ʣ�");

        Word word;
        scanf("%50s", word.En);

        WordNode* currNode = sList->next;
        for ( ; currNode; ) {
            if (strcmp((currNode->word).En, word.En) == 0) {
                strcpy(word.Cn, (currNode->word).Cn);
            }
            currNode = currNode->next;
        }
        DeleteWordLinkListByWord(sList, word);
        SaveStarCase(sList);
    } else {  
        // �˳�����


    }
    
}

/** �����ղؼ� */
int LoadStarCase(WordLinkList* sList) {
    Word word;
    int size = 0;

    // ���ļ� ("sFile" is short for "StarCase File")
    FILE* sFile = fopen("resource\\StarCase.txt", "r");

    if (sFile == NULL) {
        printf("�Ҳ����ʿ��ļ�������\n");
    }
    else {
        // ��������
        while (!feof(sFile)) {
            size++;
            fscanf(sFile, "%s %s", word.En, word.Cn);
            // ���ʿ�����д�������
            InsertWordLinkList(sList, size, word);
        }
        //printf("�������ݳɹ�.\n");
    }

    fclose(sFile);
    return 1;
}


/** �����ղؼ� */
void SaveStarCase(WordLinkList* sList) {
    // ���ļ� ("sFile" is short for "StarCase File")
    FILE* sFile = fopen("resource\\StarCase.txt", "w");
    WordNode* currNode = sList->next;

    // д������
    for (int i = 1; i < sList->length; ++i) {
        if (i != 1)
        {
            fprintf(sFile, "\n");
        }
        fprintf(sFile, "%s %s", currNode->word.En, currNode->word.Cn);
        currNode = currNode->next;
    }
    // printf("����ɹ���\n");

    // �ر��ļ�
    fclose(sFile);
}