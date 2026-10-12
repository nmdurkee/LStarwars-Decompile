/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414d10; label: FUN_00414d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414d10(int param_1,char param_2)

{
  *(char *)(param_1 + 0x107f) = param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x107e) < (int)param_2) {
    *(byte *)(param_1 + 0x107f) = *(byte *)(param_1 + 0x107e);
  }
  return;
}

