/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e67fd; label: FUN_006e67fd
 */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */

void FUN_006e67fd(void)

{
  undefined **local_54 [10];
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x6e6809;
  FUN_0060d070("invalid string position");
  local_8 = 0;
  FUN_0060cf00(local_2c);
  local_54[0] = &PTR_FUN_00777ca0;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_54,&DAT_007ece40);
}

