/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f18c0; label: FUN_004f18c0
 */

undefined4
FUN_004f18c0(int param_1,int param_2,float *param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = param_1;
  local_40 = *param_3;
  local_3c = (param_3[1] + *param_3) * 0.5;
  iVar3 = param_2 * 0xc;
  param_6 = param_6 + -1;
  local_38 = param_3[2];
  local_44 = 0;
  local_34 = (param_3[3] + param_3[2]) * 0.5;
  local_2c = param_3[1];
  local_28 = param_3[2];
  local_20 = *param_3;
  local_14 = param_3[3];
  local_c = param_3[1];
  local_4 = param_3[3];
  psVar6 = (short *)(*(int *)(param_1 + 0x14) + iVar3);
  sVar1 = *psVar6;
  local_30 = local_3c;
  local_24 = local_34;
  local_1c = local_3c;
  local_18 = local_34;
  local_10 = local_3c;
  local_8 = local_34;
  if (-1 < sVar1) {
    if (((int)sVar1 < *(int *)(param_1 + 0x30)) || (param_6 == 0)) {
      uVar8 = FUN_004f1780(param_5);
      return uVar8;
    }
    puVar10 = *(undefined1 **)(psVar6 + 2);
    uVar5 = FUN_004f1870(param_2);
    *(undefined2 *)(iVar3 + 4 + *(int *)(param_1 + 0x14)) = uVar5;
    uVar5 = FUN_004f1870(param_2);
    *(undefined2 *)(iVar3 + 6 + *(int *)(param_1 + 0x14)) = uVar5;
    uVar5 = FUN_004f1870(param_2);
    *(undefined2 *)(iVar3 + 8 + *(int *)(param_1 + 0x14)) = uVar5;
    uVar5 = FUN_004f1870(param_2);
    *(undefined2 *)(iVar3 + 10 + *(int *)(param_1 + 0x14)) = uVar5;
    iVar7 = *(int *)(param_1 + 0x14);
    if ((((*(short *)(iVar3 + 4 + iVar7) != 0) ||
         (psVar6 = (short *)(iVar3 + iVar7), *(short *)(iVar3 + 6 + iVar7) == 0)) ||
        (psVar6[4] == 0)) || (psVar6[5] == 0)) {
      *(undefined1 **)(iVar3 + 4 + iVar7) = puVar10;
      uVar8 = FUN_004f1780(param_5);
      return uVar8;
    }
    param_1 = 0;
    puVar9 = puVar10;
    if (0 < *psVar6) {
      do {
        iVar7 = FUN_004f1730();
        if (iVar7 != 0) {
          local_44 = FUN_004f18c0(iVar4,psVar6[2],&local_40,extraout_ECX,puVar9,param_6);
        }
        uVar11 = FUN_004f1730();
        if ((int)uVar11 != 0) {
          local_44 = FUN_004f18c0(iVar4,*(undefined2 *)(iVar3 + 6 + *(int *)(iVar4 + 0x14)),
                                  (int)((ulonglong)uVar11 >> 0x20),param_4,puVar9,param_6);
        }
        uVar11 = FUN_004f1730();
        if ((int)uVar11 != 0) {
          local_44 = FUN_004f18c0(iVar4,*(undefined2 *)(iVar3 + 8 + *(int *)(iVar4 + 0x14)),
                                  (int)((ulonglong)uVar11 >> 0x20),param_4,puVar9,param_6);
        }
        iVar7 = FUN_004f1730();
        if (iVar7 != 0) {
          local_44 = FUN_004f18c0(iVar4,*(undefined2 *)(iVar3 + 10 + *(int *)(iVar4 + 0x14)),
                                  &local_10,param_4,puVar9,param_6);
        }
        puVar9 = puVar9 + *(int *)(iVar4 + 0x2c);
        psVar6 = (short *)(iVar3 + *(int *)(iVar4 + 0x14));
        param_1 = param_1 + 1;
      } while (param_1 < *(short *)(iVar3 + *(int *)(iVar4 + 0x14)));
    }
    iVar7 = *(int *)(iVar4 + 0x24);
    iVar2 = *(int *)(iVar4 + 0x20);
    for (puVar9 = puVar10 + (int)*(short *)(iVar3 + *(int *)(iVar4 + 0x14)) * *(int *)(iVar4 + 0x2c)
        ; puVar9 < (undefined1 *)(iVar7 + iVar2); puVar9 = puVar9 + 1) {
      *puVar10 = *puVar9;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)(iVar3 + *(int *)(iVar4 + 0x14)) = 0xffff;
  }
  iVar7 = *(int *)(iVar4 + 0x14);
  if (*(short *)(iVar3 + iVar7) < 0) {
    uVar11 = FUN_004f1730();
    if (((int)uVar11 != 0) && (sVar1 = *(short *)(iVar3 + iVar7 + 4), sVar1 != 0)) {
      local_44 = FUN_004f18c0(iVar4,sVar1,(int)((ulonglong)uVar11 >> 0x20),param_4,param_5,param_6);
    }
    iVar7 = FUN_004f1730();
    if ((iVar7 != 0) && (sVar1 = *(short *)(iVar3 + 6 + *(int *)(iVar4 + 0x14)), sVar1 != 0)) {
      local_44 = FUN_004f18c0(iVar4,sVar1,&local_30,param_4,param_5,param_6);
    }
    uVar11 = FUN_004f1730();
    if (((int)uVar11 != 0) && (sVar1 = *(short *)(iVar3 + 8 + *(int *)(iVar4 + 0x14)), sVar1 != 0))
    {
      local_44 = FUN_004f18c0(iVar4,sVar1,(int)((ulonglong)uVar11 >> 0x20),param_4,param_5,param_6);
    }
    iVar7 = FUN_004f1730();
    if ((iVar7 != 0) && (sVar1 = *(short *)(iVar3 + 10 + *(int *)(iVar4 + 0x14)), sVar1 != 0)) {
      local_44 = FUN_004f18c0(iVar4,sVar1,&local_10,param_4,param_5,param_6);
    }
  }
  return local_44;
}

