/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66cbd0; label: FUN_0066cbd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066cbd0(undefined4 param_1,undefined4 param_2)

{
  if (DAT_02947d7c < 8) {
    (&DAT_02921218)[DAT_02947d7c * 2] = param_1;
    (&DAT_0292121c)[DAT_02947d7c * 2] = param_2;
    DAT_02947d7c = DAT_02947d7c + 1;
  }
  return;
}

