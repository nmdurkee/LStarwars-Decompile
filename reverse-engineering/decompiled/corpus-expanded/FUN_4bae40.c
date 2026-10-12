/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4bae40; label: FUN_004bae40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bae40(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  float10 extraout_ST0;
  undefined1 auStack_378 [60];
  float local_33c;
  float local_338;
  float local_334;
  float local_330;
  int local_32c;
  undefined4 local_328 [24];
  char local_2c8 [128];
  char local_248 [516];
  uint local_44;
  
  local_44 = DAT_00829570 ^ (uint)auStack_378;
  iVar2 = FUN_00574e20();
  FUN_0050e6a0();
  if (DAT_00951be0 == 0) {
    FUN_005612f0();
  }
  if ((DAT_00951364 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)) {
    FUN_004243b0();
  }
  if (DAT_00950744 == 0) {
    local_32c = DAT_0093b328;
  }
  else {
    local_32c = DAT_0093b2a0;
  }
  if (((DAT_0087b518 != 0) && (local_32c == 0)) &&
     ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0)) goto LAB_004bbbd9;
  if (DAT_0093d84c == -1) {
LAB_004bb08d:
    if ((DAT_009253d4 == '\0') || ((*(byte *)(DAT_009253b0 + 0x80) & 4) == 0)) {
      FUN_006d5040();
      FUN_004f47f0(0);
    }
    if (((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
       ((DAT_00925434 == '\0' || ((*(byte *)(DAT_00925410 + 0x80) & 4) == 0)))) {
      FUN_006d5040();
      FUN_004f47f0(1);
    }
    iVar3 = *(int *)(PTR_DAT_00802c54 + 0x128);
    if ((iVar3 == DAT_00951b98) || ((*(uint *)(iVar3 + 100) & 0x400) != 0)) {
      if (*(code **)(iVar3 + 0x80) != (code *)0x0) {
        (**(code **)(iVar3 + 0x80))();
      }
      FUN_00561400();
    }
    else if (DAT_007f3b14 == -1) {
      if ((((iVar2 != 0xf) && (iVar2 != 0x10)) && (iVar2 != 0x11)) && (DAT_00951be0 == 0)) {
        if (iVar2 == 0xc) {
          bVar7 = DAT_008569ac == 0;
LAB_004bb174:
          if (!bVar7) {
            FUN_004b9110();
          }
        }
        else {
          if (iVar2 == 0xd) {
            bVar7 = DAT_0087b748 == 0;
            goto LAB_004bb174;
          }
          if (iVar2 != 0xe) {
            bVar7 = iVar2 == 8;
            goto LAB_004bb174;
          }
        }
        if (((DAT_007f39e4 == 0) && (0.0 < _DAT_009250ac)) &&
           ((iVar2 = *(int *)(PTR_DAT_00802c54 + 0x128), (*(byte *)(iVar2 + 100) & 0xe0) == 0 &&
            ((iVar2 != DAT_00951b88 && (iVar2 != DAT_00951b9c)))))) {
          sVar1 = *(short *)(iVar2 + 0x60);
          if ((sVar1 == -1) || (sVar1 == DAT_008806a0)) {
            iVar2 = iVar2 + 0x40;
          }
          else {
            iVar2 = *(int *)(DAT_00926c20 + sVar1 * 4);
          }
          if (iVar2 != 0) {
            iVar3 = FUN_006e6b90();
            local_33c = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
            if (extraout_ST0 < (float10)_DAT_00950780) {
              local_33c = (float)(((float10)1 - ((float10)_DAT_00950780 - (float10)0.0)) *
                                 (float10)local_33c);
            }
            local_33c = (float)CONCAT22(local_33c._2_2_,in_FPUControlWord);
            local_338 = _DAT_007fc2c8 * _DAT_007fc2cc;
            FUN_0050d910(iVar2,(float)extraout_ST0,_DAT_007fc2c4,0x3f800000,local_338,_DAT_007fc2c8,
                         _DAT_007fc2c8,0,0xff,0xff,0xff,_DAT_007fc2d0,1,0,0);
          }
        }
        if (DAT_0087b9bc != 0) {
          FUN_004ba1f0();
        }
        if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364) {
LAB_004bb311:
          FUN_004b84d0();
        }
        else if (DAT_0093b2a8 == 0) {
          if (DAT_00951154 == 0) {
            if (DAT_00856c08 == 0) {
              iVar2 = FUN_0058a900();
              if (iVar2 != 0) {
                iVar2 = FUN_006e6b90();
                local_338 = (_DAT_007fc310 - _DAT_007fc314) *
                            (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + _DAT_007fc314;
                local_330 = (float)(uint)*(ushort *)
                                          (*DAT_009553d4 + 0x10 +
                                          *(char *)(DAT_009553d4[1] + 0x12) * 0x18);
                local_33c = (float)(int)local_330 - (float)DAT_009553d4[2];
                if (local_33c < 0.0) {
                  local_33c = 0.0;
                }
                FUN_0054bbc0();
                FUN_00511500(local_248,0,local_338,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,
                             0xff,0xbf);
                if (((local_32c == 0) && (iVar2 = FUN_0058aa40(DAT_009553d4), iVar2 != 0)) &&
                   (DAT_0093d810 != 0)) {
                  fVar8 = (float10)FUN_005b7d30(_DAT_00925064);
                  local_330 = (float)(int)ROUND((fVar8 + fVar8) * (float10)65536.0);
                  local_33c = (float)(&DAT_029899a0)[(uint)local_330 >> 1 & 0x7fff] * 0.2 + 0.8;
                  fVar8 = (float10)FUN_005b3c50();
                  local_330 = (float)fVar8;
                  if (DAT_0093d814 != 0) {
                    fVar8 = (float10)FUN_005b3c50();
                    local_334 = (float)fVar8;
                    if (local_334 < local_330) {
                      local_330 = local_334;
                    }
                  }
                  fVar8 = (float10)FUN_005c0240();
                  local_330 = (float)fVar8;
                  if (10.0 < local_330) {
                    local_330 = 10.0;
                  }
                  local_33c = (1.0 - local_330 / 10.0) * local_33c;
                  local_334 = 0.055 - local_338;
                  FUN_0055b830((int)*(short *)(*DAT_009553d4 +
                                              *(char *)(DAT_009553d4[1] + 0x12) * 0x18),0,local_334,
                               0,0x3e800000,0xa7,local_33c,local_33c,1);
                }
              }
            }
            else {
              local_338 = (float)(uint)*(ushort *)
                                        (*(int *)(PTR_DAT_00802c54 + 0x120) * 0x9c + 0x84 +
                                        DAT_00951354);
              local_33c = (float)(int)local_338 - _DAT_0085ea64;
              if (local_33c < 0.0) {
                local_33c = 0.0;
              }
              FUN_0054bbc0();
              iVar2 = FUN_006e6b90(0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,0xbf);
              local_338 = (_DAT_007fc310 - _DAT_007fc314) *
                          (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + _DAT_007fc314;
              FUN_00511500(local_248,0,local_338);
            }
          }
          else if (DAT_0093b324 == 0) {
            if (((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x100) != 0) &&
               (FUN_004b84d0(), _DAT_007fc380 != 2e+06)) {
              FUN_0054bb30(DAT_008668c4);
              FUN_004f1f10(local_248);
              FUN_004f1e80(local_248,local_2c8);
              FUN_004f1e80(local_248,&DAT_00755d70);
              local_338 = _DAT_007fc37c + _DAT_007fc380;
              FUN_0050c780(local_248,0,local_338,0x3f800000,0x3eb33333,0x3eb33333,0x3eb33333,0,0xff,
                           0xff,0xff);
            }
            if ((_DAT_00950780 == 0.0) &&
               ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0)) {
              iVar2 = FUN_006e6b90(_DAT_00925008,
                                   (&DAT_0086e0fc)[*(int *)(PTR_DAT_00802c54 + 0x120) * 3],0);
              local_338 = -((_DAT_007fc310 - _DAT_007fc314) *
                            (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + _DAT_007fc314);
              FUN_004b8320();
            }
          }
          else if ((DAT_0093b328 == 0) && (DAT_0093b32c == 0)) {
            FUN_00475b60();
          }
          else {
            FUN_00475b60();
          }
        }
        else if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x2000) != 0)
        goto LAB_004bb311;
      }
      if (DAT_009250b4 != 0) {
        FUN_006e6b90();
        _sprintf(local_248,"fps: %d");
        FUN_00511500(local_248,0x3f59999a,0xbf59999a,0x3f800000,0x3ecccccd,0x3ecccccd,0x3ecccccd,0xc
                     ,0xff,0xff,0xff);
      }
      if (DAT_00951be0 == 0) {
        if ((*(int *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x80) != 0) ||
           ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0)) {
          puVar4 = local_328;
          piVar5 = &DAT_0093d7f0;
          do {
            iVar2 = *piVar5;
            if (((iVar2 != 0) && ((*(byte *)(iVar2 + 0x1fc) & 0x80) != 0)) && (DAT_0087b714 != 0)) {
              _sprintf(local_248,"X:%.2f Y:%.2f Z:%.2f",(double)*(float *)(iVar2 + 0x5c),
                       (double)*(float *)(iVar2 + 0x60),(double)*(float *)(iVar2 + 100));
              FUN_0050c780(local_248,*puVar4,puVar4[1],0x3f800000,0x3ecccccd,0x3f000000,0x3f000000,0
                           ,0xff,0xbf,0,0x30);
            }
            iVar2 = local_32c;
            piVar5 = piVar5 + 1;
            puVar4 = puVar4 + 3;
          } while ((int)piVar5 < 0x93d810);
          FUN_00685770(local_32c,4);
          if (*(code **)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x80) != (code *)0x0) {
            (**(code **)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x80))();
          }
          FUN_00559db0();
          if (iVar2 == 0) {
            FUN_00576840();
            FUN_00561400();
          }
        }
      }
      else {
        FUN_0057e2c0();
      }
    }
LAB_004bba60:
    if (DAT_0087b4d8 == 0) {
      FUN_0050fed0();
    }
  }
  else {
    if ((DAT_0087b510 != 0) && (iVar3 = FUN_004feb90(), iVar3 != 0)) {
      if (DAT_0093d840 == 0) {
        _sprintf(local_2c8,"Loading \'\'%s\'\'");
        local_33c = (float)((uint)local_33c & 0xffffff00);
        local_330 = (float)CONCAT31(local_330._1_3_,0xff);
      }
      else {
        _sprintf(local_2c8,"Aborting \'\'%s\'\'");
        local_33c = (float)CONCAT31(local_33c._1_3_,0xff);
        local_330 = (float)((uint)local_330 & 0xffffff00);
      }
      fVar8 = (float10)FUN_005b7d30(_DAT_0093d844,0x3edc28f6,0x3f800000,0x3e99999a,0x3e99999a,
                                    0x3e99999a,0,local_33c,local_330);
      local_338 = (float)(&DAT_029899a0)
                         [(uint)(int)ROUND((fVar8 / (float10)0.4300000071525574) * (float10)65536.0)
                          >> 1 & 0x7fff] * 0.035 - _DAT_007fc310;
      fVar8 = (float10)FUN_005b7d30(_DAT_0093d844,0x3ef53f7d,local_338);
      local_33c = (float)CONCAT22(local_33c._2_2_,in_FPUControlWord);
      local_338 = (float)(&DAT_029899a0)
                         [(uint)(int)ROUND((fVar8 / (float10)0.4790000021457672) * (float10)65536.0)
                          >> 1 & 0x7fff] * 0.035;
      FUN_00511500(local_2c8,local_338);
    }
    if (DAT_00951388 == 0) goto LAB_004bb08d;
    if (local_334 == -NAN) goto LAB_004bba60;
  }
  if ((DAT_0087b9a8 != 0) && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe) != '\0')) {
    fVar8 = (float10)FUN_005b7d30(_DAT_00925028,0x3f451eb8,0x3f800000,_DAT_007fc334,_DAT_007fc334,
                                  _DAT_007fc334,0,0,0,*(int *)(PTR_DAT_00802c54 + 0x2ac0),0,
                                  0x3f800000);
    local_334 = (float)(&DAT_029899a0)
                       [(int)(((int)ROUND((fVar8 / (float10)0.7699999809265137) * (float10)65536.0)
                              & 0xffffU) + 0x4000) >> 1 & 0x7fff] * 0.01 - 0.05;
    fVar8 = (float10)FUN_005b7d30(_DAT_00925028,0x3f8ccccd,local_334);
    local_33c = (float)CONCAT22(local_33c._2_2_,in_FPUControlWord);
    local_334 = (float)(&DAT_029899a0)
                       [(uint)(int)ROUND((fVar8 / (float10)1.100000023841858) * (float10)65536.0) >>
                        1 & 0x7fff] * 0.01;
    FUN_00552c10(local_334);
  }
  DAT_0087b9a8 = 0;
  if (PTR_DAT_008021b4 != (undefined *)0x0) {
    puVar4 = (undefined4 *)(PTR_DAT_008021b4 + 0xb8);
    puVar6 = DAT_00925164;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  FUN_00603cc0();
LAB_004bbbd9:
  __security_check_cookie(local_44 ^ (uint)auStack_378);
  return;
}

