/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e5ba0; label: FUN_004e5ba0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5ba0(int param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if (DAT_00951b50 == 0) {
    _DAT_00889624 = *(undefined4 *)(DAT_0093d810 + 0x80);
    _DAT_00889628 = _DAT_0080014c;
    if (((*(float *)(DAT_0093d810 + 0x80) < -500.0) &&
        (_DAT_00889628 = _DAT_0080014c + _DAT_0080016c, DAT_0093b2a4 == 0)) && (DAT_00889630 == 0))
    {
      piVar6 = &DAT_00889618;
      do {
        if (*piVar6 != 0) {
          FUN_004364e0(*piVar6,4,0);
          *piVar6 = 0;
        }
        piVar6 = piVar6 + 1;
      } while ((int)piVar6 < 0x889624);
      FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"deathstarbattle_midtro_ingame",1);
      DAT_00889630 = 1;
    }
    fVar1 = *(float *)(DAT_0093d810 + 0x88);
    if (DAT_00889618 == 0) {
      _DAT_0088962c = 60.0;
    }
    else {
      _DAT_0088962c = 62.0;
    }
    if (DAT_00889620 == 0) {
      fVar2 = 72.0;
    }
    else {
      fVar2 = 70.0;
    }
    if ((_DAT_0088962c <= fVar1) && (_DAT_0088962c = fVar1, fVar2 < fVar1)) {
      _DAT_0088962c = fVar2;
    }
    if ((DAT_00876848 == '\0') &&
       (_DAT_00889634 = _DAT_00889634 - _DAT_00925018, _DAT_00889634 <= 0.0)) {
      iVar7 = 0;
      _DAT_00889634 = 5.0;
      do {
        local_c = *(float *)(DAT_0093d810 + 0x80) + _DAT_00800168;
        local_8 = *(float *)(DAT_0093d810 + 0x84) + _DAT_0080016c;
        local_4 = *(undefined4 *)(DAT_0093d810 + 0x88);
        local_18 = 0;
        local_14 = 0;
        local_10 = 0.0;
        fVar1 = _DAT_00800154;
        if (iVar7 != 0) {
          fVar1 = local_10;
          if (iVar7 == 1) {
            local_14 = _DAT_00800150;
          }
          else if (iVar7 == 2) {
            fVar1 = -_DAT_00800154;
          }
        }
        local_10 = fVar1;
        FUN_005b37d0(&local_c,&local_c,&local_18);
        if ((DAT_00889630 != 0) || (sVar3 = DAT_007f196c, iVar7 != 1)) {
          sVar3 = DAT_007f1970;
        }
        iVar4 = FUN_0043d890((int)sVar3,&local_c,0xc000,"TrenchBaddie",DAT_0093d810 + 0x420,0,0,0,0,
                             0,1);
        if (iVar4 != 0) {
          *(uint *)(iVar4 + 0xef8) = *(uint *)(iVar4 + 0xef8) | 4;
          *(undefined1 **)(iVar4 + 0xea8) = &LAB_004e5b70;
          *(code **)(iVar4 + 0x10b0) = FUN_004e5770;
          (&DAT_00889618)[iVar7] = iVar4;
          *(undefined4 *)(iVar4 + 0xe84) = local_18;
          *(undefined4 *)(iVar4 + 0xe88) = local_14;
          *(float *)(iVar4 + 0xe8c) = local_10;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 3);
    }
  }
  if (DAT_0087aa24 == '\0') {
    iVar7 = FUN_005cfd60(&DAT_0087aad8);
    if (iVar7 != 0) {
      uVar5 = FUN_005cf9e0(&DAT_0087aad8);
      FUN_00681f40("ffield",uVar5);
      return;
    }
    uVar5 = FUN_005cf9e0(&DAT_0087aad8);
    FUN_00681f40("ffieldoff",uVar5);
    DAT_0087aa24 = '\x01';
  }
  return;
}

