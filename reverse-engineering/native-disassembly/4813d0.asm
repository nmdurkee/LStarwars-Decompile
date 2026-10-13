; Original PC disassembly, not original source or decompiler pseudocode.
; Registered4816b0 ->520440 ->global9238fc; original callback execution; RET4814fd followed byINT3 padding to481500.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x4813d0..0x4814fe exclusive; bytes SHA256 63fbb083713fb881d82a844f1cf766d82524aa4a0a22ae0ef20d36a4b79dc23e
0x4813d0  8b4c2408  mov ecx, dword ptr [esp + 8]
0x4813d4  56  push esi
0x4813d5  57  push edi
0x4813d6  8b39  mov edi, dword ptr [ecx]
0x4813d8  80bfb50700005b  cmp byte ptr [edi + 0x7b5], 0x5b
0x4813df  750f  jne 0x4813f0
0x4813e1  8b87a40c0000  mov eax, dword ptr [edi + 0xca4]
0x4813e7  8b1578228000  mov edx, dword ptr [0x802278]
0x4813ed  095008  or dword ptr [eax + 8], edx
0x4813f0  8b74240c  mov esi, dword ptr [esp + 0xc]
0x4813f4  0fb68660010000  movzx eax, byte ptr [esi + 0x160]
0x4813fb  8b965c010000  mov edx, dword ptr [esi + 0x15c]
0x481401  8b0482  mov eax, dword ptr [edx + eax*4]
0x481404  85c0  test eax, eax
0x481406  743b  je 0x481443
0x481408  a900000040  test eax, 0x40000000
0x48140d  7534  jne 0x481443
0x48140f  8b96f4010000  mov edx, dword ptr [esi + 0x1f4]
0x481415  23d0  and edx, eax
0x481417  0f84a6000000  je 0x4814c3
0x48141d  a900000098  test eax, 0x98000000
0x481422  0f859b000000  jne 0x4814c3
0x481428  833dd4a27f0000  cmp dword ptr [0x7fa2d4], 0
0x48142f  b8d0a27f00  mov eax, 0x7fa2d0
0x481434  740d  je 0x481443
0x481436  8510  test dword ptr [eax], edx
0x481438  756e  jne 0x4814a8
0x48143a  83c008  add eax, 8
0x48143d  83780400  cmp dword ptr [eax + 4], 0
0x481441  75f3  jne 0x481436
0x481443  f786e801000000000020  test dword ptr [esi + 0x1e8], 0x20000000
0x48144d  7454  je 0x4814a3
0x48144f  f687c507000002  test byte ptr [edi + 0x7c5], 2
0x481456  754b  jne 0x4814a3
0x481458  d9ee  fldz 
0x48145a  d81de46c8700  fcomp dword ptr [0x876ce4]
0x481460  dfe0  fnstsw ax
0x481462  f6c405  test ah, 5
0x481465  7a3c  jp 0x4814a3
0x481467  8a8660010000  mov al, byte ptr [esi + 0x160]
0x48146d  8b8e5c010000  mov ecx, dword ptr [esi + 0x15c]
0x481473  0fb6d0  movzx edx, al
0x481476  f70491000000d8  test dword ptr [ecx + edx*4], 0xd8000000
0x48147d  7524  jne 0x4814a3
0x48147f  33d2  xor edx, edx
0x481481  84c0  test al, al
0x481483  0f94c2  sete dl
0x481486  6a00  push 0
0x481488  0fb6440a10  movzx eax, byte ptr [edx + ecx + 0x10]
0x48148d  8b8e58010000  mov ecx, dword ptr [esi + 0x158]
0x481493  6bc05c  imul eax, eax, 0x5c
0x481496  03417c  add eax, dword ptr [ecx + 0x7c]
0x481499  50  push eax
0x48149a  57  push edi
0x48149b  e800b5fbff  call 0x43c9a0
0x4814a0  83c40c  add esp, 0xc
0x4814a3  5f  pop edi
0x4814a4  33c0  xor eax, eax
0x4814a6  5e  pop esi
0x4814a7  c3  ret 
0x4814a8  8b542414  mov edx, dword ptr [esp + 0x14]
0x4814ac  8b4004  mov eax, dword ptr [eax + 4]
0x4814af  52  push edx
0x4814b0  51  push ecx
0x4814b1  56  push esi
0x4814b2  ffd0  call eax
0x4814b4  83c40c  add esp, 0xc
0x4814b7  85c0  test eax, eax
0x4814b9  7488  je 0x481443
0x4814bb  5f  pop edi
0x4814bc  b801000000  mov eax, 1
0x4814c1  5e  pop esi
0x4814c2  c3  ret 
0x4814c3  8b515c  mov edx, dword ptr [ecx + 0x5c]
0x4814c6  d9ee  fldz 
0x4814c8  899604010000  mov dword ptr [esi + 0x104], edx
0x4814ce  8b4160  mov eax, dword ptr [ecx + 0x60]
0x4814d1  898608010000  mov dword ptr [esi + 0x108], eax
0x4814d7  8b5164  mov edx, dword ptr [ecx + 0x64]
0x4814da  d99e10010000  fstp dword ptr [esi + 0x110]
0x4814e0  89960c010000  mov dword ptr [esi + 0x10c], edx
0x4814e6  668189920200000020  or word ptr [ecx + 0x292], 0x2000
0x4814ef  5f  pop edi
0x4814f0  c6863901000000  mov byte ptr [esi + 0x139], 0
0x4814f7  b801000000  mov eax, 1
0x4814fc  5e  pop esi
0x4814fd  c3  ret 
