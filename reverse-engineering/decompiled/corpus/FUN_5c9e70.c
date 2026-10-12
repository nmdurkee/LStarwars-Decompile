/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c9e70; label: FUN_005c9e70
 */

undefined4 * FUN_005c9e70(int param_1)

{
  size_t _Size;
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = (undefined4 *)0x0;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)
             FUN_004eef40(0x10,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4ec);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    _Size = param_1 * 4;
    puVar1[3] = 0;
    *(char *)(puVar1 + 3) = (char)param_1;
    pvVar2 = (void *)FUN_004eef40(_Size,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",
                                  0x4f3);
    puVar1[2] = pvVar2;
    _memset(pvVar2,0,_Size);
    pvVar2 = (void *)FUN_004eef40(_Size,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",
                                  0x4f8);
    puVar1[1] = pvVar2;
    _memset(pvVar2,0,_Size);
  }
  return puVar1;
}

