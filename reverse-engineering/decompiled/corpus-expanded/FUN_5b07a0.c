/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b07a0; label: FUN_005b07a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b07a0(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_006217e0();
  iVar3 = FUN_006217e0();
  *(int *)(param_1 + 0x50f4) = iVar3;
  uVar4 = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf3);
  if ((int)uVar4 < iVar3) {
    *(uint *)(param_1 + 0x50f4) = uVar4;
  }
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x50f4)) {
    local_8 = 0;
    do {
      iVar7 = *(int *)(param_1 + 0x50ec) + local_8;
      cVar1 = FUN_006218c0();
      FUN_006216f0(iVar7,(int)cVar1);
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x1c) = (float)fVar8;
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x20) = (float)fVar8;
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x24) = (float)fVar8;
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x28) = (float)fVar8;
      fVar8 = (float10)FUN_006217a0();
      *(float *)(iVar7 + 0x2c) = (float)fVar8;
      cVar1 = FUN_006218c0();
      iVar3 = 0;
      *(int *)(iVar7 + 0x14) = (int)cVar1;
      if (0 < cVar1) {
        iVar5 = 0;
        do {
          iVar6 = *(int *)(iVar7 + 0x10) + iVar5;
          cVar1 = FUN_006218c0();
          FUN_006216f0(iVar6,(int)cVar1);
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x24) = (float)fVar8;
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x28) = (float)fVar8;
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x2c) = (float)fVar8;
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x30) = (float)fVar8;
          uVar2 = FUN_00621860();
          *(undefined2 *)(iVar6 + 0x34) = uVar2;
          uVar2 = FUN_00621860();
          *(undefined2 *)(iVar6 + 0x36) = uVar2;
          uVar2 = FUN_00621860();
          *(undefined2 *)(iVar6 + 0x38) = uVar2;
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x3c) = (float)fVar8;
          fVar8 = (float10)FUN_006217a0();
          *(float *)(iVar6 + 0x40) = (float)fVar8;
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 0x44;
        } while (iVar3 < *(int *)(iVar7 + 0x14));
      }
      local_8 = local_8 + 0x30;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(param_1 + 0x50f4));
  }
  return 1;
}

