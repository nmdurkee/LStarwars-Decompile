/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3950; label: FUN_005f3950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f3950(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_009718a0 = FUN_005efff0();
  if ((DAT_009718d8 != 0) && (DAT_009718a0 != -1)) {
    if (*(int *)(DAT_009718dc + 0x808) == 0) {
      DAT_009718d8 = 0;
    }
    else {
      iVar1 = DAT_009718e0 * 0x380 + DAT_009718dc;
      *(int *)(iVar1 + 0x354 + *(int *)(iVar1 + 0x374) * 4) = DAT_009718a0;
      *(int *)(iVar1 + 0x374) = *(int *)(iVar1 + 0x374) + 1;
    }
    DAT_009718a0 = -1;
  }
  puVar2 = &DAT_009718a0;
  puVar3 = &DAT_009640f0 + DAT_0095fbb8 * 0x86;
  for (iVar1 = 0x86; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_0095fbb8 = DAT_0095fbb8 + 1;
  return;
}

