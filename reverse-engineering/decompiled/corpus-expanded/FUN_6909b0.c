/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x6909b0; label: FUN_006909b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006909b0(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    FUN_00620ef0(param_1);
  }
  if ((*(uint *)(param_1 + 0x70) & 0x100) != 0) {
    if (DAT_02947c14 == -1) {
      FUN_0065d540(0xbf800000);
    }
    else {
      if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
        do {
          DAT_02947c14 = DAT_02947c14 + 1;
          if (DAT_02947c14 == 0x40) {
            DAT_02947c14 = 0;
          }
        } while ((&DAT_02947d98)[DAT_02947c14 * 0x11] == -1);
      }
      if ((*(byte *)(param_1 + 0x78) & 2) != 0) {
        do {
          DAT_02947c14 = DAT_02947c14 + -1;
          if (DAT_02947c14 == -1) {
            DAT_02947c14 = 0x3f;
          }
        } while ((&DAT_02947d98)[DAT_02947c14 * 0x11] == -1);
      }
    }
    if (DAT_02947c14 != -1) {
      FUN_00620f10(&DAT_02947d9c + DAT_02947c14 * 0x44);
      DAT_0296297c = (int)(short)(&DAT_02947db0)[DAT_02947c14 * 0x22];
      _DAT_00810a28 = (float)(&DAT_02947da8)[DAT_02947c14 * 0x11];
      _DAT_02962980 = (int)(short)(&DAT_02947db2)[DAT_02947c14 * 0x22];
      _DAT_00810a2c = (float)(&DAT_02947dac)[DAT_02947c14 * 0x11];
      _DAT_00810a30 = (int)(char)(&DAT_02947db5)[DAT_02947c14 * 0x44];
      _DAT_00810a34 = (int)(char)(&DAT_02947db6)[DAT_02947c14 * 0x44];
      DAT_02920d80 = (&DAT_02947db8)[DAT_02947c14 * 0x11];
      DAT_0292fdb4 = (&DAT_02947dbc)[DAT_02947c14 * 0x11];
    }
  }
  FUN_00620fa0(&DAT_02924abc,&DAT_02921868,&DAT_0292fb60);
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
      FUN_00690830();
      DAT_02962954 = DAT_02962958;
    }
    if (((*(byte *)(param_1 + 0x78) & 0x40) != 0) && (DAT_02920d80 != -1)) {
      FUN_0065d880(&DAT_02924abc);
    }
    if (((*(byte *)(param_1 + 0x70) & 0x20) != 0) && (DAT_02947c14 != -1)) {
      FUN_0065d7d0(DAT_02947c14,&DAT_02924abc);
    }
    if ((*(byte *)(param_1 + 0x78) & 0x10) != 0) {
      if (DAT_02947c14 != -1) {
        FUN_0065d950(DAT_02947c14);
      }
      DAT_02947c14 = -1;
    }
  }
  if (DAT_02962984 == 0) {
    _DAT_02962980 = _DAT_02962980 + (uint)*(byte *)(param_1 + 0x94);
    _DAT_02962980 = _DAT_02962980 - (uint)*(byte *)(param_1 + 0x95);
    iVar1 = DAT_0296297c + (uint)*(byte *)(param_1 + 0x96);
    if (0x4000 < iVar1) {
      iVar1 = 0x2000;
    }
    DAT_0296297c = iVar1 - (uint)*(byte *)(param_1 + 0x97);
    if (DAT_0296297c < -0x4000) {
      DAT_0296297c = 0xffffe000;
      return;
    }
  }
  else if (DAT_02962984 == 1) {
    _DAT_00810a28 =
         (_DAT_00810a28 + (float)*(byte *)(param_1 + 0x96) / 2500.0) -
         (float)*(byte *)(param_1 + 0x97) / 2500.0;
    if (0.1 <= _DAT_00810a28) {
      if (20.0 < _DAT_00810a28) {
        _DAT_00810a28 = 20.0;
      }
    }
    else {
      _DAT_00810a28 = 0.1;
    }
    _DAT_00810a2c =
         (_DAT_00810a2c + (float)*(byte *)(param_1 + 0x94) / 5000.0) -
         (float)*(byte *)(param_1 + 0x95) / 5000.0;
    if (_DAT_00810a2c < 0.1) {
      _DAT_00810a2c = 0.1;
      return;
    }
    if (20.0 < _DAT_00810a2c) {
      _DAT_00810a2c = 5.0;
    }
  }
  return;
}

