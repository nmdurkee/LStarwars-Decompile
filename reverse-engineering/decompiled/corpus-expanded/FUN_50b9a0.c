/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b9a0; label: FUN_0050b9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050b9a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 fVar7;
  
  fVar6 = (float10)FUN_004f3bb0();
  iVar2 = DAT_00921e68;
  iVar1 = DAT_00921e64;
  fVar7 = (float10)0;
  fVar6 = (float10)(float)fVar6;
  if (fVar7 < (float10)_DAT_0080159c) {
    _DAT_0080159c = (float)((float10)_DAT_0080159c - fVar6);
  }
  if ((float10)_DAT_00921e28 <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e3c) {
      _DAT_00921e3c = (float)((float10)_DAT_00921e3c - fVar6);
    }
  }
  else {
    _DAT_00921e28 = (float)((float10)_DAT_00921e28 - fVar6);
  }
  if ((float10)_DAT_00921e2c <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e40) {
      _DAT_00921e40 = (float)((float10)_DAT_00921e40 - fVar6);
    }
  }
  else {
    _DAT_00921e2c = (float)((float10)_DAT_00921e2c - fVar6);
  }
  if ((float10)_DAT_00921df0 <= fVar7) {
    if ((fVar7 < (float10)_DAT_00921df4) &&
       (_DAT_00921df4 = (float)((float10)_DAT_00921df4 - fVar6), (float10)_DAT_00921df4 <= fVar7)) {
      DAT_00921df8 = 0;
    }
  }
  else {
    _DAT_00921df0 = (float)((float10)_DAT_00921df0 - fVar6);
  }
  if ((float10)_DAT_00921e30 <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e44) {
      _DAT_00921e44 = (float)((float10)_DAT_00921e44 - fVar6);
    }
  }
  else {
    _DAT_00921e30 = (float)((float10)_DAT_00921e30 - fVar6);
  }
  if ((float10)_DAT_00921e34 <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e48) {
      _DAT_00921e48 = (float)((float10)_DAT_00921e48 - fVar6);
    }
  }
  else {
    _DAT_00921e34 = (float)((float10)_DAT_00921e34 - fVar6);
  }
  if ((float10)_DAT_00921e38 <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e4c) {
      _DAT_00921e4c = (float)((float10)_DAT_00921e4c - fVar6);
    }
  }
  else {
    _DAT_00921e38 = (float)((float10)_DAT_00921e38 - fVar6);
  }
  if ((float10)_DAT_00921e50 <= fVar7) {
    if (fVar7 < (float10)_DAT_00921e54) {
      _DAT_00921e54 = (float)((float10)_DAT_00921e54 - fVar6);
    }
  }
  else {
    _DAT_00921e50 = (float)((float10)_DAT_00921e50 - fVar6);
  }
  if (DAT_00802008 != 2) {
    _DAT_00921e18 = 0;
  }
  if (DAT_00924818 != 0) {
    if (DAT_00921dec != 0) {
      _DAT_00921e40 = 1.5;
      DAT_00921de4 = 1;
    }
    DAT_00921dec = 0;
    _DAT_00921df0 = (float)fVar7;
    DAT_00921df8 = 0;
    _DAT_00921df4 = (float)fVar7;
    DAT_00921de8 = 0;
    DAT_00921dfc = 1;
    DAT_00924818 = 0;
  }
  if (DAT_00921dcc == 0) {
    if ((DAT_00921dd0 != 0) && (DAT_00924800 == 1)) {
      DAT_00921dd0 = 0;
      if (DAT_00924804 == 0) {
        iVar3 = FUN_0050b970(DAT_00921e64,DAT_00921e68);
        if (iVar3 == *(int *)(iVar2 + iVar1)) {
          FUN_004ef660(DAT_00921e60,iVar1,iVar2);
          fVar7 = (float10)0;
          DAT_00921d28 = 1;
        }
        else {
          DAT_00921dd8 = 1;
          DAT_00802014 = -1;
          fVar7 = extraout_ST0;
        }
      }
      else {
        DAT_00921dd4 = 1;
        DAT_00802014 = -1;
      }
    }
  }
  else if (((DAT_00924800 == 1) && (DAT_00802008 == 2)) && (DAT_00802010 != 0)) {
    _DAT_00921e28 = 1.5;
    if ((DAT_00921e64 == 0) || (DAT_00921e68 == 0)) {
      DAT_00921dd4 = 1;
      DAT_00921dcc = 0;
      DAT_00921dd0 = 0;
      return;
    }
    FUN_00543d90(DAT_00921dc0,DAT_00921e64,DAT_00921e68 + 4);
    fVar7 = (float10)0;
    DAT_00921dcc = 0;
    DAT_00921dd8 = 0;
    if (DAT_00924800 == 1) {
      DAT_00921dd0 = 0;
      DAT_00921dd4 = 1;
    }
    else {
      DAT_00921dd0 = 1;
      DAT_00921dd4 = 0;
    }
  }
  if (DAT_00921de8 == 0) {
    if (DAT_00921dec == 0) goto LAB_0050bd68;
    if (DAT_00921ddc != 0) goto LAB_0050bd83;
    if (DAT_00921de0 == 0) {
      if (fVar7 < (float10)_DAT_00921df0) goto LAB_0050beb0;
      DAT_00921dc0 = DAT_00802014;
      DAT_00921ddc = 1;
      goto LAB_0050bd83;
    }
  }
  else {
    DAT_00921de8 = 0;
    if (DAT_00802014 != -1) {
      DAT_00921dec = 1;
      _DAT_00921df0 = 1.0;
      DAT_00921df8 = 1;
    }
LAB_0050bd68:
    if (DAT_00921ddc != 0) {
LAB_0050bd83:
      if (((DAT_00924800 == 1) && (DAT_00802008 == 2)) && (DAT_00802010 != 0)) {
        _DAT_00921e2c = 1.5;
        if ((DAT_00921e64 == 0) || (DAT_00921e68 == 0)) {
          DAT_00921de4 = 1;
          DAT_00921ddc = 0;
          DAT_00921de0 = 0;
          return;
        }
        if (DAT_00921e70 == (code *)0x0) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = (*DAT_00921e70)();
        }
        if (DAT_00921dc0 != -1) {
          FUN_004ef660(DAT_00921e64,DAT_00921e60,DAT_00921e68);
          iVar2 = DAT_00921e68;
          iVar1 = DAT_00921e64;
          uVar5 = FUN_0050b970(DAT_00921e64,DAT_00921e68);
          *(undefined4 *)(iVar2 + iVar1) = uVar5;
          FUN_00543d40(DAT_00921dc0,DAT_00921e64,DAT_00921e68 + 4,uVar4);
        }
        DAT_00921ddc = 0;
        DAT_00921de0 = 1;
        DAT_00921de4 = 0;
        _DAT_00921e18 = 0;
      }
      goto LAB_0050beb0;
    }
    if (DAT_00921de0 == 0) goto LAB_0050beb0;
  }
  if (DAT_00924800 == 1) {
    DAT_00921de0 = 0;
    if (DAT_00924804 == 0) {
      _DAT_00921d30 = 1;
      if (DAT_00921e88 != (code *)0x0) {
        (*DAT_00921e88)();
      }
      if (DAT_00921dec == 0) goto LAB_0050beb0;
      _DAT_00921df4 = 1.0;
    }
    else {
      DAT_00921de4 = 1;
      if (DAT_00802014 != -1) {
        DAT_00924818 = 1;
        _DAT_00921e40 = 1.5;
        DAT_00802014 = -1;
        DAT_00921dfc = 1;
      }
      DAT_00921df8 = 0;
    }
    DAT_00921dec = 0;
  }
LAB_0050beb0:
  if (DAT_00921e00 == 0) {
    if ((DAT_00921e04 != 0) && (DAT_00924800 == 1)) {
      DAT_00921e04 = 0;
      DAT_00921e08 = 0;
      if (DAT_00924804 != 0) {
        DAT_00921e08 = 1;
      }
    }
  }
  else if (((DAT_00924800 == 1) && (DAT_00802008 == 2)) && (DAT_00802010 != 0)) {
    FUN_00543e30(DAT_00921dc0);
    _DAT_00921e38 = 1.5;
    DAT_00921e00 = 0;
    DAT_00921e04 = 1;
    DAT_00921e08 = 0;
  }
  if (DAT_00921e0c == 0) {
    if ((DAT_00921e10 != 0) && (DAT_00924800 == 3)) {
      DAT_00921e10 = 0;
      if (DAT_00924804 == 0) {
        _DAT_00921e18 = 1;
        return;
      }
      DAT_00921e14 = 1;
    }
  }
  else if ((DAT_00924800 == 1) && (DAT_00802008 == 2)) {
    FUN_00543e20();
    _DAT_00921e30 = 1.5;
    DAT_00921e10 = 1;
    DAT_00921e0c = 0;
    DAT_00921e14 = 0;
    _DAT_00921e18 = 0;
    return;
  }
  return;
}

