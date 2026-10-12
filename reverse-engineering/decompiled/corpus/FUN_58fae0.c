/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58fae0; label: FUN_0058fae0
 */

void FUN_0058fae0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  byte *pbVar8;
  float10 fVar9;
  float local_64;
  float local_60;
  float local_5c;
  int local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  local_64 = -1e+09;
  iVar7 = 0;
  if (*(int *)(PTR_DAT_00802c54 + 0x46a8) != 0) {
    fVar1 = *(float *)(param_1 + 0x80);
    local_20 = *(undefined4 *)(param_1 + 0x84);
    fVar2 = *(float *)(param_1 + 0x88);
    local_58 = 0;
    if ((short)(*(int **)(PTR_DAT_00802c54 + 0x46a8))[1] != 0) {
      pbVar8 = (byte *)(**(int **)(PTR_DAT_00802c54 + 0x46a8) + 0x6f);
      puVar6 = PTR_DAT_00802c54;
      local_24 = fVar1;
      local_1c = fVar2;
      do {
        local_54 = DAT_0093b0cc;
        local_50 = DAT_0093b0d0;
        local_4c = DAT_0093b0d4;
        if ((((pbVar8[3] & 8) != 0) && ((pbVar8[0xb] & 2) != 0)) && (*pbVar8 != 0)) {
          local_10 = *(float *)(pbVar8 + -0x33);
          local_18 = *(float *)(pbVar8 + -0x3b);
          local_14 = *(float *)(pbVar8 + -0x37);
          local_3c = 1e+09;
          local_34 = 1e+09;
          iVar5 = 0;
          local_48 = -1e+09;
          local_40 = -1e+09;
          if ((pbVar8[3] & 0x10) == 0) {
            if (*pbVar8 != 0) {
              do {
                iVar3 = *(int *)(*(int *)(*(int *)(pbVar8 + -0x5b) + iVar5 * 4) + 0x24);
                local_30 = *(float *)(iVar3 + 0x70);
                local_2c = *(undefined4 *)(iVar3 + 0x74);
                local_28 = *(float *)(iVar3 + 0x78);
                local_54 = local_30 + local_54;
                local_4c = local_28 + local_4c;
                fVar2 = local_30 - local_18;
                fVar1 = local_28 - local_10;
                if (local_48 <= fVar2) {
                  local_48 = fVar2;
                }
                if (local_40 <= fVar1) {
                  local_40 = fVar1;
                }
                if (fVar2 <= local_3c) {
                  local_3c = fVar2;
                }
                if (fVar1 <= local_34) {
                  local_34 = fVar1;
                }
                fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
                if (local_64 < fVar1) {
                  local_64 = fVar1;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < (int)(uint)*pbVar8);
            }
            local_54 = local_54 / (float)*pbVar8;
            local_4c = local_4c / (float)*pbVar8;
            local_50 = local_14;
            fVar9 = (float10)FUN_005c0240(local_64);
            local_5c = (float)fVar9;
          }
          else {
            local_60 = 1e+09;
            if (*pbVar8 != 0) {
              do {
                iVar3 = *(int *)(*(int *)(*(int *)(pbVar8 + -0x5b) + iVar5 * 4) + 0x24);
                local_30 = *(float *)(iVar3 + 0x70);
                local_28 = *(float *)(iVar3 + 0x78);
                fVar4 = (local_30 - fVar1) * (local_30 - fVar1) +
                        (local_28 - fVar2) * (local_28 - fVar2);
                if (fVar4 < local_60) {
                  iVar7 = iVar5;
                  local_60 = fVar4;
                  local_54 = local_30;
                  local_50 = *(float *)(iVar3 + 0x74);
                  local_4c = local_28;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < (int)(uint)*pbVar8);
            }
            iVar5 = *(int *)(*(int *)(pbVar8 + -0x5b) + iVar7 * 4) + 4;
            FUN_005d0130(iVar5,&local_3c,&local_48);
            FUN_005d0260(iVar5,local_c,&local_5c);
          }
          local_48 = local_54 + local_48;
          local_44 = local_50 + 0.01;
          local_40 = local_4c + local_40;
          local_3c = local_3c + local_54;
          local_38 = local_50;
          local_34 = local_4c + local_34;
          FUN_0055e660(&local_54,local_5c,&local_3c,&local_48,param_1,0,0x3f800000,0);
          puVar6 = PTR_DAT_00802c54;
          fVar2 = local_1c;
          fVar1 = local_24;
        }
        local_58 = local_58 + 1;
        pbVar8 = pbVar8 + 0x7c;
      } while (local_58 < (int)(uint)*(ushort *)(*(int *)(puVar6 + 0x46a8) + 4));
    }
  }
  return;
}

