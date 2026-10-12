/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x5118a0; label: FUN_005118a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005118a0(int param_1)

{
  undefined *puVar1;
  
  FUN_004f1f10(&DAT_009213f8,PTR_s_Save_Game_008009f4);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  puVar1 = PTR_s_Confirm_Save__00800a20;
  if (DAT_00921d38 != 0) {
    puVar1 = PTR_s_Are_you_sure_you_wish_to_overwri_00800a24;
  }
  FUN_0050f3b0(puVar1,0,0xbe99999a,0x3f800000,_DAT_0080098c,_DAT_0080098c,_DAT_0080098c,0,
               DAT_00800998,DAT_00800999,DAT_00921da8,0x3f99999a,2,0,0,_DAT_00921d60);
  *(float *)(param_1 + 0x98) = _DAT_00800974 - _DAT_00800994;
  FUN_0050f740(param_1,PTR_PTR_008009cc,_DAT_00921d60 & 0xff);
  FUN_0050f740(param_1,PTR_DAT_008009d0,_DAT_00921d60 & 0xff);
  return;
}

