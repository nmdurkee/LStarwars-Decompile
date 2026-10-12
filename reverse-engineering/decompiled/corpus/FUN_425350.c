/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x425350; label: FUN_00425350
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00425350(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  float local_74;
  float local_70;
  char local_6c [4];
  uint local_68;
  undefined4 *local_64;
  float local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_74;
  local_50 = param_1;
  if ((param_1 != 0) && (0.0 < _DAT_008569a4)) {
    FUN_004246f0(&local_68,&local_5c);
    uVar9 = local_68;
    if ((local_5c == 1) && ((&DAT_0087b6ca)[local_68] != '\0')) {
      uVar9 = (uint)(local_68 == 0);
    }
    local_4c = 0;
    if (0 < local_5c) {
      do {
        if (uVar9 == 0) {
          iVar6 = 0xbf;
          uVar8 = 0;
          uVar4 = 0xff;
        }
        else {
          uVar8 = 0x7f;
          iVar6 = 0xff;
          uVar4 = 0;
        }
        if ((&DAT_008568f0)[uVar9] == 1) {
          local_60 = _DAT_007f3874;
          local_6c[1] = 0;
          if (DAT_008668d4._3_1_ != '\0') {
            local_60 = _DAT_007f3874 * 0.8;
          }
          iVar3 = uVar9 * 0x38;
          iVar7 = 0xf;
          do {
            if (*(char *)(iVar3 + 0x86e4ff + iVar7) != ' ') break;
            if (*(char *)(iVar3 + 0x86e4fe + iVar7) != ' ') {
              iVar7 = iVar7 + -1;
              break;
            }
            if (*(char *)(iVar3 + 0x86e4fd + iVar7) != ' ') {
              iVar7 = iVar7 + -2;
              break;
            }
            if (*(char *)(iVar3 + 0x86e4fc + iVar7) != ' ') {
              iVar7 = iVar7 + -3;
              break;
            }
            if (*(char *)(iVar3 + 0x86e4fb + iVar7) != ' ') {
              iVar7 = iVar7 + -4;
              break;
            }
            iVar7 = iVar7 + -5;
          } while (0 < iVar7);
          local_64 = (undefined4 *)(&DAT_008568a0 + uVar9 * 0xc);
          local_70 = *(float *)(&DAT_008568a0 + uVar9 * 0xc) - local_60 * 7.0;
          if (local_5c == 2) {
            fVar1 = _DAT_007f3878;
            if (uVar9 == 0) {
              fVar1 = -_DAT_007f3878;
            }
            local_70 = fVar1 + local_70;
          }
          iVar5 = 0;
          local_68 = uVar8;
          local_58 = iVar6;
          local_54 = uVar4;
          local_48 = iVar3;
          do {
            if (iVar5 == *(int *)(&DAT_008569b0 + uVar9 * 4)) {
              local_6c[0] = s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec
                            [*(int *)(&DAT_008568b8 + uVar9 * 4)];
              iVar6 = (-(uint)(DAT_009213e4 != 0) & 0xffffffc0) + 0xff;
              local_74 = _DAT_007f3880 - 0.65;
              FUN_00511500(PTR_DAT_007f3a18,local_70,local_74,0x3f800000,_DAT_007f387c,_DAT_007f387c
                           ,_DAT_007f387c,0,iVar6,iVar6,iVar6);
              local_74 = -0.65 - _DAT_007f3880;
              FUN_00511500(PTR_DAT_007f3a1c,local_70,local_74,0x3f800000,_DAT_007f387c,_DAT_007f387c
                           ,_DAT_007f387c,0,iVar6,iVar6,iVar6);
              local_74 = (float)(&DAT_00856974)[uVar9];
              iVar6 = (-(uint)(DAT_009213e4 != 0) & 0xffffff01) + 0xff;
              uVar8 = 0xff;
              uVar4 = 0xff;
              iVar3 = local_48;
            }
            else {
              local_6c[0] = *(char *)((int)&DAT_0086e500 + iVar5 + iVar3);
              if (((*(int *)(&DAT_008569b0 + uVar9 * 4) < iVar5) && (iVar7 <= iVar5)) &&
                 (local_6c[0] == ' ')) {
                local_6c[0] = '.';
              }
              local_74 = 1.0;
              iVar6 = local_58;
              uVar8 = local_68;
              uVar4 = local_54;
            }
            fVar1 = local_74 * 0.5;
            local_74 = local_74 * _DAT_007f381c;
            FUN_00511500(local_6c,local_70,0xbf266666,0x3f800000,local_74,fVar1,0x3f000000,0,uVar8,
                         iVar6,uVar4);
            if (iVar5 == 0) {
              local_74 = (local_70 - local_60) + _DAT_007f3884;
              puVar10 = &DAT_00753374;
LAB_0042573d:
              FUN_00511500(puVar10,local_74,_DAT_007f3888 - 0.65,0x3f800000,0x3f000000,0x3f19999a,
                           0x3f000000,0,local_68,local_58,local_54);
            }
            else if (iVar5 == 0xe) {
              local_74 = (local_70 + local_60) - _DAT_007f3884;
              puVar10 = &DAT_00753370;
              goto LAB_0042573d;
            }
            iVar5 = iVar5 + 1;
            local_70 = local_70 + local_60;
          } while (iVar5 < 0xf);
        }
        else {
          FUN_00434930((int)*(short *)(local_50 + 0x6c + uVar9 * 2),0,local_44);
          local_64 = (undefined4 *)(&DAT_008568a0 + uVar9 * 0xc);
          uVar2 = FUN_006e6b90();
          FUN_0050d910(local_44,*local_64,0xbf266666,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,
                       uVar8,iVar6,uVar4,0x3f400000,2,0,0,uVar2);
        }
        local_70 = (float)*local_64;
        local_74 = (1.0 - (float)(&DAT_00856964)[uVar9]) * _DAT_008569a4;
        FUN_00552c10(local_70,0xbef5c28f,0x3f800000,_DAT_007fc318,_DAT_007fc318,_DAT_007fc318,0,0,0,
                     *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xa70,0,local_74);
        iVar6 = local_4c;
        iVar3 = FUN_00593920(local_50,&DAT_0086e4ec + uVar9 * 0x1c,local_4c);
        if (iVar3 != -1) {
          if (iVar3 != DAT_00803b98) {
            iVar3 = iVar3 + 1;
          }
          FUN_00552c10(local_70,0xbef5c28f,0x3f800000,_DAT_007fc318,_DAT_007fc318,_DAT_007fc318,0,0,
                       0,iVar3 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),0,local_74);
        }
        local_4c = iVar6 + 1;
        uVar9 = uVar9 + 1;
      } while (local_4c < local_5c);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_74);
  return;
}

