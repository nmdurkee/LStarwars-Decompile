/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44e9b0; label: FUN_0044e9b0
 */

undefined4 FUN_0044e9b0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  local_4 = 0;
  if (((in_stack_00000018 != 0) && (in_stack_00000014 != 0)) && (0 < in_stack_00000014)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"FALSE");
        if (iVar1 == 0) {
          local_4 = 1;
        }
      }
      else {
        piVar2 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                     iVar1 + 5);
        if (piVar2 != (int *)0x0) {
          iVar3 = *piVar2;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < in_stack_00000014);
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 0x9c) =
           *(uint *)(iVar3 + 0x9c) ^ (local_4 * 8 ^ *(uint *)(iVar3 + 0x9c)) & 8;
    }
  }
  return 1;
}

