/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x491d50; label: FUN_00491d50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491d50(undefined4 *param_1)

{
  float fVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  int local_2c;
  undefined4 *local_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  FUN_00549450();
  FUN_0055fac0(param_1);
  FUN_005f9e90(DAT_007fac24);
  if (DAT_0093b328 == 0) {
    FUN_0043b940(param_1[0xaba]);
  }
  _DAT_00950f68 = 0;
  DAT_00802c60 = 0xffffffff;
  _DAT_00950f64 = 0;
  FUN_004c00c0();
  FUN_0046c7d0();
  FUN_0054b0b0(PTR_DAT_00802c54);
  if (((((DAT_00921e58 != 0) && (DAT_00921dfc != 0)) &&
       ((param_1 == (undefined4 *)0x0 ||
        ((param_1[0x4b] == 0 || ((*(byte *)(param_1[0x4b] + 0x7a) & 2) == 0)))))) &&
      ((DAT_0087658c == 0 &&
       (((DAT_00951b80 == 0 && (_DAT_00950780 == 0.0)) && (DAT_0087b4d8 == 0)))))) &&
     (((DAT_00926bd4 == (code *)0x0 || (iVar4 = (*DAT_00926bd4)(), iVar4 == 0)) &&
      (((DAT_00951be0 == 0 || (iVar4 = FUN_0057cf70(DAT_00951be8), iVar4 != 0)) &&
       ((DAT_00855de0 == 0 && (DAT_00951c58 == 0)))))))) {
    if ((&DAT_00921454)[DAT_00800944 * 0x70] == -1) {
      if (DAT_0093b328 == 0) {
        piVar8 = &DAT_0093d7f0;
        do {
          iVar4 = *piVar8;
          if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0x1fc) & 0x80) != 0)) {
            FUN_0055c120((*(int *)(iVar4 + 0xca4) + -0x9253b0) / 0x60);
            break;
          }
          piVar8 = piVar8 + 1;
        } while ((int)piVar8 < 0x93d7f8);
      }
    }
    else {
      iVar4 = FUN_0050b310();
      if (((iVar4 == 0) && ((&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7] != 1))
         && ((&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7] != 4)) {
        FUN_00509830(0x3f3,0,0xffffffff);
      }
      else {
        DAT_00921dfc = 0;
        DAT_00921e58 = 0;
      }
    }
  }
  local_30 = _DAT_00925018;
  local_38 = DAT_009253b0;
  local_28 = &local_38;
  local_34 = DAT_00925410;
  local_2c = DAT_0093b328;
  local_24 = 2;
  (**(code **)(*DAT_0095e418 + 0x20))(&local_30);
  if (DAT_02962034 == 0) {
    uVar2 = DAT_008668ce;
    if ((DAT_0093b328 != 0) && ((&DAT_00921454)[DAT_00800944 * 0x70] == 4)) {
      uVar2 = DAT_0087656e;
    }
    FUN_00698820(uVar2,0);
    FUN_00698e70();
    FUN_00548690(param_1,DAT_0093b328);
    if (((DAT_008668cd == '\0') || (DAT_0093d7f4 == 0)) ||
       ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = **(undefined4 **)(DAT_0093d7f4 + 0xca4);
    }
    if (((DAT_008668cc == '\0') || (DAT_0093d7f0 == 0)) ||
       ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = **(undefined4 **)(DAT_0093d7f0 + 0xca4);
    }
    FUN_00698930(uVar5,uVar6);
    FUN_00698920(_DAT_00925018);
    FUN_00653460(_DAT_00925018);
    FUN_00548c40(param_1[0x4a],&DAT_008668cc);
  }
  if (DAT_0093d7f0 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = DAT_0093d7f0 + 0x19c;
  }
  if (DAT_0093d7f4 == 0) {
    iStack_20 = 0;
  }
  else {
    iStack_20 = DAT_0093d7f4 + 0x19c;
  }
  if (DAT_0093d7f8 == 0) {
    iStack_1c = 0;
  }
  else {
    iStack_1c = DAT_0093d7f8 + 0x19c;
  }
  if (DAT_0093d7fc == 0) {
    iStack_18 = 0;
  }
  else {
    iStack_18 = DAT_0093d7fc + 0x19c;
  }
  if (DAT_0093d800 == 0) {
    iStack_14 = 0;
  }
  else {
    iStack_14 = DAT_0093d800 + 0x19c;
  }
  if (DAT_0093d804 == 0) {
    iStack_10 = 0;
  }
  else {
    iStack_10 = DAT_0093d804 + 0x19c;
  }
  if (DAT_0093d808 == 0) {
    iStack_c = 0;
  }
  else {
    iStack_c = DAT_0093d808 + 0x19c;
  }
  if (DAT_0093d80c == 0) {
    iStack_8 = 0;
  }
  else {
    iStack_8 = DAT_0093d80c + 0x19c;
  }
  if (((DAT_0093b328 == 0) || (DAT_00950744 != 0)) || (cVar3 = FUN_00565bf0(), cVar3 != '\0')) {
    FUN_005d4770(0);
    FUN_0063dcd0(_DAT_00925018);
    DAT_0087b924 = 0;
    FUN_00552ac0();
    FUN_005d3490(0xffff);
    FUN_0057ed70(param_1);
    if ((DAT_0093b328 == 0) || (cVar3 = FUN_00565bf0(), cVar3 != '\0')) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    FUN_0057ef50(param_1,uVar6);
    FUN_00428a40(&DAT_00856c0c);
    if ((*(byte *)(param_1[0x4a] + 100) & 8) != 0) {
      FUN_0068ed90();
    }
    FUN_0059f740(param_1[0xab3],_DAT_00925018);
    if (param_1[0x119c] != 0) {
      FUN_0043d0c0(param_1[0x119c]);
    }
    if (param_1[0x4f] != 0) {
      FUN_005f4b90(param_1[0x4f],_DAT_00925018 * 60.0);
    }
    FUN_005a1780(param_1[0xa58]);
    FUN_00686950(0x3f800000);
    FUN_00544420(&DAT_0093d620);
    if (DAT_00947bbc != 0) {
      FUN_00546380(&local_24);
      FUN_00545a80(&local_24);
    }
    FUN_00637860(param_1[0xaad],_DAT_00925018);
    FUN_0058baf0(param_1[0xab7]);
    FUN_00471650(param_1);
    FUN_004d4980(param_1[0x145a]);
    FUN_00559c60(param_1[0xab2],param_1,_DAT_00925018);
    if ((*(byte *)(param_1[0x4a] + 100) & 8) != 0) {
      FUN_0066cc60();
    }
    FUN_005b1b10(param_1);
    FUN_004ce5f0(param_1);
    if (DAT_00951be0 == 0) {
      FUN_00430430();
      FUN_00434a20(param_1);
    }
    else {
      piVar8 = &DAT_0093d7f0;
      do {
        iVar4 = *piVar8;
        if (((iVar4 != 0) && ((*(byte *)(iVar4 + 0x1fc) & 0x80) != 0)) &&
           (**(int **)(iVar4 + 0xca4) != 0)) {
          FUN_0054a810(*(int **)(iVar4 + 0xca4) + 0x10);
        }
        piVar8 = piVar8 + 1;
      } while ((int)piVar8 < 0x93d810);
    }
    FUN_0058b3a0();
    if (DAT_00951be0 == 0) {
      iVar4 = FUN_0056e160(0x2c);
      if (iVar4 == 0) {
        _DAT_00856c10 = 0;
      }
      FUN_004ce630(param_1);
      FUN_005a3050(param_1[0x1414]);
      FUN_00426fa0();
      FUN_00405ac0();
      FUN_00408af0();
      FUN_0057a4d0(param_1);
      FUN_00583030(param_1);
      FUN_0064eb00(_DAT_00925018);
      if (0.0 < _DAT_00951000) {
        _DAT_00951000 = _DAT_00951000 - _DAT_00925018;
      }
      if (0.0 < _DAT_00879364) {
        _DAT_00879364 = _DAT_00879364 - _DAT_00925018;
      }
      if (0.0 < _DAT_0087b8c0) {
        _DAT_0087b8c0 = _DAT_0087b8c0 - _DAT_00925018;
      }
      if (0.0 < _DAT_00924ddc) {
        _DAT_00924ddc = _DAT_00924ddc - _DAT_00925018;
      }
      if (0.0 < _DAT_00876830) {
        _DAT_00876830 = _DAT_00876830 - _DAT_00925018;
      }
      if (0.0 < _DAT_00876834) {
        _DAT_00876834 = _DAT_00876834 - _DAT_00925018;
      }
      FUN_0056ee80();
      FUN_0059ff80(*(undefined4 *)(*(int *)(param_1[0x4d] + 8) + 0x30c),
                   *(undefined4 *)(*(int *)(param_1[0x4d] + 8) + 800),0xb4);
      FUN_005488a0();
      FUN_00559cd0(param_1[0xab2],param_1,_DAT_00925018);
      FUN_004bcb10();
      FUN_005769d0(_DAT_00925018);
      FUN_0056e570();
    }
    FUN_00495310(&DAT_009253b0,1);
    FUN_00690610(0);
    if (DAT_00951be0 == 0) {
      FUN_0042f4a0();
    }
    FUN_005a25e0(DAT_00876688);
    FUN_005a82c0(param_1,0x7a);
    FUN_005e4e00(0x3f800000);
    FUN_005e4ea0(0xffff);
    FUN_0040ade0(PTR_DAT_008021b4);
    FUN_0055d1e0();
    FUN_0054a0d0();
    if (DAT_00951be0 == 0) {
      FUN_005a3bd0(_DAT_00925018);
    }
    if ((((param_1[0x4b] != 0) && (param_1[0x4b] == DAT_00951364)) ||
        ((iVar4 = param_1[0x4a], iVar4 == DAT_00951b88 ||
         ((iVar4 == DAT_00951b98 || ((*(uint *)(iVar4 + 100) & 0x400) != 0)))))) ||
       (iVar4 == DAT_00951b9c)) {
      FUN_00564ac0(_DAT_00925018);
    }
  }
  else {
    FUN_005e4e00(0);
    FUN_005d3490(2);
    FUN_005d4770(1);
    puVar7 = (undefined4 *)(PTR_DAT_008021b4 + 0xb8);
    puVar9 = DAT_00925164;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    FUN_00603cc0(DAT_00925164);
    FUN_00495310(&DAT_009253b0,1);
    piVar8 = &DAT_0093d7f0;
    do {
      iVar4 = *piVar8;
      if (iVar4 != 0) {
        FUN_00570a80(*(undefined4 *)(iVar4 + 0x7fc),*(uint *)(iVar4 + 0x1fc) >> 7 & 1,
                     (int)*(char *)(iVar4 + 0x280));
      }
      piVar8 = piVar8 + 1;
    } while ((int)piVar8 < 0x93d7f8);
    FUN_00690610(1);
  }
  if (*(code **)(param_1[0x4a] + 0x78) != (code *)0x0) {
    (**(code **)(param_1[0x4a] + 0x78))(param_1);
  }
  FUN_005606d0(param_1);
  FUN_00565670();
  if ((DAT_0093b328 == 0) || (DAT_0087b4d8 != 0)) {
    fVar1 = _DAT_00925018 / 0.016666668;
  }
  else {
    fVar1 = 0.0;
  }
  FUN_005f9940(fVar1);
  FUN_005f9530();
  FUN_00549050(param_1,&DAT_0086e4e8);
  FUN_004b71a0();
  *param_1 = 0;
  FUN_00565230(param_1[0x4a] + 0x84,&DAT_009506f0);
  if (((DAT_0087658c != 0) || (DAT_00951b80 != 0)) && (_DAT_00950780 == 0.0)) {
    if ((((param_1[0x4a] != 0) && ((*(uint *)(param_1[0x4a] + 100) & 0x400) != 0)) &&
        ((DAT_00951b94 != 0 && ((DAT_00951b80 != DAT_00951b94 && (DAT_00951b80 != 0)))))) &&
       ((*(char *)(DAT_00951b80 + 0xa3) != -1 &&
        ((*(byte *)(*(char *)(DAT_00951b80 + 0xa3) * 0x9c + 0x7a + DAT_00951354) & 2) == 0)))) {
      _DAT_00950780 = 1.0;
      DAT_00802e14 = 0;
      return;
    }
    if ((DAT_009507a0 == -1) ||
       (((DAT_00951b80 != 0 && (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_00951b80)) &&
        (DAT_00951b80 == DAT_00951b94)))) {
      FUN_005b1220(&stack0x00000000,0);
    }
    FUN_005b11b0(2);
  }
  return;
}

