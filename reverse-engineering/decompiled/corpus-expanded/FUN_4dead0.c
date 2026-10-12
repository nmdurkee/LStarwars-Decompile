/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dead0; label: FUN_004dead0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dead0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int local_18;
  undefined **local_14 [4];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_18;
  local_18 = param_1;
  local_14[0] = &PTR_DAT_007ffe80;
  local_14[1] = &PTR_DAT_007ffec0;
  local_14[2] = (undefined **)0x7fff00;
  if (DAT_00951b50 == 0) {
    if ((3 < DAT_00888ed4 + 1) && (_DAT_00888ed8 < 3.0)) {
      _DAT_00888ed8 = _DAT_00888ed8 + _DAT_00925018;
      __security_check_cookie(DAT_00829570 ^ (uint)&local_18 ^ (uint)&local_18);
      return;
    }
    DAT_00888ed4 = DAT_00888ed4 + 1;
    if (DAT_00888ed4 == 6) {
      DAT_00888ed4 = 7;
    }
    switch((int)DAT_00888ed4) {
    case 1:
    case 2:
    case 3:
      ppuVar6 = local_14[DAT_00888ed4 + -1];
      while (((ppuVar6 != (undefined **)0x0 && (*ppuVar6 != (undefined *)0x0)) && (DAT_00888ed2 < 8)
             )) {
        _sprintf((char *)local_14,"phase%d_%d",(int)DAT_00888ed4,DAT_00888ed2 + 1);
        puVar1 = (undefined4 *)FUN_0051ac10(*(undefined4 *)(local_18 + 0x2ae8),local_14);
        if (puVar1 != (undefined4 *)0x0) {
          puVar7 = puVar1;
          puVar9 = (undefined4 *)(&DAT_00888bec + DAT_00888ed2 * 0x60);
          for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          uVar2 = FUN_0043d890((int)*(short *)*ppuVar6,puVar1 + 4,puVar1[7],ppuVar6[1],puVar1 + 8,0,
                               1,0,0,0,0);
          (&DAT_00888be4)[DAT_00888ed2 * 0x18] = uVar2;
          if ((&DAT_00888be4)[DAT_00888ed2 * 0x18] != 0) {
            *(int *)(&DAT_00888be0 + DAT_00888ed2 * 0x30) = (int)*(short *)*ppuVar6;
            *(undefined4 **)((&DAT_00888be4)[DAT_00888ed2 * 0x18] + 0x36c) = puVar1;
            *(uint *)((&DAT_00888be4)[DAT_00888ed2 * 0x18] + 0xeec) =
                 *(uint *)((&DAT_00888be4)[DAT_00888ed2 * 0x18] + 0xeec) | 0x1000000;
            *(code **)((&DAT_00888be4)[DAT_00888ed2 * 0x18] + 0xea8) = FUN_004de9d0;
            DAT_00888ed2 = DAT_00888ed2 + 1;
          }
        }
        ppuVar6 = ppuVar6 + 2;
      }
      break;
    case 4:
    case 5:
    case 6:
      iVar5 = 0;
      _DAT_00888fa0 = 0;
      _DAT_00888fa4 = 0;
      if (0 < DAT_00888ed0) {
        puVar3 = &DAT_00882c2c;
        do {
          *puVar3 = *puVar3 & 0xffffffe7;
          iVar5 = iVar5 + 1;
          puVar3 = puVar3 + 0x18;
        } while (iVar5 < DAT_00888ed0);
      }
      iVar5 = 0;
      do {
        iVar8 = (int)DAT_00888ed0;
        iVar4 = FUN_005b9e90(0);
        iVar4 = iVar4 % iVar8;
        if (DAT_00888ed4 == 4) {
LAB_004ded58:
          iVar10 = (int)DAT_007f1894;
        }
        else if (DAT_00888ed4 == 5) {
          iVar10 = (int)DAT_007f1904;
          if (iVar5 < 3) goto LAB_004ded58;
        }
        else if (iVar5 < 3) {
          iVar10 = (int)DAT_007f1900;
        }
        else {
          iVar10 = (int)DAT_007f1904;
        }
        while (((((&DAT_00882c2c)[iVar4 * 0x18] & 8) != 0 ||
                (((&DAT_00882c2c)[iVar4 * 0x18] & 2) == 0)) ||
               ((&DAT_00882be0)[iVar4 * 0x18] == iVar10))) {
          iVar4 = iVar4 + 1;
          if (iVar8 <= iVar4) {
            iVar4 = 0;
          }
        }
        if ((&DAT_00882be4)[iVar4 * 0x18] != 0) {
          FUN_0055cad0((&DAT_00882be4)[iVar4 * 0x18],1);
          (&DAT_00882c2c)[iVar4 * 0x18] = (&DAT_00882c2c)[iVar4 * 0x18] & 0xfffffffe;
          (&DAT_00882be4)[iVar4 * 0x18] = 0;
        }
        (&DAT_00882be0)[iVar4 * 0x18] = iVar10;
        (&DAT_00888f94)[iVar5] = (short)iVar10;
        (&DAT_00882c2c)[iVar4 * 0x18] = (&DAT_00882c2c)[iVar4 * 0x18] | 8;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 6);
      _DAT_00888fac = 0;
    }
    if (DAT_00888f7c == 0) {
      DAT_00888f7c = FUN_005aac00(DAT_0095df4c,"Phase",0);
    }
    if (DAT_00888f80 == 0) {
      DAT_00888f80 = FUN_005aac00(DAT_0095df4c,"PhaseComplete",0);
    }
    if (DAT_00888f84 == 0) {
      DAT_00888f84 = FUN_005aac00(DAT_0095df4c,"ObjectivesLeft",0);
    }
    if (DAT_00888f88 == 0) {
      DAT_00888f88 = FUN_005aac00(DAT_0095df4c,"RestrainPadme",0);
    }
    if (DAT_00888f8c == 0) {
      DAT_00888f8c = FUN_005aac00(DAT_0095df4c,"RestrainAnakin",0);
    }
    if (DAT_00888f90 == 0) {
      DAT_00888f90 = FUN_005aac00(DAT_0095df4c,"RestrainObiWan",0);
    }
    *(float *)(DAT_00888f7c + 0x28) = (float)(int)DAT_00888ed4;
    local_18 = (int)DAT_00888ed2;
    *(float *)(DAT_00888f84 + 0x28) = (float)local_18;
    *(undefined4 *)(DAT_00888f80 + 0x28) = 0;
    _DAT_00888ed8 = 0.0;
    DAT_00888ed6 = 1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
}

