/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a6c30; label: FUN_004a6c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a6c30(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined2 uVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float afStack_c [2];
  float fStack_4;
  
  if (0.0 < *(float *)(in_EAX + 0xd58)) {
    *(float *)(in_EAX + 0xd58) = *(float *)(in_EAX + 0xd58) - _DAT_00925018;
  }
  if (((((DAT_007f3b14 != -1) ||
        ((((cVar1 = *(char *)(in_EAX + 0x7b5), cVar1 != -1 && (cVar1 != '*')) && (cVar1 != '6')) &&
         (cVar1 != ':')))) || (*(char *)(in_EAX + 0x28b) != '\0')) ||
      ((((cVar1 == '6' &&
         (fVar3 = 1.0 - *(float *)(in_EAX + 0x77c) / *(float *)(in_EAX + 0x784), 0.2 < fVar3)) &&
        (fVar3 < 0.666)) || ((param_4 != 0 && (0.0 < *(float *)(in_EAX + 0xd58))))))) ||
     ((param_1 == 0 && ((param_2 == 0 || (0.0 < *(float *)(in_EAX + 0xd58))))))) {
    return;
  }
  uVar5 = FUN_00407e40();
  iVar6 = FUN_005806a0(uVar5,PTR_DAT_00802c54);
  if ((*(byte *)(in_EAX + 0x1fc) & 0x80) == 0) goto LAB_004a71b7;
  (**(code **)(PTR_PTR_008040bc + 0x14))();
  if ((_DAT_009543f4 == 0.0) || (_DAT_009543f8 == 0.0)) {
    fVar3 = *(float *)(iVar6 + 0x14) * *(float *)(iVar6 + 0x10);
  }
  else {
    fVar3 = _DAT_009543f4 * _DAT_009543f8;
  }
  uVar2 = *(undefined2 *)(in_EAX + 0x7aa);
  *(undefined2 *)(in_EAX + 0x7aa) = 2;
  (**(code **)(PTR_PTR_008040bc + 0x10))();
  iVar7 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar7 == 0) || (iVar7 != DAT_0087b01c)) {
    if (((*(uint *)(iVar6 + 0x60) & 0x800) == 0) && ((iVar7 == 0 || (iVar7 != DAT_0087af84)))) {
      iVar7 = FUN_00433df0();
      if (iVar7 == 0) {
        iVar7 = FUN_0046a450(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54);
        if (iVar7 == 0) {
          iVar7 = FUN_0056a240();
          if (iVar7 == 0) {
            iVar7 = FUN_00572020();
            if (iVar7 == 0) {
              if ((*(uint *)(iVar6 + 0x60) & 0x400) != 0) {
                *(float *)(in_EAX + 0xc80) =
                     *(float *)(in_EAX + 0x68) * *(float *)(iVar6 + 0x14) +
                     fStack_24 + fVar3 * local_30;
                *(float *)(in_EAX + 0xc88) =
                     *(float *)(in_EAX + 0x70) * *(float *)(iVar6 + 0x14) +
                     fStack_28 * fVar3 + fStack_1c;
                if (*(char *)(in_EAX + 0x107a) == '\x04') {
                  fStack_20 = *(float *)(in_EAX + 0x6c) * *(float *)(iVar6 + 0x14) +
                              fVar3 * fStack_2c + fStack_20;
                }
                *(float *)(in_EAX + 0xc84) = fStack_20;
                *(undefined4 *)(in_EAX + 0xc8c) = DAT_0093b0cc;
                *(undefined4 *)(in_EAX + 0xc90) = DAT_0093b0d0;
                *(undefined4 *)(in_EAX + 0xc94) = DAT_0093b0d4;
                goto LAB_004a719d;
              }
            }
            else {
              FUN_004a5fe0();
            }
          }
          else {
            FUN_004a5f70();
          }
        }
      }
      else {
        FUN_004a5ec0();
        if ((DAT_00951288 != 0) && ((*(uint *)(*(int *)(iVar7 + 0x54) + 4) & 0x2000) != 0)) {
          iVar8 = FUN_005be2d0(*(undefined4 *)(iVar7 + 0x68),*(undefined4 *)(iVar7 + 0x70));
          FUN_005b3620(afStack_c,&DAT_0080250c,iVar8 + 0x4000);
          fVar4 = ABS(afStack_c[0] * local_30 + fStack_4 * fStack_28) * 0.5 *
                  *(float *)(iVar6 + 0x14);
          fStack_18 = *(float *)(iVar7 + 0x80) + fVar4 * *(float *)(iVar7 + 0x68);
          fStack_14 = *(float *)(iVar7 + 0x6c) * fVar4 + *(float *)(iVar7 + 0x84);
          fStack_10 = fVar4 * *(float *)(iVar7 + 0x70) + *(float *)(iVar7 + 0x88);
          FUN_005b3800(&fStack_18,&fStack_18,&fStack_24);
          FUN_005b3b30(&fStack_18,&fStack_18);
          FUN_005b3830(&fStack_18,&fStack_18,fVar3);
          FUN_005b37d0(in_EAX + 0xc80,&fStack_24,&fStack_18);
        }
      }
    }
  }
  else if ((*(short *)(in_EAX + 0x1064) == DAT_007f19f8) ||
          (*(short *)(in_EAX + 0x1064) == DAT_007f19fc)) {
    iVar6 = -1;
    if (DAT_0093d814 != 0) {
      if (in_EAX == DAT_0093d810) {
        iVar6 = 0;
      }
      else if (in_EAX == DAT_0093d814) {
        iVar6 = 1;
      }
    }
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0e0) {
      iVar7 = DAT_007fc08c;
      if ((iVar6 != 0) && (iVar7 = DAT_007fc088, iVar6 == 1)) {
        iVar7 = DAT_0087b914;
      }
    }
    else {
      iVar7 = DAT_007fc080;
      if ((iVar6 != 0) && (iVar7 = DAT_007fc084, iVar6 != 1)) {
        iVar7 = DAT_007fc07c;
      }
    }
    local_30 = 0.0;
    fStack_2c = 0.0;
    fStack_28 = 100.0;
    FUN_005b35a0(&local_30,&local_30,(iVar7 * 0x10000) / 0x168);
    FUN_005b3620(&local_30,&local_30,*(undefined2 *)(in_EAX + 0x5a));
    FUN_005b37d0(in_EAX + 0xc80,&fStack_24,&local_30);
    *(undefined4 *)(in_EAX + 0xc8c) = DAT_0093b0cc;
    *(undefined4 *)(in_EAX + 0xc90) = DAT_0093b0d0;
    *(undefined4 *)(in_EAX + 0xc94) = DAT_0093b0d4;
LAB_004a719d:
    *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x800;
  }
  *(undefined2 *)(in_EAX + 0x7aa) = uVar2;
LAB_004a71b7:
  FUN_0049d430(uVar5,3);
  *(undefined4 *)(in_EAX + 0xd58) = param_3;
  *(bool *)(in_EAX + 0xe3a) = *(char *)(in_EAX + 0xe3a) == '\0';
  return;
}

