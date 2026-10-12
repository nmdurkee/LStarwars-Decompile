/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f8b60; label: FUN_005f8b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8b60(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x8c + param_2 * 4) = param_3;
  return;
}

