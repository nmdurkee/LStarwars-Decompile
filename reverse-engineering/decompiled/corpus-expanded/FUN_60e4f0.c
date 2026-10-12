/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e4f0; label: FUN_0060e4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060e4f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (**(code **)puVar1[0xc])();
  }
  return;
}

