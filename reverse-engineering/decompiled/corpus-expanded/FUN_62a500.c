/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x62a500; label: FUN_0062a500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0062a500(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_EDX;
  
  DAT_02900a6c = 0;
  if (DAT_02912e88 != 0) {
    FUN_006273a0(0,0);
  }
  if (DAT_02912e68 == 0) {
    if (DAT_02912e64 != 0) goto LAB_0062a5b7;
  }
  else if (DAT_02912e64 != 0) {
    if (*(code **)(DAT_02912e64 + 0x2c) == (code *)0x0) {
      DAT_02912e68 = 0;
      return DAT_02900a6c;
    }
    iVar1 = (**(code **)(DAT_02912e64 + 0x2c))(param_1,param_2);
    if (iVar1 != 0) {
      if (*(code **)(DAT_02912e64 + 0x18) != (code *)0x0) {
        (**(code **)(DAT_02912e64 + 0x18))();
      }
      DAT_02912e68 = 0;
      if (iVar1 == 2) {
        DAT_02900a6c = 1;
        return 1;
      }
    }
    return DAT_02900a6c;
  }
  DAT_02912e64 = DAT_02912e60;
  FUN_006271a0(DAT_02912e6c);
  DAT_02912eb4 = extraout_EDX;
LAB_0062a5b7:
  FUN_0062a4b0(param_1,param_2);
  return DAT_02900a6c;
}

