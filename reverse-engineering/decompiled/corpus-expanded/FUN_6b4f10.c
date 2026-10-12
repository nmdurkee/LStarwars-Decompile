/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4f10; label: FUN_006b4f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_006b4f10(undefined4 param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t _NumOfElements;
  int iVar7;
  int iVar8;
  int *local_120;
  int *local_11c;
  int local_118;
  int local_114;
  int local_104 [65];
  
  pvVar2 = _calloc(1,0x520);
  iVar4 = *param_2;
  iVar6 = param_2[0xd2];
  local_114 = 0;
  *(int **)((int)pvVar2 + 0x510) = param_2;
  *(int *)((int)pvVar2 + 0x508) = iVar6;
  piVar3 = param_2;
  if (0 < iVar4) {
    do {
      local_114 = local_114 + param_2[piVar3[1] + 0x20];
      iVar4 = iVar4 + -1;
      piVar3 = piVar3 + 1;
    } while (iVar4 != 0);
  }
  _NumOfElements = local_114 + 2;
  iVar4 = 0;
  *(size_t *)((int)pvVar2 + 0x504) = _NumOfElements;
  if (0 < (int)_NumOfElements) {
    piVar3 = param_2 + 0xd1;
    do {
      local_104[iVar4] = (int)piVar3;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < (int)_NumOfElements);
  }
  _qsort(local_104,_NumOfElements,4,(_PtFuncCompare *)&LAB_006b4ef0);
  iVar4 = 0;
  if (0 < (int)_NumOfElements) {
    piVar3 = (int *)((int)pvVar2 + 0x104);
    do {
      *piVar3 = (local_104[iVar4] - (int)param_2) + -0x344 >> 2;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < (int)_NumOfElements);
  }
  iVar4 = 0;
  if (0 < (int)_NumOfElements) {
    piVar3 = (int *)((int)pvVar2 + 0x104);
    do {
      *(int *)((int)pvVar2 + *piVar3 * 4 + 0x208) = iVar4;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < (int)_NumOfElements);
  }
  iVar4 = 0;
  if (0 < (int)_NumOfElements) {
    do {
      *(int *)((int)pvVar2 + iVar4 * 4) = param_2[*(int *)((int)pvVar2 + iVar4 * 4 + 0x104) + 0xd1];
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)_NumOfElements);
  }
  switch(param_2[0xd0]) {
  case 1:
    *(undefined4 *)((int)pvVar2 + 0x50c) = 0x100;
    break;
  case 2:
    *(undefined4 *)((int)pvVar2 + 0x50c) = 0x80;
    break;
  case 3:
    *(undefined4 *)((int)pvVar2 + 0x50c) = 0x56;
    break;
  case 4:
    *(undefined4 *)((int)pvVar2 + 0x50c) = 0x40;
  }
  if (0 < local_114) {
    piVar3 = (int *)((int)pvVar2 + 0x30c);
    local_11c = param_2 + 0xd3;
    iVar4 = 2;
    do {
      local_118 = *(int *)((int)pvVar2 + 0x508);
      iVar6 = 0;
      iVar7 = 0;
      iVar5 = 0;
      iVar8 = 1;
      if (0 < iVar4) {
        local_120 = param_2 + 0xd1;
        do {
          iVar1 = *local_120;
          if ((iVar7 < iVar1) && (iVar1 < *local_11c)) {
            iVar6 = iVar5;
            iVar7 = iVar1;
          }
          if ((iVar1 < local_118) && (*local_11c < iVar1)) {
            iVar8 = iVar5;
            local_118 = iVar1;
          }
          local_120 = local_120 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      local_11c = local_11c + 1;
      piVar3[0x3f] = iVar6;
      *piVar3 = iVar8;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + 1;
      local_114 = local_114 + -1;
    } while (local_114 != 0);
  }
  return pvVar2;
}

