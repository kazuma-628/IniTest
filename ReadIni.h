// Ini�t�@�C����ǂݍ��񂾌��f�[�^
typedef struct
{
    int a1;
    int a2;
    int a3;
    int a4;
} IniOriginalData;

// Ini�t�@�C����ǂݍ��񂾌��f�[�^�����H���ăv���O�������Ŏg����悤�ɂ����f�[�^
typedef struct
{
    int* data;
} IniData;

// Ini�t�@�C����ǂݍ��ރn���h���[
static int ReadIniHandler(void* user, const char* section, const char* name, const char* value);

// Ini�t�@�C����ǂݍ��񂾌��f�[�^�����H���ăv���O�������Ŏg����悤�ɂ����f�[�^�ɂ���
int CreateIniData(IniOriginalData* pIniOriginal, IniData* pIniData);

// Ini�t�@�C����ǂݍ���
int ReadIni(IniData* pIniData);