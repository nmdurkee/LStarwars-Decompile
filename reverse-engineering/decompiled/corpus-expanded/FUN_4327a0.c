/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4327a0; label: FUN_004327a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004327a0(int param_1)

{
  float10 fVar1;
  
  *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x200) != 0) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x41;
    *(undefined2 *)(param_1 + 0x7aa) = 0x80;
    fVar1 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0x80,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar1;
    *(undefined4 *)(param_1 + 0x784) = 0;
  }
  return;
}

