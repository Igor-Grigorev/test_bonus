#include <windows.h>
#include "serviopump.hpp"
#include "UDriver.h"



extern "C" __declspec(dllexport) __stdcall void* Init(void* reserved0, void* reserved1)
{
    try {
        TDriver* Driver = new TDriver();
        return (void*)Driver;
    }
    catch (...) {
        return NULL;
    }
}
extern "C" __declspec(dllexport)__stdcall void Deinit(void* callee)
{
    try {
        if (callee) {
            TDriver* Driver = (TDriver*)callee;
            delete Driver;
        }
    }
    catch (...) {
        /* silent */
    }
}

extern "C" __declspec(dllexport)__stdcall void Call(void* callee, char* request, int request_len,
    char** response, int* response_len)
{
    try {
		if (callee) {

			TDriver* Driver = (TDriver*)callee;
			Driver->call(request, request_len, response, response_len);
		}
	}
	catch (...) {
		/* silent */
	}
}

extern "C" __declspec(dllexport)__stdcall void FreeResponse(void* callee, char* response)
{
    try {
        if (callee) {
            TDriver* Driver = (TDriver*)callee;
            Driver->freeResponse(response);
        }
    }
    catch (...) {
        /* silent */
    }
}


/* —обыти€ инициализации динамической библиотеки Windows. */
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        break;
    }
    case DLL_THREAD_ATTACH:
    {
        break;
    }
    case DLL_THREAD_DETACH:
    {
        break;
    }
    }

    /* Return TRUE on success, FALSE on failure */
    return TRUE;
}

