/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x562010; label: FUN_00562010
 */

void FUN_00562010(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_009505e0 != (code *)0x0) {
    iVar2 = (*DAT_009505e0)(param_1);
    if (iVar2 != 0) {
      *param_2 = *(undefined4 *)(param_1 + 0x80);
      uVar1 = *(undefined4 *)(param_1 + 0x88);
      goto LAB_0056208c;
    }
  }
  iVar2 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x100);
  if ((((iVar2 == -1) || (*(char *)(param_1 + 0x28c) == '\0')) || (*(int *)(param_1 + 0x50) == 0))
     || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) == 0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x5c);
    uVar1 = *(undefined4 *)(param_1 + 100);
  }
  else {
    *param_2 = *(undefined4 *)(iVar2 * 0x40 + 0x834 + param_1);
    uVar1 = *(undefined4 *)(iVar2 * 0x40 + param_1 + 0x83c);
  }
LAB_0056208c:
  param_2[2] = uVar1;
  param_2[1] = *(undefined4 *)(param_1 + 0x21c);
  if (param_3 != (undefined4 *)0x0) {
    iVar2 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x101);
    if (((iVar2 != -1) && (*(char *)(param_1 + 0x28c) != '\0')) &&
       ((*(int *)(param_1 + 0x50) != 0 &&
        (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)))) {
      param_2 = (undefined4 *)(iVar2 * 0x40 + 0x834 + param_1);
    }
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    param_3[2] = param_2[2];
  }
  return;
}

