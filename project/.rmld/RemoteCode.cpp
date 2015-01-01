#include <windows.h>
#include "RemoteCode.h"

#ifndef _M_X64
BYTE m_code1[] = {                      // DWORD WINAPI Fun(DWORD pd)           // call ptr(pd, DLL_PROCESS_ATTACH, 0);
    0x55,                               //   0: push ebp
    0x8B,0xEC,                          //   1: mov ebp,esp
    0x8B,0x45,0x08,                     //   3: mov eax,dword ptr [ebp+8]
    0x6A,0x00,                          //   6: push 0
    0x6A,0x01,                          //   8: push 1 ? DLL_PROCESS_ATTACH
    0x50,                               //  10: push eax
    0xB8,0x00,0x00,0x00,0x00,           //  11: mov eax,ptr:00000000 ?          // DllMain
    0xFF,0xD0,                          //  16: call eax
    0x5D,                               //  18: pop ebp
    0xC2,0x04,0x00,                     //  19: ret 4
};
const int __pos1_ul_reason_for_call = 9;
const int __pos1_DllMain = 12;
#else
BYTE m_code1[] = {                      // DWORD WINAPI Fun(QWORD pd)           // call ptr(pd, DLL_PROCESS_ATTACH, 0);
    0x4D,0x33,0xC0,                     //   0: xor r8,r8
    0x41,0x8D,0x50,0x01,                //   3: lea edx,[r8+1] ? DLL_PROCESS_ATTACH
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, //   7: mov rax,ptr:0000000000000000 ?  // DllMain
        0x00,0x00,0x00,
    0xFF,0xE0                           //  17: jmp rax
};
const int __pos1_ul_reason_for_call = 6;
const int __pos1_DllMain = 9;
#endif
const int sizeof_m_code1 = sizeof(m_code1);

#ifndef _M_X64
BYTE m_code2[] = {                      // DWORD WINAPI Fun(DWORD* pd)          // call ptr(pd[1], pd[2]);
    0x55,                               //   0: push ebp
    0x8B,0xEC,                          //   1: mov ebp,esp
    0x8B,0x45,0x08,                     //   3: mov eax,dword ptr [ebp+8]
    0x8B,0x48,0x04,                     //   6: mov ecx,dword ptr [eax+4]
    0x8B,0x10,                          //   9: mov edx,dword ptr [eax]
    0x51,                               //  11: push ecx
    0x52,                               //  12: push edx
    0xB8,0x00,0x00,0x00,0x00,           //  13: mov eax,ptr:00000000 ?          // GetProcAddress
    0xFF,0xD0,                          //  18: call eax
    0x5D,                               //  20: pop ebp
    0xC2,0x04,0x00                      //  21: ret 4
};
const int __pos2_GetProcAddress = 14;
#else
BYTE m_code2[] = {                      // DWORD WINAPI Fun(QDWORD* pd)         // call ptr(pd[1], pd[2]);
    0x48,0x8B,0x51,0x08,                //   0: mov rdx,qword ptr [rcx+8]
    0x48,0x8B,0x09,                     //   4: mov rcx,qword ptr [rcx]
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, //   7: mov rax,ptr:0000000000000000 ?  // GetProcAddress
        0x00,0x00,0x00,
    0xFF,0xE0                           //  17: jmp rax
};
const int __pos2_GetProcAddress = 9;
#endif
const int sizeof_m_code2 = sizeof(m_code2);

#ifndef _M_X64
BYTE m_code3[] = {                      // BOOL WINAPI FillRavAddress(LPVOID pBase)
    0x55,                               //   0: push ebp
    0x8B,0xEC,                          //   1: mov ebp,esp
    0x83,0xEC,0x0C,                     //   3: sub esp,0Ch
    0x53,                               //   6: push ebx
    0x8B,0x5D,0x08,                     //   7: mov ebx,dword ptr [ebp+8]
    0x8B,0x43,0x3C,                     //  10: mov eax,dword ptr [ebx+3Ch]
    0x83,0xBC,0x18,0x84,
        0x00,0x00,0x00,0x00,            //  13: cmp dword ptr [eax+ebx+84h],0
    0x56,                               //  21: push esi
    0x57,                               //  22: push edi
    0x0F,0x84,0x87,0x00,0x00,0x00,      //  23: je 0A4h:164
    0x8B,0x84,0x18,0x80,0x00,0x00,0x00, //  29: mov eax,dword ptr [eax+ebx+80h]
    0x85,0xC0,                          //  36: test eax,eax
    0x74,0x7C,                          //  38: je 0A4h:164
    0x8D,0x3C,0x18,                     //  40: lea edi,[eax+ebx]
    0xEB,0x71,                          //  43: jmp 9Eh:158
    0x8B,0x77,0x10,                     //  45: mov esi,dword ptr [edi+10h]
    0x03,0xC3,                          //  48: add eax,ebx
    0x89,0x45,0xF4,                     //  50: mov dword ptr [ebp-0Ch],eax
    0x8B,0x47,0x0C,                     //  53: mov eax,dword ptr [edi+0Ch]
    0x03,0xC3,                          //  56: add eax,ebx
    0x50,                               //  58: push eax
    0x03,0xF3,                          //  59: add esi,ebx
    0xB8,0x00,0x00,0x00,0x00,           //  61: mov eax,ptr:00000000 ?          // LoadLibraryA
    0xFF,0xD0,                          //  66: call eax
    0x89,0x45,0xFC,                     //  68: mov dword ptr [ebp-4],eax
    0x33,0xC9,                          //  71: xor ecx,ecx
    0x3B,0xC1,                          //  73: cmp eax,ecx
    0x74,0x61,                          //  75: je 0AEh:174
    0x8B,0x45,0xF4,                     //  77: mov eax,dword ptr [ebp-0Ch]
    0x89,0x4D,0x08,                     //  80: mov dword ptr [ebp+8],ecx
    0x39,0x08,                          //  83: cmp dword ptr [eax],ecx
    0x74,0x44,                          //  85: je 9Bh:155
    0x89,0x4D,0xF8,                     //  87: mov dword ptr [ebp-8],ecx
    0x8B,0x00,                          //  90: mov eax,dword ptr [eax]
    0x85,0xC0,                          //  92: test eax,eax
    0x79,0x0D,                          //  94: jns 6Dh:109
    0x50,                               //  96: push eax
    0xFF,0x75,0xFC,                     //  97: push dword ptr [ebp-4]
    0xB8,0x00,0x00,0x00,0x00,           // 100: mov eax,ptr:00000000 ?          // GetProcAddress
    0xFF,0xD0,                          // 105: call eax
    0xEB,0x10,                          // 107: jmp 7Dh:125
    0x03,0xC3,                          // 109: add eax,ebx
    0x83,0xC0,0x02,                     // 111: add eax,2
    0x50,                               // 114: push eax
    0xFF,0x75,0xFC,                     // 115: push dword ptr [ebp-4]
    0xB8,0x00,0x00,0x00,0x00,           // 118: mov eax,ptr:00000000 ?          // GetProcAddress
    0xFF,0xD0,                          // 123: call eax
    0x85,0xC0,                          // 125: test eax,eax
    0x74,0x2D,                          // 127: je 0AEh:174
    0x8B,0x4D,0xF8,                     // 129: mov ecx,dword ptr [ebp-8]
    0xFF,0x45,0x08,                     // 132: inc dword ptr [ebp+8]
    0x89,0x04,0x31,                     // 135: mov dword ptr [ecx+esi],eax
    0x8B,0x45,0x08,                     // 138: mov eax,dword ptr [pBase]
    0xC1,0xE0,0x02,                     // 141: shl eax,2
    0x89,0x45,0xF8,                     // 144: mov dword ptr [ebp-8],eax
    0x03,0x45,0xF4,                     // 147: add eax,dword ptr [ebp-0Ch]
    0x83,0x38,0x00,                     // 150: cmp dword ptr [eax],0
    0x75,0xBF,                          // 153: jne 5Ah:90
    0x83,0xC7,0x14,                     // 155: add edi,14h
    0x8B,0x07,                          // 158: mov eax,dword ptr [edi]
    0x85,0xC0,                          // 160: test eax,eax
    0x75,0x89,                          // 162: jne 2Dh:45
    0x33,0xC0,                          // 164: xor eax,eax
    0x40,                               // 166: inc eax
    0x5F,                               // 167: pop edi
    0x5E,                               // 168: pop esi
    0x5B,                               // 169: pop ebx
    0xC9,                               // 170: leave
    0xC2,0x04,0x00,                     // 171: ret 4
    0x33,0xC0,                          // 174: xor eax,eax
    0xEB,0xF5                           // 176: jmp 0A7h:167
};
const int __pos3_LoadLibraryA = 62;
const int __pos3_GetProcAddress1 = 101;
const int __pos3_GetProcAddress2 = 119;
#else
BYTE m_code3[] = {                      // BOOL WINAPI FillRavAddress(LPVOID pBase)
    0x4C,0x8B,0xDC,                     //   0: mov r11,rsp
    0x41,0x56,                          //   3: push r14
    0x48,0x83,0xEC,0x40,                //   5: sub rsp,40h
    0x48,0x63,0x41,0x3C,                //   9: movsxd rax,dword ptr [rcx+3Ch]
    0x4C,0x8B,0xF1,                     //  13: mov r14,rcx
    0x83,0xBC,0x08,0x94,
        0x00,0x00,0x00,0x00,            //  16: cmp dword ptr [rax+rcx+94h],0
    0x0F,0x84,0x1D,0x01,0x00,0x00,      //  24: je 13Bh:315
    0x8B,0x94,0x08,0x90,0x00,0x00,0x00, //  30: mov edx,dword ptr [rax+rcx+90h]
    0x85,0xD2,                          //  37: test edx,edx
    0x0F,0x84,0x0E,0x01,0x00,0x00,      //  39: je 13Bh:315
    0x8B,0x04,0x11,                     //  45: mov eax,dword ptr [rcx+rdx]
    0x49,0x89,0x5B,0x08,                //  48: mov qword ptr [r11+8],rbx
    0x49,0x89,0x6B,0x10,                //  52: mov qword ptr [r11+10h],rbp
    0x49,0x89,0x73,0x18,                //  56: mov qword ptr [r11+18h],rsi
    0x49,0x89,0x7B,0xF0,                //  60: mov qword ptr [r11-10h],rdi
    0x4D,0x89,0x63,0xE8,                //  64: mov qword ptr [r11-18h],r12
    0x48,0x8D,0x34,0x11,                //  68: lea rsi,[rcx+rdx]
    0x4D,0x89,0x6B,0xE0,                //  72: mov qword ptr [r11-20h],r13
    0x4D,0x89,0x7B,0xD8,                //  76: mov qword ptr [r11-28h],r15
    0x85,0xC0,                          //  80: test eax,eax
    0x0F,0x84,0xB0,0x00,0x00,0x00,      //  82: je 108h:264
    0x49,0xBF,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x80,            //  88: mov r15,8000000000000000h
    0x66,0x66,0x66,0x66,0x66,0x66,
        0x0F,0x1F,0x84,0x00,
        0x00,0x00,0x00,0x00,            //  98: nop word ptr [rax+rax]
    0x8B,0x4E,0x0C,                     // 112: mov ecx,dword ptr [rsi+0Ch]
    0x44,0x8B,0x6E,0x10,                // 115: mov r13d,dword ptr [rsi+10h]
    0x8B,0xE8,                          // 119: mov ebp,eax
    0x49,0x03,0xCE,                     // 121: add rcx,r14
    0x4D,0x03,0xEE,                     // 124: add r13,r14
    0x49,0x03,0xEE,                     // 127: add rbp,r14
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, // 130: mov rax,ptr:0000000000000000 ?  // LoadLibraryA
        0x00,0x00,0x00,
    0xFF,0xD0,                          // 140: call rax
    0x4C,0x8B,0xE0,                     // 142: mov r12,rax
    0x48,0x85,0xC0,                     // 145: test rax,rax
    0x0F,0x84,0x9D,0x00,0x00,0x00,      // 148: je 137h:311
    0x33,0xDB,                          // 154: xor ebx,ebx
    0x48,0x39,0x5D,0x00,                // 156: cmp qword ptr [rbp],rbx
    0x74,0x57,                          // 160: je 0F9h:249
    0x48,0x8B,0xCD,                     // 162: mov rcx,rbp
    0x33,0xFF,                          // 165: xor edi,edi
    0x66,0x0F,0x1F,0x84,0x00,
        0x00,0x00,0x00,0x00,            // 167: nop word ptr [rax+rax]
    0x48,0x8B,0x11,                     // 176: mov rdx,qword ptr [rcx]
    0x49,0x8B,0xCC,                     // 179: mov rcx,r12
    0x49,0x85,0xD7,                     // 182: test r15,rdx
    0x74,0x0E,                          // 185: je 0C9h:201
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, // 187: mov rax,ptr:0000000000000000 ?  // GetProcAddress
        0x00,0x00,0x00,
    0xFF,0xD0,                          // 197: call rax
    0xEB,0x11,                          // 199: jmp 0DAh:218
    0x4A,0x8D,0x54,0x32,0x02,           // 201: lea rdx,[rdx+r14+2]
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, // 206: mov rax,ptr:0000000000000000 ?  // GetProcAddress
        0x00,0x00,0x00,
    0xFF,0xD0,                          // 216: call rax
    0x48,0x85,0xC0,                     // 218: test rax,rax
    0x74,0x58,                          // 221: je 137h:311
    0x48,0xFF,0xC3,                     // 223: inc rbx
    0x4A,0x89,0x04,0x2F,                // 226: mov qword ptr [rdi+r13],rax
    0x48,0x8D,0x3C,0xDD,
        0x00,0x00,0x00,0x00,            // 230: lea rdi,[rbx*8]
    0x48,0x83,0x3C,0x2F,0x00,           // 238: cmp qword ptr [rdi+rbp],0
    0x48,0x8D,0x0C,0x2F,                // 243: lea rcx,[rdi+rbp]
    0x75,0xB7,                          // 247: jne 0B0h:176
    0x8B,0x46,0x14,                     // 249: mov eax,dword ptr [rsi+14h]
    0x48,0x83,0xC6,0x14,                // 252: add rsi,14h
    0x85,0xC0,                          // 256: test eax,eax
    0x0F,0x85,0x68,0xFF,0xFF,0xFF,      // 258: jne 70h:112
    0xB8,0x01,0x00,0x00,0x00,           // 264: mov eax,1
    0x4C,0x8B,0x6C,0x24,0x28,           // 269: mov r13,qword ptr [rsp+28h]
    0x4C,0x8B,0x64,0x24,0x30,           // 274: mov r12,qword ptr [rsp+30h]
    0x48,0x8B,0x7C,0x24,0x38,           // 279: mov rdi,qword ptr [rsp+38h]
    0x48,0x8B,0x74,0x24,0x60,           // 284: mov rsi,qword ptr [rsp+60h]
    0x48,0x8B,0x6C,0x24,0x58,           // 289: mov rbp,qword ptr [rsp+58h]
    0x48,0x8B,0x5C,0x24,0x50,           // 294: mov rbx,qword ptr [pBase]
    0x4C,0x8B,0x7C,0x24,0x20,           // 299: mov r15,qword ptr [rsp+20h]
    0x48,0x83,0xC4,0x40,                // 304: add rsp,40h
    0x41,0x5E,                          // 308: pop r14
    0xC3,                               // 310: ret
    0x33,0xC0,                          // 311: xor eax,eax
    0xEB,0xD2,                          // 313: jmp 10Dh:269
    0xB8,0x01,0x00,0x00,0x00,           // 315: mov eax,1
    0x48,0x83,0xC4,0x40,                // 320: add rsp,40h
    0x41,0x5E,                          // 324: pop r14
    0xC3                                // 326: ret
};
const int __pos3_LoadLibraryA = 132;
const int __pos3_GetProcAddress1 = 189;
const int __pos3_GetProcAddress2 = 208;
#endif
const int sizeof_m_code3 = sizeof(m_code3);

#ifndef _M_X64
BYTE m_code4[] = {                      // VOID WINAPI DoRelocation(LPVOID NewBase)
    0x55,                               //   0: push ebp
    0x8B,0xEC,                          //   1: mov ebp,esp
    0x51,                               //   3: push ecx
    0x8B,0x4D,0x08,                     //   4: mov ecx,dword ptr [ebp+8]
    0x8B,0x41,0x3C,                     //   7: mov eax,dword ptr [ecx+3Ch]
    0x8B,0xD1,                          //  10: mov edx,ecx
    0x2B,0x54,0x08,0x34,                //  12: sub edx,dword ptr [eax+ecx+34h]
    0x8B,0x84,0x08,0xA0,0x00,0x00,0x00, //  16: mov eax,dword ptr [eax+ecx+0A0h]
    0x03,0xC1,                          //  23: add eax,ecx
    0x8B,0x48,0x04,                     //  25: mov ecx,dword ptr [eax+4]
    0x56,                               //  28: push esi
    0x8B,0x30,                          //  29: mov esi,dword ptr [eax]
    0x03,0xF1,                          //  31: add esi,ecx
    0x74,0x60,                          //  33: je 83h:131
    0x53,                               //  35: push ebx
    0x57,                               //  36: push edi
    0x83,0x65,0xFC,0x00,                //  37: and dword ptr [ebp-4],0
    0x8D,0x71,0xF8,                     //  41: lea esi,[ecx-8]
    0xD1,0xEE,                          //  44: shr esi,1
    0x85,0xF6,                          //  46: test esi,esi
    0x7E,0x43,                          //  48: jle 75h:117
    0x8B,0x4D,0xFC,                     //  50: mov ecx,dword ptr [ebp-4]
    0x0F,0xB7,0x4C,0x48,0x08,           //  53: movzx ecx,word ptr [eax+ecx*2+8]
    0x8B,0xF9,                          //  58: mov edi,ecx
    0x81,0xE7,0x00,0xF0,0x00,0x00,      //  60: and edi,0F000h
    0xBB,0x00,0x30,0x00,0x00,           //  66: mov ebx,3000h
    0x66,0x3B,0xFB,                     //  71: cmp di,bx
    0x74,0x14,                          //  74: je 60h:96
    0xBB,0x00,0xA0,0x00,0x00,           //  76: mov ebx,0A000h
    0x66,0x3B,0xFB,                     //  81: cmp di,bx
    0x74,0x0A,                          //  84: je 60h:96
    0xBB,0x00,0x90,0x00,0x00,           //  86: mov ebx,9000h
    0x66,0x3B,0xFB,                     //  91: cmp di,bx
    0x75,0x0D,                          //  94: jne 6Dh:109
    0x81,0xE1,0xFF,0x0F,0x00,0x00,      //  96: and ecx,0FFFh
    0x03,0x08,                          // 102: add ecx,dword ptr [eax]
    0x03,0x4D,0x08,                     // 104: add ecx,dword ptr [ebp+8]
    0x01,0x11,                          // 107: add dword ptr [ecx],edx
    0xFF,0x45,0xFC,                     // 109: inc dword ptr [ebp-4]
    0x39,0x75,0xFC,                     // 112: cmp dword ptr [ebp-4],esi
    0x7C,0xBD,                          // 115: jl 32h:50
    0x03,0x40,0x04,                     // 117: add eax,dword ptr [eax+4]
    0x8B,0x48,0x04,                     // 120: mov ecx,dword ptr [eax+4]
    0x8B,0x30,                          // 123: mov esi,dword ptr [eax]
    0x03,0xF1,                          // 125: add esi,ecx
    0x75,0xA4,                          // 127: jne 25h:37
    0x5F,                               // 129: pop edi
    0x5B,                               // 130: pop ebx
    0x5E,                               // 131: pop esi
    0xC9,                               // 132: leave
    0xC2,0x04,0x00                      // 133: ret 4
};
#else
BYTE m_code4[] = {                      // VOID WINAPI DoRelocation(LPVOID NewBase)
    0x40,0x53,                          //   0: push rbx
    0x48,0x63,0x41,0x3C,                //   2: movsxd rax,dword ptr [rcx+3Ch]
    0x48,0x8B,0xD9,                     //   6: mov rbx,rcx
    0x4C,0x8B,0xD9,                     //   9: mov r11,rcx
    0x44,0x8B,0x8C,0x08,
        0xB0,0x00,0x00,0x00,            //  12: mov r9d,dword ptr [rax+rcx+0B0h]
    0x48,0x2B,0x5C,0x08,0x30,           //  20: sub rbx,qword ptr [rax+rcx+30h]
    0x4C,0x03,0xC9,                     //  25: add r9,rcx
    0x45,0x8B,0x41,0x04,                //  28: mov r8d,dword ptr [r9+4]
    0x41,0x8B,0x01,                     //  32: mov eax,dword ptr [r9]
    0x41,0x8D,0x14,0x00,                //  35: lea edx,[r8+rax]
    0x85,0xD2,                          //  39: test edx,edx
    0x0F,0x84,0xA5,0x00,0x00,0x00,      //  41: je 0D4h:212
    0x48,0x89,0x6C,0x24,0x10,           //  47: mov qword ptr [rsp+10h],rbp
    0x48,0x89,0x74,0x24,0x18,           //  52: mov qword ptr [rsp+18h],rsi
    0x48,0x89,0x7C,0x24,0x20,           //  57: mov qword ptr [rsp+20h],rdi
    0x4C,0x89,0x64,0x24,0x28,           //  62: mov qword ptr [rsp+28h],r12
    0xBD,0x00,0xF0,0x00,0x00,           //  67: mov ebp,0F000h
    0xBF,0x00,0x30,0x00,0x00,           //  72: mov edi,3000h
    0x41,0xBC,0x00,0xA0,0x00,0x00,      //  77: mov r12d,0A000h
    0xBE,0x00,0x90,0x00,0x00,           //  83: mov esi,9000h
    0x0F,0x1F,0x84,0x00,
        0x00,0x00,0x00,0x00,            //  88: nop dword ptr [rax+rax]
    0x41,0x8B,0xC0,                     //  96: mov eax,r8d
    0x33,0xD2,                          //  99: xor edx,edx
    0x48,0x83,0xE8,0x08,                // 101: sub rax,8
    0x48,0xD1,0xE8,                     // 105: shr rax,1
    0x4C,0x63,0xD0,                     // 108: movsxd r10,eax
    0x85,0xC0,                          // 111: test eax,eax
    0x7E,0x37,                          // 113: jle 0AAh:170
    0x45,0x0F,0xB7,0x44,0x51,0x08,      // 115: movzx r8d,word ptr [r9+rdx*2+8]
    0x41,0x0F,0xB7,0xC0,                // 121: movzx eax,r8w
    0x66,0x23,0xC5,                     // 125: and ax,bp
    0x66,0x41,0x3B,0xC4,                // 128: cmp ax,r12w
    0x74,0x0A,                          // 132: je 90h:144
    0x66,0x3B,0xC7,                     // 134: cmp ax,di
    0x74,0x05,                          // 137: je 90h:144
    0x66,0x3B,0xC6,                     // 139: cmp ax,si
    0x75,0x12,                          // 142: jne 0A2h:162
    0x41,0x8B,0x09,                     // 144: mov ecx,dword ptr [r9]
    0x41,0x81,0xE0,0xFF,0x0F,0x00,0x00, // 147: and r8d,0FFFh
    0x4B,0x8D,0x04,0x03,                // 154: lea rax,[r11+r8]
    0x48,0x01,0x1C,0x01,                // 158: add qword ptr [rcx+rax],rbx
    0x48,0xFF,0xC2,                     // 162: inc rdx
    0x49,0x3B,0xD2,                     // 165: cmp rdx,r10
    0x7C,0xC9,                          // 168: jl 73h:115
    0x41,0x8B,0x41,0x04,                // 170: mov eax,dword ptr [r9+4]
    0x4C,0x03,0xC8,                     // 174: add r9,rax
    0x45,0x8B,0x41,0x04,                // 177: mov r8d,dword ptr [r9+4]
    0x41,0x8B,0x01,                     // 181: mov eax,dword ptr [r9]
    0x41,0x8D,0x0C,0x00,                // 184: lea ecx,[r8+rax]
    0x85,0xC9,                          // 188: test ecx,ecx
    0x75,0xA0,                          // 190: jne 60h:96
    0x4C,0x8B,0x64,0x24,0x28,           // 192: mov r12,qword ptr [rsp+28h]
    0x48,0x8B,0x7C,0x24,0x20,           // 197: mov rdi,qword ptr [rsp+20h]
    0x48,0x8B,0x74,0x24,0x18,           // 202: mov rsi,qword ptr [rsp+18h]
    0x48,0x8B,0x6C,0x24,0x10,           // 207: mov rbp,qword ptr [rsp+10h]
    0x5B,                               // 212: pop rbx
    0xC3                                // 213: ret
};
#endif
const int sizeof_m_code4 = sizeof(m_code4);

#ifndef _M_X64
BYTE m_code5[] = {                      // BOOL WINAPI BaseInit(DWORD* pBase) call DoRelocation & FillRavAddress
    0x55,                               //   0: push ebp
    0x8B,0xEC,                          //   1: mov ebp,esp
    0x56,                               //   3: push esi
    0x8B,0x75,0x08,                     //   4: mov esi,dword ptr [ebp+8]       // mov esi,dword ptr [pBase]
    0x56,                               //   7: push esi
    0xB8,0x00,0x00,0x00,0x00,           //   8: mov eax,ptr:00000000 ?          // DoRelocation
    0xFF,0xD0,                          //  13: call eax
    0x56,                               //  15: push esi
    0xB8,0x00,0x00,0x00,0x00,           //  16: mov eax,ptr:00000000 ?          // FillRavAddress
    0xFF,0xD0,                          //  21: call eax
    0x5E,                               //  23: pop esi
    0x5D,                               //  24: pop ebp
    0xC2,0x04,0x00                      //  25: ret 4
};
const int __pos5_GetDoRelocation = 9;
const int __pos5_FillRavAddress = 17;
#else
BYTE m_code5[] = {                      // BOOL WINAPI BaseInit(QWORD* pBase) call DoRelocation & FillRavAddress
    0x48,0x89,0x5C,0x24,0x10,           //   0: mov qword ptr [rsp+10h],rbx
    0x48,0x83,0xEC,0x20,                //   5: sub rsp,20h
    0x48,0x8B,0xD9,                     //   9: mov rbx,rcx
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, //  12: mov rax,ptr:0000000000000000 ?  // DoRelocation
        0x00,0x00,0x00,
    0xFF,0xD0,                          //  22: call rax
    0x48,0x8B,0xCB,                     //  24: mov rcx,rbx
    0x48,0xB8,0x00,0x00,0x00,0x00,0x00, //  27: mov rax,ptr:0000000000000000 ?  // FillRavAddress
        0x00,0x00,0x00,
    0xFF,0xD0,                          //  37: call rax
    0x48,0x83,0xC4,0x20,                //  39: add rsp,20h
    0x48,0x8B,0x5C,0x24,0x10,           //  43: pop rbx
    0xC3                                //  48: ret
};
const int __pos5_GetDoRelocation = 14;
const int __pos5_FillRavAddress = 29;
#endif
const int sizeof_m_code5 = sizeof(m_code5);
