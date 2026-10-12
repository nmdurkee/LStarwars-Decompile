/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49d430; label: FUN_0049d430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049d430(undefined1 param_1,undefined1 param_2)

{
  int unaff_ESI;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((*(uint *)(unaff_ESI + 0x1f8) & 0x40000) == 0) || (*(char *)(unaff_ESI + 0x280) == -1)) {
    if ((*(uint *)(*(int *)(unaff_ESI + 0x54) + 4) & 0x2000) == 0) {
      uVar1 = **(undefined4 **)(unaff_ESI + 0xca4);
      uVar2 = 2;
    }
    else {
      uVar1 = **(undefined4 **)(unaff_ESI + 0xca4);
      uVar2 = 1;
    }
    FUN_0054a8d0(uVar1,uVar2,0);
    *(uint *)(unaff_ESI + 0xeec) = *(uint *)(unaff_ESI + 0xeec) | 0x800;
    *(undefined1 *)(unaff_ESI + 0xe3f) = param_1;
    *(undefined1 *)(unaff_ESI + 0xe30) = param_2;
    if ((*(byte *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x98) & 2) != 0) {
      FUN_0058d8e0();
    }
    if (((*(int *)(unaff_ESI + 0x7f4) != 0) &&
        (*(char *)(*(int *)(unaff_ESI + 0x7f4) + 8) == '\x02')) &&
       (*(char *)(unaff_ESI + 0x7f8) != '\0')) {
      *(char *)(unaff_ESI + 0x7f8) = *(char *)(unaff_ESI + 0x7f8) + -1;
    }
  }
  return;
}

