/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52d310; label: FUN_0052d310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052d310(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_5c;
  char *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_5c;
  iVar5 = 0;
  local_4c = param_1;
  local_48 = param_2;
  local_54 = 0;
  local_50 = 0;
  local_5c = 0;
  local_58 = (char *)0x0;
  if (((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
       (**(int **)(param_3 + 0xd0) != 0)) &&
      ((*(int *)(param_3 + 0x158) != 0 && (*(int *)(param_3 + 0x15c) != 0)))) &&
     ((param_6 != 0 && (*(undefined4 *)(param_2 + 0xa4) = 0, 0 < param_5)))) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_0075782c);
      if (iVar3 == 0) {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"personal");
        if (iVar3 == 0) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"indexed");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"random");
            if (iVar3 != 0) {
              FUN_00514920(param_3,param_3,iVar3 + 7);
              local_5c = FUN_006e6b90();
            }
          }
          else {
            local_50 = 1;
          }
        }
        else {
          local_54 = 1;
        }
      }
      else {
        local_58 = (char *)(iVar3 + 5);
      }
      pcVar2 = local_58;
      iVar3 = local_5c;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (local_58 != (char *)0x0) {
      if ((local_50 == 0) || (cVar1 = *(char *)(*(int *)(param_3 + 0xd0) + 0x280), cVar1 == -1)) {
        if ((local_54 == 0) || (iVar5 = *(int *)(*(int *)(param_3 + 0xd0) + 0x54), iVar5 == 0)) {
          if (local_5c == 0) {
            _sprintf(local_44,local_58);
          }
          else {
            iVar5 = FUN_005b9e90(0);
            _sprintf(local_44,"%s_%d",pcVar2,iVar5 % iVar3);
          }
        }
        else {
          _sprintf(local_44,"%s_%s",local_58,*(undefined4 *)(iVar5 + 0xc));
        }
      }
      else {
        _sprintf(local_44,"%s_%d",local_58,(int)cVar1);
      }
      uVar4 = FUN_0051ac10(local_4c,local_44);
      *(undefined4 *)(local_48 + 0xa4) = uVar4;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_5c);
  return;
}

