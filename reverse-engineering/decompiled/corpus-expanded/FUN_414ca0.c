/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414ca0; label: FUN_00414ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414ca0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0x3c);
  *(undefined4 *)(param_1 + 0xffc) = *(undefined4 *)(iVar1 + 0x30);
  *(undefined4 *)(param_1 + 0xff0) = *(undefined4 *)(iVar1 + 0x34);
  *(undefined4 *)(param_1 + 0xff4) = *(undefined4 *)(iVar1 + 0x38);
  FUN_0055ccd0();
  return;
}

