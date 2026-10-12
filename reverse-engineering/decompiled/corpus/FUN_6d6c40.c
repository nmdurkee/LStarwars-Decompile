/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6c40; label: FUN_006d6c40
 */

undefined4 FUN_006d6c40(int param_1)

{
  if (((&DAT_029751a0)[param_1 + DAT_029755a1 * 0x100] != '\0') &&
     ((&DAT_029751a0)[param_1 + ((int)DAT_029755a1 ^ 1U) * 0x100] !=
      (&DAT_029751a0)[param_1 + DAT_029755a1 * 0x100])) {
    return 1;
  }
  return 0;
}

