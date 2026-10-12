/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x446710; label: FUN_00446710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00446710(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_1c;
  undefined4 local_18;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_1c = 1.0;
  local_c = 1e+09;
  iVar7 = 0;
  local_8 = 1e+09;
  local_4 = 1e+09;
  local_18 = 0;
  local_10 = 0;
  bVar2 = false;
  if (((param_3 == 0) || (piVar4 = *(int **)(param_3 + 0xd0), piVar4 == (int *)0x0)) ||
     (*piVar4 == 0)) {
    return true;
  }
  iVar1 = *piVar4;
  if (param_6 == 0) {
    return *(char *)(iVar1 + 0x7b5) != '\x1f';
  }
  iVar8 = 0;
  uVar5 = 0;
  uVar6 = 0;
  if (0 < param_5) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"tgt_character=");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_0075786c);
        if (iVar3 == 0) {
          local_18 = 1;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"to_origin");
          if (iVar3 == 0) {
            bVar2 = true;
          }
          else {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"jump_factor=");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_0075785c);
              if (iVar3 == 0) {
                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_00757858);
                if (iVar3 == 0) {
                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_00757854);
                  if (iVar3 == 0) {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"check_terrain");
                    if (iVar3 == 0) {
                      local_10 = 1;
                    }
                  }
                  else {
                    fVar9 = (float10)FUN_005147c0(param_2,iVar3 + 2);
                    local_4 = (float)fVar9;
                  }
                }
                else {
                  fVar9 = (float10)FUN_005147c0(param_2,iVar3 + 2);
                  local_8 = (float)fVar9;
                }
              }
              else {
                fVar9 = (float10)FUN_005147c0(param_2,iVar3 + 2);
                local_c = (float)fVar9;
              }
            }
            else {
              fVar9 = (float10)FUN_005147c0(param_2,iVar3 + 0xc);
              local_1c = (float)fVar9;
              if (local_1c < 0.0) {
                local_1c = 0.0;
              }
            }
          }
        }
      }
      else if ((DAT_00923904 == (code *)0x0) ||
              (piVar4 = (int *)(*DAT_00923904)(param_1,iVar3 + 0xe), piVar4 == (int *)0x0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = *piVar4;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_5);
    if (((bVar2) && ((*(uint *)(iVar1 + 0x1f8) & 0x400) != 0)) && (*(byte *)(iVar1 + 0x400) != 0xff)
       ) {
      iVar7 = (uint)*(byte *)(iVar1 + 0x400) * 0xa4 + *(int *)(param_1 + 0x18);
      FUN_00561e20(iVar1,(undefined4 *)(iVar7 + 0x20),local_18,local_1c,0x3f800000,0);
      *(undefined4 *)(iVar1 + 0x420) = *(undefined4 *)(iVar7 + 0x30);
      *(undefined4 *)(iVar1 + 0x424) = *(undefined4 *)(iVar7 + 0x34);
      *(undefined4 *)(iVar1 + 0x428) = *(undefined4 *)(iVar7 + 0x38);
      *(undefined4 *)(iVar1 + 0x42c) = *(undefined4 *)(iVar7 + 0x3c);
      *(undefined4 *)(iVar1 + 0x430) = *(undefined4 *)(iVar7 + 0x40);
      *(undefined4 *)(iVar1 + 0x434) = *(undefined4 *)(iVar7 + 0x44);
      *(undefined4 *)(iVar1 + 0x438) = *(undefined4 *)(iVar7 + 0x20);
      *(undefined4 *)(iVar1 + 0x43c) = *(undefined4 *)(iVar7 + 0x24);
      *(undefined4 *)(iVar1 + 0x440) = *(undefined4 *)(iVar7 + 0x28);
      return *(char *)(iVar1 + 0x7b5) != '\x1f';
    }
    uVar5 = local_10;
    uVar6 = local_18;
    if (iVar7 != 0) {
      FUN_00561e20(iVar1,iVar7 + 0x1b4,local_18,local_1c,0x3f800000,0);
      *(undefined4 *)(iVar1 + 0x420) = *(undefined4 *)(iVar7 + 0x420);
      *(undefined4 *)(iVar1 + 0x424) = *(undefined4 *)(iVar7 + 0x424);
      *(undefined4 *)(iVar1 + 0x428) = *(undefined4 *)(iVar7 + 0x428);
      *(undefined4 *)(iVar1 + 0x42c) = *(undefined4 *)(iVar7 + 0x42c);
      *(undefined4 *)(iVar1 + 0x430) = *(undefined4 *)(iVar7 + 0x430);
      *(undefined4 *)(iVar1 + 0x434) = *(undefined4 *)(iVar7 + 0x434);
      *(undefined4 *)(iVar1 + 0x438) = *(undefined4 *)(iVar7 + 0x438);
      *(undefined4 *)(iVar1 + 0x43c) = *(undefined4 *)(iVar7 + 0x43c);
      *(undefined4 *)(iVar1 + 0x440) = *(undefined4 *)(iVar7 + 0x440);
      return *(char *)(iVar1 + 0x7b5) != '\x1f';
    }
  }
  if (((local_c != 1e+09) && (local_8 != 1e+09)) && (local_4 != 1e+09)) {
    FUN_00561e20(iVar1,&local_c,uVar6,local_1c,0x3f800000,uVar5);
    return *(char *)(iVar1 + 0x7b5) != '\x1f';
  }
  FUN_00561e20(iVar1,iVar1 + 0x80,uVar6,local_1c,0x3f800000,uVar5);
  return *(char *)(iVar1 + 0x7b5) != '\x1f';
}

