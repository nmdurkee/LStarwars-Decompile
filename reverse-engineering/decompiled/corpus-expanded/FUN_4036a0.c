/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x4036a0; label: FUN_004036a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004036a0(undefined4 param_1,int param_2)

{
  float fVar1;
  bool bVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [12];
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  if ((((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) || (*(int *)(param_2 + 0xcbc) == 0)) ||
     ((*(byte *)(*(int *)(param_2 + 0xcbc) + 0xc) & 0x80) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
    _sprintf(local_24,"%i",(uint)*(ushort *)(param_2 + 0x1062));
    FUN_005b3200(local_30,&DAT_007ef194,param_2 + 0xb8);
    FUN_005b37d0(local_30,local_30,param_2 + 0x5c);
    iVar4 = FUN_00560fa0(local_24,local_30,0x3fa66666,0,0,0xff,0xff,0xff,0x1087,0);
    if (iVar4 != 0) {
      local_40 = (float)CONCAT22(local_40._2_2_,in_FPUControlWord);
      local_44 = (float)(int)ROUND((_DAT_009250b8 * 0.2 + 0.6) * 128.0);
      *(undefined1 *)(iVar4 + 0xf7) = local_44._0_1_;
    }
  }
  if (*(char *)(param_2 + 0x7b5) == 'S') {
    if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) != 0)
       && (iVar4 = FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0), iVar4 == 0))
    goto LAB_00403c3f;
    if ((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) == 0) {
      local_40 = *(float *)(param_2 + 0x784) - _DAT_00925018;
      *(float *)(param_2 + 0x784) = local_40;
      if (local_40 <= 0.0) goto LAB_004038cc;
      goto LAB_00403c3f;
    }
    *(float *)(param_2 + 0x77c) = *(float *)(param_2 + 0x77c) + _DAT_00925018;
    local_40 = *(float *)(param_2 + 0x784) - _DAT_00925018;
    *(float *)(param_2 + 0x784) = local_40;
    if (0.0 < local_40) goto LAB_00403c3f;
    if ((*(short *)(param_2 + 0x1062) == 0) ||
       (iVar4 = *(int *)(param_2 + 0x798), *(byte *)(iVar4 + 0x5e) <= *(byte *)(iVar4 + 0x5f))) {
LAB_0040388c:
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
    }
    else {
      *(short *)(param_2 + 0x1062) = *(short *)(param_2 + 0x1062) + -1;
      *(char *)(iVar4 + 0x5f) = *(char *)(iVar4 + 0x5f) + '\x01';
      *(undefined4 *)(param_2 + 0x784) = 0x3e4ccccd;
      iVar4 = *(int *)(param_2 + 0x798);
      if (*(char *)(iVar4 + 0x5f) == *(char *)(iVar4 + 0x5e)) {
        *(byte *)(iVar4 + 0x62) = *(byte *)(iVar4 + 0x62) | 4;
        goto LAB_0040388c;
      }
      if (*(short *)(param_2 + 0x1062) == 0) goto LAB_0040388c;
    }
    if (*(char *)(param_2 + 0x7b5) != -1) goto LAB_00403c3f;
  }
  else {
    if (*(char *)(param_2 + 0x7b5) == 'R') {
      if (((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) != 0) ||
         (*(float *)(param_2 + 0x77c) < 0.3)) {
        if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) ==
             0) || (iVar4 = FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0),
                   iVar4 != 0)) {
          fVar1 = *(float *)(param_2 + 0x77c) + _DAT_00925018;
          *(float *)(param_2 + 0x77c) = fVar1;
          local_40 = *(float *)(*(int *)(param_2 + 0xca4) + 0x2c) * 1.25;
          local_44 = *(float *)(*(int *)(param_2 + 0xca4) + 0x30) * 1.25;
          if (fVar1 < 0.25) {
            local_48 = fVar1 * 4.0;
            local_40 = local_48 * local_40;
            local_44 = local_48 * local_44;
          }
          fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(param_2 + 0x754),local_40,0x41200000);
          *(float *)(param_2 + 0x754) = (float)fVar6;
          fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(param_2 + 0x758),local_44,0x41200000);
          local_48 = (float)fVar6;
          *(float *)(param_2 + 0x758) = local_48;
          *(float *)(param_2 + 0x748) =
               *(float *)(param_2 + 0x754) * _DAT_00925018 + *(float *)(param_2 + 0x748);
          *(float *)(param_2 + 0x74c) = local_48 * _DAT_00925018 + *(float *)(param_2 + 0x74c);
          iVar4 = FUN_00403450(param_1);
          if (iVar4 != 0) {
            local_48 = *(float *)(iVar4 + 0x10) - *(float *)(param_2 + 0x80);
            uVar3 = FUN_005be2d0(local_48,*(float *)(iVar4 + 0x18) - *(float *)(param_2 + 0x88));
            *(undefined2 *)(param_2 + 0x5a) = uVar3;
            iVar5 = FUN_0062c350(0x40400000,_DAT_00925018);
            if (iVar5 < 1) {
              *(byte *)(iVar4 + 0x3c) = *(byte *)(iVar4 + 0x3c) | 0x20;
              iVar4 = FUN_0054fa60(0);
              local_48 = (float)iVar4 * 1.5259022e-05 * 0.4;
              FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),local_48);
            }
            else {
              FUN_004c0c00(iVar4,param_2);
            }
          }
        }
        FUN_005655d0(param_2 + 0x748,param_2 + 0x754);
        FUN_00404f30((int)*(short *)(param_2 + 0x1064),&local_38,&local_34,&local_3c,0);
        FUN_00560fa0(&DAT_007516f0,param_2 + 0x748,0x3f800000,0,0,local_38,local_34,local_3c,0x1080,
                     0);
        __security_check_cookie(local_4 ^ (uint)&local_48);
        return;
      }
LAB_004038cc:
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      __security_check_cookie(local_4 ^ (uint)&local_48);
      return;
    }
    if (((!bVar2) || (*(char *)(param_2 + 0x281) == '\0')) ||
       (iVar4 = FUN_005620f0(param_2), iVar4 == 0)) goto LAB_00403c3f;
    local_48 = *(float *)(param_2 + 0x1dc) + 0.25;
    iVar4 = FUN_00402e00(param_1,param_2 + 0x19c,param_2,&local_44);
    if ((((iVar4 != 0) && (local_48 = local_48 * local_48, local_44 < local_48)) &&
        (*(short *)(param_2 + 0x1062) != 0)) &&
       ((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802280) != 0)) {
      *(undefined1 *)(param_2 + 0x7b5) = 0x53;
      *(undefined4 *)(param_2 + 0x77c) = 0;
      *(int *)(param_2 + 0x798) = iVar4;
      *(undefined2 *)(param_2 + 0x7aa) = 0x9b;
      *(undefined2 *)(param_2 + 0x5a) = *(undefined2 *)(iVar4 + 0x5c);
      __security_check_cookie(local_4 ^ (uint)&local_48);
      return;
    }
    if (((*(char *)(param_2 + 0x288) == '\0') || (*(float *)(param_2 + 0xc64) <= 0.0)) ||
       ((*(uint *)(*(int *)(param_2 + 0xca4) + 4) & DAT_00802280) == 0)) goto LAB_00403c3f;
  }
  FUN_00403630();
LAB_00403c3f:
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

