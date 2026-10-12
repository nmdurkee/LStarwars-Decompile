/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4c80; label: FUN_004f4c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f4c80(void)

{
  if (DAT_0297dc2c != 0) {
    DAT_0297dc2c = 0;
  }
  if (DAT_0297dc08 == 1) {
    *DAT_0297dc14 = _DAT_0297dbfc;
    DAT_0297dc14 = DAT_0297dc14 + 1;
    if (DAT_0297dc14 <= DAT_0297dc10 + -0x610) {
      return;
    }
  }
  else {
    if (DAT_0297dc08 != 2) {
      return;
    }
    if (DAT_0297dc14 != DAT_0297dc10) {
      _DAT_0297dbfc = *DAT_0297dc14;
      DAT_0297dc14 = DAT_0297dc14 + 1;
      return;
    }
  }
  DAT_0297dc08 = 0;
  return;
}

