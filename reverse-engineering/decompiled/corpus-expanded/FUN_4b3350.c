/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b3350; label: FUN_004b3350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b3350(int param_1)

{
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0,0);
  }
  return;
}

