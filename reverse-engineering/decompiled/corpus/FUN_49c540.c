/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49c540; label: FUN_0049c540
 */

void FUN_0049c540(int param_1,int param_2)

{
  float10 fVar1;
  
  if (*(char *)(param_1 + 0x7b5) == -1) {
    *(undefined1 *)(param_1 + 0x7b5) = 0x38;
    if ((*(short *)(param_2 + 0x1064) == DAT_007f1884) && (*(char *)(param_2 + 0x280) == -1)) {
      *(undefined2 *)(param_1 + 0x7aa) = 0x1f;
    }
    else {
      *(undefined2 *)(param_1 + 0x7aa) = 100;
    }
    if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0) {
      *(undefined4 *)(param_1 + 0x784) = 0x40000000;
    }
    else {
      fVar1 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                    (int)*(short *)(param_1 + 0x7aa),0,0,1);
      *(float *)(param_1 + 0x784) = (float)fVar1;
    }
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
    *(int *)(param_1 + 0x790) = param_2;
    *(undefined4 *)(param_1 + 0x794) = 0;
    *(undefined4 *)(param_1 + 0xd10) = 0;
  }
  return;
}

