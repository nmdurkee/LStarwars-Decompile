/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46df70; label: FUN_0046df70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046df70(int param_1,undefined4 param_2,float param_3)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  float10 fVar10;
  int local_40;
  uint local_3c;
  int local_38;
  float local_34;
  float local_30;
  int local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  piVar4 = *(int **)(param_1 + 0x5070);
  local_40 = 0;
  if ((piVar4 != (int *)0x0) && (local_2c = 0, 0 < *piVar4)) {
    local_38 = 0;
    do {
      iVar9 = piVar4[1] + local_38;
      if ((*(byte *)(iVar9 + 0x62) & 8) != 0) {
        local_30 = 1e+09;
        local_40 = 0;
        if ((*(byte *)(iVar9 + 0x62) & 0x10) == 0) {
          local_34 = 0.80999994;
        }
        else {
          local_34 = 1.21;
        }
        piVar8 = &DAT_0093d7f0;
        do {
          iVar5 = *piVar8;
          if (((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) &&
             (*(char *)(iVar5 + 0x28b) == '\0')) {
            uVar7 = FUN_0046d8f0();
            fVar10 = (float10)FUN_005b3c50(uVar7,iVar5 + 0x80,&local_24);
            local_28 = (float)fVar10;
            if ((local_28 < local_30) && (local_28 < local_34)) {
              local_18 = local_24;
              local_40 = *piVar8;
              local_14 = local_20;
              local_10 = local_1c;
              local_30 = local_28;
            }
          }
          piVar8 = piVar8 + 1;
        } while ((int)piVar8 < 0x93d810);
      }
      if (local_40 == 0) {
        uVar6 = FUN_00550070(*(undefined2 *)(iVar9 + 0x7c),0xe000,0x41200000);
        *(undefined2 *)(iVar9 + 0x7c) = uVar6;
        uVar6 = FUN_00550070(*(undefined2 *)(iVar9 + 0x7e),0,0x41200000);
        *(undefined2 *)(iVar9 + 0x7e) = uVar6;
        if ((*(byte *)(iVar9 + 0x62) & 0x10) != 0) {
          FUN_00681f40("DPanelDis",iVar9 + 0x50);
        }
        *(byte *)(iVar9 + 0x62) = *(byte *)(iVar9 + 0x62) & 0xef;
        if (0.0 < *(float *)(iVar9 + 0x88)) {
          local_28 = *(float *)(iVar9 + 0x88) - param_3;
          *(float *)(iVar9 + 0x88) = local_28;
          if (local_28 < 0.0) {
            *(undefined4 *)(iVar9 + 0x88) = 0;
          }
        }
      }
      else {
        uVar2 = *(ushort *)(iVar9 + 0x7c);
        uVar3 = *(ushort *)(iVar9 + 0x7e);
        FUN_0054ff40(&local_18,&local_3c,&param_1);
        sVar1 = (short)param_1 - *(short *)(iVar9 + 0x5c);
        param_1 = CONCAT22(param_1._2_2_,sVar1);
        if ((uVar3 < 0x4001) && ((ushort)(sVar1 + 0xbfffU) < 0x7fff)) {
          param_1 = 0x4000;
        }
        else if ((0xbfff < uVar3) && ((ushort)(sVar1 + 0xbfffU) < 0x7fff)) {
          param_1 = 0xc000;
        }
        if ((uVar2 < 0x4001) && ((ushort)((short)local_3c + 0xbfffU) < 0x7fff)) {
          local_3c = (uint)(ushort)(*(short *)(iVar9 + 0x5c) + 0x4000);
        }
        else if ((0xbfff < uVar2) && ((ushort)((short)local_3c + 0xbfffU) < 0x7fff)) {
          local_3c = 0xc000;
        }
        uVar6 = FUN_00550070(*(undefined2 *)(iVar9 + 0x7c),local_3c,0x40a00000);
        *(undefined2 *)(iVar9 + 0x7c) = uVar6;
        uVar6 = FUN_00550070(*(undefined2 *)(iVar9 + 0x7e),param_1,0x40a00000);
        *(undefined2 *)(iVar9 + 0x7e) = uVar6;
        if ((*(byte *)(iVar9 + 0x62) & 0x10) == 0) {
          *(undefined4 *)(iVar9 + 0x88) = 0;
          *(byte *)(iVar9 + 0x62) = *(byte *)(iVar9 + 0x62) | 0x10;
          FUN_00681f40("DPanelAct",iVar9 + 0x50);
        }
        else {
          local_28 = *(float *)(iVar9 + 0x88) + _DAT_00925018;
          *(float *)(iVar9 + 0x88) = local_28;
          if (0.8 < local_28) {
            *(undefined4 *)(iVar9 + 0x88) = 0x3f4ccccd;
          }
        }
      }
      local_38 = local_38 + 0x90;
      local_2c = local_2c + 1;
    } while (local_2c < *piVar4);
  }
  return;
}

