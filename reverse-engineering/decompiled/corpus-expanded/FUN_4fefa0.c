/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4fefa0; label: FUN_004fefa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fefa0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00547580(DAT_0091f1b4,DAT_00921230);
  do {
    if (iVar1 == 0) break;
    iVar2 = FUN_00547580(DAT_0091f1b4,iVar1);
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 2;
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))(iVar1);
    }
    FUN_005474d0(iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0);
  if (DAT_00921230 != 0) {
    *(uint *)(DAT_00921230 + 8) = *(uint *)(DAT_00921230 + 8) | 2;
  }
  return;
}

