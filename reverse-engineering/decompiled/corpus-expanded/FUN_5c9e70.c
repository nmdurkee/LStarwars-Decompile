/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9e70; label: FUN_005c9e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

