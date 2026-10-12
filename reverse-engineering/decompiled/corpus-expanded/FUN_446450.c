/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x446450; label: FUN_00446450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00446450(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  float10 fVar7;
  float local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  undefined4 local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_5c;
  local_5c = 1.0;
  local_48 = param_1;
  local_58 = 0;
  local_50 = 0;
  local_54 = 0;
  local_4c = (char *)0x0;
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    if (param_6 != 0) {
      iVar6 = 0;
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_2 + 0xa4);
      if (0 < param_5) {
        do {
          iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_0075782c);
          if (iVar4 == 0) {
            iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"personal");
            if (iVar4 == 0) {
              iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"indexed");
              if (iVar4 == 0) {
                iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"random");
                if (iVar4 == 0) {
                  iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"jump_factor=");
                  if (iVar4 != 0) {
                    fVar7 = (float10)FUN_005147c0(param_2,iVar4 + 0xc);
                    local_5c = (float)fVar7;
                    if (local_5c < 0.0) {
                      local_5c = 0.0;
                    }
                  }
                }
                else {
                  FUN_005147c0(param_2,iVar4 + 9);
                  local_54 = FUN_006e6b90();
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
            local_4c = (char *)(iVar4 + 5);
          }
          pcVar3 = local_4c;
          iVar4 = local_54;
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_5);
        if (local_4c != (char *)0x0) {
          if (((local_50 == 0) || (iVar2 == 0)) || (*(char *)(iVar2 + 0x280) == -1)) {
            if (((local_58 == 0) || (iVar2 == 0)) || (*(int *)(iVar2 + 0x54) == 0)) {
              if (local_54 == 0) {
                _sprintf(local_44,local_4c);
              }
              else {
                iVar6 = FUN_005b9e90(0);
                _sprintf(local_44,"%s_%d",pcVar3,iVar6 % iVar4);
              }
            }
            else {
              _sprintf(local_44,"%s_%s",local_4c,*(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xc));
            }
          }
          else {
            _sprintf(local_44,"%s_%d",local_4c,(int)*(char *)(iVar2 + 0x280));
          }
          uVar5 = FUN_0051ac10(local_48,local_44);
          *(undefined4 *)(param_2 + 0x6c) = uVar5;
        }
      }
      iVar6 = *(int *)(param_2 + 0x6c);
      if (iVar6 != 0) {
        FUN_00561e20(iVar2,(undefined4 *)(iVar6 + 0x10),0,local_5c,0x3f800000,0);
        *(undefined4 *)(iVar2 + 0x420) = *(undefined4 *)(iVar6 + 0x20);
        *(undefined4 *)(iVar2 + 0x424) = *(undefined4 *)(iVar6 + 0x24);
        *(undefined4 *)(iVar2 + 0x428) = *(undefined4 *)(iVar6 + 0x28);
        *(undefined4 *)(iVar2 + 0x42c) = *(undefined4 *)(iVar6 + 0x2c);
        *(undefined4 *)(iVar2 + 0x430) = *(undefined4 *)(iVar6 + 0x30);
        *(undefined4 *)(iVar2 + 0x434) = *(undefined4 *)(iVar6 + 0x34);
        *(undefined4 *)(iVar2 + 0x438) = *(undefined4 *)(iVar6 + 0x10);
        *(undefined4 *)(iVar2 + 0x43c) = *(undefined4 *)(iVar6 + 0x14);
        *(undefined4 *)(iVar2 + 0x440) = *(undefined4 *)(iVar6 + 0x18);
      }
    }
    __security_check_cookie(local_4 ^ (uint)&local_5c);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_5c);
  return;
}

