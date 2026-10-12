/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a9ab0; label: FUN_005a9ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

