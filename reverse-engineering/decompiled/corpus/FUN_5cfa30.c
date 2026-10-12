/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfa30; label: FUN_005cfa30
 */

void FUN_005cfa30(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x10;
  puVar2 = *(undefined4 **)(param_1 + 8);
  if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(param_1 + 4);
  }
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

