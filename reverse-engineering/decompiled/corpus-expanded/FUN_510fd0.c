/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x510fd0; label: FUN_00510fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00510fd0(void)

{
  undefined4 local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  local_408 = _DAT_0080098c;
  if (DAT_00921e74 != (code *)0x0) {
    (*DAT_00921e74)();
  }
  _sprintf(local_404,PTR_s_Autosave_will_now_use_Game__i_00800a8c,DAT_00802014 + 1);
  FUN_0050f3b0(local_404,0,0x3ee66666,0x3f800000,local_408,local_408,local_408,0,DAT_00800998,
               DAT_00800999,DAT_00921da8,0x3fc00000,3,0,0,_DAT_00921d60);
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

