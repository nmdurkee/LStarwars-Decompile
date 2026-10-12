/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64a390; label: FUN_0064a390
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064a390(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar3 = &local_c;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  iVar1 = FUN_00617f80();
  if (iVar1 == 0) {
    _DAT_0291f658 = DAT_00973718;
    _DAT_0291f65c = DAT_0097371c;
    _DAT_0291f660 = DAT_00973720;
  }
  else {
    puVar2 = (undefined4 *)FUN_00617f80();
    _DAT_0291f658 = *puVar2;
    _DAT_0291f65c = puVar2[1];
    _DAT_0291f660 = puVar2[2];
  }
  if (DAT_0291f7a4 != 0) {
    iVar1 = FUN_00617f80();
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)FUN_00617f80(0,0);
    }
    FUN_00620f60(puVar3);
    DAT_0291f7a4 = 0;
  }
  DAT_02920888 = 0xffffffff;
  return;
}

