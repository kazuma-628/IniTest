#include "CppSource.h"


shared_ptr<CppSource> CppSource::*_Inst = nullptr;
shared_ptr<INIReader>  CppSource::_IniData = nullptr;


void CppSource::ReadIniFile()
{
	_IniData = make_shared<INIReader>("test.ini");

	if (_IniData->ParseError() != 0) {
		std::cout << "Can't load 'test.ini'\n";
	}
}


int CppSource::LoadData()
{
	return _IniData->GetInteger("protocol", "version", -1);
}