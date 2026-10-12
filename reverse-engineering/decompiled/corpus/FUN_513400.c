/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513400; label: FUN_00513400
 */

void FUN_00513400(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c4 [64];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_cc;
  FUN_004f1f10(local_c4);
  puVar1 = (undefined1 *)FUN_004f8a70(local_c4,&DAT_0075ffd8);
  if (puVar1 == (undefined1 *)0x0) {
    __security_check_cookie(local_4 ^ (uint)&local_cc);
    return;
  }
  *puVar1 = 0;
  _sprintf(local_84,"%s\\%s",param_1);
  if (unaff_EDI != 0) {
    iVar2 = FUN_004f9de0();
    if (iVar2 == 0) {
      if (DAT_00922248 == 1) {
        FUN_00512870();
      }
      else {
        FUN_00512850();
      }
    }
    else {
      FUN_004f0f30();
      iVar2 = FUN_004f02d0(local_cc,local_c8,0);
      if (iVar2 != 0) {
        FUN_004fc750(iVar2);
        __security_check_cookie(local_4 ^ (uint)&local_cc);
        return;
      }
      FUN_00512870();
    }
    if (DAT_00923874 != 0) {
      if (DAT_00922248 == 1) {
        FUN_00512860();
      }
      else {
        FUN_00512850();
      }
    }
  }
  FUN_004fc860(local_84);
  __security_check_cookie(local_4 ^ (uint)&local_cc);
  return;
}

