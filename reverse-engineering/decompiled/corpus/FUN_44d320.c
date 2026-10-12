/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44d320; label: FUN_0044d320
 */

undefined4 FUN_0044d320(void)

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
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),&DAT_0075782c);
      if (iVar1 != 0) {
        iVar2 = iVar1 + 5;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
    if (iVar2 != 0) {
      FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),iVar2,0);
    }
  }
  return 1;
}

