/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8e90; label: FUN_004f8e90
 */

undefined * FUN_004f8e90(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  puVar3 = &DAT_0091eed0;
  do {
    iVar1 = puVar3[1];
    if (0 < iVar1) {
      piVar4 = (int *)*puVar3;
      iVar5 = 0;
      do {
        if ((*piVar4 != 0) && (piVar4[1] != 0)) {
          iVar2 = FUN_004f8b10(*piVar4,param_1);
          if (iVar2 == 0) {
            return *(undefined **)((&DAT_0091eed0)[local_4 * 3] + 4 + iVar5 * 8);
          }
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 2;
      } while (iVar5 < iVar1);
    }
    local_4 = local_4 + 1;
    puVar3 = puVar3 + 3;
  } while ((int)puVar3 < 0x91eef4);
  return PTR_DAT_00800488;
}

