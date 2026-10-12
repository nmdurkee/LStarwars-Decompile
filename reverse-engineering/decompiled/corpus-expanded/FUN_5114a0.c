/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x5114a0; label: FUN_005114a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005114a0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_00543de0();
  if (DAT_00924808 != 0) {
    DAT_00921e5c = 1;
  }
  FUN_0050b9a0();
  iVar2 = 0;
  DAT_00921e84 = 0;
  if ((DAT_00924810 != 0) && (iVar1 = 0, 0 < DAT_00801598)) {
    do {
      if ((&DAT_02989540)[iVar1] != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
      DAT_00921e84 = iVar2;
    } while (iVar1 < DAT_00801598);
  }
  return;
}

