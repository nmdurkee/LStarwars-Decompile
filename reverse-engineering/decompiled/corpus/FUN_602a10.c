/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x602a10; label: FUN_00602a10
 */

int * FUN_00602a10(int *param_1,undefined4 param_2)

{
  int *piVar1;
  void *_Dst;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = (int *)FUN_004eef40(0x50,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0xb4
                              );
  piVar3 = param_1;
  piVar4 = piVar1;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  if (*piVar1 != 0) {
    iVar2 = FUN_00602a10(*param_1,param_2);
    *piVar1 = iVar2;
  }
  if (piVar1[3] != 0) {
    _Dst = (void *)FUN_004eef40((uint)*(ushort *)((int)piVar1 + 10) * 2,
                                "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugobj.c",0xbe);
    piVar1[3] = (int)_Dst;
    _memcpy(_Dst,(void *)param_1[3],(uint)*(ushort *)((int)piVar1 + 10) * 2);
  }
  param_1[3] = 0;
  return piVar1;
}

