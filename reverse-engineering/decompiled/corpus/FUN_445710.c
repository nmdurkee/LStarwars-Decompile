/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x445710; label: FUN_00445710
 */

undefined4 FUN_00445710(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
    FUN_00426de0(*(int *)(param_3 + 0xd0) + 0x5c,0);
  }
  return 1;
}

