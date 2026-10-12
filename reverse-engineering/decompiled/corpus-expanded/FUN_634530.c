/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634530; label: FUN_00634530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634530(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = param_2;
  *in_ECX = &PTR_FUN_0076b668;
  in_ECX[5] = param_1;
  return;
}

