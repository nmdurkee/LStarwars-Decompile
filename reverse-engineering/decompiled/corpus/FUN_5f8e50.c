/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8e50; label: FUN_005f8e50
 */

void FUN_005f8e50(undefined4 *param_1)

{
  int *piVar1;
  undefined1 local_20 [12];
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (((param_1 != (undefined4 *)0x0) && (param_1[7] != 0)) && (param_1[8] != 0)) {
    FUN_006df300();
    FUN_006e59f0(param_1[7],param_1[8],param_1 + 9);
    piVar1 = (int *)param_1[9];
    (**(code **)(*piVar1 + 0x44))(piVar1,0,local_20);
    FUN_006df310();
    *param_1 = uStack_14;
    param_1[1] = uStack_10;
    param_1[7] = 0;
    param_1[8] = 0;
  }
  return;
}

