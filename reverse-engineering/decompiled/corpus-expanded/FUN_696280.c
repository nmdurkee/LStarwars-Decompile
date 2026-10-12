/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x696280; label: FUN_00696280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696280(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  FUN_004f7fb0(param_1);
  FUN_00694740(local_104,*(undefined4 *)(param_1 + 0x510),"$lang",*(undefined4 *)(in_ECX + 0x1d4));
  iVar2 = FUN_006946b0(local_104);
  if (iVar2 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 300);
    iVar2 = FUN_004f1ff0(local_104);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + iVar2 + 1;
    FUN_004f1f10(uVar1,local_104);
    *(undefined4 *)(*(int *)(in_ECX + 0x20) + 4) = uVar1;
  }
  else {
    *(int *)(*(int *)(in_ECX + 0x20) + 4) = iVar2;
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

