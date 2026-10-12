/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0940; label: FUN_005d0940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d0940(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_009738c0;
  DAT_009738c0 = param_1;
  if (param_1 == 2) {
    _DAT_0080b600 = 0x3f800000;
    _DAT_0080b604 = 0x3f000000;
    _DAT_009738ac = 0x3f800000;
    _DAT_009738b0 = 0x3f800000;
    _DAT_0080b608 = 0x3f800000;
    _DAT_0080b60c = 0x3f800000;
    return uVar1;
  }
  if (param_1 != 3) {
    if (param_1 != 4) {
      _DAT_0080b600 = 0x3d800000;
      _DAT_0080b604 = 0x3d800000;
      _DAT_009738ac = 0;
      _DAT_009738b0 = 0;
      _DAT_0080b608 = 0x41800000;
      _DAT_0080b60c = 0x41800000;
      return uVar1;
    }
    _DAT_0080b600 = 0x3f800000;
    _DAT_0080b604 = 0x3f800000;
    _DAT_009738ac = 0;
    _DAT_009738b0 = 0;
    _DAT_0080b608 = 0x3f800000;
    _DAT_0080b60c = 0xbf800000;
    return uVar1;
  }
  _DAT_0080b600 = 0x43a00000;
  _DAT_0080b604 = 0xc2e00000;
  _DAT_009738ac = 0x43a00000;
  _DAT_009738b0 = 0x42e00000;
  _DAT_0080b608 = 0x3b4ccccd;
  _DAT_0080b60c = 0xbc124925;
  return uVar1;
}

