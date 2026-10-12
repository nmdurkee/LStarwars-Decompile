/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44cd40; label: FUN_0044cd40
 */

undefined4 FUN_0044cd40(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = 1;
  if (in_stack_00000018 == 0) {
    return 1;
  }
  iVar3 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (0 < in_stack_00000014) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),&DAT_0075782c);
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"FALSE");
        if (iVar1 != 0) {
          uVar2 = 0;
        }
      }
      else {
        FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_c,iVar1 + 5,1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
  }
  iVar3 = FUN_005cfac0(&local_c);
  if (iVar3 != 0) {
    FUN_005cfc00(&local_c,uVar2);
  }
  return 1;
}

