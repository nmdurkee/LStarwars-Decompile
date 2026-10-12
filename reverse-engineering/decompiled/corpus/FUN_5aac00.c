/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aac00; label: FUN_005aac00
 */

void FUN_005aac00(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  if (param_1 != 0) {
    if (param_3 != 0) {
      __security_check_cookie(local_4 ^ (uint)local_24);
      return;
    }
    if (param_2 != 0) {
      iVar1 = FUN_004f8a70(param_2,&DAT_00805d48);
      if (iVar1 == 0) {
        iVar1 = FUN_004f1ff0(param_2);
        iVar2 = FUN_004f1ff0(&DAT_00805d48);
        if (0x1f < iVar1 + 1 + iVar2) {
          __security_check_cookie(local_4 ^ (uint)local_24);
          return;
        }
        _sprintf(local_24,"%s%s",&DAT_00805d48,param_2);
      }
      else {
        _sprintf(local_24,"%s");
      }
      iVar1 = param_1 + 0x10;
      for (iVar2 = FUN_004f1440(iVar1); iVar2 != 0; iVar2 = FUN_004f1460(iVar1,iVar2)) {
        iVar3 = FUN_004f8b80(local_24,iVar2 + 8,0x20);
        if (iVar3 == 0) {
          if (iVar2 != 0) goto LAB_005aad30;
          break;
        }
      }
      iVar2 = FUN_004f1440(param_1 + 8);
      if (iVar2 != 0) {
        FUN_004f1410(param_1 + 8,iVar2);
        FUN_004f1310(iVar1,iVar2);
        FUN_004f1f40(iVar2 + 8,local_24,0x20);
      }
    }
  }
LAB_005aad30:
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

