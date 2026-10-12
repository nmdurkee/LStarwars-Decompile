/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d4310; label: FUN_005d4310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d4310(undefined4 *param_1,float *param_2)

{
  _DAT_0096d9c4 = *param_1;
  _DAT_0096d9c8 = param_1[1];
  _DAT_0096d9cc = param_1[2];
  _DAT_009715a4 = *param_2;
  _DAT_009715a8 = param_2[1];
  _DAT_009715ac = param_2[2];
  _DAT_00971584 = 1.0 / *param_2;
  _DAT_00971588 = 1.0 / param_2[1];
  _DAT_0097158c = 1.0 / param_2[2];
  return;
}

