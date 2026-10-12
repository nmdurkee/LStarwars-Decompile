/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c37f0; label: FUN_005c37f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c37f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_0097acc0 = DAT_00963e08;
  if (DAT_0080bf20 == param_1) {
    if (param_1 != -1) {
      DAT_0097acc0 = DAT_00963e08;
      return DAT_00963e08;
    }
  }
  else if (param_1 != -1) {
    DAT_0080bf20 = param_1;
  }
  uVar1 = FUN_005f8a50();
  DAT_0097acc0 = DAT_00963e08;
  FUN_005f8be0(uVar1,1);
  uVar2 = FUN_005f7c50(DAT_0097acc0);
  uVar2 = FUN_005f7c40(DAT_0097acc0,uVar2);
  FUN_0060a7a0(0,DAT_0097acc0,0,0,0,uVar2);
  FUN_005f8be0(uVar1,0);
  return DAT_0097acc0;
}

