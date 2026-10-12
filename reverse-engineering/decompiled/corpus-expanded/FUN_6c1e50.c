/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c1e50; label: FUN_006c1e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1e50(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[5] = param_1;
  in_ECX[6] = param_2;
  in_ECX[3] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_0076aba0;
  in_ECX[2] = 1;
  return;
}

