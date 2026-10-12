/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bdd20; label: FUN_006bdd20
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

