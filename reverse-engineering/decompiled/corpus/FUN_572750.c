/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x572750; label: FUN_00572750
 */

undefined4 FUN_00572750(float *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5170) != 0)) {
    *param_1 = *(float *)(*(int *)(iVar1 + 0x128) + 0xd0) + *param_1;
    param_1[2] = *(float *)(*(int *)(iVar1 + 0x128) + 0xd4) + param_1[2];
  }
  return 0;
}

