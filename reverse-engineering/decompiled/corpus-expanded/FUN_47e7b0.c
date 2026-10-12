/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47e7b0; label: FUN_0047e7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047e7b0(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  bool bVar7;
  int *piVar8;
  int local_2c4;
  int local_2c0;
  int local_2bc;
  int local_2b8;
  int local_2b4;
  uint local_2b0;
  short local_2ac [340];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2c4;
  if ((0.0 < _DAT_00950780) || (0.0 < _DAT_00950678)) {
    __security_check_cookie(local_4 ^ (uint)&local_2c4);
    return;
  }
  local_2b0 = (uint)*(char *)(DAT_00951b78 + 0xa3 + DAT_00879588 * 0x130);
  iVar4 = DAT_00951b78 + DAT_00879588 * 0x130;
  iVar6 = 0;
  if ((DAT_0087b02c == 0) || (*(byte *)(DAT_0087b02c + 0x7c) != local_2b0)) {
    local_2c4 = 0;
  }
  else {
    local_2c4 = 1;
  }
  switch(DAT_00879514) {
  case 0:
    bVar7 = false;
    local_2b8 = 0;
    local_2b4 = 0;
    local_2c0 = 0;
    if (local_2c4 == 0) {
      uVar1 = *(ushort *)(local_2b0 * 0x9c + 0x7a + DAT_00951354);
      local_2bc = 0;
      if (((uVar1 & 0x1000) == 0) && (local_2bc = 1, (uVar1 & 0x10) != 0)) {
        local_2bc = 2;
      }
    }
    else {
      local_2bc = 1;
    }
    puVar5 = &DAT_009253b8;
    do {
      if (bVar7) goto LAB_0047e915;
      if (local_2c0 != 0) goto LAB_0047ea34;
      if ((&DAT_0087b6c8)[iVar6] != '\0') {
        uVar2 = *puVar5;
        if ((DAT_008022c4 & uVar2) == 0) {
          if ((DAT_008022c8 & uVar2) == 0) {
            if (((DAT_00802290 & puVar5[2]) == 0) && ((DAT_00802290 & uVar2) == 0)) {
              if (((DAT_00802294 & puVar5[2]) != 0) || ((DAT_00802294 & uVar2) != 0)) {
                local_2b8 = 1;
              }
            }
            else {
              local_2b4 = 1;
            }
          }
          else {
            local_2c0 = 1;
          }
        }
        else {
          bVar7 = true;
        }
      }
      puVar5 = puVar5 + 0x18;
      iVar6 = iVar6 + 1;
    } while ((int)puVar5 < 0x925478);
    if (bVar7) {
LAB_0047e915:
      if (local_2c4 == 0) {
        FUN_00547930(0x30,0,0,0);
        uVar2 = local_2b0;
        if (DAT_0087951c != 0) {
          if (DAT_0087951c == 1) {
            if ((*(byte *)(local_2b0 * 0x9c + 0x7a + DAT_00951354) & 1) == 0) {
              iVar4 = -1;
              iVar6 = -1;
            }
            else {
              iVar3 = FUN_00594b70(&DAT_00855ed0,0x4002000,0x2000,local_2ac,&local_2b4,&local_2b8,0)
              ;
              iVar4 = local_2b4;
              iVar6 = local_2b8;
              if (iVar3 == 1) {
                DAT_0087b6c4 = local_2ac[0];
                DAT_00879514 = 1;
                DAT_0087b6c6 = DAT_0087b6c4;
                goto LAB_0047e936;
              }
            }
          }
          else {
            if (DAT_0087951c != 2) break;
            iVar4 = -1;
            iVar6 = -1;
          }
          DAT_008795a4 = 0;
          FUN_0047ba10(uVar2,iVar4,iVar6);
          FUN_00509830(0x11,0xffffffff,0xffffffff);
          break;
        }
        DAT_00879514 = 2;
      }
      else {
        FUN_00547930(0x30,0,0,0);
        DAT_00879514 = 4;
      }
    }
    else {
      if (local_2c0 == 0) {
        if (local_2b4 == 0) {
          if (((local_2b8 == 0) || (local_2bc <= DAT_0087951c)) ||
             ((local_2c4 == 0 && ((&DAT_0086e0f5)[local_2b0 * 0xc] == '\0')))) break;
          iVar4 = DAT_0087951c + 1;
        }
        else {
          if (DAT_0087951c < 1) break;
          iVar4 = DAT_0087951c + -1;
        }
        bVar7 = iVar4 != DAT_0087951c;
        DAT_0087951c = iVar4;
        if (bVar7) {
          FUN_00547930(0x2f,0,0,0);
        }
        break;
      }
LAB_0047ea34:
      FUN_00547930(0x31,0,0,0);
      DAT_00879514 = 3;
    }
LAB_0047e936:
    _DAT_0087959c = 0.0;
    _DAT_00879500 = 0.6;
    break;
  case 1:
    _DAT_0087959c = _DAT_00925018 + _DAT_0087959c;
    if (_DAT_00879500 < _DAT_0087959c != (_DAT_00879500 == _DAT_0087959c)) {
      FUN_00489150((int)DAT_0087b6c4,(int)DAT_0087b6c6,(int)*(char *)(iVar4 + 0xa3),0xffffffff,1);
      DAT_00855f7c = 2;
      DAT_0093b29c = 1;
      DAT_0093b2a4 = 1;
      DAT_00951b80 = FUN_005735a0(DAT_00879588);
      piVar8 = &local_2c0;
      local_2c0 = 3;
LAB_0047eb9f:
      DAT_0087b2c0 = 1;
      FUN_005b1220(piVar8,0);
      DAT_00802e14 = 0;
      __security_check_cookie(local_4 ^ (uint)&local_2c4);
      return;
    }
    break;
  case 2:
    _DAT_0087959c = _DAT_00925018 + _DAT_0087959c;
    if ((_DAT_00879500 < _DAT_0087959c != (_DAT_00879500 == _DAT_0087959c)) && (DAT_00951b80 == 0))
    {
      piVar8 = &local_2c4;
      DAT_0093b29c = 0;
      DAT_0093b2a4 = 0;
      local_2c4 = 3;
      DAT_00951b80 = iVar4;
      goto LAB_0047eb9f;
    }
    break;
  case 3:
    _DAT_0087959c = _DAT_00925018 + _DAT_0087959c;
    if (_DAT_00879500 < _DAT_0087959c != (_DAT_00879500 == _DAT_0087959c)) {
      FUN_00474fd0();
      __security_check_cookie(local_4 ^ (uint)&local_2c4);
      return;
    }
    break;
  case 4:
    _DAT_0087959c = _DAT_00925018 + _DAT_0087959c;
    if (_DAT_00879500 < _DAT_0087959c != (_DAT_00879500 == _DAT_0087959c)) {
      DAT_00951b80 = DAT_00951b94;
      DAT_007fac20 = DAT_0087951c;
      if (DAT_0087951c == 1) {
        DAT_0086e4e5 = 1;
        __security_check_cookie(local_4 ^ (uint)&local_2c4);
        return;
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_2c4);
  return;
}

