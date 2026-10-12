/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dfb70; label: FUN_005dfb70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dfb70(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004ffaa0(DAT_00973fa4);
  iVar2 = 0;
  if (0 < DAT_009739b8) {
    piVar3 = &DAT_009739bc;
    do {
      uVar1 = *(uint *)(*piVar3 + 0x74);
      if ((uVar1 & 6) != 0) {
        *(uint *)(*piVar3 + 0x74) = uVar1 | 8;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < DAT_009739b8);
  }
  if ((DAT_00973e30 & 2) != 0) {
    DAT_00973e30 = DAT_00973e30 | 8;
  }
  FUN_004ffac0(DAT_00973fa4);
  return;
}

