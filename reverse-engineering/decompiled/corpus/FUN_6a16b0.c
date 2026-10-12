/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a16b0; label: FUN_006a16b0
 */

undefined4 FUN_006a16b0(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)(param_2 + 0x1c);
  if (piVar1 != (int *)0x0) {
    iVar7 = piVar1[0x392];
    _memset(param_1,0,0x70);
    pvVar2 = _calloc(1,0x88);
    param_1[1] = param_2;
    param_1[0x1a] = pvVar2;
    iVar6 = 0;
    if (piVar1[2] != 0) {
      for (uVar3 = piVar1[2] - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
        iVar6 = iVar6 + 1;
      }
    }
    *(int *)((int)pvVar2 + 0x2c) = iVar6;
    pvVar4 = _calloc(1,4);
    *(void **)((int)pvVar2 + 0xc) = pvVar4;
    pvVar4 = _calloc(1,4);
    *(void **)((int)pvVar2 + 0x10) = pvVar4;
    pvVar4 = _calloc(1,0x14);
    **(undefined4 **)((int)pvVar2 + 0xc) = pvVar4;
    pvVar4 = _calloc(1,0x14);
    **(undefined4 **)((int)pvVar2 + 0x10) = pvVar4;
    FUN_006af2a0(**(undefined4 **)((int)pvVar2 + 0xc),*piVar1 >> ((byte)iVar7 & 0x1f));
    FUN_006af2a0(**(undefined4 **)((int)pvVar2 + 0x10),piVar1[1] >> ((byte)iVar7 & 0x1f));
    iVar7 = 0;
    if (*piVar1 != 0) {
      for (uVar3 = *piVar1 - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
        iVar7 = iVar7 + 1;
      }
    }
    *(int *)((int)pvVar2 + 4) = iVar7 + -6;
    iVar7 = 0;
    if (piVar1[1] != 0) {
      for (uVar3 = piVar1[1] - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
        iVar7 = iVar7 + 1;
      }
    }
    *(int *)((int)pvVar2 + 8) = iVar7 + -6;
    if (param_3 == 0) {
      if (piVar1[0x2c8] == 0) {
        pvVar4 = _calloc(piVar1[6],0x2c);
        piVar1[0x2c8] = (int)pvVar4;
        local_8 = 0;
        if (0 < piVar1[6]) {
          local_4 = 0;
          piVar8 = piVar1 + 0x1c8;
          do {
            FUN_006a8920(piVar1[0x2c8] + local_4,*piVar8);
            FUN_006a87c0(*piVar8);
            local_4 = local_4 + 0x2c;
            *piVar8 = 0;
            local_8 = local_8 + 1;
            piVar8 = piVar8 + 1;
          } while (local_8 < piVar1[6]);
        }
      }
    }
    else {
      FUN_006af210((int)pvVar2 + 0x14,*piVar1);
      FUN_006af210((int)pvVar2 + 0x20,piVar1[1]);
      if (piVar1[0x2c8] == 0) {
        pvVar4 = _calloc(piVar1[6],0x2c);
        piVar1[0x2c8] = (int)pvVar4;
        local_8 = 0;
        if (0 < piVar1[6]) {
          local_4 = 0;
          piVar8 = piVar1 + 0x1c8;
          do {
            FUN_006a8850(piVar1[0x2c8] + local_4,*piVar8);
            local_4 = local_4 + 0x2c;
            local_8 = local_8 + 1;
            piVar8 = piVar8 + 1;
          } while (local_8 < piVar1[6]);
        }
      }
      pvVar4 = _calloc(piVar1[7],0x34);
      *(void **)((int)pvVar2 + 0x38) = pvVar4;
      local_8 = 0;
      if (0 < piVar1[7]) {
        local_4 = 0;
        piVar8 = piVar1 + 0x2c9;
        do {
          FUN_006a4c70(*(int *)((int)pvVar2 + 0x38) + local_4,(int *)*piVar8,piVar1 + 0x2cd,
                       piVar1[*(int *)*piVar8] / 2,*(undefined4 *)(param_2 + 8));
          local_4 = local_4 + 0x34;
          local_8 = local_8 + 1;
          piVar8 = piVar8 + 1;
        } while (local_8 < piVar1[7]);
      }
      *param_1 = 1;
    }
    param_1[4] = piVar1[1];
    pvVar4 = _malloc(*(int *)(param_2 + 4) * 4);
    param_1[2] = pvVar4;
    pvVar4 = _malloc(*(int *)(param_2 + 4) * 4);
    iVar7 = 0;
    param_1[3] = pvVar4;
    if (0 < *(int *)(param_2 + 4)) {
      do {
        pvVar4 = _calloc(param_1[4],4);
        *(void **)(param_1[2] + iVar7 * 4) = pvVar4;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_2 + 4));
    }
    param_1[9] = 0;
    param_1[10] = 0;
    iVar7 = piVar1[1];
    param_1[0xc] = iVar7 / 2;
    param_1[5] = iVar7 / 2;
    pvVar4 = _calloc(piVar1[4],4);
    *(void **)((int)pvVar2 + 0x30) = pvVar4;
    pvVar4 = _calloc(piVar1[5],4);
    *(void **)((int)pvVar2 + 0x34) = pvVar4;
    local_8 = 0;
    if (0 < piVar1[4]) {
      piVar8 = piVar1 + 200;
      do {
        uVar5 = (**(code **)((&PTR_DAT_00817010)[*piVar8] + 8))(param_1,piVar8[0x40]);
        *(undefined4 *)((int)piVar8 + *(int *)((int)pvVar2 + 0x30) + (-800 - (int)piVar1)) = uVar5;
        local_8 = local_8 + 1;
        piVar8 = piVar8 + 1;
      } while (local_8 < piVar1[4]);
    }
    local_8 = 0;
    if (0 < piVar1[5]) {
      piVar8 = piVar1 + 0x148;
      do {
        uVar5 = (**(code **)((&PTR_DAT_00817018)[*piVar8] + 8))(param_1,piVar8[0x40]);
        *(undefined4 *)((int)piVar8 + *(int *)((int)pvVar2 + 0x34) + (-0x520 - (int)piVar1)) = uVar5
        ;
        local_8 = local_8 + 1;
        piVar8 = piVar8 + 1;
      } while (local_8 < piVar1[5]);
    }
    return 0;
  }
  return 1;
}

