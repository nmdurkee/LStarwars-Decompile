/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x511b10; label: FUN_00511b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511b10(int param_1)

{
  FUN_004f1f10(&DAT_009213f8,PTR_s_Load_Game_008009f8);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  FUN_0050f4c0(PTR_s_Confirm_Load__00800a1c,0,0xbe99999a,0x3f800000,_DAT_0080098c,_DAT_0080098c,
               _DAT_0080098c,0,DAT_00800998,DAT_00800999,DAT_00921da8,DAT_00921d60);
  *(float *)(param_1 + 0x98) = _DAT_00800974 - _DAT_00800994;
  FUN_0050f740(param_1,PTR_PTR_008009cc,DAT_00921d60);
  FUN_0050f740(param_1,PTR_DAT_008009d0,DAT_00921d60);
  return;
}

