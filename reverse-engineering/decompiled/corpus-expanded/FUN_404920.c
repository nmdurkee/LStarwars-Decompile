/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404920; label: FUN_00404920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00404920(int param_1)

{
  float10 fVar1;
  
  FUN_0062e650(param_1 + 8,0xffffffff);
  *(undefined1 *)(param_1 + 0x7b5) = 0x5e;
  *(undefined2 *)(param_1 + 0x7aa) = 0xb2;
  fVar1 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0xb2,0,0,1);
  *(float *)(param_1 + 0x77c) = (float)fVar1;
  return;
}

