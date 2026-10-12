/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45fc50; label: FUN_0045fc50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045fc50(int param_1,int param_2,int param_3)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 fVar8;
  float local_50;
  float local_4c;
  float local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_50;
  if (param_3 == 0) {
    if (*(char *)(param_1 + 0x12) != '\0') {
      fVar7 = (float10)FUN_0045e430(param_2);
      local_48 = (float)fVar7;
      iVar3 = FUN_006e6b90();
      local_48 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
      uVar4 = FUN_006e6b90();
      local_4c = _DAT_00925064;
      if (0.25 < _DAT_00925064) {
        local_4c = 0.0;
      }
      iVar3 = FUN_006e6b90();
      local_4c = (1.0 - ABS((float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff])) + 1.0;
      if ((&DAT_0086e0f9)[(uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c) * 0xc] == '\0') {
        fVar2 = _DAT_007f864c * local_4c;
        local_50 = _DAT_007f8650 + _DAT_007f8634;
        FUN_0050c780(&DAT_00755ba8,_DAT_007f862c,local_50,_DAT_007f8640,fVar2,fVar2,fVar2,0,0xff,
                     0xff,0xff,uVar4);
      }
      else {
        local_50 = _DAT_007f8638 * local_48;
        FUN_004851b0(_DAT_007f862c,_DAT_007f8634,_DAT_007f8640,local_50,0x3f800000,
                     (&DAT_0086e0f9)[(uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c) * 0xc],param_2
                     ,(float)extraout_ST0_00);
      }
      if ((&DAT_0086e0f9)[(uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c) * 0xc] !=
          *(byte *)(param_2 + 0xb6)) {
        _sprintf(local_44,"%i/%i",
                 (uint)(byte)(&DAT_0086e0f9)[(uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c) * 0xc]
                 ,(uint)*(byte *)(param_2 + 0xb6));
        local_50 = _DAT_007f8644 + _DAT_007f8634;
        FUN_0050c780(local_44,_DAT_007f862c,local_50,0x3f800000,_DAT_007f8648,_DAT_007f8648,
                     _DAT_007f8648,0,0xff,0,0x7f,uVar4);
        __security_check_cookie(local_4 ^ (uint)&local_50);
        return;
      }
      local_50 = _DAT_007f8658 + _DAT_007f8634;
      FUN_0050c780(&DAT_00758804,_DAT_007f862c,local_50,0x3f800000,_DAT_007f8654,_DAT_007f8654,
                   _DAT_007f8654,0,0xff,0,0x7f,uVar4);
      __security_check_cookie(local_4 ^ (uint)&local_50);
      return;
    }
    goto LAB_0046019c;
  }
  if (*(int *)(param_1 + 0x14) < 1) goto LAB_0046019c;
  bVar1 = true;
  fVar7 = (float10)0;
  local_48 = *(float *)(param_1 + 0x18);
  if (0.5 <= *(float *)(param_1 + 0x18)) {
    if (local_48 < 3.5) {
      local_48 = 1.0;
      goto LAB_0045fe73;
    }
    fVar8 = (float10)1;
    if (*(float *)(param_1 + 0x18) < 4.0) {
      local_4c = *(float *)(param_1 + 0x18) - 3.5;
      local_4c = local_4c + local_4c;
      fVar5 = (float10)local_4c;
      local_48 = (float)(fVar8 - fVar5);
LAB_0045fd6f:
      if (fVar5 <= fVar7) goto LAB_0045fe64;
      if (bVar1) goto LAB_0045fd17;
      fVar6 = (float10)0;
      fVar8 = fVar7;
    }
    else {
      local_48 = (float)fVar7;
      if (6.0 <= *(float *)(param_1 + 0x18)) {
        if (6.5 <= *(float *)(param_1 + 0x18)) goto LAB_0046019c;
        bVar1 = false;
        fVar5 = (float10)*(float *)(param_1 + 0x18) - (float10)6.0;
        local_4c = (float)(fVar8 - (fVar5 + fVar5));
        fVar5 = (float10)local_4c;
        goto LAB_0045fd6f;
      }
      local_4c = 1.0;
LAB_0045fd17:
      iVar3 = FUN_006e6b90();
      fVar6 = (extraout_ST1 - (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff]) * (float10)-0.5;
      fVar5 = extraout_ST0;
    }
    local_50 = (float)(fVar6 + (float10)0.22499999403953552);
    FUN_0055b830((int)DAT_007f195c,(float)fVar8,local_50,(float)fVar8,0x3ecccccd,0xa7,(float)fVar5,
                 (float)fVar5,1,0);
    uVar4 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *(int *)(DAT_007f195c * 0x4c + DAT_0093b274) * 4),0,
                 0xbdcccccd,0x3f800000,_DAT_007f860c,_DAT_007f860c,_DAT_007f860c,0,DAT_007fa4c8,
                 DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,uVar4);
  }
  else {
    local_48 = local_48 + local_48;
  }
LAB_0045fe64:
  if (0.0 < local_48) {
LAB_0045fe73:
    fVar2 = local_48 * 128.0;
    local_48 = (float)CONCAT22(local_48._2_2_,in_FPUControlWord);
    local_50 = (float)(int)ROUND(fVar2);
    FUN_0050c780(*(undefined4 *)(DAT_00926c20 + DAT_00880720 * 4),0,0x3e666666,0x3f800000,
                 _DAT_007f8600,_DAT_007f8600,_DAT_007f8600,0,DAT_007fa4c8,DAT_007fa4cc,DAT_0087a774,
                 (uint)local_50 & 0xff);
    __security_check_cookie(local_4 ^ (uint)&local_50);
    return;
  }
LAB_0046019c:
  __security_check_cookie(local_4 ^ (uint)&local_50);
  return;
}

