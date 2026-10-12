/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b300; label: FUN_0055b300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b300(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  int in_EDX;
  int iVar2;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  iVar2 = in_EDX * 0x4c;
  _sprintf(local_84,"chars\\%s\\%s.gsc",*(undefined4 *)(iVar2 + 8 + DAT_0093b274),
           *(undefined4 *)(iVar2 + 0xc + DAT_0093b274));
  iVar1 = FUN_005ef7f0(param_1,param_2,local_84);
  *in_ECX = iVar1;
  if (iVar1 != 0) {
    FUN_005cf5b0(iVar1,in_ECX + 1,*(undefined4 *)(iVar2 + 0xc + DAT_0093b274),1);
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

