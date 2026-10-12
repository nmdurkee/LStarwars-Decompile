/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7eb0; label: FUN_006c7eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c7eb0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1 == (int *)0x0) {
    iVar2 = DAT_0081fdf8;
    if (DAT_0081fdf8 != 0) {
      do {
        if (*(int *)(iVar2 + 0x34) != 0) {
          return *(int *)(iVar2 + 0x2c);
        }
        iVar2 = *(int *)(iVar2 + 4);
      } while (iVar2 != 0);
      return iVar1;
    }
  }
  else {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      for (iVar1 = *(int *)(param_1[0x10] + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
        if (*(int *)(iVar1 + 0x34) != 0) {
          return *(int *)(iVar1 + 0x2c);
        }
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}

