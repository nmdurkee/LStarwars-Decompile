/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420420; label: FUN_00420420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420420(undefined4 param_1)

{
  int in_ECX;
  
  if (*(code **)(in_ECX + 0xec0) != (code *)0x0) {
    (**(code **)(in_ECX + 0xec0))(param_1);
  }
  return;
}

