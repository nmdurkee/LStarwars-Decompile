/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x445cf0; label: FUN_00445cf0
 */

void FUN_00445cf0(undefined4 param_1,float param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  char *_Format;
  int iVar3;
  float10 fVar4;
  int local_78;
  float local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  float local_5c;
  int local_58;
  int local_54;
  undefined1 local_50 [12];
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_78;
  local_5c = 1e+09;
  iVar3 = 0;
  local_74 = param_2;
  _Format = (char *)0x0;
  local_6c = param_3;
  local_68 = 0;
  local_54 = 0;
  local_60 = 0;
  local_64 = 0;
  local_70 = 0;
  local_78 = 0;
  local_58 = 0;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
      local_70 = *(int *)(param_3 + 0xd0);
    }
    if (param_5 != 0) {
      if (0 < param_5) {
        do {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"name=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"personal");
            if (iVar2 == 0) {
              local_68 = 1;
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"indexed");
              if (iVar2 == 0) {
                local_54 = 1;
              }
              else {
                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"nearest");
                if (iVar2 == 0) {
                  local_60 = 1;
                }
                else {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"random=");
                  if (iVar2 == 0) {
                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
                    if ((iVar2 != 0) && (DAT_00923904 != (code *)0x0)) {
                      local_70 = (*DAT_00923904)(param_1,iVar2 + 10);
                    }
                  }
                  else {
                    FUN_005147c0(local_74,iVar2 + 7);
                    local_64 = FUN_006e6b90();
                  }
                }
              }
            }
          }
          else {
            _Format = (char *)(iVar2 + 5);
          }
          iVar2 = local_64;
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_5);
        if (_Format != (char *)0x0) {
          if (local_60 == 0) {
            if (local_6c != 0) {
              if ((local_54 == 0) ||
                 (cVar1 = *(char *)(*(int *)(local_6c + 0xd0) + 0x280), cVar1 == -1)) {
                if ((local_68 == 0) ||
                   (iVar3 = *(int *)(*(int *)(local_6c + 0xd0) + 0x54), iVar3 == 0)) {
                  if (local_64 == 0) {
                    _sprintf(local_44,_Format);
                  }
                  else {
                    iVar3 = FUN_005b9e90(0);
                    _sprintf(local_44,"%s_%d",_Format,iVar3 % iVar2);
                  }
                }
                else {
                  _sprintf(local_44,"%s_%s",_Format,*(undefined4 *)(iVar3 + 0xc));
                }
              }
              else {
                _sprintf(local_44,"%s_%d",_Format,(int)cVar1);
              }
              local_78 = FUN_0051ac10(param_1,local_44);
            }
          }
          else {
            iVar3 = 0;
            while( true ) {
              _sprintf(local_44,"%s_%d",_Format,iVar3);
              iVar3 = iVar3 + 1;
              iVar2 = FUN_0051ac10(param_1,local_44);
              if (iVar2 == 0) break;
              fVar4 = (float10)FUN_005b3c50(local_6c + 0x14c,iVar2 + 0x10,local_50);
              local_74 = (float)fVar4;
              if (local_74 < local_5c) {
                local_5c = local_74;
                local_58 = iVar2;
              }
            }
            local_78 = local_58;
          }
        }
      }
      if (local_70 != 0) {
        *(int *)(*(int *)(local_70 + 4) + 0xa4) = local_78;
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_78);
  return;
}

