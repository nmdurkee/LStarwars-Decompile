/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x618310; label: FUN_00618310
 */

void FUN_00618310(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  int in_ECX;
  int unaff_EDI;
  int local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  if (DAT_02912eb8 != 0) goto LAB_006183be;
  FUN_005d0880(2);
  _vsprintf(local_404,param_3,&stack0x00000010);
  FUN_005d0d60(param_1,local_404);
  iVar1 = FUN_006e6b90();
  if (unaff_EDI != 0x10) {
    if (unaff_EDI != 0x20) {
      if (unaff_EDI != 0x40) goto LAB_00618386;
      iVar1 = iVar1 / 2;
    }
    in_ECX = in_ECX - iVar1;
  }
LAB_00618386:
  local_408 = in_ECX;
  FUN_005eabb0(param_1,(float)in_ECX,(float)param_2,0);
  FUN_005f3510(param_1,local_404);
  FUN_005d08c0();
LAB_006183be:
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

