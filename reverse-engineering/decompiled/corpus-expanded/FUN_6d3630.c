/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d3630; label: FUN_006d3630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3630(float param_1,int param_2,float param_3)

{
  undefined4 uVar1;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar2;
  
  fVar2 = (float10)0;
  if ((fVar2 <= (float10)param_1) && ((float10)param_1 <= (float10)1)) {
    uVar1 = FUN_006e6b90();
    *(undefined4 *)(in_ECX + 0x6568) = uVar1;
    fVar2 = extraout_ST0;
  }
  if (0 < param_2) {
    *(int *)(in_ECX + 0x656c) = param_2;
  }
  if ((float10)param_3 < fVar2) {
    return;
  }
  *(float *)(in_ECX + 0x6570) = param_3;
  return;
}

