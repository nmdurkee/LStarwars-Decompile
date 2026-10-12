/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0530; label: FUN_005d0530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d0530(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00806ccc;
  if (param_1 == 0) {
    DAT_00806ccc = 0xffffffff;
    return uVar1;
  }
  DAT_00806ccc = param_2;
  return uVar1;
}

