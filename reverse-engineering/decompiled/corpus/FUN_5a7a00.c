/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a7a00; label: FUN_005a7a00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a7a00(int param_1,undefined4 param_2)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  float10 fVar12;
  int local_a4;
  float local_9c;
  int local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  *(undefined4 *)(param_1 + 0x46c8) = 0;
  DAT_0095de94 = 0;
  _DAT_0095de98 = 0;
  iVar10 = *(int *)(param_1 + 0x46bc);
  *(undefined4 *)(param_1 + 0x46c4) = *(undefined4 *)(param_1 + 0x104);
  *(uint *)(param_1 + 0x104) =
       *(int *)(param_1 + 0x104) + 3 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x100) * 0xc &
       0xfffffffc;
  FUN_005a4540(param_1,param_2);
  local_a4 = 0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    do {
      *(uint *)(iVar10 + 200) = *(uint *)(iVar10 + 200) & 0xffff8fff;
      piVar1 = (int *)(iVar10 + 0x24);
      iVar5 = FUN_005d0420(piVar1);
      if (iVar5 != 0) {
        FUN_005ca4b0(*(undefined4 *)(*(int *)(*piVar1 + 0x54) + (uint)*(ushort *)(iVar5 + 0x5c) * 4)
                    );
        iVar5 = FUN_006e6b90();
        *(uint *)(iVar10 + 200) =
             *(uint *)(iVar10 + 200) ^ (iVar5 << 0xc ^ *(uint *)(iVar10 + 200)) & 0x7000;
        uVar6 = *(uint *)(iVar10 + 200) >> 0xc;
        *(byte *)(iVar10 + 0xd2) = (byte)uVar6 & 7;
        uVar6 = uVar6 & 7;
        iVar5 = *(int *)(param_1 + 0x46c8) + uVar6;
        if ((int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x100) < iVar5) {
          if (DAT_0095de94 == 0) {
            DAT_0095de94 = 1;
            _DAT_0095de98 =
                 _DAT_0095de98 + (iVar5 - (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x100));
          }
          else {
            _DAT_0095de98 = _DAT_0095de98 + uVar6;
          }
        }
        uVar6 = *(uint *)(iVar10 + 200) >> 0xc & 7;
        if ((uVar6 != 0) && (DAT_0095de94 == 0)) {
          local_9c = 1.0;
          *(int *)(iVar10 + 0x54) = *(int *)(param_1 + 0x46c4) + *(int *)(param_1 + 0x46c8) * 0xc;
          local_98 = 0;
          if (uVar6 != 0) {
            iVar5 = 0;
            do {
              FUN_005526c0(piVar1,local_9c,local_40,0);
              pfVar7 = (float *)(*(int *)(iVar10 + 0x54) + iVar5);
              *pfVar7 = local_10;
              pfVar7[1] = local_c;
              pfVar7[2] = local_8;
              puVar8 = (undefined4 *)FUN_005cfa20(piVar1);
              puVar11 = local_40;
              for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
                *puVar11 = *puVar8;
                puVar8 = puVar8 + 1;
                puVar11 = puVar11 + 1;
              }
              pfVar7 = (float *)(*(int *)(iVar10 + 0x54) + iVar5);
              *pfVar7 = *pfVar7 + local_10;
              *(float *)(*(int *)(iVar10 + 0x54) + 4 + iVar5) =
                   *(float *)(*(int *)(iVar10 + 0x54) + 4 + iVar5) + local_c;
              pfVar7 = (float *)(*(int *)(iVar10 + 0x54) + 8 + iVar5);
              pfVar2 = (float *)(*(int *)(iVar10 + 0x54) + 8 + iVar5);
              iVar5 = iVar5 + 0xc;
              *pfVar2 = *pfVar7 + local_8;
              *(int *)(param_1 + 0x46c8) = *(int *)(param_1 + 0x46c8) + 1;
              local_9c = local_9c + 1.0;
              local_98 = local_98 + 1;
            } while (local_98 < (int)(*(uint *)(iVar10 + 200) >> 0xc & 7));
          }
        }
      }
      FUN_005a4450(param_1,iVar10,local_a4);
      local_a4 = local_a4 + 1;
      iVar10 = iVar10 + 0xd4;
    } while (local_a4 < *(int *)(param_1 + 0x46c0));
  }
  if (0 < *(int *)(param_1 + 0x46c0)) {
    puVar8 = (undefined4 *)(*(int *)(param_1 + 0x46bc) + 0x8c);
    iVar10 = 0;
    do {
      pfVar7 = (float *)puVar8[-0xd];
      local_94 = *pfVar7;
      local_90 = pfVar7[1];
      local_8c = pfVar7[2];
      *puVar8 = DAT_0093b0cc;
      puVar8[1] = DAT_0093b0d0;
      puVar8[2] = DAT_0093b0d4;
      puVar8[3] = DAT_0093b0cc;
      puVar8[4] = DAT_0093b0d0;
      puVar8[5] = DAT_0093b0d4;
      puVar8[6] = local_94;
      puVar8[7] = local_90;
      puVar8[8] = local_8c;
      local_88 = _DAT_00805b2c + ABS((float)puVar8[9]);
      local_80 = ABS((float)puVar8[0xc]) + _DAT_00805b2c;
      local_7c = ABS((float)puVar8[0xb]) + _DAT_00805b2c;
      local_48 = ABS((float)puVar8[0xe]);
      local_84 = _DAT_00805b2c + local_48;
      local_44 = ABS((float)puVar8[10]);
      local_50 = (local_90 - local_44) - _DAT_00805b28;
      local_74 = local_50 + 0.025;
      local_68 = local_50 + 0.025;
      local_5c = local_50 + 0.025;
      local_50 = local_50 + 0.025;
      local_78 = local_94 - local_88;
      local_70 = local_8c - local_7c;
      local_6c = local_80 + local_94;
      local_64 = local_8c - local_7c;
      local_60 = local_80 + local_94;
      local_58 = local_84 + local_8c;
      local_54 = local_94 - local_88;
      local_4c = local_84 + local_8c;
      FUN_0067c8e0(puVar8[-0x16],0);
      FUN_0067a6d0();
      fVar12 = (float10)FUN_005506f0(0,&local_78,0x3dcccccd,0xffffffff);
      local_84 = (float)fVar12;
      uVar4 = FUN_0067a600();
      *(undefined1 *)(puVar8 + -0x1f) = uVar4;
      uVar4 = FUN_0067a670();
      *(undefined1 *)(puVar8 + -0x1e) = uVar4;
      FUN_0067a6d0();
      fVar12 = (float10)FUN_005506f0(0,&local_6c,0x3dcccccd,0xffffffff);
      local_80 = (float)fVar12;
      uVar4 = FUN_0067a600();
      *(undefined1 *)((int)puVar8 + -0x7b) = uVar4;
      uVar4 = FUN_0067a670();
      *(undefined1 *)((int)puVar8 + -0x77) = uVar4;
      FUN_0067a6d0();
      fVar12 = (float10)FUN_005506f0(0,&local_60,0x3dcccccd,0xffffffff);
      local_7c = (float)fVar12;
      uVar4 = FUN_0067a600();
      *(undefined1 *)((int)puVar8 + -0x7a) = uVar4;
      uVar4 = FUN_0067a670();
      *(undefined1 *)((int)puVar8 + -0x76) = uVar4;
      FUN_0067a6d0();
      fVar12 = (float10)FUN_005506f0(0,&local_54,0x3dcccccd,0xffffffff);
      local_88 = (float)fVar12;
      uVar4 = FUN_0067a600();
      *(undefined1 *)((int)puVar8 + -0x79) = uVar4;
      uVar4 = FUN_0067a670();
      *(undefined1 *)((int)puVar8 + -0x75) = uVar4;
      FUN_0067c8e0(puVar8[-0x16],1);
      if (((local_80 == local_84) && (local_7c == local_80)) && (local_88 == local_7c)) {
        FUN_0067a6d0();
        fVar12 = (float10)FUN_005506f0(0,&local_94,0x40a00000,0xffffffff);
        local_90 = (float)fVar12;
        fVar3 = local_90;
        if (local_90 == 2e+06) {
          local_90 = 0.0;
          fVar3 = local_90;
        }
      }
      else {
        fVar3 = (local_88 + local_7c + local_80 + local_84) * 0.25;
      }
      puVar8[-0x22] = fVar3;
      puVar8[-0x1d] = puVar8[-0x1e];
      iVar10 = iVar10 + 1;
      puVar8 = puVar8 + 0x35;
    } while (iVar10 < *(int *)(param_1 + 0x46c0));
  }
  iVar10 = 0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    iVar5 = 0;
    do {
      FUN_005a7980(param_1,*(int *)(param_1 + 0x46bc) + iVar5,iVar10);
      iVar10 = iVar10 + 1;
      iVar5 = iVar5 + 0xd4;
    } while (iVar10 < *(int *)(param_1 + 0x46c0));
  }
  return;
}

