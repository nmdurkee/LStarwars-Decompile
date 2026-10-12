/* Ghidra pseudocode, not original source.
 * ev_a3dc7e4d451c42d041af92cbf24a16255b1dce01fb5c93e82b55e7bce3880be0
 * Entry: 0x5116c0; label: FUN_005116c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005116c0(int param_1)

{
  FUN_004f1f10(&DAT_009213f8,PTR_s_Save_Game_008009f4);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  if (((PTR_FUN_00800968 != (undefined *)0x0) && (0.2 < _DAT_00921d5c)) && (DAT_00921d24 == 0)) {
    (*(code *)PTR_FUN_00800968)(param_1,0xbe99999a);
  }
  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
  if (DAT_00921d7c == 0) {
    *(undefined4 *)(param_1 + 0x98) = _DAT_00800974;
    FUN_0050f740(param_1,PTR_s_Cancel_008009d8,DAT_00921d60);
  }
  return;
}

