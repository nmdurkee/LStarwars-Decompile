/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414c50; label: FUN_00414c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414c50(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0058a900(0);
  if ((iVar1 == 0) && (param_1 != 0)) {
    iVar1 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1);
    if ((iVar1 != 0) && ((DAT_0093b2a4 == 0 || ((*(uint *)(iVar1 + 0x1f8) & 0x400) != 0)))) {
      FUN_00414bb0();
      return;
    }
  }
  return;
}

