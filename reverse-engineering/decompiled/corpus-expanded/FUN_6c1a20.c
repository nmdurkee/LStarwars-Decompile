/* Ghidra pseudocode, not original source.
 * ev_139f76d7dade80e5283f2bbc23e2b9031909e5f7cb36236e0c190b06f1e16beb
 * Entry: 0x6c1a20; label: FUN_006c1a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1a20(int param_1)

{
  undefined4 *in_ECX;
  
  if (*(int *)(param_1 + 4) == 0) {
    in_ECX[1] = *(undefined4 *)(param_1 + 8);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 8);
  }
  if (*(int *)(param_1 + 8) == 0) {
    *in_ECX = *(undefined4 *)(param_1 + 4);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = *(undefined4 *)(param_1 + 4);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  in_ECX[2] = in_ECX[2] + -1;
  return;
}

