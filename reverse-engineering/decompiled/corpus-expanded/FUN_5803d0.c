/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5803d0; label: FUN_005803d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005803d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if ((iVar1 != 0) && (DAT_00951cb8 != 0)) {
    iVar2 = FUN_005cf5b0(DAT_00951cb8,DAT_00951cc0 + 0x74,*(undefined4 *)(param_1 + 0x510),1);
    iVar1 = DAT_00951cc0;
    if (iVar2 != 0) {
      *(undefined4 *)(DAT_00951cc0 + 0x8c) = *(undefined4 *)(DAT_00951cc0 + 0x74);
      *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(iVar1 + 0x78);
      *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x7c);
    }
  }
  return;
}

