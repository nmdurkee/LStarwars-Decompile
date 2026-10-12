/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6810; label: FUN_006d6810
 */

uint FUN_006d6810(int param_1,uint param_2)

{
  if (param_1 < 0) {
    return param_1 * 2 + 1U ^ param_2 ^ 0x12345678;
  }
  return param_1 * 2 ^ param_2 ^ 0x12345678;
}

