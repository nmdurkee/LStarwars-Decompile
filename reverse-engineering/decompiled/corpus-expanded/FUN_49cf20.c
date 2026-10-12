/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49cf20; label: FUN_0049cf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

