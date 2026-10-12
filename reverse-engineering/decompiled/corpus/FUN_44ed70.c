/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44ed70; label: FUN_0044ed70
 */

undefined4 FUN_0044ed70(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  iVar2 = 0;
  if (((in_stack_00000018 != 0) && (in_stack_00000014 != 0)) && (iVar3 = 0, 0 < in_stack_00000014))
  {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"name=");
      if (iVar1 != 0) {
        iVar2 = FUN_00558920(*(undefined4 *)(PTR_DAT_00802c54 + 0x46a4),iVar1 + 5);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
    if (iVar2 != 0) {
      FUN_00558990(iVar2);
    }
  }
  return 1;
}

