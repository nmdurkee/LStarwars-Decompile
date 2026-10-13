; Original PC disassembly, not original source or decompiler pseudocode.
; SCP IAm dispatch binding and direct original execution; INT3 padding then next entry515790.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x515750..0x51578e exclusive; bytes SHA256 0eb472acd6bcdf4d0a6564ad8e26c9493026cfb844dac23d40b21200e5b75991
0x515750  8b44240c  mov eax, dword ptr [esp + 0xc]
0x515754  85c0  test eax, eax
0x515756  7433  je 0x51578b
0x515758  8b80d0000000  mov eax, dword ptr [eax + 0xd0]
0x51575e  85c0  test eax, eax
0x515760  7429  je 0x51578b
0x515762  3b442414  cmp eax, dword ptr [esp + 0x14]
0x515766  7503  jne 0x51576b
0x515768  d9e8  fld1 
0x51576a  c3  ret 
0x51576b  8b4054  mov eax, dword ptr [eax + 0x54]
0x51576e  85c0  test eax, eax
0x515770  7419  je 0x51578b
0x515772  8b400c  mov eax, dword ptr [eax + 0xc]
0x515775  85c0  test eax, eax
0x515777  7412  je 0x51578b
0x515779  8b4c2410  mov ecx, dword ptr [esp + 0x10]
0x51577d  51  push ecx
0x51577e  50  push eax
0x51577f  e88c33feff  call 0x4f8b10
0x515784  83c408  add esp, 8
0x515787  85c0  test eax, eax
0x515789  74dd  je 0x515768
0x51578b  d9ee  fldz 
0x51578d  c3  ret 
