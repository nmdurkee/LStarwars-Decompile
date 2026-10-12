/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x601210; label: FUN_00601210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601210(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x1d0 + param_2 * 8) = param_3;
  *(undefined4 *)(param_1 + 0x1d4 + param_2 * 8) = param_4;
  return;
}

