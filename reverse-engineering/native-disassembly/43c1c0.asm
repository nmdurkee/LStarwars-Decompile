; Original PC disassembly, not original source or decompiler pseudocode.
; Registered by0x43c830 and executed through native perception commands.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x43c1c0..0x43c1e0 (exclusive); bytes SHA256 a23d4ff0ba36c44077aee43575c5d2b6021f04a4ab775712815b8327b51d4488
0x43c1c0  mov eax, dword ptr [esp + 4]
0x43c1c4  cmp eax, -1
0x43c1c7  jne 0x43c1cc
0x43c1c9  fldz 
0x43c1cb  ret 
0x43c1cc  mov ecx, dword ptr [0x29130e4]
0x43c1d2  imul eax, eax, 0x4c
0x43c1d5  mov edx, dword ptr [ecx + 0x20]
0x43c1d8  mov eax, dword ptr [edx + eax + 0x24]
0x43c1dc  fld dword ptr [eax + 0x68]
0x43c1df  ret 
