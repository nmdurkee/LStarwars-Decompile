/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455e60; label: FUN_00455e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00455e60(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(undefined4 **)(param_3 + 0xd0) != (undefined4 *)0x0)) {
    FUN_004ba2d0(**(undefined4 **)(param_3 + 0xd0));
  }
  return 1;
}

