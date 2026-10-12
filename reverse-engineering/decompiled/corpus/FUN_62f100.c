/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62f100; label: FUN_0062f100
 */

undefined4 FUN_0062f100(int param_1,int param_2,int param_3,int param_4)

{
  if (((((*(char *)(param_2 + 0x31) != '\0') && (param_3 != -1)) &&
       (*(short *)(param_2 + 0x32) == param_3)) &&
      ((param_4 != -1 && (*(short *)(param_2 + 0x34) == param_4)))) &&
     ((param_1 == 0 ||
      ((*(int *)(*(int *)(param_1 + 0xc) + param_3 * 4) != 0 &&
       (*(int *)(*(int *)(param_1 + 0xc) + param_4 * 4) != 0)))))) {
    return 1;
  }
  return 0;
}

