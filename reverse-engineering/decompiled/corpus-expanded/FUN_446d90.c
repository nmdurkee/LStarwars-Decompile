/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x446d90; label: FUN_00446d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00446d90(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  undefined2 local_14;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 0.0;
  iVar10 = 0;
  local_8 = 0.0;
  local_4 = 0.0;
  iVar8 = 0;
  bVar5 = true;
  local_14 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
       (*piVar1 != 0)) {
      iVar8 = *piVar1;
    }
    iVar9 = iVar8;
    uVar6 = 0;
    if (0 < param_5) {
      do {
        local_14 = uVar6;
        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"player1");
        iVar9 = DAT_0093d810;
        if (((iVar7 == 0) &&
            (iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"player"),
            iVar9 = DAT_0093d810, iVar7 == 0)) &&
           (iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"player2"),
           iVar9 = DAT_0093d814, iVar7 == 0)) {
          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),&DAT_007578a8);
          iVar9 = iVar8;
          if (iVar7 == 0) {
            iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),&DAT_00757898);
            if (iVar8 == 0) {
              iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),&DAT_00757894);
              if (iVar8 == 0) {
                iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),&DAT_00757890);
                if (iVar8 == 0) {
                  iVar8 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"dont_check_terrain");
                  if (iVar8 != 0) {
                    bVar5 = false;
                  }
                }
                else {
                  fVar11 = (float10)FUN_005147c0(param_2,iVar8 + 2);
                  local_4 = (float)fVar11;
                }
              }
              else {
                fVar11 = (float10)FUN_005147c0(param_2,iVar8 + 2);
                local_8 = (float)fVar11;
              }
            }
            else {
              fVar11 = (float10)FUN_005147c0(param_2,iVar8 + 2);
              local_c = (float)fVar11;
            }
          }
          else {
            FUN_005147c0(param_2,iVar7 + 5);
            FUN_006e6b90();
            local_14 = FUN_006e6b90();
          }
        }
        iVar10 = iVar10 + 1;
        iVar8 = iVar9;
        uVar6 = local_14;
      } while (iVar10 < param_5);
    }
    if (iVar9 != 0) {
      *(float *)(iVar9 + 0x5c) = local_c;
      *(float *)(iVar9 + 0x60) = local_8;
      *(float *)(iVar9 + 0x98) = local_c;
      *(float *)(iVar9 + 0x80) = local_c;
      *(float *)(iVar9 + 100) = local_4;
      *(float *)(iVar9 + 0x9c) = local_8;
      *(float *)(iVar9 + 0x84) = local_8;
      *(float *)(iVar9 + 0xa0) = local_4;
      *(float *)(iVar9 + 0x88) = local_4;
      *(undefined2 *)(iVar9 + 0x27a) = local_14;
      *(undefined2 *)(iVar9 + 0x58) = local_14;
      *(undefined2 *)(iVar9 + 0x5a) = local_14;
      _DAT_0093d620 = local_c;
      DAT_0093d624 = local_8;
      DAT_0093d628 = local_4;
      *(float *)(iVar9 + 0x8c) = local_c;
      uVar2 = *(undefined4 *)(iVar9 + 0x60);
      *(float *)(iVar9 + 0x90) = local_8;
      uVar3 = *(undefined4 *)(iVar9 + 100);
      *(float *)(iVar9 + 0x94) = local_4;
      uVar4 = *(undefined4 *)(iVar9 + 0x5c);
      *(undefined4 *)(iVar9 + 0x1cc) = uVar4;
      *(undefined4 *)(iVar9 + 0x1b4) = uVar4;
      *(undefined4 *)(iVar9 + 0x10bc) = uVar4;
      *(undefined4 *)(iVar9 + 0x1d0) = uVar2;
      *(undefined4 *)(iVar9 + 0x1b8) = uVar2;
      *(undefined4 *)(iVar9 + 0x10c0) = uVar2;
      *(undefined4 *)(iVar9 + 0x1d4) = uVar3;
      *(undefined4 *)(iVar9 + 0x1bc) = uVar3;
      *(undefined4 *)(iVar9 + 0x10c4) = uVar3;
      *(undefined4 *)(iVar9 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)(iVar9 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)(iVar9 + 0x70) = DAT_0093b0d4;
      FUN_005728a0(iVar9);
      if (bVar5) {
        FUN_00572660(iVar9,0);
      }
    }
  }
  return 1;
}

