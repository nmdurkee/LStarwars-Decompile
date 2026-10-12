/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c09c0; label: FUN_006c09c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006c09c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float in_ECX;
  float10 fVar1;
  undefined4 local_4;
  
  local_4 = in_ECX;
  if (DAT_02973aec == 0) {
    fVar1 = (float10)FUN_00673820(param_1,param_2,param_3,param_4);
    local_4 = (float)fVar1;
  }
  return (float10)local_4;
}

