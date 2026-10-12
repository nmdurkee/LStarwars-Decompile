/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ab0f0; label: FUN_005ab0f0
 */

void FUN_005ab0f0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    if (*(short *)(param_2 + 2) != 0) {
      _memset(*(void **)(param_2 + 4),0,(int)*(short *)(param_2 + 2) << 4);
      *(undefined2 *)(param_2 + 2) = 0;
    }
    if (DAT_0095dfd0 != (code *)0x0) {
      (*DAT_0095dfd0)(param_1);
    }
  }
  return;
}

