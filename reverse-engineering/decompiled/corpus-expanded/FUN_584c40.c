/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584c40; label: FUN_00584c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584c40(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00954410 == '\0') {
    iVar1 = FUN_00584a70(param_1);
  }
  else {
    iVar1 = FUN_00584ad0(param_1);
  }
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_00954404 + 0xa8) = *(undefined4 *)(DAT_00954404 + 0xa4);
  }
  return;
}

