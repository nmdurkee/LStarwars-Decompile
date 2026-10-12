/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x458500; label: FUN_00458500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00458500(undefined4 param_1,int *param_2)

{
  *(byte *)(*param_2 + 3) = *(byte *)(*param_2 + 3) | 1;
  _DAT_00876da0 = -_DAT_007f824c;
  _DAT_00876da4 = -_DAT_007f8250 + -_DAT_007f8250;
  _DAT_00876da8 = 0xc0400000;
  return 0;
}

