/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f4f40; label: FUN_004f4f40
 */

int * FUN_004f4f40(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(*param_1 + (int)param_1);
  iVar4 = *piVar2;
  if (0 < iVar4) {
    do {
      piVar2 = piVar2 + 1;
      iVar1 = *(int *)(*piVar2 + (int)piVar2);
      piVar3 = (int *)(*piVar2 + (int)piVar2);
      if (iVar1 != 0) {
        *piVar3 = iVar1 + (int)piVar3;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return param_1 + 1;
}

