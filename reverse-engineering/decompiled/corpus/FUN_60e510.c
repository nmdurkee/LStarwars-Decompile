/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60e510; label: FUN_0060e510
 */

void FUN_0060e510(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    if (*(char *)(puVar2 + 3) == (char)param_2) {
      iVar3 = FUN_0053d180();
      puVar2[0xf] = puVar2[0xf] + iVar3;
      puVar2[0x11] = puVar2[0x11] + 1;
      if (param_1[1] == 0) {
        FUN_0060f2d0(*param_1,0,param_1[2],param_1[3],param_2,param_3);
      }
      else {
        piVar1 = (int *)(param_1[1] + 0x4b0);
        *piVar1 = *piVar1 + 1;
      }
      (**(code **)(*(int *)puVar2[2] + 4))();
    }
  }
  return;
}

