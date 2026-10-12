/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48ce00; label: FUN_0048ce00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ce00(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  char local_17c [24];
  char local_164 [32];
  char local_144 [256];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_17c;
  builtin_strncpy(local_17c,"levels\\titles\\titles",0x15);
  FUN_0057a420(param_1);
  if ((DAT_0093d840 == 0) &&
     ((*(int *)(param_1 + 0x10c) < 1 ||
      (FUN_00578f60(*(undefined4 *)(param_1 + 0x128),&DAT_0092b0c8,DAT_00951ba8), DAT_0093d840 == 0)
      ))) {
    if ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 4) != 0) {
      puVar1 = (uint *)(param_1 + 0x104);
      *puVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
      if (*(int *)(param_1 + 0x128) == DAT_00951b88) {
        FUN_004f1f10(local_144,"levels\\titles\\");
        FUN_00489aa0();
        FUN_004f1e80(local_144,local_44);
      }
      else {
        FUN_004f1f10(local_144,param_1 + 0x80);
      }
      FUN_004f1e80(local_144,&DAT_0075a1fc);
      _DAT_02854d4c = *(byte *)(*(int *)(param_1 + 0x128) + 0xa0) + 1;
      iVar9 = *(int *)(param_1 + 0x128);
      iVar5 = 0;
      do {
        if (iVar9 == *(int *)((int)&DAT_0087b060 + iVar5)) {
          iVar9 = 1;
          goto LAB_0048cf6e;
        }
        iVar5 = iVar5 + 4;
      } while (iVar5 != 0x2c);
      iVar5 = 0;
      do {
        if (iVar9 == *(int *)((int)&DAT_0087b164 + iVar5)) {
          iVar9 = 3;
          goto LAB_0048cf6e;
        }
        iVar5 = iVar5 + 4;
      } while (iVar5 != 0x10);
      iVar9 = *(char *)(iVar9 + 0xa2) + 1;
LAB_0048cf6e:
      FUN_006d34c0(iVar9);
      if (DAT_008264bc == 2) {
        uVar6 = FUN_005f4f00(puVar1,*(undefined4 *)(param_1 + 0x108),local_144,2);
      }
      else {
        uVar6 = FUN_005ef7f0(puVar1,*(undefined4 *)(param_1 + 0x108),local_144);
      }
      *(undefined4 *)(param_1 + 0x13c) = uVar6;
      FUN_006d34c0(0);
      _DAT_02854d4c = 0;
      FUN_0048c270(*(undefined4 *)(param_1 + 0x13c),param_1 + 0x15c,1);
      FUN_005528b0(*(undefined4 *)(param_1 + 0x13c));
      if (*(int *)(param_1 + 0x13c) != 0) {
        FUN_0048c630(param_1);
      }
      if (DAT_0093d840 != 0) goto LAB_0048d64d;
    }
    iVar9 = *(int *)(param_1 + 0x128);
    if ((iVar9 == DAT_00951b88) || (iVar9 == DAT_00951b9c)) {
      _DAT_02854d4c = *(byte *)(iVar9 + 0xa0) + 1;
      uVar6 = FUN_005ef7f0(param_1 + 0x104,*(undefined4 *)(param_1 + 0x108),
                           "levels\\titles\\pictures.gsc");
      *(undefined4 *)(param_1 + 0x140) = uVar6;
      if (DAT_0093d840 != 0) goto LAB_0048d64d;
    }
    puVar2 = (undefined4 *)(param_1 + 0x108);
    puVar1 = (uint *)(param_1 + 0x104);
    uVar6 = FUN_005a05b0(puVar1,puVar2);
    *(undefined4 *)(param_1 + 0x2960) = uVar6;
    FUN_005a8090(param_1,&PTR_s_BULLET_SPARK_007f5dd0,400,0x93);
    if ((DAT_0093d840 == 0) && (FUN_00571a50(param_1), DAT_0093d840 == 0)) {
      if (0 < *(int *)(param_1 + 0x10c)) {
        FUN_00581e40(param_1,&DAT_0092b0c8);
      }
      uVar6 = FUN_0059a620(param_1,puVar1,puVar2,*(undefined2 *)(*(int *)(param_1 + 0x128) + 0xd8));
      *(undefined4 *)(param_1 + 0x510c) = uVar6;
      uVar6 = FUN_005598e0(param_1,puVar1,puVar2);
      *(undefined4 *)(param_1 + 0x2ac8) = uVar6;
      _sprintf(local_144,"%s%s",param_1 + 0x80,&DAT_0075a2c0);
      FUN_005b1ee0(local_144,puVar1,puVar2);
      FUN_0056a9b0();
      FUN_0055ad70(*(undefined4 *)(param_1 + 0x2ac8),param_1,param_1 + 0x80);
      if (DAT_0093d840 == 0) {
        iVar9 = *(int *)(param_1 + 300);
        if (((iVar9 == 0) || (iVar9 != DAT_00951364)) || (DAT_0093b338 != 0)) {
          if ((((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x400) != 0) && (iVar9 != 0)) &&
             (*(short *)(iVar9 + 0x8a) != -1)) {
            piVar3 = (int *)(param_1 + 0x2968);
            FUN_00599a40(piVar3,(int)*(short *)(iVar9 + 0x8a),puVar1,puVar2,0);
            if (*piVar3 != 0) {
              FUN_00599b20(piVar3,10,puVar1,puVar2);
            }
            goto joined_r0x0048d1c6;
          }
        }
        else {
          FUN_004778f0(param_1,puVar1,puVar2);
joined_r0x0048d1c6:
          if (DAT_0093d840 != 0) goto LAB_0048d64d;
        }
        if (((*(int *)(param_1 + 0x128) == DAT_00951b94) ||
            ((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x400) != 0)) && (DAT_009248a0 == 0)) {
          uVar6 = FUN_005ef7f0(puVar1,*puVar2,"stuff\\icons\\starwars_icons_all.gsc");
          *(undefined4 *)(param_1 + 0x2964) = uVar6;
        }
        if (((DAT_0092489c == 0) || (*(int *)(param_1 + 300) == 0)) ||
           (iVar9 = DAT_0092489c, (*(ushort *)(*(int *)(param_1 + 300) + 0x7a) & 0x400) == 0)) {
          iVar9 = DAT_00924880;
        }
        uVar6 = FUN_0057c3e0(&DAT_0092b0c8,*(undefined4 *)(param_1 + 0x13c),iVar9,
                             *(undefined4 *)(param_1 + 0x2a98),puVar1,puVar2,
                             *(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x11c),
                             param_1);
        *(undefined4 *)(param_1 + 0x2ab0) = uVar6;
        if (DAT_0093d840 == 0) {
          uVar7 = *puVar1 + 3 & 0xfffffffc;
          *puVar1 = uVar7;
          *(uint *)(param_1 + 0x2980) = uVar7;
          *puVar1 = DAT_0093b278 * 0x10 + uVar7;
          FUN_0055b3a0(param_1);
          uVar7 = *(uint *)(*(int *)(param_1 + 0x128) + 100);
          if (((uVar7 & 2) != 0) && ((uVar7 & 0xe0) == 0)) {
            uVar6 = FUN_0053e3b0(puVar1,*puVar2,*(undefined4 *)(param_1 + 0x13c));
            *(undefined4 *)(param_1 + 0x2988) = uVar6;
          }
          FUN_00579c60(param_1);
          FUN_0057a000(param_1);
          FUN_00580790(param_1);
          if (0 < *(int *)(param_1 + 0x10c)) {
            FUN_00579b40(*(undefined4 *)(param_1 + 0x128),&DAT_0092b0c8,&DAT_0087b2e8);
            FUN_0055fbf0(param_1,&DAT_0092b0c8);
            FUN_004ce020(param_1,&DAT_0092b0c8);
            FUN_00575240(param_1,&DAT_0092b0c8);
            FUN_005a1c00(param_1,&DAT_0092b0c8);
            FUN_0058b8d0(param_1,&DAT_0092b0c8);
            FUN_00470370(param_1,&DAT_0092b0c8);
            FUN_005a2aa0(param_1,&DAT_0092b0c8);
            FUN_004d44a0(param_1,&DAT_0092b0c8);
            FUN_00570c90(param_1,&DAT_0092b0c8);
            FUN_004669e0(param_1,&DAT_0092b0c8);
          }
          if (*(int *)(param_1 + 0x2988) != 0) {
            if (0 < *(int *)(param_1 + 0x10c)) {
              FUN_005404f0(*(int *)(param_1 + 0x2988),&DAT_0092b0c8,0,puVar1,puVar2,
                           *(undefined4 *)(param_1 + 0x13c));
            }
            FUN_005414f0(*(undefined4 *)(param_1 + 0x2988),puVar1,*puVar2);
            if (DAT_0093d840 != 0) goto LAB_0048d64d;
          }
          if ((((*(int *)(param_1 + 300) == 0) ||
               ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 5) != 5)) ||
              (((*(uint *)(*(int *)(param_1 + 0x128) + 100) & 0x4e0) != 0 ||
               (FUN_00599e00(&DAT_00855f24,param_1,puVar1,puVar2), DAT_0093d840 == 0)))) &&
             (((FUN_0055fe10(param_1), DAT_0093d840 == 0 &&
               (FUN_0055fe90(param_1), DAT_0093d840 == 0)) &&
              (FUN_0055ff30(param_1), DAT_0093d840 == 0)))) {
            uVar7 = *(uint *)(*(int *)(param_1 + 0x128) + 100);
            if (((uVar7 & 2) == 0) || ((uVar7 & 0xe0) != 0)) {
              *(undefined4 *)(param_1 + 0x2ae4) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 0x2ae4) = 0;
            }
            if (*(int *)(param_1 + 0x2ae4) == 0) {
              *puVar1 = *puVar1 + 3 & 0xfffffffc;
              _sprintf(local_164,"ai");
              uVar6 = FUN_0052e920(puVar1,puVar2,0x1cc00,*(undefined4 *)(param_1 + 0x13c),
                                   *(int *)(param_1 + 0x128),*(int *)(param_1 + 0x128) + 0x40,
                                   local_164);
              *(undefined4 *)(param_1 + 0x2ae8) = uVar6;
              uVar6 = FUN_0043ff30(puVar1,puVar2,0x20);
              *(undefined4 *)(param_1 + 0x4670) = uVar6;
              uVar6 = FUN_005ab0a0(puVar1,puVar2,0x20);
              *(undefined4 *)(param_1 + 0x4674) = uVar6;
              uVar6 = FUN_00402890(puVar1,puVar2);
              *(undefined4 *)(param_1 + 0x4678) = uVar6;
              FUN_004568b0(param_1,&DAT_00921ee8);
              FUN_004568b0(param_1,*(int *)(param_1 + 0x2ae8) + 0x1c);
              uVar6 = FUN_0056ca60(puVar1,puVar2,*(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf7));
              *(undefined4 *)(param_1 + 0x467c) = uVar6;
            }
            if (DAT_0093d840 == 0) {
              uVar6 = FUN_0062a7d0(0x10d8,puVar1,puVar2);
              *(undefined4 *)(param_1 + 0x298c) = uVar6;
              if (DAT_0093d840 == 0) {
                if ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 4) == 0) {
                  *(undefined4 *)(param_1 + 0x2ab8) = 0xffffffff;
LAB_0048d597:
                  *(undefined4 *)(param_1 + 0x2abc) = 0;
                }
                else {
                  pcVar8 = local_17c;
                  if (*(int *)(param_1 + 0x128) != DAT_00951b88) {
                    pcVar8 = (char *)(param_1 + 0x80);
                  }
                  FUN_00595970(param_1,pcVar8);
                  iVar9 = FUN_006355f0(*(undefined4 *)(param_1 + 0x2ab4),DAT_007faa98);
                  *(int *)(param_1 + 0x2ab8) = iVar9;
                  if (iVar9 == -1) goto LAB_0048d597;
                  FUN_00635630(*(undefined4 *)(param_1 + 0x2ab4),iVar9,param_1 + 0x2abc);
                }
                if (DAT_0093d840 == 0) {
                  if (0 < *(int *)(param_1 + 0x10c)) {
                    FUN_005a2060(param_1,&DAT_0092b0c8);
                    FUN_0055f960(param_1,&DAT_0092b0c8);
                    if (DAT_0093d840 != 0) goto LAB_0048d64d;
                  }
                  FUN_0055af20(*(undefined4 *)(param_1 + 0x2ac8),*(undefined4 *)(param_1 + 0x2acc),
                               param_1);
                  if (DAT_0093d840 == 0) {
                    FUN_004f1f10(local_144,param_1 + 0x80);
                    FUN_004f1e80(local_144,&DAT_0075a2b4);
                    uVar6 = FUN_0059f0e0(param_1,*(undefined4 *)(param_1 + 0x2ac8),local_144,puVar1,
                                         puVar2);
                    *(undefined4 *)(param_1 + 0x2acc) = uVar6;
                    if (DAT_0093d840 == 0) {
                      FUN_005b1770(param_1);
                      FUN_005b1e30(param_1);
                      if (DAT_0093d840 == 0) {
                        pcVar4 = *(code **)(*(int *)(param_1 + 0x128) + 0x68);
                        if (pcVar4 != (code *)0x0) {
                          (*pcVar4)(param_1,puVar1,puVar2);
                        }
                        FUN_0056f9f0(*(undefined4 *)(param_1 + 0x120),
                                     *(undefined4 *)(param_1 + 0x11c));
                        *(undefined4 *)(param_1 + 0x110) = 1;
                        goto LAB_0048d695;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0048d64d:
  FUN_0055f6c0(param_1);
  FUN_0055ffb0(param_1,0xffffffff);
LAB_0048d695:
  __security_check_cookie(local_4 ^ (uint)local_17c);
  return;
}

