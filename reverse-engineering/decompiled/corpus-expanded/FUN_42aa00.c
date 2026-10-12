/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42aa00; label: FUN_0042aa00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042aa00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == -1) ||
     ((iVar2 = param_1 * 0x9c + DAT_00951354, iVar2 != DAT_0087b02c && (iVar2 != DAT_0087b048)))) {
    DAT_00876580 = 0;
    _DAT_007fd118 = 0x3e4ccccd;
    DAT_00950c48 = 0;
    DAT_00802454 = 0;
    DAT_00955fb8 = 0;
    DAT_00955fbc = 0;
    uVar3 = 0x40c00000;
    uVar1 = 0x3f800000;
    _DAT_007fd13c = DAT_0093b0cc;
    DAT_00803984 = 1;
    DAT_007fd11e = 0x2c;
    DAT_007fd120 = 0xffff;
    _DAT_007fd122 = 0xffff;
    _DAT_007fd140 = DAT_0093b0d0;
    _DAT_007fd144 = DAT_0093b0d4;
    _DAT_007faaa8 = 0x55;
    DAT_007fd148 = 0x2d;
    DAT_007fd14a = 0x2e;
  }
  else {
    _DAT_008030e8 = 0x3d99999a;
    DAT_008030e4 = 0;
    DAT_00803984 = 0;
    _DAT_007fd118 = 0xbe4ccccd;
    DAT_00876580 = 1;
    _DAT_007fd13c = 0;
    DAT_00950c48 = 1;
    _DAT_007fd140 = 0;
    DAT_00802454 = 1;
    DAT_00927038 = 1;
    _DAT_007fd144 = 0xbe049ba6;
    DAT_00955fb8 = 1;
    DAT_00955fbc = 1;
    uVar3 = 0x40400000;
    uVar1 = 0x3dcccccd;
    DAT_007fd11e = 0x2f;
    DAT_007fd120 = 0x30;
    _DAT_007fd122 = 0x31;
    _DAT_007faaa8 = 0x56;
    DAT_007fd148 = 0xffff;
    DAT_007fd14a = 0xffff;
  }
  _DAT_00804dc8 = 0x3e99999a;
  _DAT_00804dc4 = 0x3e99999a;
  _DAT_007fd124 = DAT_0093b0cc;
  _DAT_007fd128 = DAT_0093b0d0;
  _DAT_007fd12c = DAT_0093b0d4;
  _DAT_007fd134 = DAT_0093b0d0;
  _DAT_007fd138 = DAT_0093b0d4;
  DAT_007fd11c = _DAT_007faaa8;
  _DAT_007fd130 = _DAT_007fd124;
  FUN_00547a10(uVar1,uVar3);
  return;
}

