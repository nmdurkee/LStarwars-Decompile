/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x456350; label: FUN_00456350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00456350(void)

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
      FUN_0055a2b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),iVar2,local_4,1);
    }
  }
  return 1;
}

