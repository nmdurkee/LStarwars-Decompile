/* Ghidra pseudocode, not original source.
 * ev_139f76d7dade80e5283f2bbc23e2b9031909e5f7cb36236e0c190b06f1e16beb
 * Entry: 0x6c1c10; label: FUN_006c1c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1c10(int param_1)

{
  undefined4 *in_ECX;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    in_ECX[1] = *(undefined4 *)(param_1 + 0x30);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x30) = *(undefined4 *)(param_1 + 0x30);
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    *in_ECX = *(undefined4 *)(param_1 + 0x2c);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

