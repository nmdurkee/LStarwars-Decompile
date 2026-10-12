/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8e20; label: FUN_004f8e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f8e20(undefined4 param_1)

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
            return local_4 * 0x1000000 + iVar5;
          }
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 2;
      } while (iVar5 < iVar1);
    }
    local_4 = local_4 + 1;
    puVar3 = puVar3 + 3;
  } while ((int)puVar3 < 0x91eef4);
  return -1;
}

