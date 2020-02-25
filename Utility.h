#pragma once

#include <Windows.h>

//Thanks to Rake for his scanning code
class Utility
{
public:
    static char* ScanBasic(char* pattern, char* mask, char* begin, uintptr_t size)
    {
        uintptr_t patternLen = strlen(mask);

        //for (int i = 0; i < size - patternLen; i++)
        for (int i = 0; i < size; i++)
        {
            bool found = true;
            for (int j = 0; j < patternLen; j++)
            {
                if (mask[j] != '?' && pattern[j] != *(char*)((uintptr_t)begin + i + j))
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return (begin + i);
            }
        }
        return nullptr;
    }

    static char* Scan(char* pattern, char* mask, char* begin, uintptr_t size)
    {
        char* match{ nullptr };
        DWORD oldprotect = 0;
        MEMORY_BASIC_INFORMATION mbi{};

        for (char* curr = begin; curr < begin + size; curr += mbi.RegionSize)
        {
            if (!VirtualQuery(curr, &mbi, sizeof(mbi)) || mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS) continue;

            if (VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
            {
                match = ScanBasic(pattern, mask, curr, mbi.RegionSize);

                VirtualProtect(mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

                if (match != nullptr)
                {
                    break;
                }
            }
        }
        return match;
    }

    static char* ScanProc(char* pattern, char* mask)
    {
        unsigned long long int kernelMemory = (sizeof(char*) == 4) ? 0x80000000 : 0x800000000000;

        return Scan(pattern, mask, 0x0, (uintptr_t)kernelMemory);
    }

};