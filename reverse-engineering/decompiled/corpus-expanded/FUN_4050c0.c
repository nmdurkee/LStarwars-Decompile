/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x4050c0; label: FUN_004050c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004050c0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined1 **ppuVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  float local_8c;
  float local_88;
  float local_84;
  undefined1 *local_80 [5];
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined4 local_68;
  undefined1 local_31;
  undefined1 local_30 [12];
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_8c;
  if (*(char *)(param_1 + 0x7b5) == 'P') {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x400000;
    fVar1 = *(float *)(param_1 + 0xde4);
    if (!NAN(fVar1) && 0.25 < fVar1 != (fVar1 == 0.25)) goto LAB_00405877;
    iVar2 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),0,0);
    if (iVar2 != 0) {
      if (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        __security_check_cookie(local_4 ^ (uint)&local_8c);
        return;
      }
      local_88 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
      *(float *)(param_1 + 0x77c) = local_88;
      if (local_88 < 0.0 != (local_88 == 0.0)) {
        if ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c) != 0) {
          iVar2 = FUN_00404fa0(param_1);
          if (iVar2 != 0) goto LAB_0040520e;
          *(undefined4 *)(param_1 + 0xde4) = 0;
        }
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        __security_check_cookie(local_4 ^ (uint)&local_8c);
        return;
      }
    }
    goto LAB_0040520e;
  }
  if (*(char *)(param_1 + 0x7b5) != 'M') {
    if (((((((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) ||
           ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x20000000) == 0)) ||
          (*(int *)(param_1 + 0xcc0) == 0)) ||
         ((*(char *)(*(int *)(param_1 + 0xcc0) + 0x7d) != '\0' ||
          (*(char *)(param_1 + 0x1079) == '\0')))) || ((*(byte *)(param_1 + 0xe24) & 8) == 0)) ||
       (((*(char *)(param_1 + 0x288) == '\0' || (*(float *)(param_1 + 0xc64) <= 0.0)) ||
        ((fVar1 = *(float *)(param_1 + 0xde4), NAN(fVar1) || 0.25 < fVar1 == (fVar1 == 0.25) ||
         (((*(char *)(param_1 + 0x281) == '\0' || (iVar2 = FUN_005620f0(param_1), iVar2 == 0)) ||
          (*(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x400000,
          0.25 <= *(float *)(param_1 + 0xde4) - _DAT_00925018)))))))) goto LAB_0040520e;
LAB_00405877:
    FUN_00404fa0(param_1);
    __security_check_cookie(local_4 ^ (uint)&local_8c);
    return;
  }
  if (*(char *)(param_1 + 0x7b3) == '\0') {
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x20000;
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x400000;
    if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) {
      FUN_00561ba0(param_1,0);
      goto LAB_0040520e;
    }
    if (((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c) != 0) ||
       (*(float *)(param_1 + 0x77c) < 0.3)) {
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0
          ) || (iVar2 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0), iVar2 != 0))
      {
        fVar1 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
        *(float *)(param_1 + 0x77c) = fVar1;
        local_84 = *(float *)(*(int *)(param_1 + 0xca4) + 0x2c) * 1.25;
        local_88 = *(float *)(*(int *)(param_1 + 0xca4) + 0x30) * 1.25;
        if (fVar1 < 0.25) {
          local_8c = fVar1 * 4.0;
          local_84 = local_8c * local_84;
          local_88 = local_8c * local_88;
        }
        fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x94),local_84,
                                      0x41200000);
        *(float *)(*(int *)(param_1 + 0xcc0) + 0x94) = (float)fVar8;
        fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(*(int *)(param_1 + 0xcc0) + 0x98),local_88,
                                      0x41200000);
        *(float *)(*(int *)(param_1 + 0xcc0) + 0x98) = (float)fVar8;
        iVar2 = *(int *)(param_1 + 0xcc0);
        *(float *)(iVar2 + 0x88) =
             *(float *)(iVar2 + 0x94) * _DAT_00925018 + *(float *)(iVar2 + 0x88);
        iVar2 = *(int *)(param_1 + 0xcc0);
        *(float *)(iVar2 + 0x8c) =
             *(float *)(iVar2 + 0x98) * _DAT_00925018 + *(float *)(iVar2 + 0x8c);
      }
      FUN_005655d0(*(int *)(param_1 + 0xcc0) + 0x88,*(int *)(param_1 + 0xcc0) + 0x94);
      iVar2 = FUN_00403f60(PTR_DAT_00802c54,param_1,0);
      if (iVar2 != 0) {
        FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
      }
      FUN_00404f30((int)*(short *)(param_1 + 0x1064),&local_8c,&local_88,&local_84,local_24);
      puVar5 = &DAT_00802cd8;
      ppuVar7 = local_80;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *ppuVar7 = (undefined1 *)*puVar5;
        puVar5 = puVar5 + 1;
        ppuVar7 = ppuVar7 + 1;
      }
      local_80[3] = (undefined1 *)0x3f800000;
      local_6b = local_88._0_1_;
      local_80[1] = (undefined1 *)(*(int *)(param_1 + 0xcc0) + 0x88);
      local_6c = local_8c._0_1_;
      local_80[0] = local_24;
      local_6a = local_84._0_1_;
      local_8c = (float)(int)ROUND((_DAT_009250b8 * 0.2 + 0.8) * 128.0);
      local_69 = local_8c._0_1_;
      local_68 = 0x1080;
      FUN_00560b60(local_80);
      local_80[0] = PTR_DAT_007f3a1c;
      local_68 = 0x87;
      local_80[3] = (undefined1 *)0x40400000;
      local_31 = 4;
      iVar2 = 0;
      local_84 = (float)CONCAT22(local_84._2_2_,in_FPUControlWord);
      local_8c = (float)(int)ROUND((0.8 - _DAT_009250b8 * 0.2) * 128.0);
      local_69 = local_8c._0_1_;
      if (*(char *)(*(int *)(param_1 + 0xcc0) + 0x7c) != '\0') {
        do {
          iVar3 = FUN_00404850(iVar2);
          if (iVar3 != 0) {
            local_80[1] = local_30;
            FUN_00560b60(local_80);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uint)*(byte *)(*(int *)(param_1 + 0xcc0) + 0x7c));
      }
    }
    else if (*(char *)(*(int *)(param_1 + 0xcc0) + 0x7c) == '\0') {
LAB_00405697:
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
    else {
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffdffff;
      *(undefined1 *)(param_1 + 0x7b3) = 1;
      *(undefined2 *)(param_1 + 0x7aa) = 0x65;
      fVar8 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),0x65,0,0,1);
      local_88 = (float)fVar8;
      *(float *)(param_1 + 0x784) = local_88;
      if (local_88 <= 0.0) {
        *(undefined4 *)(param_1 + 0x784) = 0x3f000000;
      }
      *(undefined4 *)(param_1 + 0x77c) = 0;
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0
          ) || (fVar8 = (float10)FUN_0062f1f0(*(int *)(param_1 + 0x50),
                                              (int)*(short *)(param_1 + 0x7aa),0),
               fVar8 != (float10)0.0)) goto LAB_0040575d;
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
    }
  }
  else if (*(char *)(param_1 + 0x7b3) == '\x01') {
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffdffff;
    pfVar6 = (float *)0x0;
    if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) {
      *(undefined1 *)(param_1 + 0x7b1) = 1;
    }
    uVar4 = *(uint *)(param_1 + 0x7bc) >> 6 & 1;
    if (((uVar4 == 0) || (*(char *)(param_1 + 0x7b1) != '\x01')) ||
       (*(float *)(param_1 + 0x77c) < 0.2)) {
      if (((uVar4 != 0) && (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) &&
         (fVar1 = *(float *)(param_1 + 0x77c), !NAN(fVar1) && 0.3 < fVar1 != (fVar1 == 0.3)))
      goto LAB_00405697;
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0
          ) || (pfVar6 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
               pfVar6 != (float *)0x0)) {
        local_88 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
        *(float *)(param_1 + 0x77c) = local_88;
        if (*(float *)(param_1 + 0x784) < local_88 == (*(float *)(param_1 + 0x784) == local_88)) {
          if ((*(byte *)(param_1 + 0x7bc) & 0x40) != 0) goto LAB_0040520e;
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4)
              != 0) {
            fVar8 = (float10)FUN_0062f1f0(*(int *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),
                                          2);
            local_8c = (float)fVar8;
            if (((pfVar6 == (float *)0x0) || (*pfVar6 <= 0.0)) ||
               (local_8c < *pfVar6 == (local_8c == *pfVar6))) goto LAB_0040576b;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          if ((*(byte *)(param_1 + 0x7bc) & 0x40) != 0) goto LAB_0040520e;
        }
LAB_0040575d:
        *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x40;
        *(undefined1 *)(param_1 + 0xe3d) = 1;
      }
    }
    else {
      FUN_00561ba0(param_1,0);
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
    }
  }
LAB_0040576b:
  if (((*(byte *)(param_1 + 0x7bc) & 0x40) == 0) && (*(char *)(param_1 + 0xe3d) == '\0')) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x400000;
    __security_check_cookie(local_4 ^ (uint)&local_8c);
    return;
  }
LAB_0040520e:
  __security_check_cookie(local_4 ^ (uint)&local_8c);
  return;
}

