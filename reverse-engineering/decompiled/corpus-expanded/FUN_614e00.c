/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x614e00; label: FUN_00614e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00614e00(undefined4 param_1,undefined1 param_2,int param_3,int param_4,int param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  uVar4 = 0;
  iVar3 = FUN_00612b60(param_1);
  iVar2 = param_4;
  if (iVar3 != 0) {
    if (*(char *)(*(int *)(iVar3 + 8) + 0xc) != '\0') {
      local_18 = FUN_006be780(*(undefined4 *)(iVar3 + 0x10));
      iVar5 = param_5;
      iVar1 = param_3;
      local_14 = (uint)*(ushort *)(iVar3 + 2);
      local_18 = local_18 & 0xffff;
      local_c = iVar2;
      local_8 = param_5;
      local_4 = param_6;
      local_10 = param_3;
      if (iVar2 == 0) {
        FUN_0060f2d0();
      }
      else {
        *(int *)(iVar2 + 0x4b0) = *(int *)(iVar2 + 0x4b0) + 1;
        iVar3 = param_5 + -2 + iVar2;
        FUN_004ef660(iVar3,&local_18,2);
        if (iVar1 != 0) {
          FUN_00621180(iVar3);
        }
        iVar5 = iVar5 + -4;
        local_8 = iVar5;
        FUN_004ef660(iVar5 + iVar2,&local_14,2);
        if (iVar1 != 0) {
          FUN_00621180(iVar5 + iVar2);
        }
      }
      param_1._0_1_ = param_2;
      if (iVar2 != 0) {
        iVar5 = iVar5 + -1;
        local_8 = iVar5;
        FUN_004ef660(iVar5 + iVar2,&param_1,1);
      }
      param_1 = CONCAT31(param_1._1_3_,8);
      if (iVar2 != 0) {
        local_8 = iVar5 + -1;
        FUN_004ef660(local_8 + iVar2,&param_1,1);
      }
      FUN_0053d460(&local_10);
      FUN_0060f190();
      if (iVar2 != 0) {
        if (*(uint *)(iVar2 + 0x4b0) < 2) {
          *(undefined4 *)(iVar2 + 0x4b0) = 0;
        }
        else {
          *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
        }
      }
    }
    uVar4 = 1;
  }
  if (iVar2 != 0) {
    if (1 < *(uint *)(iVar2 + 0x4b0)) {
      *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
      return uVar4;
    }
    *(undefined4 *)(iVar2 + 0x4b0) = 0;
  }
  return uVar4;
}

