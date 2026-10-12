/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x543cf0; label: FUN_00543cf0
 */

undefined4 FUN_00543cf0(undefined4 param_1)

{
  _sprintf((char *)&DAT_009246f8,"SaveGame%d.%s_SavedGame",param_1,PTR_s_GameTitle_0082761c);
  FUN_006e8de2(&DAT_009246f8);
  return 1;
}

