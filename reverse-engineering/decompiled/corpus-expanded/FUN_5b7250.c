/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b7250; label: FUN_005b7250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b7250(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float local_90;
  float local_8c;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  local_90 = 3.4028235e+38;
  local_8c = 1.0;
  FUN_005b7180(local_40,param_2);
  puVar4 = &DAT_00806680;
  puVar6 = param_1;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar3 = 100;
  do {
    iVar5 = 0;
    do {
      fVar2 = local_90;
      if (((byte)iVar5 & 3) != 3) {
        uVar1 = param_1[iVar5];
        param_1[iVar5] = (float)param_1[iVar5] + local_8c;
        *(undefined1 *)(param_1 + iVar5) = 0;
        FUN_005c1240(local_80,param_1,local_40);
        fVar7 = (float10)FUN_005b6ff0(local_80,param_2);
        fVar2 = (float)fVar7;
        if (local_90 < fVar2 != (local_90 == fVar2)) {
          param_1[iVar5] = uVar1;
          fVar2 = local_90;
        }
        local_90 = fVar2;
        uVar1 = param_1[iVar5];
        param_1[iVar5] = (float)param_1[iVar5] - local_8c;
        *(undefined1 *)(param_1 + iVar5) = 0;
        FUN_005c1240(local_80,param_1,local_40);
        fVar7 = (float10)FUN_005b6ff0(local_80,param_2);
        fVar2 = (float)fVar7;
        if (local_90 < fVar2 != (local_90 == fVar2)) {
          param_1[iVar5] = uVar1;
          fVar2 = local_90;
        }
      }
      local_90 = fVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x10);
    iVar3 = iVar3 + -1;
    local_8c = local_8c * 0.9;
  } while (iVar3 != 0);
  return;
}

