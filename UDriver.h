#ifndef UDRIVER_H
#define UDRIVER_H

#include <string>
/* JSON for Modern C++ https://github.com/nlohmann/json */
#include <fstream>
#include "json.hpp"
#include "serviopump.hpp"
#include "form.h"
#include "zlib.h"
#pragma comment(lib,"zlib-bcc.lib")
#pragma link "zlib-bcc.lib"
//#pragma option -k "_gzopen"

using namespace std;
using namespace nlohmann;

/* Драйвер терминала смарт-карт */
class TDriver {
protected:
    void* FServioPump;
   callback_fn_t* FCallback;
   free_response_fn_t* FFreeResponse;
   string LogPath;
   string CurrentFolderPath;

public:
    TDriver();
    void freeResponse(char* response);
	void call(char* request, int request_len, char** response, int* response_len);
	void extractLitresValue(const json& request, float & total);
	void extractPresetPrice(const json& request, float & price);
	void CreateOrExistsDir();
	void CreateFolder(char* text);
	size_t ByteOfFile(const string path);
	void Arcivate();



};

#endif // UDRIVER_H
