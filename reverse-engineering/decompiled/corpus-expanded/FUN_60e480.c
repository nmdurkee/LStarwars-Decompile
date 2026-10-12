/* Ghidra pseudocode, not original source.
 * ev_168b65d5705473c04d5f4e526193e1abf552a66e90d2db36f509f2a3124060c2
 * Entry: 0x60e480; label: FUN_0060e480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0060e480(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 1;
  for (puVar1 = *(undefined4 **)(in_ECX + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    iVar2 = (**(code **)(*(int *)puVar1[2] + 0x24))(param_1,param_2);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
  }
  return uVar3;
}

