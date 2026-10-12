/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c8bd0; label: FUN_004c8bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004c8bd0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  param_1 = param_1 + 0xf2;
  iVar1 = FUN_004f20f0(param_1,"thermocrate_011");
  if ((((iVar1 != 0) && (iVar1 = FUN_004f20f0(param_1,"thermocrate_021"), iVar1 != 0)) &&
      (iVar1 = FUN_004f20f0(param_1,"thermocrate_031"), iVar1 != 0)) &&
     (iVar1 = FUN_004f20f0(param_1,"minikit101"), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

