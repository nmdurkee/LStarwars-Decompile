/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74e9f0; label: FUN_0074e9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074e9f0(float param_1)

{
  _DAT_0297dba0 = 0.0;
  if ((0.0 <= param_1) && (_DAT_0297dba0 = param_1, 1.0 < param_1)) {
    _DAT_0297dba0 = 1.0;
    return;
  }
  return;
}

