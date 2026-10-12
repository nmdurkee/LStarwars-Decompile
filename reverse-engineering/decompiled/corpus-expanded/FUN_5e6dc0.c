/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e6dc0; label: FUN_005e6dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e6dc0(void)

{
  int *piVar1;
  
  piVar1 = (int *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28 + 0x24);
  *piVar1 = *piVar1 + -1;
  piVar1 = (int *)(DAT_0080bbbc + 0x24 + DAT_0080bbb8 * 0x28);
  *piVar1 = *piVar1 + -1;
  piVar1 = (int *)(DAT_0080bbc4 + 0x24 + DAT_0080bbc0 * 0x28);
  *piVar1 = *piVar1 + -1;
  piVar1 = (int *)(DAT_0080bbd4 + 0x24 + DAT_0080bbd0 * 0x28);
  *piVar1 = *piVar1 + -1;
  piVar1 = (int *)(DAT_0080bbdc + 0x24 + DAT_0080bbd8 * 0x28);
  *piVar1 = *piVar1 + -1;
  if (DAT_00973828 != 0) {
    FUN_005f7b40(DAT_00973828);
    DAT_00973828 = 0;
  }
  if (DAT_0097382c != 0) {
    FUN_005f7b40(DAT_0097382c);
    DAT_0097382c = 0;
  }
  return;
}

