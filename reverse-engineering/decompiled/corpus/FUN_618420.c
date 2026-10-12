/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x618420; label: FUN_00618420
 */

void FUN_00618420(undefined4 param_1,int param_2,int param_3,int param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  char *pcVar3;
  undefined4 local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  if (DAT_02912eb8 == 0) {
    FUN_005d0880(2);
    _vsprintf(local_404,param_5,&stack0x00000018);
    FUN_005d0d60();
    iVar1 = FUN_006e6b90();
    if (param_2 != 0x10) {
      if (param_2 == 0x20) {
        in_ECX = in_ECX - iVar1;
      }
      else if (param_2 == 0x40) {
        in_ECX = in_ECX - iVar1 / 2;
      }
    }
    local_408 = in_ECX;
    if (in_ECX < param_3) {
      local_408 = param_3;
    }
    iVar2 = FUN_004f1ff0(local_404);
    for (pcVar3 = local_404 + iVar2 + -1; (param_4 < iVar1 && (local_404 < pcVar3));
        pcVar3 = pcVar3 + -1) {
      *pcVar3 = '\0';
      FUN_005d0d60();
      iVar1 = FUN_006e6b90();
    }
    FUN_005eabb0();
    FUN_005f3510();
    FUN_005d08c0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

