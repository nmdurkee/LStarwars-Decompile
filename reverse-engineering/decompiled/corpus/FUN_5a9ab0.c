/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a9ab0; label: FUN_005a9ab0
 */

int FUN_005a9ab0(void)

{
  int in_EAX;
  
  if (DAT_0093d810 == 0) {
    return 0;
  }
  if (DAT_0093d814 != 0) {
    if ((*(float *)(DAT_0093d810 + 0x80) - *(float *)(in_EAX + 0x44) <
         *(float *)(DAT_0093d814 + 0x80) - *(float *)(in_EAX + 0x44)) &&
       (*(float *)(DAT_0093d810 + 0x88) - *(float *)(in_EAX + 0x4c) <
        *(float *)(DAT_0093d814 + 0x88) - *(float *)(in_EAX + 0x4c))) {
      return DAT_0093d814;
    }
  }
  return DAT_0093d810;
}

