/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534d70; label: FUN_00534d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00534d70(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (*(int *)(DAT_009238e4 + 0x371b0) == *(int *)(DAT_009238e4 + 0x371ac))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,FUN_0052a290,"Delete creature??");
    if (iVar1 != 0) {
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_0052a220,&DAT_0075f2d0);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_0052a220,&PTR_DAT_0075f2d4);
      FUN_00618e10(iVar1,uVar2);
      return iVar1;
    }
  }
  return 0;
}

