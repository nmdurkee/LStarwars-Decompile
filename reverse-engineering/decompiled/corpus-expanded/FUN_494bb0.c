/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x494bb0; label: FUN_00494bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00494bb0(void)

{
  float fVar1;
  undefined4 *unaff_ESI;
  float10 fVar2;
  float local_8;
  
  if (DAT_008668d2 == '\0') {
    local_8 = 0.0;
  }
  else {
    fVar2 = (float10)FUN_00547a70(&DAT_0087656c);
    local_8 = (float)fVar2;
  }
  if (DAT_0087b5a0 != 0) {
    fVar1 = local_8;
    if (DAT_0087b5a0 == 1) {
      if (0.0 < _DAT_0087b6c0) {
        _DAT_0087b6c0 = _DAT_0087b6c0 - _DAT_00925018;
      }
      else {
        _DAT_0087b6d4 = _DAT_00925018 + _DAT_00925018 + _DAT_0087b6d4;
        if (1.0 < _DAT_0087b6d4) {
          DAT_0087b5a0 = 0;
          _DAT_0087b6d4 = 1.0;
        }
      }
    }
    else if (0.0 < _DAT_0087b6c0) {
      local_8 = 0.0;
      _DAT_0087b6c0 = _DAT_0087b6c0 - _DAT_00925018;
      fVar1 = 0.0;
      if (_DAT_0087b6c0 <= 0.0) {
        if (DAT_02962034 == 0) {
          FUN_00693fd0(0);
          FUN_00548e90();
          FUN_00652ad0();
        }
        FUN_005b2510(PTR_s_demointro_007fac08,&DAT_00924890,&DAT_00924894,_DAT_0092501c,0,
                     (float)DAT_008668d0 / 10.0);
        FUN_00566290(2);
        FUN_00548fb0(&DAT_0092505c,0);
        *unaff_ESI = 0;
        unaff_ESI[1] = 0;
        _DAT_0087b6d4 = 0.0;
        DAT_0087b5a0 = 1;
        _DAT_0087b6c0 = 0.5;
        fVar1 = local_8;
        if ((DAT_02962034 == 0) && (DAT_02962038 == 0)) {
          FUN_00693fd0(0);
          FUN_00548ae0(*(undefined4 *)(PTR_DAT_00802c54 + 0x128),0,&DAT_008668cc);
        }
      }
    }
    else if (DAT_0087b5a0 == 2) {
      _DAT_0087b6d4 = _DAT_0087b6d4 - (_DAT_00925018 + _DAT_00925018);
      if (0.0 < _DAT_0087b6d4) {
        fVar1 = _DAT_0087b6d4 * local_8;
      }
      else {
        _DAT_0087b6d4 = 0.0;
        _DAT_0087b6c0 = 0.1;
        fVar1 = local_8 * 0.0;
      }
    }
    local_8 = fVar1;
    FUN_00547a30(local_8);
    return 1;
  }
  FUN_00547a30(local_8);
  return 0;
}

