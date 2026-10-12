/* Ghidra pseudocode, not original source.
 * ev_8db3786b1d2e9370d3feb832809c6ae27354528dfff9c38ddb75cfb6eefed4ac
 * Entry: 0x6f4d3b; label: FUN_006f4d3b
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006f4d3b(uint param_1,uint param_2)

{
  DAT_00829d70 = ~param_2 & DAT_00829d70 | param_1 & param_2;
  return;
}

