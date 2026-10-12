/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574fa0; label: FUN_00574fa0
 */

void FUN_00574fa0(int param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_00578da0(*(undefined4 *)(param_1 + 0x510),&local_4);
    if (local_4 != -1) {
      *(short *)(DAT_00951398 + 0xf0) = (short)local_4;
    }
  }
  return;
}

