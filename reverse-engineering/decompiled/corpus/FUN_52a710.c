/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52a710; label: FUN_0052a710
 */

void FUN_0052a710(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  
  *(undefined4 *)(unaff_ESI + 0x54) = 1;
  iVar3 = 1;
  if (1 < *(byte *)(unaff_ESI + 0x5b)) {
    do {
      iVar1 = FUN_0052a630();
      if (iVar1 != 0) {
        uVar2 = __allshl();
        *(uint *)(unaff_ESI + 0x54) = *(uint *)(unaff_ESI + 0x54) | uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(unaff_ESI + 0x5b));
  }
  return;
}

