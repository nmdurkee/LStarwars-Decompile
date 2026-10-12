/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b8440; label: FUN_006b8440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b8440(float *param_1)

{
  float *in_ECX;
  
  return (float10)(param_1[2] * in_ECX[2] + *param_1 * *in_ECX + param_1[1] * in_ECX[1]);
}

