/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440470; label: FUN_00440470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00440470(int param_1,int param_2,float param_3,undefined4 param_4,float param_5,int param_6,
            float param_7,float param_8)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_118;
  int local_114;
  undefined1 local_10c [4];
  float local_108;
  int aiStack_100 [64];
  
  iVar5 = 0;
  local_114 = -1;
  if (param_5 == 1e+09) {
    local_118 = 1e+09;
  }
  else {
    local_118 = param_5 * param_5;
  }
  if (0x40 < param_2) {
    param_2 = 0x40;
  }
  iVar4 = 0;
  if (param_2 < 1) {
    return 0;
  }
  do {
    iVar3 = *(int *)(param_1 + iVar4 * 4);
    if (iVar3 != 0) {
      if (param_6 == 0) {
        if (param_3 <= 0.0) {
          aiStack_100[iVar5] = iVar4;
          iVar5 = iVar5 + 1;
        }
        else {
          iVar3 = FUN_005d6620(iVar3 + 0x10,param_3,&DAT_00806680);
          if (iVar3 != 0) {
            aiStack_100[iVar5] = iVar4;
            iVar5 = iVar5 + 1;
          }
        }
      }
      else {
        iVar3 = FUN_005d6620(iVar3 + 0x10,0,&DAT_00806680);
        if (iVar3 == 0) {
          aiStack_100[iVar5] = iVar4;
          iVar5 = iVar5 + 1;
        }
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < param_2);
  if ((iVar5 != 0) && (iVar4 = 0, 0 < iVar5)) {
    do {
      fVar6 = (float10)FUN_005b3c50(param_4,*(int *)(param_1 + aiStack_100[iVar4] * 4) + 0x10,
                                    local_10c);
      if (((param_8 != 1e+09) && (local_108 < param_8)) ||
         (((param_7 == 1e+09 || (fVar2 = local_118, iVar3 = local_114, local_108 <= param_7)) &&
          (fVar2 = (float)fVar6, iVar3 = iVar4, local_118 <= (float)fVar6)))) {
        fVar2 = local_118;
        iVar3 = local_114;
      }
      local_114 = iVar3;
      local_118 = fVar2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
    if (local_114 != -1) {
      uVar1 = *(undefined4 *)(param_1 + aiStack_100[local_114] * 4);
      *(undefined4 *)(param_1 + aiStack_100[local_114] * 4) = 0;
      return uVar1;
    }
  }
  return 0;
}

