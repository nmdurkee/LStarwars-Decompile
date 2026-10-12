/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49cf20; label: FUN_0049cf20
 */

void FUN_0049cf20(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_ESI + 0x790) = 0;
  *(undefined4 *)(unaff_ESI + 0x794) = 0;
  if (unaff_EDI == 0) {
    uVar1 = FUN_0049ca80();
    *(undefined4 *)(unaff_ESI + 0x790) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x790) == 0) {
    if (((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0) || (unaff_EDI != 0)) {
      uVar1 = FUN_00569980();
      *(undefined4 *)(unaff_ESI + 0x794) = uVar1;
    }
    if ((*(int *)(unaff_ESI + 0x794) == 0) && (unaff_EDI == 0)) {
      uVar1 = FUN_0049ca80();
      *(undefined4 *)(unaff_ESI + 0x790) = uVar1;
    }
  }
  return;
}

