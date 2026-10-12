/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x456410; label: FUN_00456410
 */

undefined4 FUN_00456410(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  iVar2 = 0;
  if ((in_stack_00000018 != 0) && (iVar3 = 0, 0 < in_stack_00000014)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"name=");
      if (iVar1 != 0) {
        iVar2 = FUN_004f1ff0("name=");
        iVar2 = FUN_00570090(PTR_DAT_00802c54,iVar1 + iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
    if (iVar2 != 0) {
      FUN_005700f0(iVar2);
    }
  }
  return 1;
}

