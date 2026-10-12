/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f150; label: FUN_0062f150
 */

int FUN_0062f150(int param_1,int param_2,int param_3,int param_4)

{
  if (param_2 != -1) {
    if (*(char *)(param_1 + 0x31) == '\0') {
      if (*(short *)(param_1 + 0x36) == param_2) {
        return param_1;
      }
    }
    else {
      if ((param_3 != 0) && (*(short *)(param_1 + 0x34) == param_2)) {
        return param_1 + 0x14;
      }
      if ((param_4 != 0) && (*(short *)(param_1 + 0x32) == param_2)) {
        return param_1 + 0x10;
      }
    }
  }
  return 0;
}

