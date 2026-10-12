/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455e30; label: FUN_00455e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00455e30(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(undefined4 **)(param_3 + 0xd0) != (undefined4 *)0x0)) {
    FUN_0049d540(**(undefined4 **)(param_3 + 0xd0));
  }
  return 1;
}

