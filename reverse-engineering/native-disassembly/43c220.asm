; Original PC disassembly, not original source or decompiler pseudocode.
; Registered43c830 ->520460 ->global923904, executed in commands and helper probes; next entry43c3a0.
; Binary SHA256 6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
; Range 0x43c220..0x43c397 exclusive; bytes SHA256 814673099e6cc912d4514a4f8dfc18ede58365d5c79e96e3521067bf5cb7e0dd
0x43c220  83ec44  sub esp, 0x44
0x43c223  a170958200  mov eax, dword ptr [0x829570]
0x43c228  33c4  xor eax, esp
0x43c22a  89442440  mov dword ptr [esp + 0x40], eax
0x43c22e  53  push ebx
0x43c22f  8b5c2450  mov ebx, dword ptr [esp + 0x50]
0x43c233  55  push ebp
0x43c234  8b6c2450  mov ebp, dword ptr [esp + 0x50]
0x43c238  85ed  test ebp, ebp
0x43c23a  56  push esi
0x43c23b  57  push edi
0x43c23c  0f84a6000000  je 0x43c2e8
0x43c242  33ff  xor edi, edi
0x43c244  393d00d59300  cmp dword ptr [0x93d500], edi
0x43c24a  0f8e98000000  jle 0x43c2e8
0x43c250  8b0d04d59300  mov ecx, dword ptr [0x93d504]
0x43c256  33f6  xor esi, esi
0x43c258  eb06  jmp 0x43c260
0x43c25a  8d9b00000000  lea ebx, [ebx]
0x43c260  f6840efc01000001  test byte ptr [esi + ecx + 0x1fc], 1
0x43c268  7455  je 0x43c2bf
0x43c26a  f7840ef801000000040000  test dword ptr [esi + ecx + 0x1f8], 0x400
0x43c275  742d  je 0x43c2a4
0x43c277  8a840e00040000  mov al, byte ptr [esi + ecx + 0x400]
0x43c27e  3cff  cmp al, 0xff
0x43c280  7422  je 0x43c2a4
0x43c282  0fb6c0  movzx eax, al
0x43c285  69c0a4000000  imul eax, eax, 0xa4
0x43c28b  034518  add eax, dword ptr [ebp + 0x18]
0x43c28e  7414  je 0x43c2a4
0x43c290  53  push ebx
0x43c291  50  push eax
0x43c292  e879c80b00  call 0x4f8b10
0x43c297  83c408  add esp, 8
0x43c29a  85c0  test eax, eax
0x43c29c  7434  je 0x43c2d2
0x43c29e  8b0d04d59300  mov ecx, dword ptr [0x93d504]
0x43c2a4  8b440e54  mov eax, dword ptr [esi + ecx + 0x54]
0x43c2a8  8b480c  mov ecx, dword ptr [eax + 0xc]
0x43c2ab  53  push ebx
0x43c2ac  51  push ecx
0x43c2ad  e85ec80b00  call 0x4f8b10
0x43c2b2  83c408  add esp, 8
0x43c2b5  85c0  test eax, eax
0x43c2b7  7419  je 0x43c2d2
0x43c2b9  8b0d04d59300  mov ecx, dword ptr [0x93d504]
0x43c2bf  83c701  add edi, 1
0x43c2c2  81c6d8100000  add esi, 0x10d8
0x43c2c8  3b3d00d59300  cmp edi, dword ptr [0x93d500]
0x43c2ce  7c90  jl 0x43c260
0x43c2d0  eb16  jmp 0x43c2e8
0x43c2d2  69ffd8100000  imul edi, edi, 0x10d8
0x43c2d8  033d04d59300  add edi, dword ptr [0x93d504]
0x43c2de  8bc7  mov eax, edi
0x43c2e0  85c0  test eax, eax
0x43c2e2  0f859c000000  jne 0x43c384
0x43c2e8  68605d7500  push 0x755d60
0x43c2ed  53  push ebx
0x43c2ee  e81dc80b00  call 0x4f8b10
0x43c2f3  83c408  add esp, 8
0x43c2f6  85c0  test eax, eax
0x43c2f8  7507  jne 0x43c301
0x43c2fa  a110d89300  mov eax, dword ptr [0x93d810]
0x43c2ff  eb7f  jmp 0x43c380
0x43c301  68545d7500  push 0x755d54
0x43c306  53  push ebx
0x43c307  e804c80b00  call 0x4f8b10
0x43c30c  83c408  add esp, 8
0x43c30f  85c0  test eax, eax
0x43c311  7514  jne 0x43c327
0x43c313  a1f0d79300  mov eax, dword ptr [0x93d7f0]
0x43c318  390510d89300  cmp dword ptr [0x93d810], eax
0x43c31e  7560  jne 0x43c380
0x43c320  a1f4d79300  mov eax, dword ptr [0x93d7f4]
0x43c325  eb59  jmp 0x43c380
0x43c327  33f6  xor esi, esi
0x43c329  8da42400000000  lea esp, [esp]
0x43c330  833cb5f0d7930000  cmp dword ptr [esi*4 + 0x93d7f0], 0
0x43c338  7422  je 0x43c35c
0x43c33a  56  push esi
0x43c33b  8d542414  lea edx, [esp + 0x14]
0x43c33f  68485d7500  push 0x755d48
0x43c344  52  push edx
0x43c345  e8a5a62a00  call 0x6e69ef
0x43c34a  8d44241c  lea eax, [esp + 0x1c]
0x43c34e  53  push ebx
0x43c34f  50  push eax
0x43c350  e8bbc70b00  call 0x4f8b10
0x43c355  83c414  add esp, 0x14
0x43c358  85c0  test eax, eax
0x43c35a  741d  je 0x43c379
0x43c35c  83c601  add esi, 1
0x43c35f  83fe08  cmp esi, 8
0x43c362  7ccc  jl 0x43c330
0x43c364  5f  pop edi
0x43c365  5e  pop esi
0x43c366  5d  pop ebp
0x43c367  33c0  xor eax, eax
0x43c369  5b  pop ebx
0x43c36a  8b4c2440  mov ecx, dword ptr [esp + 0x40]
0x43c36e  33cc  xor ecx, esp
0x43c370  e8c5a52a00  call 0x6e693a
0x43c375  83c444  add esp, 0x44
0x43c378  c3  ret 
0x43c379  8b04b5f0d79300  mov eax, dword ptr [esi*4 + 0x93d7f0]
0x43c380  85c0  test eax, eax
0x43c382  7500  jne 0x43c384
0x43c384  8b4c2450  mov ecx, dword ptr [esp + 0x50]
0x43c388  5f  pop edi
0x43c389  5e  pop esi
0x43c38a  5d  pop ebp
0x43c38b  5b  pop ebx
0x43c38c  33cc  xor ecx, esp
0x43c38e  e8a7a52a00  call 0x6e693a
0x43c393  83c444  add esp, 0x44
0x43c396  c3  ret 
