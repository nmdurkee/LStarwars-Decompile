/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x5117f0; label: FUN_005117f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005117f0(int param_1)

{
  FUN_0050f3b0(PTR_s_Are_you_sure_you_wish_to_delete_t_00800a54,0,0,0x3f800000,_DAT_0080098c,
               _DAT_0080098c,_DAT_0080098c,0,DAT_00800998,DAT_00800999,DAT_00921da8,0x3f99999a,2,0,0
               ,_DAT_00921d60);
  *(float *)(param_1 + 0x98) = _DAT_00800974 - _DAT_00800994;
  FUN_0050f740(param_1,PTR_PTR_008009cc,_DAT_00921d60 & 0xff);
  FUN_0050f740(param_1,PTR_DAT_008009d0,_DAT_00921d60 & 0xff);
  return;
}

