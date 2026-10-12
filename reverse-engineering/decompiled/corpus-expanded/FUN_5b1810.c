/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1810; label: FUN_005b1810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1810(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  float *pfVar13;
  int iVar14;
  float10 fVar15;
  int local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_50;
  iVar11 = 0;
  if (param_2 != 0) {
    FUN_006211c0(1);
    iVar7 = FUN_00621270(param_1,0);
    if (iVar7 != 0) {
      local_48 = FUN_006217e0();
      if (local_48 < 3) {
        local_4c = FUN_006217e0();
        if (0xc0 < local_4c) {
          local_4c = 0xc0;
        }
        iVar7 = local_4c;
        FUN_006217e0();
        *(undefined4 *)(param_2 + 0x46cc) = 0;
        local_50 = iVar7;
        if (0 < iVar7) {
          do {
            local_50 = iVar7;
            pbVar12 = (byte *)(*(int *)(param_2 + 0x46d0) + iVar11);
            sVar5 = FUN_00621860();
            FUN_006216f0(local_44,(int)sVar5);
            uVar1 = *(undefined4 *)(param_2 + 0x13c);
            local_44[sVar5] = 0;
            FUN_005cf5b0(uVar1,pbVar12 + 4,local_44,1);
            bVar2 = FUN_006218c0();
            pbVar12[2] = bVar2;
            if (1 < local_48) {
              bVar2 = FUN_006218c0();
              *pbVar12 = *pbVar12 ^ (*pbVar12 ^ bVar2) & 0xf;
            }
            *(int *)(param_2 + 0x46cc) = *(int *)(param_2 + 0x46cc) + 1;
            iVar11 = iVar11 + 0x14;
            iVar7 = local_50 + -1;
            local_50 = local_4c;
          } while (iVar7 != 0);
        }
        pfVar13 = *(float **)(param_2 + 0x46d8);
        if (0 < local_50) {
          local_4c = 0;
          do {
            local_48 = *(int *)(param_2 + 0x46d0) + local_4c;
            iVar11 = 0;
            if ('\0' < *(char *)(local_48 + 2)) {
              do {
                sVar5 = FUN_00621860();
                FUN_006216f0(local_44,(int)sVar5);
                local_44[sVar5] = 0;
                uVar6 = FUN_00650dc0(local_44);
                *(undefined2 *)((int)pfVar13 + 6) = uVar6;
                uVar3 = FUN_006218c0();
                *(undefined1 *)(pfVar13 + 1) = uVar3;
                cVar4 = FUN_00650ef0((int)*(short *)((int)pfVar13 + 6));
                *(byte *)(pfVar13 + 1) =
                     *(byte *)(pfVar13 + 1) ^ (cVar4 * '\x02' ^ *(byte *)(pfVar13 + 1)) & 2;
                fVar15 = (float10)FUN_006217a0();
                pfVar13[2] = (float)fVar15;
                fVar15 = (float10)FUN_006217a0();
                *pfVar13 = (float)fVar15;
                *(int *)(param_2 + 0x46d4) = *(int *)(param_2 + 0x46d4) + 1;
                iVar11 = iVar11 + 1;
                pfVar13 = pfVar13 + 4;
              } while (iVar11 < *(char *)(local_48 + 2));
            }
            local_4c = local_4c + 0x14;
            local_50 = local_50 + -1;
          } while (local_50 != 0);
        }
        local_50 = 0;
        if (0 < *(int *)(param_2 + 0x46cc)) {
          iVar7 = 0;
          iVar11 = *(int *)(param_2 + 0x46d8);
          do {
            iVar14 = 0;
            iVar9 = *(int *)(param_2 + 0x46d0) + iVar7;
            *(int *)(iVar9 + 0x10) = iVar11;
            if (iVar11 == *(int *)(param_2 + 0x46d4) * 0x10 + *(int *)(param_2 + 0x46d8)) {
              iVar8 = 0;
            }
            else {
              iVar8 = iVar11 + 0x10;
            }
            iVar10 = iVar11;
            if (*(char *)(iVar9 + 2) != 1 && -1 < *(char *)(iVar9 + 2) + -1) {
              do {
                iVar11 = iVar8;
                *(int *)(iVar10 + 0xc) = iVar11;
                iVar14 = iVar14 + 1;
                iVar8 = iVar11 + 0x10;
                iVar10 = iVar11;
              } while (iVar14 < *(char *)(iVar9 + 2) + -1);
            }
            if (iVar11 != 0) {
              *(undefined4 *)(iVar11 + 0xc) = 0;
            }
            local_50 = local_50 + 1;
            iVar7 = iVar7 + 0x14;
            iVar11 = iVar8;
          } while (local_50 < *(int *)(param_2 + 0x46cc));
        }
        FUN_006213e0();
        __security_check_cookie(local_4 ^ (uint)&local_50);
        return;
      }
      FUN_006213e0();
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_50);
  return;
}

