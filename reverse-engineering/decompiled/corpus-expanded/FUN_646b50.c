/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x646b50; label: FUN_00646b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00646b50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_14;
  if (DAT_02920970 != 0) {
    DAT_02920a10 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_00646b30,"Attached Sounds");
    if (DAT_02920a10 != 0) {
      iVar3 = 0;
      do {
        iVar1 = iVar3 + 1;
        _sprintf(local_14,"Sound %d...",iVar1);
        uVar2 = FUN_00627a80(iVar3,&DAT_008109d8,0,0,FUN_00646a20,local_14);
        FUN_00618e10(DAT_02920a10,uVar2);
        iVar3 = iVar1;
      } while (iVar1 < 4);
      FUN_006279b0(param_1,DAT_02920a10);
      *(int *)(DAT_02920a10 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a10 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_14);
  return;
}

