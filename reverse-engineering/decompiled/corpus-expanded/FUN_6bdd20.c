/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdd20; label: FUN_006bdd20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bdd20(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  float10 extraout_ST0;
  undefined4 local_c;
  int *local_8;
  undefined4 local_4;
  
  piVar1 = DAT_0081faa4;
  if ((*(char *)(param_1 + 0x66) == '\0') || (*(float *)(param_1 + 0x170) == 0.0)) {
    return;
  }
  local_4 = DAT_0081faa8;
  local_c = DAT_0081faa0;
  local_8 = DAT_0081faa4;
  iVar2 = FUN_006bd980(&local_c);
  if (iVar2 == 0) {
    _DAT_0081faac = 0xff000080;
  }
  else {
    _DAT_0081faac = 0xff008000;
    if ((*(char *)(param_1 + 0x91) != '\0') &&
       (extraout_ST0 != (float10)*(float *)(param_1 + 0x17c))) {
      uVar3 = (**(code **)(*piVar1 + 0xc))();
      FUN_006ba280(uVar3);
      return;
    }
  }
  return;
}

