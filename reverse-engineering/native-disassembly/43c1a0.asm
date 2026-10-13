; Original PC disassembly, not original source or decompiler pseudocode.
; Registered by0x43c830 and executed through native perception commands.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x43c1a0..0x43c1c0 (exclusive); bytes SHA256 024461397745e277c0712a4c5c520ff5934f00aec630937f711bf4ee328a912b
0x43c1a0  mov eax, dword ptr [esp + 4]
0x43c1a4  cmp eax, -1
0x43c1a7  jne 0x43c1ac
0x43c1a9  fldz 
0x43c1ab  ret 
0x43c1ac  mov ecx, dword ptr [0x29130e4]
0x43c1b2  imul eax, eax, 0x4c
0x43c1b5  mov edx, dword ptr [ecx + 0x20]
0x43c1b8  mov eax, dword ptr [edx + eax + 0x24]
0x43c1bc  fld dword ptr [eax + 0x64]
0x43c1bf  ret 
