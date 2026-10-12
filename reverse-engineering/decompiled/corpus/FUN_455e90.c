/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x455e90; label: FUN_00455e90
 */

undefined4 FUN_00455e90(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if (in_stack_00000018 == 0) {
    return 1;
  }
  iVar4 = 0;
  iVar1 = 0;
  if (0 < in_stack_00000014) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"cutscene=");
      if (iVar1 != 0) {
        iVar3 = FUN_004f1ff0("cutscene=");
        iVar3 = iVar3 + iVar1;
      }
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"newlevel=");
      if (iVar1 != 0) {
        iVar2 = FUN_004f1ff0("newlevel=");
        local_4 = FUN_00578da0(iVar1 + iVar2,0);
      }
      iVar4 = iVar4 + 1;
      iVar1 = local_4;
    } while (iVar4 < in_stack_00000014);
  }
  if (DAT_0093b2a4 == 0) {
    if (iVar3 != 0) {
      iVar3 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),iVar3,0);
      if (iVar3 != 0) {
        return 1;
      }
      if (DAT_0093b2a4 != 0) goto LAB_00455f4f;
    }
  }
  else {
LAB_00455f4f:
    if (iVar1 == 0) goto LAB_00455f90;
    if ((*(byte *)(iVar1 + 100) & 0xe0) != 0) {
      iVar1 = FUN_00573520(*(undefined4 *)(PTR_DAT_00802c54 + 300),0);
    }
  }
  if (iVar1 != 0) {
    FUN_0057a580((int)*(short *)(iVar1 + 0x62));
    return 1;
  }
LAB_00455f90:
  FUN_0057a5b0(PTR_DAT_00802c54);
  return 1;
}

