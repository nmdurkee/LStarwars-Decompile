/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1b70; label: FUN_006e1b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006e1b70(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int local_18;
  int *local_14;
  int local_10;
  int local_8;
  
  iVar1 = *(int *)(in_ECX + 0x618);
  local_18 = 10000;
  local_10 = 10000;
  local_8 = 10000;
  iVar4 = 0;
  iVar8 = 0;
  local_14 = (int *)0x0;
  if (iVar1 != 0) {
    piVar3 = *(int **)(in_ECX + 0x61c);
    do {
      local_14 = piVar3;
      uVar2 = *local_14 - param_1;
      uVar5 = (int)uVar2 >> 0x1f;
      uVar6 = local_18 - param_1 >> 0x1f;
      if ((int)((uVar2 ^ uVar5) - uVar5) <= (int)((local_18 - param_1 ^ uVar6) - uVar6)) {
        iVar4 = iVar8;
        local_18 = *local_14;
      }
      piVar3 = local_14 + 4;
      iVar8 = iVar8 + 1;
      local_14 = (int *)iVar4;
    } while (iVar8 != iVar1);
  }
  iVar4 = 0;
  if (iVar1 != 0) {
    piVar3 = *(int **)(in_ECX + 0x61c);
    do {
      if ((*piVar3 == local_18) &&
         (uVar2 = piVar3[1] - param_2, uVar5 = (int)uVar2 >> 0x1f,
         uVar6 = local_10 - param_2 >> 0x1f,
         (int)((uVar2 ^ uVar5) - uVar5) <= (int)((local_10 - param_2 ^ uVar6) - uVar6))) {
        local_14 = (int *)iVar4;
        local_10 = piVar3[1];
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar4 != iVar1);
  }
  piVar3 = local_14;
  if ((param_3 != 0) && (iVar4 = 0, iVar1 != 0)) {
    piVar7 = *(int **)(in_ECX + 0x61c);
    do {
      if (((*piVar7 == local_18) && (piVar7[1] == local_10)) &&
         (uVar2 = piVar7[2] - param_3, uVar5 = (int)uVar2 >> 0x1f, uVar6 = local_8 - param_3 >> 0x1f
         , piVar3 = local_14,
         (int)((uVar2 ^ uVar5) - uVar5) <= (int)((local_8 - param_3 ^ uVar6) - uVar6))) {
        piVar3 = (int *)iVar4;
        local_14 = (int *)iVar4;
        local_8 = piVar7[2];
      }
      iVar4 = iVar4 + 1;
      piVar7 = piVar7 + 4;
    } while (iVar4 != iVar1);
  }
  if (*(char *)(in_ECX + 0x65c) != '\0') {
    piVar7 = (int *)(*(int *)(in_ECX + 0x61c) + (int)piVar3 * 0x10);
    if (*piVar7 != param_1) {
      *piVar7 = param_1;
    }
    piVar7 = (int *)((int)piVar3 * 0x10 + 4 + *(int *)(in_ECX + 0x61c));
    if (*piVar7 != param_2) {
      *piVar7 = param_2;
    }
  }
  return (int)piVar3;
}

