/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x534740; label: FUN_00534740
 */

void FUN_00534740(void)

{
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (DAT_009242b8 == 0)) {
    FUN_00627bc0(1,&DAT_00801cb4,1,1,FUN_005346d0,"Reset Params");
    DAT_009242b8 = FUN_00618e10();
  }
  return;
}

