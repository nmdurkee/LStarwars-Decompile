/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x621180; label: FUN_00621180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621180(undefined1 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_1[1];
  param_1[1] = uVar1;
  return;
}

