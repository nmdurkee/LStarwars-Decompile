/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420440; label: FUN_00420440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420440(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = 3;
  *(undefined4 *)(in_ECX + 0x28) = 3;
  FUN_006d5db0();
  return;
}

