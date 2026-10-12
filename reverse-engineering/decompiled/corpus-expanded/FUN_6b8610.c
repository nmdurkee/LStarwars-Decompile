/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b8610; label: FUN_006b8610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8610(int *param_1,int *param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = 0;
  in_ECX[3] = *param_2 - *param_1;
  return;
}

