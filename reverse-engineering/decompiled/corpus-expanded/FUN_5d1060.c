/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d1060; label: FUN_005d1060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d1060(int param_1,undefined4 param_2)

{
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    **(undefined4 **)(param_1 + 0x48) = param_2;
  }
  return;
}

