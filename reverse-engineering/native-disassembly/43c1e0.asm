; Original PC disassembly, not original source or decompiler pseudocode.
; Registered by0x43c830 and executed through native perception commands.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x43c1e0..0x43c200 (exclusive); bytes SHA256 af525488d71f9961c9979503cd0702e44d004c61a6eeaaf29d3a97c4ed7d51f2
0x43c1e0  mov eax, dword ptr [esp + 4]
0x43c1e4  cmp eax, -1
0x43c1e7  jne 0x43c1ec
0x43c1e9  fldz 
0x43c1eb  ret 
0x43c1ec  mov ecx, dword ptr [0x29130e4]
0x43c1f2  imul eax, eax, 0x4c
0x43c1f5  mov edx, dword ptr [ecx + 0x20]
0x43c1f8  mov eax, dword ptr [edx + eax + 0x24]
0x43c1fc  fld dword ptr [eax + 0x6c]
0x43c1ff  ret 
