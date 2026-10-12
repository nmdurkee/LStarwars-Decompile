/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x603e80; label: FUN_00603e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603e80(void)

{
  int *piVar1;
  undefined *puVar2;
  
  if ((undefined4 *)PTR_DAT_0080e864 != &DAT_0280a578) {
    puVar2 = PTR_DAT_0080e864 + -0x7c;
    piVar1 = (int *)(PTR_DAT_0080e864 + -4);
    PTR_DAT_0080e864 = puVar2;
    if (*piVar1 != (int)DAT_009868cc) {
      FUN_005ed540(puVar2,0);
      DAT_009868cc = *(short *)(PTR_DAT_0080e864 + 0x78);
    }
    return;
  }
  FUN_005f7490();
  return;
}

