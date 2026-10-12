/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0fa0; label: FUN_005d0fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0fa0(undefined4 param_1,int param_2,undefined4 param_3)

{
  **(undefined4 **)(param_2 + 0x48) = param_3;
  return;
}

