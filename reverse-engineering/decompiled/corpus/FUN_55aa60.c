/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55aa60; label: FUN_0055aa60
 */

void FUN_0055aa60(int param_1,undefined4 param_2,undefined1 *param_3,char *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *local_60;
  int local_5c;
  undefined4 local_58;
  char local_54 [16];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_60;
  local_58 = param_2;
  local_5c = param_1;
  local_60 = param_4;
  iVar2 = 1;
  if (((param_1 != 0) && (param_3 != (undefined1 *)0x0)) && (param_4 != (char *)0x0)) {
    iVar4 = 0;
    if (0 < *DAT_0093b268) {
      iVar3 = 0;
      do {
        iVar1 = FUN_004f8b10(local_58,DAT_0093b268[2] + 0x20 + iVar3);
        if (iVar1 != 0) {
          iVar1 = FUN_0055aa00(param_3,DAT_0093b268[2] + 0x20 + iVar3);
          if (iVar1 != 0) goto LAB_0055ab95;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x9c;
      } while (iVar4 < *DAT_0093b268);
    }
    iVar4 = FUN_004f1ff0(param_3);
    do {
      _sprintf(local_54,"%d",iVar2);
      iVar3 = FUN_004f1ff0(local_54);
      if (param_5 <= iVar3 + iVar4) {
        iVar4 = param_5 - iVar3;
        if (iVar4 < 1) break;
        FUN_004f1f40(local_44,param_3,iVar4);
        param_3 = local_44;
      }
      _sprintf(local_60,"%s%s",param_3,local_54);
      iVar3 = FUN_0055a970(local_5c,local_60);
      if (iVar3 != 0) {
        __security_check_cookie(local_4 ^ (uint)&local_60);
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 999);
  }
LAB_0055ab95:
  __security_check_cookie(local_4 ^ (uint)&local_60);
  return;
}

