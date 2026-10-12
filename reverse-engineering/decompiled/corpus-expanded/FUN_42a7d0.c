/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42a7d0; label: FUN_0042a7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042a7d0(undefined2 *param_1)

{
  int iVar1;
  
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364))
  {
    iVar1 = FUN_00574e20();
    if (iVar1 == 0x11) {
      if ((((DAT_00879564 == 0) || (DAT_00879564 == 1)) || (DAT_00879564 == 2)) ||
         (DAT_00879564 == 3)) {
        iVar1 = 0;
        if ((DAT_0087b6c8 != '\0') && (DAT_0087955c < 3)) {
          *param_1 = DAT_0087b6c4;
          iVar1 = 1;
        }
        if ((DAT_0087b6c9 != '\0') && (DAT_00879560 < 3)) {
          param_1[iVar1] = DAT_0087b6c6;
        }
      }
    }
  }
  return;
}

