/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x577950; label: FUN_00577950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577950(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float10 fVar6;
  float local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  ushort local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  local_34 = (uint)DAT_0095188e;
  local_30 = (uint)DAT_00951890;
  local_2c = _DAT_00951888;
  local_3c = 0.0;
  uVar4 = (uint)DAT_0095188c;
  local_38 = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = DAT_009518c4;
  local_14 = DAT_009518e4;
  local_18 = DAT_009518e0;
  local_10 = DAT_009518e8;
  while (local_1c = (ushort)uVar4, DAT_00951881 < DAT_00951880) {
    uVar3 = (uint)DAT_00951881;
    iVar1 = uVar3 * 0x1c;
    switch((&DAT_00951500)[uVar3 * 7]) {
    case 0:
      goto switchD_005779ec_caseD_0;
    case 1:
    case 3:
    case 4:
      local_3c = (float)(&DAT_00951504)[(uint)DAT_00951881 * 7];
    case 2:
      goto switchD_005779ec_caseD_2;
    case 5:
      local_3c = (float)(&DAT_00951504)[(uint)DAT_00951881 * 7];
      FUN_005775b0();
      goto switchD_005779ec_caseD_2;
    case 6:
      FUN_00577060(*(undefined4 *)(&DAT_00951508 + iVar1));
      fVar2 = _DAT_00951894;
      if (local_38 != 0) {
        local_1c = (ushort)(int)ROUND((double)local_38 * 0.0);
      }
      uVar5 = (uint)DAT_0095189a;
      uVar3 = (uint)DAT_0095189c;
      DAT_009518bc = DAT_0095188c;
      DAT_00951898 = local_1c;
      FUN_005775b0();
      if (local_1c == uVar4) {
        uVar4 = (uint)DAT_00951898;
      }
      if (uVar5 == local_34) {
        local_34 = (uint)DAT_0095189a;
      }
      if (uVar3 == local_30) {
        local_30 = (uint)DAT_0095189c;
      }
      if (local_2c == fVar2) {
        local_2c = _DAT_00951894;
      }
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 7:
      DAT_00951883 = (&DAT_00951508)[iVar1];
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 8:
      local_20 = *(int *)(&DAT_00951518 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 9:
      local_2c = (float)(&DAT_00951504)[uVar3 * 7];
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 10:
      uVar4 = *(uint *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0xb:
      local_34 = *(uint *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0xc:
      local_30 = *(uint *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0xd:
      local_38 = *(int *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0xe:
      local_28 = *(int *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0xf:
      local_24 = *(int *)(&DAT_00951508 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0x10:
      local_18 = *(undefined4 *)(&DAT_0095150c + iVar1);
      local_14 = *(undefined4 *)(&DAT_00951510 + iVar1);
      local_10 = *(undefined4 *)(&DAT_00951514 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    case 0x11:
      DAT_009518ec = *(undefined4 *)(&DAT_00951518 + iVar1);
      DAT_00951881 = DAT_00951881 + 1;
      break;
    default:
      DAT_00951881 = DAT_00951881 + 1;
      return;
    }
  }
switchD_005779ec_caseD_2:
  _DAT_009518f8 = _DAT_00925018 + _DAT_009518f8;
  if ((_DAT_009518f4 == 0.0) || (_DAT_009518f8 <= _DAT_009518f4)) {
    if (DAT_00951881 < DAT_00951880) {
      iVar1 = (&DAT_00951500)[(uint)DAT_00951881 * 7];
      if (iVar1 == 1) {
        if (_DAT_009518f0 < local_3c) {
          _DAT_009518f0 = _DAT_009518f0 + _DAT_00925018;
          return;
        }
        fVar6 = (float10)FUN_005becc0(PTR_DAT_008021b4 + 0xe8,DAT_009518c4,local_c);
        _DAT_00951888 = (float)fVar6;
        _DAT_009518b8 = _DAT_00951888;
        DAT_0095188c = *(short *)(PTR_DAT_008021b4 + 0x1f8) + -0x8000;
        DAT_0095188e = *(ushort *)(PTR_DAT_008021b4 + 0x1fc);
        DAT_009518e0 = *(undefined4 *)(PTR_DAT_008021b4 + 0x11c);
        DAT_009518e4 = *(undefined4 *)(PTR_DAT_008021b4 + 0x120);
        DAT_009518e8 = *(undefined4 *)(PTR_DAT_008021b4 + 0x124);
        DAT_009518bc = DAT_0095188c;
        DAT_009518be = DAT_0095188e;
        FUN_00577630();
        return;
      }
      if (iVar1 == 3) {
        if (local_3c <= _DAT_009518f0) {
          DAT_009514de = 0;
          FUN_00577710();
          _DAT_009514e8 = 0;
          if (_DAT_009514ec == 0.0) {
            PTR_DAT_008021b4[0x22c] = 0xff;
            FUN_00577630();
          }
          if (DAT_00855de0 != 0) {
            return;
          }
          FUN_00577630();
          return;
        }
        _DAT_009518f0 = _DAT_009518f0 + _DAT_00925018;
      }
      else {
        if ((iVar1 == 4) && (_DAT_009518f0 == 0.0)) {
          if (local_3c == 0.0) {
            _DAT_00951888 = local_2c;
            DAT_009518c4 = local_20;
            _DAT_009518c8 = DAT_0093b0cc;
            _DAT_009518cc = DAT_0093b0d0;
            _DAT_009518d0 = DAT_0093b0d4;
            DAT_009518e0 = local_18;
            DAT_009518e4 = local_14;
            DAT_009518e8 = local_10;
            DAT_0095188e = (ushort)local_34;
            DAT_00951890 = (ushort)local_30;
            DAT_0095188c = local_1c;
            FUN_005775b0();
            PTR_DAT_008021b4[0x22c] = 0xff;
          }
          else {
            DAT_00951898 = local_1c;
            if (local_38 != 0) {
              local_1c = (ushort)(int)ROUND((float)local_38 * local_3c);
              DAT_00951898 = local_1c;
            }
            DAT_009518bc = DAT_0095188c;
            if (local_28 == 0) {
              DAT_0095189a = (ushort)local_34;
            }
            else {
              local_1c = (ushort)(int)ROUND((float)local_28 * local_3c);
              DAT_0095189a = local_1c;
            }
            DAT_009518be = DAT_0095188e;
            if (local_24 == 0) {
              DAT_0095189c = (ushort)local_30;
            }
            else {
              local_1c = (ushort)(int)ROUND(local_3c * (float)local_24);
              DAT_0095189c = local_1c;
            }
            _DAT_00951894 = local_2c;
            DAT_009518c0 = DAT_00951890;
            _DAT_009518b8 = _DAT_00951888;
            if (local_20 != DAT_009518c4) {
              FUN_005b3800(&DAT_009518c8,DAT_009518c4,local_20);
              FUN_005b3830(&DAT_009518a0,&DAT_009518c8,1.0 / local_3c);
              DAT_009518c4 = local_20;
            }
            FUN_005b3800(&DAT_009518ac,&local_18,&DAT_009518e0);
            FUN_005b3830(&DAT_009518ac,&DAT_009518ac,1.0 / local_3c);
          }
        }
        _DAT_009518f0 = _DAT_009518f0 + _DAT_00925018;
        if (local_3c <= _DAT_009518f0) {
          FUN_005770e0(local_3c);
          FUN_00577630();
          FUN_00577710();
          return;
        }
      }
    }
    else {
      local_3c = 1e+09;
    }
    FUN_005770e0(local_3c);
    FUN_00577710();
  }
  else {
    FUN_005770e0(local_3c);
    FUN_00577710();
    _DAT_009514e8 = 0;
    if (_DAT_009514ec == 0.0) {
      PTR_DAT_008021b4[0x22c] = 0xff;
      FUN_00577630();
    }
    if (DAT_00855de0 == 0) {
      FUN_00577630();
      return;
    }
  }
switchD_005779ec_caseD_0:
  return;
}

