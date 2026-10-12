/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49ca10; label: FUN_0049ca10
 */

void FUN_0049ca10(int param_1)

{
  float10 fVar1;
  
  *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  if (((*(int *)(param_1 + 0x790) != 0) && ((*(byte *)(param_1 + 0xe24) & 1) != 0)) &&
     (*(undefined2 *)(param_1 + 0x7aa) = 0x4e,
     *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x138) != 0)) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x3f;
    fVar1 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0x4e,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar1;
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
  }
  return;
}

