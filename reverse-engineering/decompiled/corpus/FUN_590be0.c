/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590be0; label: FUN_00590be0
 */

void FUN_00590be0(int param_1,int param_2)

{
  float10 fVar1;
  
  *(undefined4 *)(param_1 + 0x48) = 0x3e99999a;
  if (param_2 != 0) {
    fVar1 = (float10)FUN_0058fe80(param_2);
    *(float *)(param_1 + 0x48) = (float)((float10)0.30000001192092896 / fVar1);
  }
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x48);
  return;
}

