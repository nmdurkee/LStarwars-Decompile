/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60e4c0; label: FUN_0060e4c0
 */

void FUN_0060e4c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 4); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (**(code **)(*(int *)puVar1[2] + 0x28))(param_1,param_2);
  }
  return;
}

