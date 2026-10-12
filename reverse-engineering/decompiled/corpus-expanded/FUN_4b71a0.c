/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b71a0; label: FUN_004b71a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b71a0(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  float10 fVar7;
  float local_8;
  ushort local_4;
  
  if ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) == 0) {
    return;
  }
  uVar6 = 0;
  if ((((_DAT_00950780 == 0.0) && (DAT_00951be0 == 0)) && (DAT_0087b738 == 0)) &&
     (((DAT_00951364 == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)) ||
      (PTR_DAT_008021b4[0x22c] != '\x04')))) {
    uVar6 = 0x3f800000;
  }
  fVar7 = (float10)FUN_0054fad0(_DAT_0087b928,uVar6,_DAT_00925018);
  _DAT_0087b928 = (float)fVar7;
  if (DAT_0093b2a8 == 0) {
    if (DAT_00856c08 == 0) {
      if (0.0 < _DAT_0087b934) goto LAB_004b728f;
    }
    else {
      _DAT_0087b934 = 2.0;
LAB_004b728f:
      _DAT_0087b934 = _DAT_0087b934 - _DAT_00925018;
    }
    local_8 = 0.0;
    if (((_DAT_00950780 == 0.0) && (DAT_00951be0 == 0)) &&
       (((DAT_0093b328 != 0 || ((DAT_0093b32c != 0 || (0.0 < _DAT_0087b934)))) &&
        (DAT_00950744 == 0)))) {
      local_8 = 1.0;
    }
    if (DAT_00856c08 != 0) {
      fVar7 = (float10)FUN_00457ec0();
      if (0.0 < (float)fVar7) {
        local_8 = (1.0 - (float)fVar7) * local_8;
      }
    }
    fVar7 = (float10)FUN_0054fad0(_DAT_0087b99c,local_8,_DAT_00925018);
    _DAT_0087b99c = (float)fVar7;
    fVar7 = (float10)FUN_0054fad0(_DAT_00955fc0,0x3f800000,_DAT_00925018 * 5.0);
    _DAT_00955fc0 = (float)fVar7;
    uVar6 = 0;
    if (DAT_00856c08 == 0) {
      if (0.0 < _DAT_0087b944) {
        _DAT_0087b944 = _DAT_0087b944 - _DAT_00925018;
      }
      if ((((_DAT_00950780 == 0.0) && (DAT_00951be0 == 0)) &&
          ((DAT_0093b328 != 0 ||
           (((DAT_0093b32c != 0 &&
             ((DAT_0095122c != 0 ||
              ((*(int *)(PTR_DAT_00802c54 + 0x120) != -1 &&
               ((&DAT_0086e0fa)[*(int *)(PTR_DAT_00802c54 + 0x120) * 0xc] != '\0')))))) ||
            (0.0 < _DAT_0087b944)))))) && (DAT_00950744 == 0)) {
        uVar6 = 0x3f800000;
      }
      fVar7 = (float10)FUN_0054fad0(_DAT_0087b974,uVar6,_DAT_00925018);
      _DAT_0087b974 = (float)fVar7;
      fVar7 = (float10)FUN_0054fad0(_DAT_0087b948,0x3f800000,_DAT_00925018 * 5.0);
      _DAT_0087b948 = (float)fVar7;
      uVar6 = 0;
      if (0.0 < _DAT_0087b94c) {
        _DAT_0087b94c = _DAT_0087b94c - _DAT_00925018;
      }
      if ((((_DAT_00950780 == 0.0) && (DAT_00951be0 == 0)) &&
          ((DAT_0093b328 != 0 ||
           (((DAT_0093b32c != 0 || (0.0 < _DAT_0087b94c)) || (DAT_0087b980 != 0)))))) &&
         (DAT_00950744 == 0)) {
        uVar6 = 0x3f800000;
      }
      fVar7 = (float10)FUN_0054fad0(_DAT_0087b978,uVar6,_DAT_00925018);
      _DAT_0087b978 = (float)fVar7;
      uVar4 = ~-(uint)(DAT_0093b338 != 0) & DAT_0093b2a4;
      if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
         ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x10) != 0)) {
        if (DAT_0093b314 == 0) {
          iVar5 = *(int *)(PTR_DAT_00802c54 + 0x120) * 0xc;
          if ((&DAT_0086e0f6)[iVar5] != '\0') goto LAB_004b76b2;
          cVar1 = (&DAT_0086e0f7)[iVar5];
        }
        else {
          cVar1 = (&DAT_0086e0f6)[*(int *)(PTR_DAT_00802c54 + 0x120) * 0xc + uVar4];
        }
        if ((cVar1 == '\0') &&
           (uVar4 = *(uint *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x8c + uVar4 * 4), uVar4 != 0)) {
          if (DAT_0087b980 == 0) {
            DAT_0087b994 = 0;
            if ((DAT_0093d7f0 != 0) && (*(uint **)(DAT_0093d7f0 + 0x7fc) != (uint *)0x0)) {
              DAT_0087b994 = **(uint **)(DAT_0093d7f0 + 0x7fc);
            }
            if ((DAT_0093d7f4 != 0) && (*(int **)(DAT_0093d7f4 + 0x7fc) != (int *)0x0)) {
              DAT_0087b994 = DAT_0087b994 + **(int **)(DAT_0093d7f4 + 0x7fc);
            }
            if (uVar4 <= DAT_0087b994) {
              _DAT_0087b92c = 2.5;
              DAT_0087b980 = 1;
              FUN_00561b20(*(undefined4 *)(DAT_00926c20 + DAT_008807f8 * 4),0,0,0x3f800000,
                           0x3f800000,1,0);
            }
          }
          fVar7 = (float10)FUN_0054fad0(_DAT_0087b92c,0x3f800000,_DAT_00925018 * 3.0);
          _DAT_0087b92c = (float)fVar7;
        }
      }
      goto LAB_004b76b2;
    }
  }
  else {
    _DAT_0087b934 = 0.0;
    _DAT_00955fc0 = 1.0;
  }
  _DAT_0087b978 = 0.0;
  _DAT_0087b94c = 0.0;
  _DAT_0087b948 = 1.0;
  _DAT_0087b92c = 1.0;
  _DAT_0087b974 = 0.0;
  _DAT_0087b944 = 0.0;
LAB_004b76b2:
  fVar2 = 0.0;
  if (((DAT_0093b2a8 != 0) &&
      (fVar3 = 1.0, (*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x2000) != 0)) ||
     (fVar3 = _DAT_0087b940, 0.0 < _DAT_0087b940)) {
    _DAT_0087b940 = fVar3;
    _DAT_0087b940 = _DAT_0087b940 - _DAT_00925018;
  }
  if (((_DAT_00950780 == 0.0) && (DAT_00951be0 == 0)) &&
     (((DAT_0093b328 == 0 && ((DAT_0093b32c == 0 && (fVar3 = fVar2, _DAT_0087b940 <= 0.0)))) ||
      (fVar3 = 1.0, DAT_00950744 == 0)))) {
    fVar2 = fVar3;
  }
  fVar7 = (float10)FUN_0054fad0(_DAT_0087b970,fVar2,_DAT_00925018);
  _DAT_0087b970 = (float)fVar7;
  fVar7 = (float10)FUN_0054fad0(_DAT_0087b93c,0x3f800000,_DAT_00925018 * 3.0);
  _DAT_0087b93c = (float)fVar7;
  if ((DAT_00951364 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)) {
    fVar7 = (float10)0;
  }
  else {
    if (((DAT_0093b328 == 0) && (DAT_0093b32c == 0)) || (iVar5 = FUN_0050b310(), iVar5 != 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x3f800000;
    }
    fVar7 = (float10)FUN_0054fad0(_DAT_0087b9a0,uVar6,_DAT_00925018);
  }
  _DAT_0087b9a0 = (float)fVar7;
  if ((DAT_0093b328 == 0) && (DAT_0093b32c == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  FUN_00475ad0(uVar6);
  if ((DAT_0093b328 == 0) && (DAT_0093b32c == 0)) {
    local_4 = (ushort)(int)ROUND((float)DAT_00879360 + _DAT_00925018 * 16384.0);
    DAT_00879360 = local_4;
    local_4 = (ushort)(int)ROUND((float)DAT_00879362 + _DAT_00925018 * 16384.0);
    DAT_00879362 = local_4;
  }
  iVar5 = 0;
  do {
    local_8 = 0.0;
    if (((DAT_0093b328 == 0) && (*(int *)((int)&DAT_0093d7f0 + iVar5) != 0)) &&
       (*(float *)(*(int *)((int)&DAT_0093d7f0 + iVar5) + 0xd60) <= 0.0)) {
      local_8 = 1.0;
    }
    fVar7 = (float10)FUN_0054fad0(*(undefined4 *)((int)&DAT_00879358 + iVar5),local_8,
                                  _DAT_00925018 + _DAT_00925018);
    *(float *)((int)&DAT_00879358 + iVar5) = (float)fVar7;
    iVar5 = iVar5 + 4;
  } while (iVar5 < 8);
  return;
}

