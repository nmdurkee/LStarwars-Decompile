/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x6920c0; label: FUN_006920c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006920c0(undefined4 param_1,int param_2)

{
  if (DAT_02962988 != 0) {
    FUN_0062a400(DAT_02962988,param_1,param_2);
    return 0;
  }
  FUN_00691a40(param_2);
  if (DAT_029629f8 == 1) {
    FUN_0065efc0();
    return *(uint *)(param_2 + 0x78) >> 0xb & 1;
  }
  FUN_00690e40(0x3f800000);
  return *(uint *)(param_2 + 0x78) >> 0xb & 1;
}

