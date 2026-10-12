/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x5925f0; label: FUN_005925f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005925f0(int param_1)

{
  int in_EAX;
  int iVar1;
  int unaff_EDI;
  
  if ((((unaff_EDI != 2) && (iVar1 = FUN_0055f450(), iVar1 != 0)) && (DAT_00951364 != 0)) &&
     (*(int *)(iVar1 + 300) == DAT_00951364)) {
    iVar1 = *(int *)(iVar1 + 0x5120 + unaff_EDI * 4);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = in_EAX * 0x20 + iVar1;
    if (*(char *)(*(int *)(param_1 + unaff_EDI * 4) + 4) == '\0') {
      if (*(int *)(iVar1 + 0x14) == 0) {
        return 0;
      }
    }
    else {
      iVar1 = FUN_005cfac0(iVar1 + 4);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

