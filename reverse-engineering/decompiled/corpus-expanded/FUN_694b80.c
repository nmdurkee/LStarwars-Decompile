/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694b80; label: FUN_00694b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00694b80(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  if ((in_ECX != (int *)0x0) && (DAT_02962b8c != 0)) {
    iVar3 = 0;
    if (0 < in_ECX[1]) {
      iVar2 = 0;
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(iVar2 + *in_ECX),param_1);
        if (iVar1 == 0) {
          return iVar3 + 0x12345678;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x24;
      } while (iVar3 < in_ECX[1]);
    }
    return 0;
  }
  return 0;
}

