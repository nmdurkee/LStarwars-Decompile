/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x534d70; label: FUN_00534d70
 */

int FUN_00534d70(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (*(int *)(DAT_009238e4 + 0x371b0) == *(int *)(DAT_009238e4 + 0x371ac))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_0052a290,"Delete creature??");
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

