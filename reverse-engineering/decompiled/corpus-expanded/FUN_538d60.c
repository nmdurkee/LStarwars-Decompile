/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538d60; label: FUN_00538d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00538d60(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  iVar1 = FUN_00538600();
  if (iVar1 == 0) {
    iVar1 = FUN_00619250(0x78,0x5a,0x1b8,0xfa,DAT_02912e80,0,"AI Save FAILED");
    if (iVar1 != 0) {
      _sprintf(local_84,"Make sure there is a folder called \"%s\" in your level directory",
               *(undefined4 *)(DAT_009238e4 + 0x43834));
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00527390,local_84);
      FUN_00618e10(iVar1,uVar2);
      FUN_006279b0(param_1,iVar1);
    }
  }
  else if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
    __security_check_cookie(local_4 ^ (uint)local_84);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

