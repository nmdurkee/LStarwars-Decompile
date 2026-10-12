/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x511a60; label: FUN_00511a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00511a60(int param_1)

{
  FUN_004f1f10(&DAT_009213f8,PTR_s_Load_Game_008009f8);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  if (((PTR_FUN_00800968 != (undefined *)0x0) && (0.2 < _DAT_00921d5c)) && (DAT_00921d24 == 0)) {
    (*(code *)PTR_FUN_00800968)(param_1,0xbe4ccccd);
  }
  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
  *(undefined4 *)(param_1 + 0x98) = _DAT_00800974;
  FUN_0050f740(param_1,PTR_s_Cancel_008009d8,DAT_00921d60);
  return;
}

