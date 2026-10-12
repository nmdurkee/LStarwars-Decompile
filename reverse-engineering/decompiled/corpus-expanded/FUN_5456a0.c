/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x5456a0; label: FUN_005456a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005456a0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 1;
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

