/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66b220; label: FUN_0066b220
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066b220(void)

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
    _DAT_0292fcdc = DAT_00973718;
    _DAT_0292fce0 = DAT_0097371c;
    _DAT_0292fce4 = DAT_00973720;
  }
  else {
    puVar2 = (undefined4 *)FUN_00617f80();
    _DAT_0292fcdc = *puVar2;
    _DAT_0292fce0 = puVar2[1];
    _DAT_0292fce4 = puVar2[2];
  }
  if (DAT_02920d7c != 0) {
    iVar1 = FUN_00617f80();
    if (iVar1 != 0) {
      puVar3 = (undefined4 *)FUN_00617f80(0,0);
    }
    FUN_00620f60(puVar3);
    DAT_02920d7c = 0;
  }
  DAT_00810ad8 = 0xffffffff;
  DAT_029231a8 = 0xffffffff;
  return;
}

