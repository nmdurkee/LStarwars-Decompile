/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x447230; label: FUN_00447230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00447230(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  float local_68;
  float local_64;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined1 local_38;
  char local_37;
  undefined1 local_30 [28];
  undefined2 local_14;
  undefined2 local_12;
  
  local_50 = 0.0;
  local_4c = 0.0;
  local_48 = 0;
  local_64 = 0.0;
  iVar12 = 0;
  bVar7 = false;
  bVar6 = false;
  local_68 = 0.0;
  if (param_6 == 0) {
    return 1;
  }
  if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
     (*piVar3 != 0)) {
    iVar12 = *piVar3;
  }
  if (0 < param_5) {
    iVar13 = 0;
    iVar11 = iVar12;
    do {
      iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"player1");
      iVar12 = DAT_0093d810;
      if (((iVar8 == 0) &&
          (iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"player"),
          iVar12 = DAT_0093d810, iVar8 == 0)) &&
         (iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"player2"),
         iVar12 = DAT_0093d814, iVar8 == 0)) {
        iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"party");
        iVar12 = iVar11;
        if (iVar8 == 0) {
          iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),&DAT_007578a8);
          if (iVar11 == 0) {
            iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"distance_from_end");
            if (iVar11 == 0) {
              iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),"distance");
              if (iVar11 == 0) {
                iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),&DAT_007578c0);
                if (iVar11 == 0) {
                  iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),&DAT_007578bc);
                  if (iVar11 == 0) {
                    iVar11 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar13 * 4),&DAT_007578b8);
                    if (iVar11 != 0) {
                      FUN_005147c0(param_2,iVar11 + 3);
                    }
                  }
                  else {
                    FUN_005147c0(param_2,iVar11 + 3);
                  }
                }
                else {
                  FUN_005147c0(param_2,iVar11 + 5);
                  local_68 = (float)FUN_006e6b90();
                }
              }
              else {
                fVar14 = (float10)FUN_005147c0(param_2,iVar11 + 9);
                local_64 = (float)fVar14;
              }
            }
            else {
              fVar14 = (float10)FUN_005147c0(param_2,iVar11 + 0x12);
              local_64 = (float)fVar14;
              bVar6 = true;
            }
          }
          else {
            FUN_005147c0(param_2,iVar11 + 5);
          }
        }
        else {
          bVar7 = true;
        }
      }
      iVar13 = iVar13 + 1;
      iVar11 = iVar12;
    } while (iVar13 < param_5);
    if (bVar6) {
      local_37 = -1;
      if (*(int *)(PTR_DAT_00802c54 + 0x2988) == 0) {
        return 1;
      }
      if (0x3f < (uint)local_68) {
        return 1;
      }
      FUN_0053f640(*(int **)(PTR_DAT_00802c54 + 0x2988),&local_38,local_68,
                   *(ushort *)((int)local_68 * 0x13c + 0x30 + **(int **)(PTR_DAT_00802c54 + 0x2988))
                   - 1,0x3f800000);
      if (local_37 == -1) {
        return 1;
      }
      goto LAB_004474c8;
    }
  }
  FUN_0053f640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),&local_38,local_68,0,0);
  if (local_37 == -1) {
    return 1;
  }
LAB_004474c8:
  FUN_0053f0e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),&local_38,local_64,&local_38);
  fVar14 = (float10)FUN_005b9dd0();
  fVar15 = (float10)FUN_005b9dd0();
  fVar1 = (float)(fVar15 * (float10)0.0 + (float10)(double)(((float10)1 - fVar14) * (float10)0.0));
  fVar14 = (float10)FUN_005b9dd0();
  fVar15 = (float10)FUN_005b9dd0();
  fVar2 = (float)(fVar15 * (float10)0.0 + (float10)(double)(((float10)1 - fVar14) * (float10)0.0));
  uVar9 = FUN_005b9e90(0);
  uVar9 = uVar9 & 0x8000ffff;
  if ((int)uVar9 < 0) {
    uVar9 = (uVar9 - 1 | 0xffff0000) + 1;
  }
  iVar13 = 0;
  iVar11 = 0;
  while( true ) {
    if (bVar7) {
      iVar12 = (&DAT_0093d7f0)[iVar13];
    }
    if (((iVar12 != 0) && ((*(uint *)(iVar12 + 0x1fc) & 1) != 0)) &&
       ((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0)) {
      local_68 = fVar2;
      local_64 = fVar1;
      if (1 < iVar13) {
        local_44 = 1.0;
        local_40 = 0.0;
        local_3c = 0;
        uVar10 = FUN_005be590(uVar9,iVar11 / 3);
        FUN_005b3690(&local_44,&local_44,uVar10);
        local_64 = local_44 + fVar1;
        local_68 = local_40 + fVar2;
      }
      if ((local_64 == 0.0) && (local_68 == 0.0)) {
        local_48 = 0;
        local_4c = 0.0;
        local_50 = 0.0;
      }
      else {
        local_50 = local_64;
        local_4c = local_68;
        local_48 = 0;
        FUN_005b35a0(&local_50,&local_50,local_14);
        uVar10 = FUN_005be590(local_12,0x8000);
        FUN_005b3620(&local_50,&local_50,uVar10);
      }
      FUN_005b37d0(&local_50,&local_50,local_30);
      *(float *)(iVar12 + 0x5c) = local_50;
      *(float *)(iVar12 + 0x60) = local_4c;
      *(undefined4 *)(iVar12 + 100) = local_48;
      *(undefined4 *)(iVar12 + 0x80) = *(undefined4 *)(iVar12 + 0x5c);
      *(undefined4 *)(iVar12 + 0x84) = *(undefined4 *)(iVar12 + 0x60);
      *(undefined4 *)(iVar12 + 0x88) = local_48;
      *(undefined4 *)(iVar12 + 0x98) = *(undefined4 *)(iVar12 + 0x5c);
      _DAT_0093d620 = *(undefined4 *)(iVar12 + 0x80);
      *(undefined4 *)(iVar12 + 0x9c) = *(undefined4 *)(iVar12 + 0x60);
      *(undefined4 *)(iVar12 + 0xa0) = local_48;
      *(undefined2 *)(iVar12 + 0x27a) = local_12;
      *(undefined2 *)(iVar12 + 0x58) = local_12;
      *(undefined2 *)(iVar12 + 0x5a) = local_12;
      DAT_0093d624 = *(undefined4 *)(iVar12 + 0x84);
      DAT_0093d628 = *(undefined4 *)(iVar12 + 0x88);
      *(undefined4 *)(iVar12 + 0x8c) = *(undefined4 *)(iVar12 + 0x80);
      uVar10 = *(undefined4 *)(iVar12 + 0x5c);
      *(undefined4 *)(iVar12 + 0x90) = *(undefined4 *)(iVar12 + 0x84);
      uVar4 = *(undefined4 *)(iVar12 + 0x60);
      *(undefined4 *)(iVar12 + 0x94) = *(undefined4 *)(iVar12 + 0x88);
      uVar5 = *(undefined4 *)(iVar12 + 100);
      *(undefined4 *)(iVar12 + 0x1cc) = uVar10;
      *(undefined4 *)(iVar12 + 0x1b4) = uVar10;
      *(undefined4 *)(iVar12 + 0x10bc) = uVar10;
      *(undefined4 *)(iVar12 + 0x1d0) = uVar4;
      *(undefined4 *)(iVar12 + 0x1b8) = uVar4;
      *(undefined4 *)(iVar12 + 0x10c0) = uVar4;
      *(undefined4 *)(iVar12 + 0x1d4) = uVar5;
      *(undefined4 *)(iVar12 + 0x1bc) = uVar5;
      *(undefined4 *)(iVar12 + 0x10c4) = uVar5;
      *(undefined4 *)(iVar12 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)(iVar12 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)(iVar12 + 0x70) = DAT_0093b0d4;
      FUN_005728a0(iVar12);
      FUN_00572660(iVar12,0);
    }
    if (!bVar7) break;
    iVar13 = iVar13 + 1;
    iVar11 = iVar11 + 0x10000;
    if (7 < iVar13) {
      return 1;
    }
  }
  return 1;
}

