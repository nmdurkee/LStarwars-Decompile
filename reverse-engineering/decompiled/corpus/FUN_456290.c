/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x456290; label: FUN_00456290
 */

undefined4 FUN_00456290(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  undefined4 local_4;
  
  iVar2 = 0;
  local_4 = 1;
  if ((in_stack_00000018 != 0) && (iVar3 = 0, 0 < in_stack_00000014)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"FALSE");
        if (iVar1 == 0) {
          local_4 = 0;
        }
      }
      else {
        iVar2 = FUN_004f1ff0("name=");
        iVar2 = FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),0xffffffff,iVar1 + iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
    if (iVar2 != 0) {
      FUN_0055a250(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),iVar2,local_4,1);
    }
  }
  return 1;
}

