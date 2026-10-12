/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d8ec0; label: FUN_004d8ec0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8ec0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int local_11c;
  int local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  int aiStack_100 [64];
  
  iVar10 = 0;
  iVar8 = 0x10;
  iVar4 = DAT_0093d504;
  do {
    if ((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
        ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) && (iVar4 != DAT_00882a68)) {
      aiStack_100[iVar10] = iVar4;
      iVar10 = iVar10 + 1;
    }
    iVar1 = iVar4 + 0x10d8;
    if (((iVar1 != 0) && ((*(uint *)(iVar4 + 0x12d4) & 1) != 0)) &&
       (((*(uint *)(iVar4 + 0x12d4) & 0x1000) != 0 && (iVar1 != DAT_00882a68)))) {
      aiStack_100[iVar10] = iVar1;
      iVar10 = iVar10 + 1;
    }
    iVar1 = iVar4 + 0x21b0;
    if (((iVar1 != 0) && ((*(uint *)(iVar4 + 0x23ac) & 1) != 0)) &&
       (((*(uint *)(iVar4 + 0x23ac) & 0x1000) != 0 && (iVar1 != DAT_00882a68)))) {
      aiStack_100[iVar10] = iVar1;
      iVar10 = iVar10 + 1;
    }
    iVar1 = iVar4 + 0x3288;
    if ((((iVar1 != 0) && ((*(uint *)(iVar4 + 0x3484) & 1) != 0)) &&
        ((*(uint *)(iVar4 + 0x3484) & 0x1000) != 0)) && (iVar1 != DAT_00882a68)) {
      aiStack_100[iVar10] = iVar1;
      iVar10 = iVar10 + 1;
    }
    iVar4 = iVar4 + 0x4360;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (DAT_00951b50 != 0) {
    bVar6 = 0;
    pfVar9 = (float *)&DAT_008824c8;
    do {
      uVar5 = 1 << (bVar6 & 0x1f);
      uVar7 = (int)uVar5 >> 0x1f;
      if (((uVar5 & _DAT_008827c8) != 0 || (uVar7 & _DAT_008827cc) != 0) &&
         ((uVar5 & _DAT_008827d0) == 0 && (uVar7 & _DAT_008827d4) == 0)) {
        iVar8 = 0;
        local_104 = _DAT_008823d4 * _DAT_007ffcfc;
        if (0 < iVar10) {
          do {
            iVar4 = aiStack_100[iVar8];
            if (iVar4 != 0) {
              local_110 = *(float *)(iVar4 + 0x80) - *pfVar9;
              local_108 = *(float *)(iVar4 + 0x88) - pfVar9[2];
              fVar2 = *(float *)(iVar4 + 0x1dc) + local_104;
              if (local_108 * local_108 + local_110 * local_110 < fVar2 * fVar2) {
                FUN_004d8e40(iVar4);
                _DAT_008827d0 = _DAT_008827d0 | uVar5;
                _DAT_008827d4 = _DAT_008827d4 | uVar7;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar10);
        }
      }
      bVar6 = bVar6 + 1;
      pfVar9 = pfVar9 + 3;
    } while ((int)pfVar9 < 0x8827c8);
    return;
  }
  pfVar9 = (float *)&DAT_00881ce8;
  local_114 = 0;
  local_11c = 0x40;
  do {
    if (pfVar9[-5] != 0.0) {
      FUN_005b3800(&local_110,pfVar9 + -4,PTR_DAT_008021b4 + 0x11c);
      if (0.0 <= *(float *)(PTR_DAT_008021b4 + 0x118) * local_108 +
                 *(float *)(PTR_DAT_008021b4 + 0x110) * local_110 +
                 *(float *)(PTR_DAT_008021b4 + 0x114) * local_10c) {
        fVar2 = pfVar9[-1] + _DAT_00925018;
        pfVar9[-1] = fVar2;
        fVar3 = _DAT_007ffcfc;
        fVar2 = (_DAT_007ffcfc * fVar2) / _DAT_007ffcf8;
        *pfVar9 = fVar2;
        if (fVar3 < fVar2) {
          *pfVar9 = fVar3;
        }
        iVar8 = 0;
        local_104 = *pfVar9 * _DAT_008823d4;
        if (0 < iVar10) {
          do {
            iVar4 = aiStack_100[iVar8];
            if (iVar4 != 0) {
              local_110 = *(float *)(iVar4 + 0x80) - pfVar9[-4];
              local_108 = *(float *)(iVar4 + 0x88) - pfVar9[-2];
              fVar2 = *(float *)(iVar4 + 0x1dc) + local_104;
              if (local_108 * local_108 + local_110 * local_110 < fVar2 * fVar2) {
                if (*(char *)(iVar4 + 0x280) == -1) {
                  FUN_00437390(iVar4,2,1,0);
                }
                else {
                  FUN_004d8d70();
                  if (*(char *)(iVar4 + 0x28b) == '\0') goto LAB_004d9144;
                }
                aiStack_100[iVar8] = 0;
              }
            }
LAB_004d9144:
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar10);
        }
      }
      else {
        uVar5 = ~(1 << (((char)(local_114 / 0x1c) + (char)(local_114 >> 0x1f)) -
                        (char)((longlong)local_114 * 0x92492493 >> 0x3f) & 0x1fU));
        _DAT_00882a48 = _DAT_00882a48 & uVar5;
        _DAT_00882a4c = _DAT_00882a4c & (int)uVar5 >> 0x1f;
        _DAT_008827e4 = _DAT_008827e4 + -1;
        pfVar9[-5] = 0.0;
        pfVar9[-4] = 0.0;
        pfVar9[-3] = 0.0;
        pfVar9[-2] = 0.0;
        pfVar9[-1] = 0.0;
        *pfVar9 = 0.0;
        pfVar9[1] = 0.0;
      }
    }
    local_114 = local_114 + 0x1c;
    pfVar9 = pfVar9 + 7;
    local_11c = local_11c + -1;
    if (local_11c == 0) {
      return;
    }
  } while( true );
}

