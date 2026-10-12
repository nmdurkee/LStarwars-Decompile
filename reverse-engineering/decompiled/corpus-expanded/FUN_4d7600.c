/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d7600; label: FUN_004d7600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d7600(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
  }
  return;
}

