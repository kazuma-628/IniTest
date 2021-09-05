// Iniファイルを読み込んだ元データ
typedef struct
{
    int a1;
    int a2;
    int a3;
    int a4;
} IniOriginalData;

// Iniファイルを読み込んだ元データを加工してプログラム内で使えるようにしたデータ
typedef struct
{
    int* data;
} IniData;

// Iniファイルを読み込むハンドラー
static int ReadIniHandler(void* user, const char* section, const char* name, const char* value);

// Iniファイルを読み込んだ元データを加工してプログラム内で使えるようにしたデータにする
int CreateIniData(IniOriginalData* pIniOriginal, IniData* pIniData);

// Iniファイルを読み込む
int ReadIni(IniData* pIniData);