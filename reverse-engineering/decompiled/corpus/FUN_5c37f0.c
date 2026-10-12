/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c37f0; label: FUN_005c37f0
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

