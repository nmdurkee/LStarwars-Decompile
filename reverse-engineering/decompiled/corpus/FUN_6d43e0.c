/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d43e0; label: FUN_006d43e0
 */

char * FUN_006d43e0(byte param_1,int param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  short *psVar3;
  
  if (param_2 < 0) {
    return (char *)0x0;
  }
  if ((param_1 & 4) != 0) {
    iVar1 = 0;
    psVar3 = (short *)(in_ECX + 0x275e);
    do {
      if ((*(int *)(psVar3 + -0xf) == *(int *)(param_2 * 0x17c + 0x4e3c + in_ECX)) &&
         ((param_3 < 0 || (*psVar3 == param_3)))) {
        iVar1 = iVar1 + 0x40;
        goto LAB_006d44d4;
      }
      iVar1 = iVar1 + 1;
      psVar3 = psVar3 + 0x4e;
    } while (iVar1 < 0x40);
  }
  if ((param_1 & 2) != 0) {
    iVar1 = 0;
    psVar3 = (short *)(in_ECX + 0x5e);
    do {
      if ((*(int *)(psVar3 + -0xf) == *(int *)(param_2 * 0x17c + 0x4e3c + in_ECX)) &&
         ((param_3 < 0 || (*psVar3 == param_3)))) {
LAB_006d44d4:
        return (char *)(iVar1 * 0x9c + in_ECX);
      }
      iVar1 = iVar1 + 1;
      psVar3 = psVar3 + 0x4e;
    } while (iVar1 < 0x40);
  }
  if ((param_1 & 1) != 0) {
    iVar1 = 0;
    uVar2 = 0;
    do {
      if ((*(int *)((int)&DAT_00825000 + uVar2) == *(int *)(param_2 * 0x17c + 0x4e3c + in_ECX)) &&
         ((param_3 < 0 || (*(short *)((int)&DAT_0082501e + uVar2) == param_3)))) {
        return s_USB_Joystick_00824fc0 + iVar1 * 0x9c;
      }
      uVar2 = uVar2 + 0x9c;
      iVar1 = iVar1 + 1;
    } while (uVar2 < 0xea0);
  }
  return (char *)0x0;
}

