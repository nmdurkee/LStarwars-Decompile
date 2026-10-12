/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x4124f0; label: FUN_004124f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004124f0(undefined4 param_1)

{
  FUN_004118d0();
  FUN_00411980(param_1);
  _DAT_009543f4 = 0x43160000;
  _DAT_009543f8 = 0x3fc00000;
  DAT_007f1628 = 0xffffffff;
  DAT_007f162c = 0xffffffff;
  _DAT_007f1630 = 0xffffffff;
  _DAT_007f1634 = 0xffffffff;
  FUN_00694030(2,0);
  FUN_00694030(0x20,0);
  return;
}

