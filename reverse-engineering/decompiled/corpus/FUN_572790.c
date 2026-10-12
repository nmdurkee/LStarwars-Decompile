/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x572790; label: FUN_00572790
 */

undefined4 FUN_00572790(int param_1)

{
  if (((*(char *)(param_1 + 0x283) == '\x01') || (*(char *)(param_1 + 0x283) == '\t')) &&
     (*(float *)(param_1 + 0x84) <= *(float *)(param_1 + 0x220))) {
    return 1;
  }
  return 0;
}

