#ifndef INCLUDED_CPPSOURCE
#define INCLUDED_CPPSOURCE

#pragma warning(push)
#pragma warning(disable:4996)
#include "INIReader.h"
#pragma warning(pop)


#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

class CppSource
{
public:
	static inline CppSource* GetInst()
	{
		if (nullptr == _Inst)
		{
			_Inst = new CppSource();

//			ReadIniFile();

			_IniData = make_shared<INIReader>("test.ini");

			if (_IniData->ParseError() != 0) {
				std::cout << "Can't load 'test.ini'\n";
			}
		}

		return _Inst;
	}

	static void ReadIniFile();

	static int LoadData();

private:
	//コンストラクタ
	CppSource() {};

	//デストラクタ
	~CppSource() {};

	static CppSource *_Inst;
	static shared_ptr<INIReader> _IniData;
};

#endif