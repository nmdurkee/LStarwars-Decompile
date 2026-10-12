/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x511dd0; label: FUN_00511dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511dd0(int param_1)

{
  FUN_0050f3b0(PTR_s_Do_you_want_to_cancel_the_Format_00800a34,0,0xbe99999a,0x3f800000,_DAT_0080098c
               ,_DAT_0080098c,_DAT_0080098c,0,DAT_00800998,DAT_00800999,DAT_00921da8,0x3fc00000,2,0,
               0,_DAT_00921d60);
  *(float *)(param_1 + 0x98) = _DAT_00800974 - _DAT_00800994;
  FUN_0050f740(param_1,PTR_PTR_008009cc,_DAT_00921d60 & 0xff);
  FUN_0050f740(param_1,PTR_DAT_008009d0,_DAT_00921d60 & 0xff);
  return;
}

