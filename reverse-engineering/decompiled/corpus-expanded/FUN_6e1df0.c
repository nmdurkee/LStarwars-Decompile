/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1df0; label: FUN_006e1df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e1df0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar4 = *(uint *)(in_ECX + 0x618);
  uVar8 = *(uint *)(in_ECX + 0x660);
  uVar6 = 0;
  if (uVar4 != 0) {
    piVar2 = (int *)(uVar8 * 0x10 + *(int *)(in_ECX + 0x61c));
    do {
      piVar3 = (int *)(uVar8 * 0x10 + *(int *)(in_ECX + 0x61c));
      if ((*piVar3 != *piVar2) || (piVar3[1] != piVar2[1])) break;
      uVar8 = uVar8 + 1;
      if (uVar8 == uVar4) {
        uVar8 = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != uVar4);
  }
  local_10 = 1000;
  local_8 = uVar8;
  if (uVar8 < uVar4) {
    iVar1 = *(int *)(in_ECX + 0x61c);
    iVar7 = uVar8 * 0x10;
    piVar2 = (int *)(iVar1 + 8 + iVar7);
    local_c = iVar7;
    do {
      if ((piVar2[-2] != *(int *)(iVar1 + iVar7)) || (piVar2[-1] != *(int *)(iVar1 + 4 + iVar7)))
      break;
      if (*piVar2 == *(int *)(*(int *)(in_ECX + 0x660) * 0x10 + 8 + iVar1)) {
        *(uint *)(in_ECX + 0x660) = uVar8;
        return;
      }
      uVar4 = *piVar2 - *(int *)(local_c + 8 + iVar1);
      uVar6 = (int)uVar4 >> 0x1f;
      iVar5 = (uVar4 ^ uVar6) - uVar6;
      if (iVar5 < local_10) {
        local_c = (-8 - iVar1) + (int)piVar2;
        local_10 = iVar5;
        local_8 = uVar8;
      }
      uVar8 = uVar8 + 1;
      piVar2 = piVar2 + 4;
    } while (uVar8 < *(uint *)(in_ECX + 0x618));
  }
  *(uint *)(in_ECX + 0x660) = local_8;
  return;
}

