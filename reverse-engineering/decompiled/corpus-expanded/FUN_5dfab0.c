/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dfab0; label: FUN_005dfab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dfab0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004ffaa0(DAT_00973fa4);
  DAT_00973e30 = DAT_00973e30 ^ 0x8000;
  FUN_005ddd10(0);
  iVar2 = 0;
  if (0 < DAT_009739b8) {
    piVar3 = &DAT_009739bc;
    do {
      iVar1 = *piVar3;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) ^ 0x8000;
      FUN_005ddd10(0);
      if (*(int *)(iVar1 + 0x78) != 0) {
        *(undefined4 *)(*(int *)(iVar1 + 0x78) + 0x44) = 0;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < DAT_009739b8);
  }
  DAT_00973ed0 = 0;
  for (iVar2 = DAT_00973ecc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffffffd;
  }
  FUN_005fd160();
  FUN_004ffac0(DAT_00973fa4);
  return;
}

