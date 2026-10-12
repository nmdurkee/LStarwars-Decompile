/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cffb0; label: FUN_005cffb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cffb0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[1] == 0) {
    if (param_1[2] != 0) {
      return *(int *)(param_1[2] + 0xc0);
    }
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x1c);
    iVar2 = 0;
    if (0 < iVar1) {
      iVar3 = *(int *)(*param_1 + 0x20);
      do {
        if (iVar3 == *(int *)(param_1[1] + 0x40)) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x50;
      } while (iVar2 < iVar1);
    }
  }
  return -1;
}

