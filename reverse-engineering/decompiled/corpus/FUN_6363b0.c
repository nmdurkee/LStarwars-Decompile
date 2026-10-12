/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x6363b0; label: FUN_006363b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006363b0(int param_1)

{
  FUN_00633e40(param_1 + 0x9c,param_1 + 0x84);
  _DAT_009716e8 = *(undefined4 *)(param_1 + 0xc0);
  _DAT_009716ec = *(undefined4 *)(param_1 + 0xc4);
  _DAT_009716f0 = *(undefined4 *)(param_1 + 200);
  FUN_005fca90();
  return;
}

