/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74ea20; label: FUN_0074ea20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074ea20(int *param_1)

{
  FUN_00631d00(param_1 + 5);
  if (*param_1 != 0) {
    FUN_005e50e0(*param_1);
  }
  if (param_1[10] != 0) {
    FUN_005e5630(param_1[10]);
  }
  _memset(param_1,0,0x60);
  return;
}

