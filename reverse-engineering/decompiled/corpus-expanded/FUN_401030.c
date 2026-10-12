/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x401030; label: FUN_00401030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00401030(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = param_4;
  return;
}

