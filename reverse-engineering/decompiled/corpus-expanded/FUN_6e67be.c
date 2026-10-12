/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e67be; label: FUN_006e67be
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */

void FUN_006e67be(void)

{
  undefined **local_54 [10];
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x6e67ca;
  FUN_0060d070("string too long");
  local_8 = 0;
  FUN_0060cf00(local_2c);
  local_54[0] = &PTR_FUN_0076a8d8;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_54,&DAT_007ecc88);
}

