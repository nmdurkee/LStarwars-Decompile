/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f9500; label: FUN_004f9500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_004f9500(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar1 = *(int **)(&DAT_02983748 + (param_1 * 5 + -0x1400) * 4);
  piVar3 = (int *)((int)piVar1 + *piVar1);
  iVar5 = *piVar3;
  if (0 < iVar5) {
    do {
      piVar3 = piVar3 + 1;
      iVar2 = *(int *)(*piVar3 + (int)piVar3);
      piVar4 = (int *)(*piVar3 + (int)piVar3);
      if (iVar2 != 0) {
        *piVar4 = iVar2 + (int)piVar4;
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return piVar1 + 1;
}

