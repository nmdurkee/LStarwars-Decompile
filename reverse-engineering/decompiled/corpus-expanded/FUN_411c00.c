/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x411c00; label: FUN_00411c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411c00(void)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_68;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  local_68 = 35.0;
  if (((DAT_0093d7f0 != 0) && (iVar2 = DAT_0093d7f0, (*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0))
     || (iVar2 = DAT_0093d7f4, DAT_0093d7f4 != 0)) {
    local_5c = *(undefined4 *)(iVar2 + 0x5c);
    local_58 = *(undefined4 *)(iVar2 + 0x60);
    local_54 = *(undefined4 *)(iVar2 + 100);
  }
  FUN_005b4670(local_40,0x2000);
  FUN_005b5160(local_40,0x2000);
  local_44 = 0x3f800000;
  iVar2 = 0;
  do {
    switch(iVar2) {
    case 0:
    case 6:
      local_50 = -35.0;
      local_4c = 0.0;
      local_48 = 0.0;
      break;
    case 1:
    case 7:
      local_50 = 35.0;
      local_4c = 0.0;
      local_48 = 0.0;
      break;
    case 2:
    case 8:
      local_4c = -35.0;
      local_50 = 0.0;
      local_48 = 0.0;
      break;
    case 3:
    case 9:
      local_4c = 35.0;
      local_50 = 0.0;
      local_48 = 0.0;
      break;
    case 4:
    case 10:
      local_48 = -35.0;
      local_50 = 0.0;
      local_4c = 0.0;
      break;
    case 5:
    case 0xb:
      local_48 = 35.0;
      local_50 = 0.0;
      local_4c = 0.0;
    }
    if (5 < iVar2) {
      FUN_005c03e0(&local_50,&local_50,local_40);
    }
    iVar1 = FUN_0067b430(&local_5c,&local_50,0,0x3f800000,0,0);
    if (iVar1 != 0) {
      fVar3 = (float10)FUN_005c0240(local_48 * local_48 + local_50 * local_50 + local_4c * local_4c)
      ;
      local_50 = (float)fVar3;
      if (local_50 < local_68) {
        local_68 = local_50;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc);
  if (local_68 < 35.0) {
    local_68 = 1.0 - local_68 / 35.0;
    FUN_00549bb0(PTR_DAT_008021b4,local_68 * _DAT_007f1624 + _DAT_00855e7c,0x3e4ccccd,
                 _DAT_007f161c * local_68 + _DAT_007f1620);
    local_68 = local_68 * 0.5;
    if (0.35 < local_68) {
      local_68 = 0.35;
    }
    FUN_0054a910(local_68,0,0,0);
  }
  _DAT_00855e78 = _DAT_00855e78 - _DAT_00925018;
  if (_DAT_00855e78 < 0.0) {
    FUN_00549de0(PTR_DAT_008021b4,0x3e4ccccd,2,0);
    FUN_0054a910(0x3e99999a,0,0,0);
    fVar3 = (float10)FUN_005b9dd0();
    _DAT_00855e78 = (float)(fVar3 * (float10)10.0 + (float10)3.0);
  }
  return;
}

