/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bd770; label: FUN_005bd770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bd770(int param_1,undefined4 param_2,undefined4 param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005bd100(param_1,param_2,param_3);
  return (float10)(float)((float10)*(float *)(param_1 + 0x50) * (float10)*(float *)(param_1 + 0x48)
                         * fVar1);
}

