#ifndef UDRIVER_CPP
#define UDRIVER_CPP
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <psapi.h>
#include "serviopump.hpp"
#include "UDriver.h"
#include <cstdlib>
#include <codecvt> 
#pragma comment(lib, "archiv.lib")


using std::string;
namespace fs = std::filesystem;
using namespace std;
using namespace std::chrono;


TDriver::TDriver()
{
	/* Инициализация внутренних переменных */
	this->FCallback = NULL;
	this->FServioPump = NULL;
	this->FFreeResponse = NULL;
	LogPath = GetDLLFileName()  + "/LogFiles";//"C:/LogFiles"; //fs::current_path().string() + "/#LogFiles";
	this -> CreateOrExistsDir();
}


void TDriver::extractLitresValue(const json& request, float & litr) {
if (request.contains("PaymentTransaction")) {
	const json& paymentTransaction = request["PaymentTransaction"]["Items"][0];
	if (paymentTransaction.contains("Quantity")) {
		litr = paymentTransaction["Quantity"].get<float >();
	} else {
		litr = 888; // default value if "total" key is not present
	}
} else {
	litr = 88; // default value if "paymenttransaction" key is not present
}
}

void TDriver::extractPresetPrice(const json& request, float & price) {
if (request.contains("PaymentTransaction")) {
	const json& paymentTransaction = request["PaymentTransaction"]["Items"][0];
	if (paymentTransaction.contains("PresetPrice")) {
		price = paymentTransaction["PresetPrice"].get<float >();
	} else {
		price = 999; // default value if "total" key is not present
		}
	}
else {
	price = 99; // default value if "paymenttransaction" key is not present
	}
}

/* Вызов к драйверу */


// актуальное
//void TDriver::call(char* request, int request_len, char** response, int* response_len) {
//
//   //	экземпляр формы;
//	TForm1* form1 = new TForm1(NULL);
////	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
////	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
////	setlocale(LC_ALL,"Rus");
//
//	if (request && request_len >= 1) {
//		// Парсинг запроса в JSON
//		json jsRequest = json::parse(request);
//		// Объявление ответа
//		*response = nullptr;
//		*response_len = 0;
//
//
//		// Формирование ответа
//		json jsResponse = jsRequest;
//
//		// поиск вхождений
//		float  litr = 0.000;
//		float  price = 0.000;
//		extractLitresValue(jsResponse, litr);
//		extractPresetPrice(jsResponse, price);
//
//
//	   jsResponse[TAG_DEVELOPER_CODE] = "Strange string";
////	   std::string JSON = nlohmann::to_string(jsResponse);
//	   std::string JSON = jsResponse.dump(4);
//	   char* rsp = (char*)malloc(sizeof(char) * JSON.length());
//	   strcpy_s(rsp, JSON.length()+1, JSON.c_str()); // JSON.length()+1
//	   CreateOrExistsDir();
//	   CreateFolder(jsResponse,1);
//	   Arcivate();
//	   
//
//		 // вывод формы
//			form1->SetText(rsp);
//			form1->SetLitres(litr);  
//			form1->SetPrice(price);       
//			form1->ShowModal();
//		 //передача параметров в форму
//
//
//
//	   //string t =  form1->GetText().c_str();
//	   jsResponse["PaymentTransaction"]["Items"][0]["Quantity"] = StrToFloat(form1->GetValues(1).c_str());    //(form1->GetValues(1)).ToInt() StrToFloat(form1->GetValues(1).c_str());
//	   jsResponse["PaymentTransaction"]["Items"][0]["PresetPrice"] = StrToFloat(form1->GetValues(2).c_str());  //form1->GetValues(2).ToFloat();
//
////	   std::string FINJSON = nlohmann::to_string(jsResponse);
//	   std::string FINJSON = jsResponse.dump(4);
//	   char* rsp1 = (char*)malloc(sizeof(char) * FINJSON.size());
//	   strcpy_s(rsp1, FINJSON.size()+1, FINJSON.c_str());
//	   CreateOrExistsDir();
//	   CreateFolder(jsResponse,0);
//	   Arcivate();
//
//		*response = rsp1;   //rsp
//		*response_len = strlen(rsp1);
//	   //MessageBoxA(0, rsp1, "UT", 0);
//
//	}
//}
//////////////////// norm no ne to
void TDriver::call(char* request, int request_len, char** response, int* response_len) {
  TForm1* form1 = new TForm1(NULL);
  std::setlocale(LC_ALL, "Russian");

  if (request && request_len >= 1) {
    json jsRequest = json::parse(request);
    *response = nullptr;
    *response_len = 0;

    json jsResponse = jsRequest;

    float  litr = 0.000;
    float  price = 0.000;
    extractLitresValue(jsResponse, litr);
    extractPresetPrice(jsResponse, price);

    jsResponse[TAG_DEVELOPER_CODE] = "Strange string";
    std::string JSON = jsResponse.dump(4);
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wideStr = converter.from_bytes(JSON);
    const wchar_t* widePtr = wideStr.c_str();
    size_t wideLen = wideStr.length();
    wchar_t* rsp = new wchar_t[wideLen + 1];
    wcscpy_s(rsp, wideLen + 1, widePtr);
    CreateOrExistsDir();
    CreateFolder(jsResponse, 1);
    Arcivate();

    form1->SetText(rsp);
    form1->SetLitres(litr);
    form1->SetPrice(price);
    form1->ShowModal();

    jsResponse["PaymentTransaction"]["Items"][0]["Quantity"] = StrToFloat(form1->GetValues(1).c_str());
    jsResponse["PaymentTransaction"]["Items"][0]["PresetPrice"] = StrToFloat(form1->GetValues(2).c_str());

    std::string FINJSON = jsResponse.dump(4);
    std::wstring wideFinStr = converter.from_bytes(FINJSON);
    const wchar_t* wideFinPtr = wideFinStr.c_str();
    size_t wideFinLen = wideFinStr.length();
    wchar_t* rsp1 = new wchar_t[wideFinLen + 1];
    wcscpy_s(rsp1, wideFinLen + 1, wideFinPtr);
    CreateOrExistsDir();
    CreateFolder(jsResponse, 0);
    Arcivate();

    *response = rsp1;
    *response_len = static_cast<int>(wideFinLen);

  }
}


void TDriver::freeResponse(char* response)
{

	if (response) {
		free(response);
    }

}

void TDriver::CreateOrExistsDir(){
    char buf[255];
	strcpy(buf,LogPath.c_str());
   // MessageBoxA(0, buf, "Путь до лог файлов", 0);

	if (fs::exists(LogPath)){
		std::cout << "Directory is already exist\n";
	   //	MessageBoxA(0, "Directory is already exist\n", "Путь до лог файлов", 0);
	   }

	else
	try
	{if(fs::create_directory(LogPath)){
				std::cout << "Created a directory\n";}
				//MessageBoxA(0, "Created a directory\n", "Путь до лог файлов", 0);

			else
				{std::cerr << "Failed to create a directory\n";}
				//MessageBoxA(0, "Failed to create a directory\n", "Путь до лог файлов", 0);
				}
	catch (const std::exception& e){
			std::cerr << e.what() << '\n';}
}



void TDriver::CreateFolder(json text,int t){

	std::time_t now = std::time(0);
	std::tm* currentTime = std::localtime(&now);
	char file_name[100];
	char log_time[100];
	std::strftime(file_name, sizeof(file_name), "LogFile_%d%m%Y.txt", currentTime);
	std::strftime(log_time, sizeof(log_time), "%d.%m.%Y %H:%M", currentTime);

	std::string file_path = LogPath + "/" + file_name;
	CurrentFolderPath = file_path;
		// Преобразование JSON в красиво отформатированную строку
	std::string jsonStr = text.dump(4); // 4 - количество пробелов для отступа
	std::ofstream out(file_path, std::ios::app); // открываем файл для записи с названием текущего времени
	if (t == 1) {
	 if (out.is_open()) {
	out << log_time << std::endl;
	out <<  "Запрос от АСУ" << std::endl;
	out << jsonStr << std::endl;
	out.close();
	std::cout << "File has been written" << std::endl;
  } else {
	std::cout << "Unable to create file." << std::endl;}
	}
  else if(t == 0){
	 if (out.is_open()) {
	out << log_time << std::endl;
	out << "Ответ к АСУ" << std::endl;
	out << jsonStr << std::endl;
	out.close();
	std::cout << "File has been written" << std::endl;}
	 else {
	std::cout << "Unable to create file." << std::endl;}
  }
  
}


size_t TDriver::ByteOfFile(const string path){
	ifstream file(path.c_str()); // файл
    size_t s = 0; // счетчик символов

    while (!file.eof()) { // пока не достигнут конец файлв
        file.get();       // читать по одному символу
        s++;              // и увеличивать счетчик
	}

	file.close(); // обязательно закрыть

    s--; // убираем лишнюю итерацию

	return s; // вернуть число символов/байтов
}



 // Архивирование файла при достижении заданного размера
extern "C" void _stdcall archivate(const char* inputFilePath, const char* outputFilePath);
  void TDriver::Arcivate() {
  if (ByteOfFile(CurrentFolderPath) >= 74428) {

  
 
	// получаем текущее время
	std::time_t now = std::time(0);
	std::tm* currentTime = std::localtime(&now);
	
//	 if (CurrentFolderPath.size() >= 4 && CurrentFolderPath.substr(CurrentFolderPath.size() - 4) == ".txt") {
//	// Удаляем расширение ".txt"
//	CurrentFolderPath = CurrentFolderPath.substr(0, CurrentFolderPath.size() - 4);
//  }
	char file_name[100];
	std::strftime(file_name, sizeof(file_name), "%H%M%S.txt", currentTime);
	string add_time = CurrentFolderPath + file_name;
	const char*   inputFilePath = CurrentFolderPath.c_str();
	const char*   outputFilePath =add_time.c_str(); //| CurrentFolderPath.c_str();
	// Вызов функции
	archivate(inputFilePath, outputFilePath);
	remove(CurrentFolderPath.c_str());
//	gets(file);
//	if(remove(CurrentFolderPath.c_str()) == 0)
//	MessageBoxA(0, "deleted", "UT", 0);
//	

}
  }



// функция поиска DLL
string TDriver::GetDLLFileName()
{
  MEMORY_BASIC_INFORMATION mbi;
  static int dummy;
  VirtualQuery(&dummy, &mbi, sizeof(mbi));
  DWORD_PTR hMod = reinterpret_cast<DWORD_PTR>(mbi.AllocationBase);
  static wchar_t szModule[MAX_PATH];
  GetModuleFileNameW(reinterpret_cast<HMODULE>(hMod), szModule, MAX_PATH);

  // Удаление подстроки "\\bonus.dll" из szModule
  wchar_t* pSubstr = wcsstr(szModule, L"\\bonus.dll");
  if (pSubstr != NULL)
  {
    wcscpy(pSubstr, pSubstr + wcslen(L"\\bonus.dll"));
  }

  std::wstring wideString(szModule);
  std::string result(wideString.begin(), wideString.end());
  return result;
  //MEMORY_BASIC_INFORMATION mbi;
        //static int dummy;
        //VirtualQuery(&dummy, &mbi, sizeof(mbi));
        //DWORD_PTR hMod = reinterpret_cast<DWORD_PTR>(mbi.AllocationBase);
        //static wchar_t szModule[MAX_PATH];
        //GetModuleFileNameW(reinterpret_cast<HMODULE>(hMod), szModule, MAX_PATH);
        //std::wstring moduleFileName = szModule;
        //moduleFileName = moduleFileName.substr(0, moduleFileName.length() - 8);
        //std::string result(moduleFileName.begin(), moduleFileName.end());
        //MessageBoxA(0, result.c_str(), "qwewrq", 0);
        ////place = result;
        //return result;
}

#endif // UDRIVER_CPP

