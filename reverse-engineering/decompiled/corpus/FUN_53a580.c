/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53a580; label: FUN_0053a580
 */

void FUN_0053a580(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_18;
  iVar10 = 0;
  if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
    FUN_0053a390();
    __security_check_cookie(local_4 ^ (uint)&local_18);
    return;
  }
  uVar5 = FUN_00520fe0(1);
  *(undefined4 *)(DAT_009238e4 + 0x383cc) = uVar5;
  iVar7 = DAT_009238e4;
  uVar2 = *(uint *)(param_1 + 0x70);
  if ((uVar2 & 0x40) == 0) {
    uVar3 = *(uint *)(param_1 + 0x78);
    if ((uVar3 & 0x10) != 0) {
      if ((*(int *)(DAT_009238e4 + 0x383c8) != 0) &&
         (*(int *)(DAT_009238e4 + 0x383c8) == *(int *)(DAT_009238e4 + 0x383cc))) {
        FUN_00538900();
        __security_check_cookie(local_4 ^ (uint)&local_18);
        return;
      }
      goto LAB_0053abac;
    }
    if ((uVar3 & 0x100) != 0) {
      uVar5 = FUN_00520fe0(0);
      *(undefined4 *)(DAT_009238e4 + 0x383c8) = uVar5;
      if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
        FUN_00620f10(*(int *)(DAT_009238e4 + 0x383c8) + 0x18);
      }
      goto LAB_0053abac;
    }
    if ((uVar2 & 0x2000) != 0) {
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        DAT_00921f30 = (int)*(short *)(iVar10 + 0x30);
      }
      if ((*(uint *)(param_1 + 0x78) & 0x8000) == 0) {
        *(int *)(DAT_009238e4 + 0x371b4) = *(int *)(DAT_009238e4 + 0x371b4) + 0x14;
        if (600 < *(int *)(DAT_009238e4 + 0x371b4)) {
          *(undefined4 *)(DAT_009238e4 + 0x371b4) = 600;
        }
      }
      else {
        *(undefined4 *)(DAT_009238e4 + 0x371b4) = 0x14;
      }
      DAT_00921f30 = FUN_005be590(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x371b4));
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        *(short *)(iVar10 + 0x30) = (short)DAT_00921f30;
      }
      goto LAB_0053abac;
    }
    if ((uVar2 & 0x8000) != 0) {
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        DAT_00921f30 = (int)*(short *)(iVar10 + 0x30);
      }
      if ((*(uint *)(param_1 + 0x78) & 0x2000) == 0) {
        *(int *)(DAT_009238e4 + 0x371b4) = *(int *)(DAT_009238e4 + 0x371b4) + 0x14;
        if (600 < *(int *)(DAT_009238e4 + 0x371b4)) {
          *(undefined4 *)(DAT_009238e4 + 0x371b4) = 600;
        }
      }
      else {
        *(undefined4 *)(DAT_009238e4 + 0x371b4) = 0x14;
      }
      DAT_00921f30 = FUN_005be5b0(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x371b4));
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        *(short *)(iVar10 + 0x30) = (short)DAT_00921f30;
      }
      goto LAB_0053abac;
    }
    if ((uVar2 & 0x4000) != 0) {
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        *(float *)(iVar10 + 0x28) = *(float *)(iVar10 + 0x28) * 0.99;
      }
      goto LAB_0053abac;
    }
    if ((uVar2 & 0x1000) != 0) {
      iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
      if ((iVar10 != 0) && (iVar10 == *(int *)(DAT_009238e4 + 0x383cc))) {
        *(float *)(iVar10 + 0x28) = *(float *)(iVar10 + 0x28) * 1.01;
      }
      goto LAB_0053abac;
    }
    if (((uVar2 & 0x100) == 0) || ((uVar3 & 8) == 0)) {
      if (((uVar2 & 0x100) == 0) || ((uVar3 & 2) == 0)) goto LAB_0053abac;
      if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
        uVar5 = FUN_004f1470(DAT_009238e4 + 0x383c0,*(undefined4 *)(DAT_009238e4 + 0x383c8));
        *(undefined4 *)(DAT_009238e4 + 0x383c8) = uVar5;
        if (*(int *)(DAT_009238e4 + 0x383c8) != 0) goto LAB_0053ab38;
      }
      uVar5 = FUN_004f1450(DAT_009238e4 + 0x383c0);
LAB_0053ab1b:
      *(undefined4 *)(DAT_009238e4 + 0x383c8) = uVar5;
      if (*(int *)(DAT_009238e4 + 0x383c8) == 0) goto LAB_0053abac;
    }
    else {
      if (*(int *)(DAT_009238e4 + 0x383c8) == 0) {
LAB_0053ab0f:
        uVar5 = FUN_004f1440(DAT_009238e4 + 0x383c0);
        goto LAB_0053ab1b;
      }
      uVar5 = FUN_004f1460(DAT_009238e4 + 0x383c0,*(undefined4 *)(DAT_009238e4 + 0x383c8));
      *(undefined4 *)(DAT_009238e4 + 0x383c8) = uVar5;
      if (*(int *)(DAT_009238e4 + 0x383c8) == 0) goto LAB_0053ab0f;
    }
LAB_0053ab38:
    FUN_00620f10(*(int *)(DAT_009238e4 + 0x383c8) + 0x18);
    goto LAB_0053abac;
  }
  if (*(int *)(DAT_009238e4 + 0x383cc) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x40) != 0) {
      iVar7 = *(int *)(DAT_009238e4 + 0x383c8);
      if (iVar7 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = (int)*(char *)(iVar7 + 0x33);
      }
      uVar5 = FUN_00520e10(0,DAT_00921f30,iVar6);
      *(undefined4 *)(DAT_009238e4 + 0x383c8) = uVar5;
      if (*(int *)(DAT_009238e4 + 0x383c8) != 0) {
        if (iVar7 == 0) {
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x2c) = 0x3f800000;
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x28) = 0x3f800000;
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x24) = 0x3f800000;
        }
        else {
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x24) = *(undefined4 *)(iVar7 + 0x24);
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x28) = *(undefined4 *)(iVar7 + 0x28);
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x2c) = *(undefined4 *)(iVar7 + 0x2c);
        }
        do {
          iVar10 = iVar10 + 1;
          _sprintf(local_14,"Area%d",iVar10);
          iVar7 = FUN_004f1440(DAT_009238e4 + 0x383c0);
          while( true ) {
            if (iVar7 == 0) {
              pcVar9 = local_14;
              pcVar8 = (char *)(*(int *)(DAT_009238e4 + 0x383c8) + 8);
              do {
                cVar1 = *pcVar9;
                *pcVar8 = cVar1;
                pcVar9 = pcVar9 + 1;
                pcVar8 = pcVar8 + 1;
              } while (cVar1 != '\0');
              goto LAB_0053abac;
            }
            iVar6 = FUN_004f8b10(local_14,iVar7 + 8);
            if (iVar6 == 0) break;
            iVar7 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar7);
          }
        } while( true );
      }
    }
    goto LAB_0053abac;
  }
  if ((*(byte *)(param_1 + 0x78) & 0x40) == 0) {
    if (*(int *)(DAT_009238e4 + 0x383c8) == 0) goto LAB_0053abac;
    iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
    *(undefined4 *)(iVar10 + 0x18) = *(undefined4 *)(DAT_009238e4 + 0x28);
    *(undefined4 *)(iVar10 + 0x1c) = *(undefined4 *)(iVar7 + 0x2c);
    *(undefined4 *)(iVar10 + 0x20) = *(undefined4 *)(iVar7 + 0x30);
  }
  else {
    *(undefined4 *)(DAT_009238e4 + 0x383c8) = *(undefined4 *)(DAT_009238e4 + 0x383cc);
    DAT_00921f30 = (int)*(short *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x30);
    FUN_00620f10(*(int *)(DAT_009238e4 + 0x383c8) + 0x18);
  }
  if (*(int *)(DAT_009238e4 + 0x383c8) == 0) goto LAB_0053abac;
  iVar10 = *(int *)(DAT_009238e4 + 0x383c8);
  uVar2 = *(uint *)(param_1 + 0x70);
  if ((*(byte *)(iVar10 + 0x33) & 1) == 0) {
    if ((uVar2 & 0x2000) == 0) {
      if ((uVar2 & 0x8000) != 0) {
        fVar4 = *(float *)(iVar10 + 0x24) * 0.99;
        goto LAB_0053a6db;
      }
    }
    else {
      fVar4 = *(float *)(iVar10 + 0x24) * 1.01;
LAB_0053a6db:
      *(float *)(iVar10 + 0x24) = fVar4;
    }
    fVar4 = 1.01;
    if (((*(uint *)(param_1 + 0x70) & 0x1000) != 0) ||
       (fVar4 = 0.99, (*(uint *)(param_1 + 0x70) & 0x4000) != 0)) {
      *(float *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x2c) =
           fVar4 * *(float *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x2c);
    }
    goto LAB_0053abac;
  }
  if ((uVar2 & 0x2000) == 0) {
    if ((uVar2 & 0x8000) != 0) {
      fVar4 = *(float *)(iVar10 + 0x24) * 0.99;
      goto LAB_0053a691;
    }
  }
  else {
    fVar4 = *(float *)(iVar10 + 0x24) * 1.01;
LAB_0053a691:
    *(float *)(iVar10 + 0x24) = fVar4;
  }
  *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x2c) =
       *(undefined4 *)(*(int *)(DAT_009238e4 + 0x383c8) + 0x24);
LAB_0053abac:
  if (((*(int *)(DAT_009238e4 + 0x383c8) != 0) &&
      (iVar10 = *(int *)(DAT_009238e4 + 0x383c8), (*(byte *)(iVar10 + 0x33) & 1) != 0)) &&
     (*(float *)(iVar10 + 0x2c) != *(float *)(iVar10 + 0x24))) {
    if (*(float *)(iVar10 + 0x2c) <= *(float *)(iVar10 + 0x24)) {
      local_18 = *(undefined4 *)(iVar10 + 0x2c);
    }
    else {
      local_18 = *(undefined4 *)(iVar10 + 0x24);
    }
    *(undefined4 *)(iVar10 + 0x24) = local_18;
  }
  __security_check_cookie(local_4 ^ (uint)&local_18);
  return;
}

