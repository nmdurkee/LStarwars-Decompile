/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x538900; label: FUN_00538900
 */

int FUN_00538900(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x383c8) != 0) &&
     (*(int *)(DAT_009238e4 + 0x383c8) == *(int *)(DAT_009238e4 + 0x383cc))) {
    iVar1 = FUN_00619250(200,0x46,0xf0,0x10e,DAT_02912e80,&LAB_00530b00,"Delete area??");
    if (iVar1 != 0) {
      uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_00530a20,&DAT_0075f2d0);
      FUN_00618e10(iVar1,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00530a20,&PTR_DAT_0075f2d4);
      FUN_00618e10(iVar1,uVar2);
      return iVar1;
    }
  }
  return 0;
}

