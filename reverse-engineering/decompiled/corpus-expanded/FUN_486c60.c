/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x486c60; label: FUN_00486c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486c60(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  float10 fVar9;
  
  fVar5 = _DAT_00925018;
  iVar8 = 0;
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  bVar4 = false;
  fVar9 = (float10)FUN_0054fad0(_DAT_0087b93c,0x3f800000,_DAT_00925018 * 3.0);
  _DAT_0087b93c = (float)fVar9;
  DAT_0087a32c = 0xffffffff;
  DAT_0087a1e0 = 0xffffffff;
  if (DAT_0093b338 != 0) {
    if (DAT_0093b338 != 1) {
      if (DAT_0093b338 != 2) {
        DAT_0087a1e0 = 0xffffffff;
        DAT_0087a32c = 0xffffffff;
        return;
      }
      if (8.0 < _DAT_0092505c == (_DAT_0092505c == 8.0)) {
        DAT_0087a1e0 = 0xffffffff;
        DAT_0087a32c = 0xffffffff;
        return;
      }
      SendMessageA(DAT_00924864,0x10,0,0);
      return;
    }
    if (_DAT_00950780 != 0.0) {
      DAT_0087a1e0 = 0xffffffff;
      DAT_0087a32c = 0xffffffff;
      return;
    }
    if (DAT_00951b80 != 0) {
      DAT_0087a1e0 = 0xffffffff;
      DAT_0087a32c = 0xffffffff;
      return;
    }
    puVar7 = &DAT_009253b8;
    do {
      if (bVar1) goto LAB_00486da3;
      if (bVar2) goto LAB_00486e0a;
      if (bVar3) goto LAB_00486e20;
      if ((&DAT_0087a6cc)[iVar8] != '\0') {
        uVar6 = *puVar7;
        if ((DAT_008022c4 & uVar6) == 0) {
          if (((DAT_00802290 & puVar7[2]) == 0) && ((DAT_00802290 & uVar6) == 0)) {
            if (((DAT_00802294 & puVar7[2]) != 0) || (bVar3 = bVar4, (DAT_00802294 & uVar6) != 0)) {
              bVar4 = true;
              bVar3 = true;
            }
          }
          else {
            bVar2 = true;
          }
        }
        else {
          bVar1 = true;
        }
      }
      puVar7 = puVar7 + 0x18;
      iVar8 = iVar8 + 1;
    } while ((int)puVar7 < 0x925478);
    if (!bVar1) {
      if (bVar2) {
LAB_00486e0a:
        if (DAT_0087a778 < 1) {
          DAT_0087a1e0 = 0xffffffff;
          DAT_0087a32c = 0xffffffff;
          return;
        }
        DAT_0087a778 = DAT_0087a778 + -1;
      }
      else {
        if (!bVar3) {
          DAT_0087a1e0 = 0xffffffff;
          DAT_0087a32c = 0xffffffff;
          return;
        }
LAB_00486e20:
        if (0 < DAT_0087a778) {
          DAT_0087a1e0 = 0xffffffff;
          DAT_0087a32c = 0xffffffff;
          return;
        }
        DAT_0087a778 = DAT_0087a778 + 1;
      }
      FUN_00547930(0x2f,0,0,0);
      return;
    }
LAB_00486da3:
    FUN_00547930(0x30,0,0,0);
    if (DAT_0087a778 == 0) {
      DAT_0093b338 = 2;
      DAT_00951b80 = DAT_00951b94;
      DAT_0087b71c = 1;
      return;
    }
    if (DAT_0087a778 != 1) {
      return;
    }
    SendMessageA(DAT_00924864,0x10,0,0);
    return;
  }
  if (DAT_0087a6dc == '\0') {
    DAT_0087a1e0 = 0xffffffff;
    DAT_0087a32c = 0xffffffff;
    return;
  }
  if (((DAT_0087a6e3 == '\0') || (DAT_0087a63c == 0)) || (DAT_0087a63c != DAT_0087af50)) {
    uVar6 = DAT_008022c4;
    if (DAT_0080235c != 0) {
      uVar6 = DAT_00802278;
    }
    if ((((DAT_0087a6cc != '\0') && ((DAT_009253b8 & uVar6) != 0)) ||
        ((DAT_0087a6cd != '\0' && ((DAT_00925418 & uVar6) != 0)))) ||
       (((byte)DAT_0087a6d8 & 2) != 0)) {
      if (DAT_0087a74c == 0) goto LAB_00486ee2;
      if (*(code **)(DAT_0087a74c + 8) != (code *)0x0) {
        (**(code **)(DAT_0087a74c + 8))(DAT_0087a74c,&DAT_0087a628);
      }
    }
  }
  if ((DAT_0087a74c != 0) && (*(code **)(DAT_0087a74c + 4) != (code *)0x0)) {
    (**(code **)(DAT_0087a74c + 4))(DAT_0087a74c,&DAT_0087a628,fVar5);
  }
LAB_00486ee2:
  FUN_00483840();
  if ((DAT_0087a6dc == '\0') && (5.0 < _DAT_0092505c != (_DAT_0092505c == 5.0))) {
    FUN_00486940(0);
    return;
  }
  return;
}

