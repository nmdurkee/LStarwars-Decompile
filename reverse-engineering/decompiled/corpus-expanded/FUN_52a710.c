/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a710; label: FUN_0052a710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

