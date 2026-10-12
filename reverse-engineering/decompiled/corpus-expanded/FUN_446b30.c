/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x446b30; label: FUN_00446b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00446b30(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *_Format;
  int iVar4;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  char acStack_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_5c;
  iVar4 = 0;
  _Format = (char *)0x0;
  iVar3 = 0;
  local_58 = param_1;
  local_48 = param_2;
  local_50 = 0;
  local_4c = 0;
  local_5c = 0;
  local_54 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar3 = *piVar2;
    }
    if (param_5 != 0) {
      if (0 < param_5) {
        do {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075782c);
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"personal");
              if (iVar1 == 0) {
                iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"indexed");
                if (iVar1 == 0) {
                  iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"take_damage");
                  if (iVar1 == 0) {
                    iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"random");
                    if (iVar1 != 0) {
                      FUN_005147c0(local_48,iVar1 + 9);
                      local_5c = FUN_006e6b90();
                    }
                  }
                  else {
                    local_54 = 1;
                  }
                }
                else {
                  local_4c = 1;
                }
              }
              else {
                local_50 = 1;
              }
            }
            else {
              _Format = (char *)(iVar1 + 5);
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar2 = (int *)(*DAT_00923904)(local_58,iVar1 + 10), piVar2 == (int *)0x0)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *piVar2;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5);
      }
      if (iVar3 != 0) {
        *(uint *)(iVar3 + 0xef0) = *(uint *)(iVar3 + 0xef0) & 0xfffff7ff;
        *(undefined4 *)(iVar3 + 0xf14) = 0;
        if (_Format != (char *)0x0) {
          if ((local_4c == 0) || (*(char *)(iVar3 + 0x280) == -1)) {
            if ((local_50 == 0) || (*(int *)(iVar3 + 0x54) == 0)) {
              if (local_5c == 0) {
                _sprintf(acStack_44,_Format);
              }
              else {
                iVar4 = FUN_005b9e90(0);
                _sprintf(acStack_44,"%s_%d",_Format,iVar4 % local_5c);
              }
            }
            else {
              _sprintf(acStack_44,"%s_%s",_Format,*(undefined4 *)(*(int *)(iVar3 + 0x54) + 0xc));
            }
          }
          else {
            _sprintf(acStack_44,"%s_%d",_Format,(int)*(char *)(iVar3 + 0x280));
          }
          iVar4 = FUN_0051ac10(local_58,acStack_44);
          *(int *)(iVar3 + 0xf14) = iVar4;
          if (iVar4 != 0) {
            *(uint *)(iVar3 + 0xef0) =
                 *(uint *)(iVar3 + 0xef0) ^ (local_54 << 0xb ^ *(uint *)(iVar3 + 0xef0)) & 0x800;
          }
        }
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_5c);
  return;
}

