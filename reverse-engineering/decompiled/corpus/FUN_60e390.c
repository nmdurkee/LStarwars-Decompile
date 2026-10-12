/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60e390; label: FUN_0060e390
 */

void FUN_0060e390(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (**(code **)(*(int *)puVar1[2] + 0x10))(param_1,param_2);
  }
  return;
}

