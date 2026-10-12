/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x5226b0; label: FUN_005226b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005226b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar1)) {
    *(undefined1 *)(iVar1 + 0x46) = 0;
  }
  if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
    iVar1 = 0x18;
    do {
      if (*(int *)(*(int *)(DAT_009238e4 + 0x41208) + iVar1) == 0) break;
      iVar3 = *(int *)(*(int *)(DAT_009238e4 + 0x41208) + iVar1);
      if (*(int *)(DAT_009238e4 + 0x3cbe0) == iVar3) {
        iVar2 = (-(uint)(*(int *)(DAT_009238e4 + 0x3cbe0) != *(int *)(DAT_009238e4 + 0x3cbe4)) &
                0x81000000) - 0xffff01;
      }
      else {
        iVar2 = (-(uint)(*(int *)(DAT_009238e4 + 0x3cbe4) != iVar3) & 0x32323233) - 1;
      }
      FUN_00522500(iVar3 + 0x18,_DAT_00801cc4,*(undefined4 *)(iVar3 + 0x24),iVar2);
      iVar1 = iVar1 + 4;
      *(undefined1 *)(iVar3 + 0x46) = 1;
    } while (iVar1 < 0x118);
  }
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar1)) {
    if (*(char *)(iVar1 + 0x46) == '\0') {
      iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
      if (*(int *)(DAT_009238e4 + 0x41208) == 0) {
        if (iVar3 == iVar1) {
          iVar3 = (-(uint)(iVar3 != *(int *)(DAT_009238e4 + 0x3cbe4)) & 0x81000000) - 0xffff01;
        }
        else {
          iVar3 = (-(uint)(*(int *)(DAT_009238e4 + 0x3cbe4) != iVar1) & 0x32323233) - 1;
        }
      }
      else if (iVar3 == iVar1) {
        iVar3 = (-(uint)(iVar3 != *(int *)(DAT_009238e4 + 0x3cbe4)) & 0xffffffd8) + 0x50;
      }
      else {
        iVar3 = (-(uint)(*(int *)(DAT_009238e4 + 0x3cbe4) != iVar1) & 0xcdcdcdce) + 0x64646464;
      }
      FUN_00522500(iVar1 + 0x18,_DAT_00801cc4,*(undefined4 *)(iVar1 + 0x24),iVar3);
      *(undefined1 *)(iVar1 + 0x46) = 1;
    }
  }
  return;
}

