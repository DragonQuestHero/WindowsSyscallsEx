#include <windows.h>
#include <dbghelp.h>
#include <Psapi.h>


#include <iostream>
#include <fstream>

std::fstream log_file;

BOOL PsymEnumeratesymbolsCallback(
    PSYMBOL_INFO pSymInfo,
    ULONG SymbolSize,
    PVOID UserContext
)
{
    log_file << pSymInfo->Name << ":"; 
    //log_file <<std::hex<< pSymInfo->Address << ":" << pSymInfo->Address - pSymInfo->ModBase << std::endl;
    log_file << std::hex << ": 0x" << pSymInfo->Address - pSymInfo->ModBase << std::endl;
    return TRUE;
}


int main()
{
    SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_FAVOR_COMPRESSED);
    if (!SymInitialize(GetCurrentProcess(), "SRV*http://msdl.microsoft.com/download/symbols", FALSE))//"SRV*http://msdl.microsoft.com/download/symbols"
    {
        std::cout << "error";
        getchar();
    }

    OFSTRUCT ReOpenBuff;
    HANDLE file_handle = (HANDLE)OpenFile("C:\\Users\\Administrator\\Desktop\\ntoskrnl.exe", &ReOpenBuff, OF_READ);


    DWORD Needed;
	ULONG64 Base[1024];
    EnumDeviceDrivers((LPVOID*)Base, sizeof(Base), &Needed);

    ULONG64 base_addr = SymLoadModuleEx(GetCurrentProcess(), file_handle, "C:\\Users\\Administrator\\Desktop\\ntoskrnl.exe", nullptr, Base[0], 0, 0, 0);


    log_file.open("log.txt",std::ios::out);

    if (!SymEnumSymbols(GetCurrentProcess(), Base[0], "*!*", &PsymEnumeratesymbolsCallback, NULL))
    {
        std::cout << "error";
        getchar();
    }










    system("pause");
}

