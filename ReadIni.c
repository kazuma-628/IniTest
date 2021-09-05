#include <stdio.h>
//#include "CppSource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini.h"

#define testaaa "�e�X�g"

// Ini�t�@�C����ǂݍ��񂾌��f�[�^
typedef struct
{
    int a1;
    int a2;
    int a3;
    int a4;
    int num;
} IniOriginalData;

// Ini�t�@�C����ǂݍ��񂾌��f�[�^�����H���ăv���O�������Ŏg����悤�ɂ����f�[�^
typedef struct
{
    int* data;
} IniData;

#pragma warning(push)
#pragma warning(disable:4996)

// Ini�t�@�C����ǂݍ��ރn���h���[
static int ReadIniHandler(void* user, const char* section, const char* name,
    const char* value)
{
    // �ǂݍ��񂾃f�[�^��ۑ�����\����
    IniOriginalData* pIniOriginal = (IniOriginalData*)user;

// �Z�N�V�����Ɩ��O���m�F�����`
#define CHECK_INI_DATA(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    ////////////////////
    // �ȍ~�A�f�[�^�ǂݍ���

    if (CHECK_INI_DATA(testaaa, "a1")) {
        pIniOriginal->a1 = atoi(value);
    }
    else if (CHECK_INI_DATA(testaaa, "a2")) {
        pIniOriginal->a2 = atoi(value);
    }
    else if (CHECK_INI_DATA(testaaa, "a3")) {
        pIniOriginal->a3 = atoi(value);
    }
    else if (CHECK_INI_DATA(testaaa, "a4")) {
        pIniOriginal->a4 = atoi(value);
    }
    else if (CHECK_INI_DATA(testaaa, "num")) {
        pIniOriginal->num = atoi(value);
    }
    else {
        return 0;  /* unknown section/name, error */
    }
    return 1;
}

#pragma warning(pop)

// Ini�t�@�C����ǂݍ��񂾌��f�[�^�����H���ăv���O�������Ŏg����悤�ɂ����f�[�^�ɂ���
static void CreateIniData(IniOriginalData* pIniOriginal, IniData* pIniData)
{
    pIniData->data = calloc(pIniOriginal->num, sizeof(int));

    memmove(pIniData->data, &pIniOriginal->num, sizeof(int));
    memmove(pIniData->data + 1, &pIniOriginal->a1, sizeof(int));
    memmove(pIniData->data + 2, &pIniOriginal->a2, sizeof(int));
    memmove(pIniData->data + 3, &pIniOriginal->a3, sizeof(int));
}


int ReadIni(IniData *pIniData)
{
    // Ini�t�@�C����ǂݍ��񂾌��f�[�^
    IniOriginalData iniOriginalData;

    // Ini�t�@�C����ǂݍ���
    if (ini_parse("test.ini", ReadIniHandler, &iniOriginalData) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }

    // Ini�t�@�C����ǂݍ��񂾌��f�[�^�����H���ăv���O�������Ŏg����悤�ɂ����f�[�^�ɂ���
    CreateIniData(&iniOriginalData, pIniData);

    return 0;
}