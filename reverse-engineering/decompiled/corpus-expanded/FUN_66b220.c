/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66b220; label: FUN_0066b220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

