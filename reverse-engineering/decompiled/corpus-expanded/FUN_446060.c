/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x446060; label: FUN_00446060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00446060(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_60;
  char *local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_60;
  iVar6 = 0;
  local_4c = param_1;
  local_48 = param_3;
  local_58 = 0;
  local_50 = 0;
  local_60 = 0;
  local_54 = 1;
  local_5c = (char *)0x0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
       (*piVar1 != 0)) {
      iVar6 = *piVar1;
    }
    iVar7 = 0;
    if (0 < param_5) {
      do {
        iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),&DAT_0075782c);
        if (iVar5 == 0) {
          iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"personal");
          if (iVar5 == 0) {
            iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"indexed");
            if (iVar5 == 0) {
              iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"random");
              if (iVar5 == 0) {
                iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"character");
                if (iVar5 == 0) {
                  iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"player=");
                  if (iVar5 == 0) {
                    iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"dont_check_terrain");
                    if (iVar5 != 0) {
                      local_54 = 0;
                    }
                  }
                  else {
                    FUN_005147c0(param_2,iVar5 + 7);
                    iVar5 = FUN_006e6b90();
                    if (iVar5 - 1U < 2) {
                      iVar6 = (&DAT_0093d7f0)[iVar5 - 1U];
                    }
                  }
                }
                else {
                  iVar6 = FUN_00440120(local_4c,iVar5 + 10);
                }
              }
              else {
                FUN_005147c0(param_2,iVar5 + 9);
                local_60 = FUN_006e6b90();
              }
            }
            else {
              local_50 = 1;
            }
          }
          else {
            local_58 = 1;
          }
        }
        else {
          local_5c = (char *)(iVar5 + 5);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_5);
    }
    if ((iVar6 != 0) ||
       (((local_48 != 0 && (piVar1 = *(int **)(local_48 + 0xd0), piVar1 != (int *)0x0)) &&
        ((*piVar1 != 0 && (iVar6 = *piVar1, iVar6 != 0)))))) {
      iVar7 = *(int *)(iVar6 + 0x36c);
      if (local_5c != (char *)0x0) {
        if ((local_50 == 0) || (*(char *)(iVar6 + 0x280) == -1)) {
          if ((local_58 == 0) || (*(int *)(iVar6 + 0x54) == 0)) {
            if (local_60 == 0) {
              _sprintf(local_44,local_5c);
            }
            else {
              iVar7 = FUN_005b9e90(0);
              _sprintf(local_44,"%s_%d",local_5c,iVar7 % local_60);
            }
          }
          else {
            _sprintf(local_44,"%s_%s",local_5c,*(undefined4 *)(*(int *)(iVar6 + 0x54) + 0xc));
          }
        }
        else {
          _sprintf(local_44,"%s_%d",local_5c,(int)*(char *)(iVar6 + 0x280));
        }
        iVar7 = FUN_0051ac10(local_4c,local_44);
      }
      if (iVar7 != 0) {
        *(undefined4 *)(iVar6 + 0x5c) = *(undefined4 *)(iVar7 + 0x10);
        *(undefined4 *)(iVar6 + 0x60) = *(undefined4 *)(iVar7 + 0x14);
        *(undefined4 *)(iVar6 + 100) = *(undefined4 *)(iVar7 + 0x18);
        *(undefined2 *)(iVar6 + 0x27a) = *(undefined2 *)(iVar7 + 0x1c);
        *(undefined2 *)(iVar6 + 0x58) = *(undefined2 *)(iVar7 + 0x1c);
        *(undefined2 *)(iVar6 + 0x5a) = *(undefined2 *)(iVar7 + 0x1c);
        *(undefined4 *)(iVar6 + 0x420) = *(undefined4 *)(iVar7 + 0x20);
        *(undefined4 *)(iVar6 + 0x424) = *(undefined4 *)(iVar7 + 0x24);
        *(undefined4 *)(iVar6 + 0x428) = *(undefined4 *)(iVar7 + 0x28);
        *(undefined4 *)(iVar6 + 0x42c) = *(undefined4 *)(iVar7 + 0x2c);
        *(undefined4 *)(iVar6 + 0x430) = *(undefined4 *)(iVar7 + 0x30);
        uVar2 = *(undefined4 *)(iVar7 + 0x34);
        *(undefined4 *)(iVar6 + 0x80) = *(undefined4 *)(iVar6 + 0x5c);
        *(undefined4 *)(iVar6 + 0x84) = *(undefined4 *)(iVar6 + 0x60);
        *(undefined4 *)(iVar6 + 0x434) = uVar2;
        *(undefined4 *)(iVar6 + 0x88) = *(undefined4 *)(iVar6 + 100);
        *(undefined4 *)(iVar6 + 0x98) = *(undefined4 *)(iVar6 + 0x5c);
        _DAT_0093d620 = *(undefined4 *)(iVar6 + 0x80);
        *(undefined4 *)(iVar6 + 0x9c) = *(undefined4 *)(iVar6 + 0x60);
        *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(iVar6 + 100);
        DAT_0093d624 = *(undefined4 *)(iVar6 + 0x84);
        DAT_0093d628 = *(undefined4 *)(iVar6 + 0x88);
        *(undefined4 *)(iVar6 + 0x8c) = *(undefined4 *)(iVar6 + 0x80);
        uVar2 = *(undefined4 *)(iVar6 + 0x5c);
        *(undefined4 *)(iVar6 + 0x90) = *(undefined4 *)(iVar6 + 0x84);
        uVar3 = *(undefined4 *)(iVar6 + 0x60);
        *(undefined4 *)(iVar6 + 0x94) = *(undefined4 *)(iVar6 + 0x88);
        uVar4 = *(undefined4 *)(iVar6 + 100);
        *(undefined4 *)(iVar6 + 0x1cc) = uVar2;
        *(undefined4 *)(iVar6 + 0x1b4) = uVar2;
        *(undefined4 *)(iVar6 + 0x10bc) = uVar2;
        *(undefined4 *)(iVar6 + 0x1d0) = uVar3;
        *(undefined4 *)(iVar6 + 0x1b8) = uVar3;
        *(undefined4 *)(iVar6 + 0x10c0) = uVar3;
        *(undefined4 *)(iVar6 + 0x1d4) = uVar4;
        *(undefined4 *)(iVar6 + 0x1bc) = uVar4;
        *(undefined4 *)(iVar6 + 0x10c4) = uVar4;
        *(undefined4 *)(iVar6 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)(iVar6 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)(iVar6 + 0x70) = DAT_0093b0d4;
        FUN_005728a0(iVar6);
        if (local_54 != 0) {
          FUN_00572660(iVar6,0);
        }
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_60);
  return;
}

