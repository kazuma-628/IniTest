#include <stdio.h>
//#include "CppSource.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ini.h"

#define testaaa "テスト"

// Iniファイルを読み込んだ元データ
typedef struct
{
    int a1;
    int a2;
    int a3;
    int a4;
    int num;
} IniOriginalData;

// Iniファイルを読み込んだ元データを加工してプログラム内で使えるようにしたデータ
typedef struct
{
    int* data;
} IniData;

#pragma warning(push)
#pragma warning(disable:4996)

// Iniファイルを読み込むハンドラー
static int ReadIniHandler(void* user, const char* section, const char* name,
    const char* value)
{
    // 読み込んだデータを保存する構造体
    IniOriginalData* pIniOriginal = (IniOriginalData*)user;

// セクションと名前を確認する定義
#define CHECK_INI_DATA(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    ////////////////////
    // 以降、データ読み込み

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

// Iniファイルを読み込んだ元データを加工してプログラム内で使えるようにしたデータにする
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
    // Iniファイルを読み込んだ元データ
    IniOriginalData iniOriginalData;

    // Iniファイルを読み込む
    if (ini_parse("test.ini", ReadIniHandler, &iniOriginalData) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }

    // Iniファイルを読み込んだ元データを加工してプログラム内で使えるようにしたデータにする
    CreateIniData(&iniOriginalData, pIniData);

    return 0;
}