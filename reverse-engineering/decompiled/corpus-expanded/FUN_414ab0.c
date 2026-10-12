/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414ab0; label: FUN_00414ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414ab0(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfff8ffff;
  *(undefined4 *)(param_1 + 0x1018) = param_2;
  return;
}

