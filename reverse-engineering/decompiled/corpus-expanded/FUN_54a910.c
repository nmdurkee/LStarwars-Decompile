/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a910; label: FUN_0054a910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054a910(undefined4 param_1,float param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if ((0 < param_3) && (param_2 < (float)param_3 / _DAT_00925024)) {
    param_2 = (float)param_3 / _DAT_00925024;
  }
  piVar4 = &DAT_0093d7f0;
  do {
    iVar1 = *piVar4;
    if (((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
       (piVar2 = *(int **)(iVar1 + 0xca4), *piVar2 != 0)) {
      uVar3 = FUN_006e6b90(0,param_1);
      FUN_00698900(*piVar2,param_2,uVar3);
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x93d810);
  return;
}

