/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e1f00; label: FUN_006e1f00
 */

void FUN_006e1f00(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_10;
  int local_c;
  
  uVar5 = *(uint *)(in_ECX + 0x618);
  iVar1 = *(int *)(in_ECX + 0x660);
  uVar10 = 0;
  iVar9 = iVar1;
  if (uVar5 != 0) {
    piVar3 = (int *)(iVar1 * 0x10 + *(int *)(in_ECX + 0x61c));
    do {
      piVar4 = (int *)(iVar9 * 0x10 + *(int *)(in_ECX + 0x61c));
      if ((*piVar4 != *piVar3) || (piVar4[1] != piVar3[1])) break;
      iVar9 = iVar9 + -1;
      if (iVar9 < 0) {
        iVar9 = uVar5 - 1;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar5);
  }
  local_10 = 1000;
  local_c = iVar9;
  if (-1 < iVar9) {
    iVar2 = *(int *)(in_ECX + 0x61c);
    iVar8 = iVar9 * 0x10;
    piVar3 = (int *)(iVar2 + 8 + iVar8);
    iVar7 = iVar8;
    do {
      if ((piVar3[-2] != *(int *)(iVar2 + iVar8)) || (piVar3[-1] != *(int *)(iVar2 + 4 + iVar8)))
      break;
      if (*piVar3 == *(int *)(iVar1 * 0x10 + 8 + iVar2)) {
        *(int *)(in_ECX + 0x660) = iVar9;
        return;
      }
      uVar5 = *piVar3 - *(int *)(iVar7 + 8 + iVar2);
      uVar10 = (int)uVar5 >> 0x1f;
      iVar6 = (uVar5 ^ uVar10) - uVar10;
      if (iVar6 < local_10) {
        iVar7 = (-8 - iVar2) + (int)piVar3;
        local_10 = iVar6;
        local_c = iVar9;
      }
      iVar9 = iVar9 + -1;
      piVar3 = piVar3 + -4;
    } while (-1 < iVar9);
  }
  *(int *)(in_ECX + 0x660) = local_c;
  return;
}

