/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44b680; label: FUN_0044b680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044b680(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_4;
  
  iVar3 = 0;
  iVar2 = 0;
  local_4 = 0;
  if (((in_stack_00000018 != 0) && (DAT_0095df4c != 0)) && (0 < in_stack_00000014)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),"from=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar3 * 4),&DAT_00757c50);
        if (iVar1 != 0) {
          iVar2 = iVar1 + 3;
        }
      }
      else {
        local_4 = iVar1 + 5;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < in_stack_00000014);
    if ((local_4 != 0) && (iVar2 != 0)) {
      iVar3 = FUN_005aac00(DAT_0095df4c,local_4,0);
      iVar2 = FUN_005aac00(DAT_0095df4c,iVar2,0);
      if ((iVar3 != 0) && (iVar2 != 0)) {
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
      }
    }
  }
  return 1;
}

