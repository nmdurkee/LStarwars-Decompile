/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x456850; label: FUN_00456850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00456850(void)

{
  int iVar1;
  int iVar2;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  iVar2 = 0;
  if (in_stack_00000018 == 0) {
    return 1;
  }
  DAT_00876ccc = 0;
  if (in_stack_00000014 < 1) {
    return 1;
  }
  do {
    iVar1 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar2 * 4),"FALSE");
    if (iVar1 == 0) {
      DAT_00876ccc = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < in_stack_00000014);
  return 1;
}

