/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a24d0; label: FUN_004a24d0
 */

void FUN_004a24d0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_2 = *(undefined4 *)(param_1 + 0x80);
  param_2[1] = *(undefined4 *)(param_1 + 0x84);
  param_2[2] = *(undefined4 *)(param_1 + 0x88);
  if (param_3 != (undefined4 *)0x0) {
    param_3[1] = 0x4e6e6b28;
  }
  if (((*(char *)(param_1 + 0x28c) != '\0') &&
      (iVar3 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x108), iVar3 != -1)) &&
     (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) != 0)) {
    iVar1 = iVar3 * 0x40 + 0x834 + param_1;
    *param_2 = *(undefined4 *)(iVar3 * 0x40 + 0x834 + param_1);
    param_2[1] = *(undefined4 *)(iVar1 + 4);
    param_2[2] = *(undefined4 *)(iVar1 + 8);
    if ((((param_3 != (undefined4 *)0x0) &&
         ((*(float *)(param_1 + 0xd3c) == 0.0 || (*(char *)(param_1 + 0xe33) == '\x02')))) &&
        (iVar3 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x109), iVar3 != -1)) &&
       (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) != 0)) {
      puVar2 = (undefined4 *)(iVar3 * 0x40 + 0x834 + param_1);
      *param_3 = *puVar2;
      param_3[1] = puVar2[1];
      param_3[2] = puVar2[2];
    }
  }
  return;
}

