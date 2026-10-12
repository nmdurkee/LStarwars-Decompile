/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x687850; label: FUN_00687850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00687850(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  short *psVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float10 fVar15;
  undefined4 *local_64;
  int local_60;
  undefined2 *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined1 local_40 [12];
  undefined1 local_34 [12];
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_64;
  iVar12 = 0;
  local_48 = param_2;
  while ((&DAT_02961f80)[iVar12] != 0) {
    iVar12 = iVar12 + 1;
    if (7 < iVar12) {
      local_54 = iVar12;
      __security_check_cookie(local_4 ^ (uint)&local_64);
      return;
    }
  }
  local_54 = iVar12;
  if (iVar12 != -1) {
    FUN_006211c0(1);
    iVar3 = FUN_00621270(param_1,0);
    if (iVar3 != 0) {
      FUN_006211b0(1);
      iVar3 = FUN_006217e0();
      local_58 = iVar3;
      if (6 < iVar3) {
        FUN_006211b0(0);
        FUN_006213e0();
        __security_check_cookie(local_4 ^ (uint)&local_64);
        return;
      }
      local_50 = FUN_006217e0();
      if (0x40 < local_50 + DAT_02962108) {
        local_50 = 0x40 - DAT_02962108;
      }
      iVar13 = 0;
      local_4c = 0;
      if (0 < local_50) {
        local_44 = local_50;
        do {
          piVar14 = &DAT_0292fe18 + iVar13 * 0xb5;
          iVar9 = (&DAT_0292fe18)[iVar13 * 0xb5];
          while (iVar9 != -1) {
            local_4c = iVar13;
            if (0x293b317 < (int)piVar14) goto LAB_00687daf;
            piVar14 = piVar14 + 0xb5;
            iVar13 = iVar13 + 1;
            local_4c = iVar13;
            iVar9 = *piVar14;
          }
          if (iVar13 < 0x40) {
            FUN_006216f0(local_18,0x14);
            iVar12 = iVar13 * 0x2d4;
            uVar4 = FUN_0065b630(local_18,param_2);
            (&DAT_0292fe18)[iVar13 * 0xb5] = uVar4;
            uVar4 = FUN_006217e0();
            (&DAT_0292fe1c)[iVar13 * 0xb5] = uVar4;
            if (iVar3 < 2) {
              (&DAT_0292fe20)[iVar13 * 0xb5] = 0;
            }
            else {
              uVar4 = FUN_006217e0();
              (&DAT_0292fe20)[iVar13 * 0xb5] = uVar4;
            }
            uVar4 = FUN_006217e0();
            (&DAT_0292fe24)[iVar13 * 0xb5] = uVar4;
            uVar4 = FUN_006217e0();
            (&DAT_0292fe28)[iVar13 * 0xb5] = uVar4;
            fVar15 = (float10)FUN_006217a0();
            (&DAT_0292fe2c)[iVar13 * 0xb5] = (float)fVar15;
            fVar15 = (float10)FUN_006217a0();
            (&DAT_0292fe30)[iVar13 * 0xb5] = (float)fVar15;
            iVar9 = 0;
            local_60 = 0;
            if (8 < (int)(&DAT_0292fe1c)[iVar13 * 0xb5]) {
              local_60 = 8 - (&DAT_0292fe1c)[iVar13 * 0xb5];
              (&DAT_0292fe1c)[iVar13 * 0xb5] = 8;
            }
            if (0 < (int)(&DAT_0292fe1c)[iVar13 * 0xb5]) {
              local_5c = &DAT_0292ff84 + iVar13 * 0x16a;
              local_64 = &DAT_0292ff14 + iVar13 * 0xb5;
              piVar14 = &DAT_0292fed4 + iVar13 * 0xb5;
              puVar10 = &DAT_0292fe34 + iVar12;
              do {
                FUN_006216f0(puVar10,0x10);
                piVar14[-8] = -1;
                if (local_58 < 5) {
                  iVar3 = FUN_006217e0();
                  if (0 < iVar3) {
                    iVar3 = iVar3 * 0x3c;
                    goto LAB_00687abb;
                  }
                  if (iVar3 < 0) {
                    iVar3 = (int)(-0x3c / (longlong)iVar3);
                    goto LAB_00687abb;
                  }
                  *piVar14 = 0;
                }
                else {
                  if (local_58 == 5) {
                    FUN_006217a0();
                    iVar3 = FUN_006e6b90();
                  }
                  else {
                    iVar3 = FUN_006217e0();
                  }
LAB_00687abb:
                  *piVar14 = iVar3;
                }
                iVar3 = FUN_006217e0();
                piVar14[8] = iVar3;
                FUN_00621900(local_64);
                if (local_58 < 3) {
                  local_5c[-8] = 0;
                  *local_5c = 0;
                }
                else {
                  uVar2 = FUN_00621860();
                  local_5c[-8] = uVar2;
                  uVar2 = FUN_00621860();
                  *local_5c = uVar2;
                }
                local_5c = local_5c + 1;
                local_64 = local_64 + 3;
                iVar9 = iVar9 + 1;
                piVar14 = piVar14 + 1;
                puVar10 = puVar10 + 0x10;
                iVar3 = local_58;
              } while (iVar9 < (int)(&DAT_0292fe1c)[iVar13 * 0xb5]);
            }
            iVar9 = local_60;
            if (0 < local_60) {
              do {
                FUN_006216f0(local_28,0x10);
                FUN_006217e0();
                FUN_006217e0();
                FUN_00621900(local_40);
                if (2 < iVar3) {
                  FUN_00621860();
                  FUN_00621860();
                }
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
            (&DAT_0292ff94)[iVar13 * 0xb5] = 0x3f7d70a4;
            if (1 < iVar3) {
              local_60 = 0;
              if (8 < (int)(&DAT_0292fe20)[iVar13 * 0xb5]) {
                local_60 = 8 - (&DAT_0292fe20)[iVar13 * 0xb5];
                (&DAT_0292fe20)[iVar13 * 0xb5] = 8;
              }
              local_64 = (undefined4 *)0x0;
              if (0 < (int)(&DAT_0292fe20)[iVar13 * 0xb5]) {
                puVar10 = &DAT_02930078 + iVar12;
                puVar6 = &DAT_02930038 + iVar13 * 0xb5;
                puVar11 = &DAT_0292ff98 + iVar12;
                do {
                  FUN_006216f0(puVar11,0x10);
                  puVar6[-8] = 0xffffffff;
                  uVar4 = FUN_006217e0();
                  *puVar6 = uVar4;
                  fVar15 = (float10)FUN_006217a0();
                  puVar6[8] = (float)fVar15;
                  FUN_00621900(puVar10);
                  local_64 = (undefined4 *)((int)local_64 + 1);
                  puVar6 = puVar6 + 1;
                  puVar11 = puVar11 + 0x10;
                  puVar10 = puVar10 + 0xc;
                  iVar3 = local_58;
                } while ((int)local_64 < (int)(&DAT_0292fe20)[iVar13 * 0xb5]);
              }
              iVar9 = local_60;
              if (0 < local_60) {
                do {
                  FUN_006216f0(local_28,0x10);
                  FUN_006217e0();
                  FUN_006217a0();
                  FUN_00621900(local_40);
                  iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
              }
            }
            FUN_005da860(local_34,local_48,(&DAT_0292fe18)[iVar13 * 0xb5]);
            iVar5 = FUN_005cffb0(local_34);
            iVar9 = DAT_0292fc68;
            if (iVar5 == -1) {
              puVar6 = (undefined4 *)0xffffffff;
              puVar1 = local_64;
            }
            else {
              puVar8 = (undefined4 *)0x0;
              local_64 = (undefined4 *)0xffffffff;
              puVar6 = local_64;
              puVar1 = local_64;
              if (0 < *(int *)(DAT_0292fc68 + 0xa48c)) {
                psVar7 = (short *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4a);
                do {
                  if ((*(int *)(psVar7 + -5) != 0) &&
                     (puVar6 = puVar8, iVar3 = local_58, puVar1 = puVar8, *psVar7 == iVar5)) break;
                  puVar8 = (undefined4 *)((int)puVar8 + 1);
                  psVar7 = psVar7 + 0x36;
                  puVar6 = local_64;
                  puVar1 = local_64;
                } while ((int)puVar8 < *(int *)(DAT_0292fc68 + 0xa48c));
              }
            }
            local_64 = puVar1;
            (&DAT_029300d8)[iVar13 * 0xb5] = puVar6;
            if (iVar3 < 4) {
              (&DAT_029300dc)[iVar13 * 0xb5] = 0;
              (&DAT_029300e0)[iVar13 * 0xb5] = 0;
              (&DAT_029300e4)[iVar13 * 0xb5] = 0;
            }
            else {
              fVar15 = (float10)FUN_006217a0();
              (&DAT_029300dc)[iVar13 * 0xb5] = (float)fVar15;
              fVar15 = (float10)FUN_006217a0();
              (&DAT_029300e0)[iVar13 * 0xb5] = (float)fVar15;
              fVar15 = (float10)FUN_006217a0();
              (&DAT_029300e4)[iVar13 * 0xb5] = (float)fVar15;
              iVar9 = DAT_0292fc68;
            }
            iVar5 = (&DAT_029300d8)[iVar13 * 0xb5];
            if (iVar5 != -1) {
              local_64 = (undefined4 *)(&DAT_029300dc)[iVar13 * 0xb5];
              local_60 = (&DAT_029300e0)[iVar13 * 0xb5];
              local_5c = (undefined2 *)(&DAT_029300e4)[iVar13 * 0xb5];
              if ((-1 < iVar5) && (iVar5 < *(int *)(iVar9 + 0xa48c))) {
                iVar5 = iVar5 * 0x6c;
                if (*(float *)(*(int *)(iVar9 + 0x68) + 0x54 + iVar5) == 0.0) {
                  *(undefined4 *)(*(int *)(iVar9 + 0x68) + iVar5 + 0x58) = 0;
                  *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x5c + iVar5) = 0;
                  iVar9 = DAT_0292fc68;
                }
                *(undefined4 **)(*(int *)(iVar9 + 0x68) + 0x54 + iVar5) = local_64;
                *(int *)(*(int *)(DAT_0292fc68 + 0x68) + 0x60 + iVar5) = local_60;
                *(undefined2 **)(*(int *)(DAT_0292fc68 + 0x68) + 100 + iVar5) = local_5c;
              }
            }
            DAT_02962108 = DAT_02962108 + 1;
            (&DAT_029300e8)[iVar12] = (undefined1)local_54;
            param_2 = local_48;
            iVar12 = local_54;
            iVar13 = local_4c;
          }
LAB_00687daf:
          local_44 = local_44 + -1;
        } while (local_44 != 0);
      }
      FUN_006211b0(0);
      FUN_006213e0();
      (&DAT_02961f80)[iVar12] = 1;
      (&DAT_02947c7c)[iVar12] = param_2;
      DAT_02947c10 = local_50;
      DAT_02961f7c = 0;
      DAT_02923194 = 0xffffffff;
      DAT_02962010 = 0xffffffff;
      DAT_02962924 = iVar12;
      FUN_00659350(0x3f800000);
      __security_check_cookie(local_4 ^ (uint)&local_64);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_64);
  return;
}

