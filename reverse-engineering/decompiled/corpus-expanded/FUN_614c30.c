/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x614c30; label: FUN_00614c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00614c30(uint param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  int iVar5;
  undefined4 uVar6;
  uint local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  uVar1 = param_1;
  uVar6 = 0;
  iVar4 = FUN_00612b60(param_1);
  if (iVar4 != 0) {
    local_14 = (int *)(iVar4 + 8);
    if (*(char *)(*local_14 + 0xc) == '\0') {
      param_1 = FUN_006be780(*(undefined4 *)(iVar4 + 0x10));
      iVar5 = param_5;
      iVar3 = param_4;
      iVar2 = param_3;
      local_18 = (uint)*(ushort *)(iVar4 + 2);
      param_1 = param_1 & 0xffff;
      local_c = param_4;
      local_8 = param_5;
      local_4 = param_6;
      local_10 = param_3;
      if (param_4 == 0) {
        FUN_0060f2d0();
      }
      else {
        *(int *)(param_4 + 0x4b0) = *(int *)(param_4 + 0x4b0) + 1;
        iVar4 = param_4 + param_5 + -2;
        FUN_004ef660(iVar4,&param_1,2);
        if (iVar2 != 0) {
          FUN_00621180(iVar4);
        }
        iVar5 = iVar5 + -4;
        local_8 = iVar5;
        FUN_004ef660(iVar3 + iVar5,&local_18,2);
        if (iVar2 != 0) {
          FUN_00621180(iVar3 + iVar5);
        }
      }
      if (iVar3 != 0) {
        iVar5 = iVar5 + -1;
        local_8 = iVar5;
        FUN_004ef660(iVar3 + iVar5,&param_2,1);
      }
      param_2 = CONCAT31(param_2._1_3_,8);
      if (iVar3 != 0) {
        local_8 = iVar5 + -1;
        FUN_004ef660(iVar3 + local_8,&param_2,1);
      }
      FUN_0053d460(&local_10);
      FUN_0060efd0();
      if (iVar3 != 0) {
        if (*(uint *)(iVar3 + 0x4b0) < 2) {
          *(undefined4 *)(iVar3 + 0x4b0) = 0;
        }
        else {
          *(uint *)(iVar3 + 0x4b0) = *(uint *)(iVar3 + 0x4b0) - 1;
        }
      }
    }
    else {
      (**(code **)(extraout_ECX + (param_2 * 3 + 0x35ac) * 4))(uVar1,&param_3);
    }
    uVar6 = 1;
  }
  if (param_4 != 0) {
    if (1 < *(uint *)(param_4 + 0x4b0)) {
      *(uint *)(param_4 + 0x4b0) = *(uint *)(param_4 + 0x4b0) - 1;
      return uVar6;
    }
    *(undefined4 *)(param_4 + 0x4b0) = 0;
  }
  return uVar6;
}

