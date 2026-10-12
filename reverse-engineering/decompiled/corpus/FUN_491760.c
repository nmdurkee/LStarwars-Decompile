/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x491760; label: FUN_00491760
 */

int FUN_00491760(void)

{
  int iVar1;
  uint uVar2;
  int in_EDX;
  uint uVar3;
  int local_550 [340];
  
  uVar3 = 0;
  iVar1 = 0;
  if (0 < DAT_0093b278) {
    do {
      if (*(short *)(in_EDX + iVar1 * 2) != -1) {
        local_550[uVar3] = iVar1;
        uVar3 = uVar3 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0093b278);
    if (uVar3 != 0) goto LAB_0049178e;
  }
  uVar3 = 0;
  if ((DAT_007f18d0 != -1) && (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f18d0 * 2) != -1))
  {
    uVar3 = 1;
    local_550[0] = (int)DAT_007f18d0;
  }
  if ((DAT_007f18d4 != -1) && (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f18d4 * 2) != -1))
  {
    local_550[uVar3] = (int)DAT_007f18d4;
    uVar3 = uVar3 + 1;
  }
  if (uVar3 == 0) {
    return -1;
  }
LAB_0049178e:
  uVar2 = FUN_005b9e30();
  return local_550[uVar2 % uVar3];
}

