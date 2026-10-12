/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d68e0; label: FUN_006d68e0
 */

bool FUN_006d68e0(int param_1,int param_2,int param_3,int param_4)

{
  if (param_3 != 0) {
    return *(char *)(DAT_02975144 + 0x6358 + (param_4 * 0x20 + param_2) * 4) != '\0';
  }
  return *(char *)(DAT_02975144 + 0x4ea2 + (param_1 * 0x5f + param_2) * 4) != '\0';
}

