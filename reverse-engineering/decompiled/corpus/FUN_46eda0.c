/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46eda0; label: FUN_0046eda0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046eda0(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float local_4;
  
  if (0.0 < *(float *)(param_2 + 0xdb0)) {
    *(float *)(param_2 + 0xdb0) = *(float *)(param_2 + 0xdb0) - _DAT_00925018;
  }
  cVar2 = *(char *)(param_2 + 0x7b5);
  DAT_0087936c = 0;
  DAT_0087936d = 0;
  DAT_0087936e = 0;
  if ((cVar2 == '\v') && (*(int *)(param_2 + 0x798) != 0)) {
    if ((*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) != 0)
       && (iVar7 = FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0), iVar7 == 0)) {
      fVar5 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
      *(float *)(param_2 + 0x77c) = fVar5;
      if (fVar5 <= 0.0) {
        if (*(int *)(param_2 + 0x798) == 0) {
          FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f000000,0);
        }
        else {
          FUN_0054a8a0(**(undefined4 **)(param_2 + 0xca4),0x3dcccccd);
          if (*(char *)(*(int *)(param_2 + 0x798) + 0x61) == '\x02') {
            FUN_00681f40("Hunter_Granted",param_2 + 0x80);
          }
          if (*(char *)(*(int *)(param_2 + 0x798) + 0x61) == '\x03') {
            FUN_00681f40("Trooper_Granted",param_2 + 0x80);
          }
        }
        if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
          cVar2 = *(char *)(*(int *)(param_2 + 0x798) + 0x61);
          if ((cVar2 == '\0') || (cVar2 == '\x01')) {
            if ((DAT_007f39e4 == 0) || (iVar7 = FUN_0058a900(0), iVar7 == 0)) {
              FUN_00576960(0x25f);
              _DAT_00876d9c = _DAT_00876d9c | 4;
            }
            else {
              FUN_00576960(0x2b9);
            }
          }
          else if (cVar2 == '\x03') {
            FUN_00576960(0x260);
          }
          else if (cVar2 == '\x02') {
            FUN_00576960(0x261);
          }
        }
        *(undefined1 *)(param_2 + 0x7b5) = 0xff;
        pbVar1 = (byte *)(*(int *)(param_2 + 0x798) + 0x62);
        *pbVar1 = *pbVar1 & 0xfe;
        pbVar1 = (byte *)(*(int *)(param_2 + 0x798) + 0x62);
        *pbVar1 = *pbVar1 | 2;
        *(undefined4 *)(param_2 + 0x798) = 0;
        return;
      }
      if ((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 0x20) == 0) {
        return;
      }
      FUN_004aa240(param_2);
      return;
    }
    uVar8 = *(uint *)(param_2 + 0xe20);
    uVar4 = uVar8 & 0x1000;
    fVar5 = *(float *)(param_2 + 0x778) + _DAT_00925018;
    *(float *)(param_2 + 0x778) = fVar5;
    if (1.0 < fVar5) {
      *(undefined4 *)(param_2 + 0x778) = 0x3f800000;
    }
    fVar5 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
    *(float *)(param_2 + 0x77c) = fVar5;
    if (fVar5 <= 0.0) {
      *(undefined1 *)(param_2 + 0x7b5) = 0xff;
      pbVar1 = (byte *)(*(int *)(param_2 + 0x798) + 0x62);
      *pbVar1 = *pbVar1 & 0xfe;
      pbVar1 = (byte *)(*(int *)(param_2 + 0x798) + 0x62);
      *pbVar1 = *pbVar1 | 2;
      uVar8 = *(uint *)(param_2 + 0xe20);
      *(undefined4 *)(param_2 + 0x798) = 0;
      if ((uVar8 & 0x1000) == 0) goto LAB_0046f01e;
    }
    if (uVar4 == 0) {
LAB_0046f01e:
      *(uint *)(param_2 + 0xe20) = uVar8 | 0x1000;
      return;
    }
  }
  else if ((cVar2 == -1) ||
          (((cVar2 == '\x01' || (cVar2 == '\x02')) ||
           (iVar7 = FUN_00578790(param_2,0xb), iVar7 != 0)))) {
    iVar7 = FUN_0046de50(PTR_DAT_00802c54,param_2 + 0x5c,param_2,&local_4,1);
    if (iVar7 == 0) {
      if (param_3 == 0) {
        return;
      }
      if ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) {
        return;
      }
      if ((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 0x20) == 0) {
        return;
      }
      if (0.0 < *(float *)(param_2 + 0xdb0)) {
        return;
      }
      FUN_0046eca0("TC14_VLN",param_2 + 0x80,1 << (*(byte *)(param_2 + 0x280) & 0x1f));
      uVar6 = 0x3f000000;
    }
    else {
      fVar5 = (*(float *)(param_2 + 0x1dc) + 0.25) * *(float *)(iVar7 + 0x8c);
      if (fVar5 * fVar5 <= local_4) {
        return;
      }
      if (param_3 == 0) {
        if (*(int *)(param_2 + 0x79c) != 1) {
          return;
        }
        if (*(int *)(param_2 + 0x7a0) == 0) {
          return;
        }
      }
      uVar3 = *(undefined2 *)(iVar7 + 0x5c);
      *(uint *)(param_2 + 0xe20) = *(uint *)(param_2 + 0xe20) & 0xffffefff;
      *(undefined4 *)(param_2 + 0x778) = 0;
      *(undefined4 *)(param_2 + 0xd48) = 0;
      *(undefined2 *)(param_2 + 0x5a) = uVar3;
      *(undefined1 *)(param_2 + 0x7b5) = 0xb;
      *(int *)(param_2 + 0x798) = iVar7;
      *(undefined1 *)(param_2 + 0x7b3) = 0;
      FUN_0058d930(param_2,0);
      *(uint *)(param_2 + 0xe24) = *(uint *)(param_2 + 0xe24) | 0x200;
      cVar2 = *(char *)(*(int *)(param_2 + 0x798) + 0x61);
      if (cVar2 == '\x02') {
        if (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + 0x118) == 0) {
          *(undefined2 *)(param_2 + 0x7aa) = 0x45;
        }
        else {
          *(undefined2 *)(param_2 + 0x7aa) = 0x46;
        }
        FUN_00576960(0x261);
        FUN_00576960(0x26a);
      }
      else if (cVar2 == '\x03') {
        iVar7 = *(int *)(*(int *)(param_2 + 0x50) + 0xc);
        if ((*(int *)(iVar7 + 0x114) == 0) && (*(int *)(iVar7 + 0x118) != 0)) {
          *(undefined2 *)(param_2 + 0x7aa) = 0x46;
        }
        else {
          *(undefined2 *)(param_2 + 0x7aa) = 0x45;
        }
        FUN_0043a910(1);
        FUN_00576960(0x260);
        FUN_00576960(0x269);
      }
      else {
        *(undefined2 *)(param_2 + 0x7aa) = 0x18;
        if (*(char *)(*(int *)(param_2 + 0x798) + 0x61) == '\x01') {
          iVar7 = FUN_0055c690();
          if ((iVar7 == 0) || ((*(byte *)(*(int *)(param_2 + 0x798) + 99) & 4) == 0)) {
            FUN_0046eca0("TC14_VLA",param_2 + 0x80,1 << (*(byte *)(param_2 + 0x280) & 0x1f));
          }
          if ((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 0x20) != 0) {
            FUN_004aa240(param_2);
          }
        }
        else {
          iVar7 = FUN_0055c690();
          if ((iVar7 == 0) || ((*(byte *)(*(int *)(param_2 + 0x798) + 99) & 4) == 0)) {
            FUN_0046eca0("R2D2_VLA",param_2 + 0x80,1 << (*(byte *)(param_2 + 0x280) & 0x1f));
          }
        }
        FUN_00576960(0x25f);
        _DAT_00876d9c = _DAT_00876d9c | 4;
      }
      fVar9 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),
                                    (int)*(short *)(param_2 + 0x7aa),0,0,1);
      *(float *)(param_2 + 0x77c) = (float)fVar9;
      uVar6 = 0;
      if ((float)fVar9 <= 0.0) {
        *(undefined4 *)(param_2 + 0x77c) = 0x40000000;
        *(undefined4 *)(param_2 + 0xdb0) = 0;
        return;
      }
    }
    *(undefined4 *)(param_2 + 0xdb0) = uVar6;
  }
  return;
}

