; Original PC disassembly, not original source or decompiler pseudocode.
; Registered by0x43c830 and executed through native perception commands.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x43c200..0x43c220 (exclusive); bytes SHA256 c2c9e9fa86878dc9d10e39db6a86b3b24da7d64035ffa6f4677bc36e02ab7018
0x43c200  mov eax, dword ptr [esp + 4]
0x43c204  cmp eax, -1
0x43c207  jne 0x43c20c
0x43c209  fldz 
0x43c20b  ret 
0x43c20c  mov ecx, dword ptr [0x29130e4]
0x43c212  imul eax, eax, 0x4c
0x43c215  mov edx, dword ptr [ecx + 0x20]
0x43c218  mov eax, dword ptr [edx + eax + 0x24]
0x43c21c  fld dword ptr [eax + 0x70]
0x43c21f  ret 
