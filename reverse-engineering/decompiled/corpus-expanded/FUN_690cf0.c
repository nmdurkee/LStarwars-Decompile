/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x690cf0; label: FUN_00690cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00690cf0(undefined4 param_1,int param_2)

{
  if (DAT_02962954 != 0) {
    FUN_0062a400(DAT_02962954,param_1,param_2);
    return 0;
  }
  FUN_006909b0(param_2);
  FUN_0065d540(0x3f800000);
  return *(uint *)(param_2 + 0x78) >> 0xb & 1;
}

