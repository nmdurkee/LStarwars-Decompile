/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c74e0; label: FUN_004c74e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004c74e0(undefined4 param_1)

{
  int iVar1;
  float10 fVar2;
  
  FUN_004c15e0();
  _DAT_0087bd7c = 0;
  _DAT_0087bd80 = 0x3ecccccd;
  _DAT_0087bd84 = 0x3f4ccccd;
  _DAT_0087bd8c = 0x3f4ccccd;
  _DAT_0087bd90 = 0x3ecccccd;
  _DAT_0087bd94 = 0;
  if ((_DAT_0087bd78 < 1.0) &&
     (_DAT_0087bd78 = _DAT_00925018 + _DAT_00925018 + _DAT_0087bd78, 1.0 < _DAT_0087bd78)) {
    _DAT_0087bd78 = 1.0;
  }
  fVar2 = (float10)FUN_0054fad0(_DAT_0087c570,0x3f800000,_DAT_00925018 * 3.0);
  _DAT_0087c570 = (float)fVar2;
  _DAT_008800a4 = _DAT_007fcbc4;
  _DAT_0087bbb8 = _DAT_007fcbc8;
  if (DAT_008800a0 == (code *)0x0) {
    if (DAT_008800b8 == 0) {
      DAT_008800a0 = FUN_004c6e90;
      _DAT_008800e4 = 0x3e000000;
      DAT_00880494 = 0;
      DAT_0087c574 = 1;
      DAT_008801ac = 0;
      DAT_00880490 = 0;
      DAT_008800e0 = FUN_004c6400;
      DAT_00880154 = 0;
      DAT_008801c0 = 0;
      DAT_0087c4e0 = 0;
      DAT_008800f8 = 0;
    }
    else {
      _DAT_0087c55c = _DAT_0087ff94;
      DAT_008800b8 = 0;
      _DAT_0087bf30 = _DAT_0087c484;
      DAT_0087c4e0 = DAT_008800fc;
      DAT_008801c0 = DAT_008800ac;
      DAT_008800a0 = DAT_0088000c;
      DAT_008801c4 = DAT_008800b0;
      DAT_0087c4e8 = DAT_00880104;
      DAT_0087c4e4 = DAT_00880100;
      DAT_008800e0 = DAT_0088041c;
      DAT_0087bf8c = DAT_0087bf34;
      DAT_008801c8 = DAT_008800b4;
      DAT_00880154 = DAT_008800f4;
      DAT_008801ac = DAT_0087ffe4;
      DAT_008800f8 = DAT_0087c4f8;
    }
  }
  iVar1 = FUN_004c4110(param_1);
  return iVar1 != 0;
}

