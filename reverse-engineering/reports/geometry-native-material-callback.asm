00608000 sub esp, 0x50
00608003 push ebp
00608004 push esi
00608005 push edi
00608006 mov edi, dword ptr [esp + 0x60]
0060800a movsx eax, word ptr [edi + 0x1f4]
00608011 push eax
00608012 call 0x741620
00608017 mov ebp, eax
00608019 or eax, 0xffffffff
0060801c mov dword ptr [0x991da4], edi
00608022 mov dword ptr [0x2854c20], edi
00608028 mov dword ptr [0x986eb4], eax
0060802d mov dword ptr [0x80e194], eax
00608032 mov eax, dword ptr [edi + 0x1f0]
00608038 add esp, 4
0060803b test eax, 0x100000
00608040 je 0x608169
00608046 xor esi, esi
00608048 push esi
00608049 call 0x6e5700
0060804e push esi
0060804f call 0x6e5290
00608054 push esi
00608055 mov dword ptr [0x2854c18], esi
0060805b mov dword ptr [0x2854c1c], esi
00608061 call 0x741640
00608066 mov ecx, dword ptr [0x2854d3c]
0060806c push ecx
0060806d call 0x6e56c0
00608072 mov esi, dword ptr [0x2854d2c]
00608078 add esp, 0x10
0060807b cmp byte ptr [edi + 0x99], 0x97
00608082 je 0x60808a
00608084 mov esi, dword ptr [0x2854d28]
0060808a call 0x5fa0a0
0060808f cmp byte ptr [0x8264c7], 0
00608096 je 0x6080a1
00608098 cmp dword ptr [0x2974d1c], 4
0060809f je 0x6080ec
006080a1 lea edx, [esp + 0x1c]
006080a5 push 0x97e230
006080aa push edx
006080ab call 0x5b59a0
006080b0 push 4
006080b2 lea eax, [esp + 0x28]
006080b6 push eax
006080b7 push 0
006080b9 call 0x6e5750
006080be lea ecx, [esp + 0x30]
006080c2 push 0x986eb8
006080c7 push ecx
006080c8 call 0x5b59a0
006080cd push 4
006080cf lea edx, [esp + 0x3c]
006080d3 push edx
006080d4 push 0xc
006080d6 call 0x6e5750
006080db push 1
006080dd push 0x82cab8
006080e2 push 0x30
006080e4 call 0x6e5750
006080e9 add esp, 0x34
006080ec push 1
006080ee push 0x82ca5c
006080f3 push 0
006080f5 call 0x6e52e0
006080fa add esp, 0xc
006080fd cmp byte ptr [edi + 0x99], 0x97
00608104 jne 0x60823b
0060810a push -1
0060810c call 0x5c37f0
00608111 add esp, 4
00608114 test eax, eax
00608116 je 0x60811d
00608118 mov eax, dword ptr [eax]
0060811a push eax
0060811b jmp 0x60811f
0060811d push 0
0060811f push 0
00608121 call 0x6e5630
00608126 add esp, 8
00608129 push 3
0060812b push 1
0060812d push 0
0060812f call 0x6e54e0
00608134 push 3
00608136 push 2
00608138 push 0
0060813a call 0x6e54e0
0060813f push 0
00608141 push 7
00608143 push 0
00608145 call 0x6e54e0
0060814a mov ecx, dword ptr [0x2854d48]
00608150 push ecx
00608151 call 0x5e5310
00608156 mov edx, dword ptr [eax + 0x24]
00608159 push edx
0060815a push 1
0060815c call 0x6e5630
00608161 add esp, 0x30
00608164 jmp 0x6082f0
00608169 test eax, 0x200000
0060816e je 0x608262
00608174 push edi
00608175 push ebp
00608176 call 0x742730
0060817b push 0
0060817d call 0x741640
00608182 push 0
00608184 call 0x6e5700
00608189 push 0
0060818b call 0x6e5290
00608190 mov ecx, dword ptr [0x2854d40]
00608196 push ecx
00608197 mov dword ptr [0x2854c18], 0
006081a1 mov dword ptr [0x2854c1c], 0
006081ab call 0x6e56c0
006081b0 add esp, 0x18
006081b3 cmp dword ptr [0x2976c80], 0
006081ba je 0x6081cb
006081bc test byte ptr [edi + 0x268], 0xf
006081c3 mov esi, dword ptr [0x2854d30]
006081c9 jne 0x6081d1
006081cb mov esi, dword ptr [0x2854d34]
006081d1 call 0x5fa0a0
006081d6 cmp dword ptr [0x2974d1c], 4
006081dd je 0x60822a
006081df lea edx, [esp + 0x1c]
006081e3 push 0x97e230
006081e8 push edx
006081e9 call 0x5b59a0
006081ee push 4
006081f0 lea eax, [esp + 0x28]
006081f4 push eax
006081f5 push 0
006081f7 call 0x6e5750
006081fc lea ecx, [esp + 0x30]
00608200 push 0x986eb8
00608205 push ecx
00608206 call 0x5b59a0
0060820b push 4
0060820d lea edx, [esp + 0x3c]
00608211 push edx
00608212 push 0xc
00608214 call 0x6e5750
00608219 push 1
0060821b push 0x82cab8
00608220 push 0x30
00608222 call 0x6e5750
00608227 add esp, 0x34
0060822a push 1
0060822c push 0x82ca5c
00608231 push 0
00608233 call 0x6e52e0
00608238 add esp, 0xc
0060823b mov eax, dword ptr [edi + 0xb8]
00608241 test eax, eax
00608243 je 0x6082f0
00608249 push eax
0060824a call 0x5e5310
0060824f mov eax, dword ptr [eax + 0x24]
00608252 push eax
00608253 push 0
00608255 call 0x6e5630
0060825a add esp, 0xc
0060825d jmp 0x6082f0
00608262 cmp dword ptr [edi + 0x3c], 0
00608266 je 0x6082ae
00608268 test ebp, ebp
0060826a je 0x60829d
0060826c push edi
0060826d push ebp
0060826e call 0x742730
00608273 push ebp
00608274 call 0x741640
00608279 mov ecx, dword ptr [edi + 0x2bc]
0060827f push ecx
00608280 call 0x6e56c0
00608285 add esp, 0x10
00608288 cmp dword ptr [0x2854bb0], 0
0060828f je 0x6082f0
00608291 push 0
00608293 call 0x6e5290
00608298 add esp, 4
0060829b jmp 0x6082f0
0060829d call 0x5f7490
006082a2 push 0
006082a4 call 0x741640
006082a9 add esp, 4
006082ac jmp 0x6082f0
006082ae test ebp, ebp
006082b0 je 0x6082d0
006082b2 push edi
006082b3 push ebp
006082b4 call 0x742730
006082b9 push ebp
006082ba call 0x741640
006082bf mov edx, dword ptr [edi + 0x2bc]
006082c5 push edx
006082c6 call 0x6e56c0
006082cb add esp, 0x10
006082ce jmp 0x6082f0
006082d0 push 0
006082d2 call 0x741640
006082d7 mov eax, dword ptr [0x2854d44]
006082dc push eax
006082dd call 0x6e56c0
006082e2 mov esi, dword ptr [0x2854d38]
006082e8 add esp, 8
006082eb call 0x5fa0a0
006082f0 xor esi, esi
006082f2 push edi
006082f3 mov dword ptr [0x2854d50], esi
006082f9 call 0x601360
006082fe add esp, 4
00608301 test byte ptr [ebp + 0x4d4], 6
00608308 push 1
0060830a mov ecx, 0x29765c8
0060830f jne 0x608317
00608311 push 1
00608313 push 1
00608315 jmp 0x608319
00608317 push esi
00608318 push esi
00608319 call 0x6e2810
0060831e mov eax, dword ptr [ebp + 0x4d4]
00608324 not eax
00608326 and eax, 8
00608329 shr eax, 3
0060832c push 3
0060832e push eax
0060832f push eax
00608330 mov ecx, 0x29765c8
00608335 call 0x6e2810
0060833a cmp dword ptr [0x2974d1c], 4
00608341 je 0x6083ba
00608343 call 0x741610
00608348 test eax, eax
0060834a je 0x6083ba
0060834c call 0x741610
00608351 test eax, eax
00608353 je 0x60838d
00608355 call 0x741610
0060835a cmp word ptr [eax + 0x3d0], si
00608361 jl 0x60838d
00608363 fld1 
00608365 lea ecx, [esp + 0xc]
00608369 push ecx
0060836a fst dword ptr [esp + 0x10]
0060836e fst dword ptr [esp + 0x14]
00608372 push esi
00608373 fst dword ptr [esp + 0x1c]
00608377 push 0x4f
00608379 fstp dword ptr [esp + 0x24]
0060837d call 0x741300
00608382 add esi, 1
00608385 add esp, 0xc
00608388 cmp esi, 0x20
0060838b jl 0x608363
0060838d mov eax, dword ptr [0x97389c]
00608392 test eax, eax
00608394 je 0x6083ba
00608396 cmp eax, 8
00608399 jl 0x6083a0
0060839b mov eax, 8
006083a0 mov edx, dword ptr [0x9738a0]
006083a6 push edx
006083a7 push eax
006083a8 push 0
006083aa push 0x4e
006083ac call 0x741610
006083b1 push eax
006083b2 call 0x744060
006083b7 add esp, 0x14
006083ba pop edi
006083bb pop esi
006083bc pop ebp
006083bd add esp, 0x50
006083c0 ret 
