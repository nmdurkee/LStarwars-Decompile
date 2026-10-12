/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52b390; label: FUN_0052b390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0052b390(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float in_ECX;
  float10 fVar1;
  undefined4 local_4;
  
  local_4 = in_ECX;
  if (DAT_009242bc == 0) {
    fVar1 = (float10)FUN_00673820(param_1,param_2,param_3,param_4);
    local_4 = (float)fVar1;
  }
  return (float10)local_4;
}

