/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a7da0; label: FUN_004a7da0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7da0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  float **ppfVar8;
  float10 fVar9;
  float local_134;
  undefined4 local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  undefined1 local_11c [12];
  float *local_110 [3];
  int local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  code *local_c4;
  code *local_bc;
  float local_84;
  undefined4 local_6c;
  float local_48 [17];
  
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x18e) != '\0') {
    iVar4 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x114);
    if ((iVar4 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar4 * 4) == 0)) {
      local_134 = *(float *)(param_1 + 0x80) -
                  (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x27a) >> 1] *
                  *(float *)(param_1 + 0x1dc);
      local_130 = *(undefined4 *)(param_1 + 0x84);
      local_12c = *(float *)(param_1 + 0x88) -
                  (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x27a) + 0x4000) >> 1 & 0x7fff]
                  * *(float *)(param_1 + 0x1dc);
    }
    else {
      local_134 = *(float *)(iVar4 * 0x40 + 0x834 + param_1);
      iVar4 = iVar4 * 0x40 + 0x834 + param_1;
      local_130 = *(undefined4 *)(iVar4 + 4);
      local_12c = *(float *)(iVar4 + 8);
    }
    if (*(char *)(param_1 + 0x7b5) == '7') {
      fVar1 = *(float *)(param_1 + 0x77c);
      fVar3 = _DAT_00925018 + *(float *)(param_1 + 0x77c);
      *(float *)(param_1 + 0x77c) = fVar3;
      if (*(float *)(param_1 + 0x784) < fVar3 == (*(float *)(param_1 + 0x784) == fVar3)) {
        fVar2 = *(float *)(param_1 + 0x784) * 0.5;
        if ((fVar1 < fVar2) && ((!NAN(fVar2) && !NAN(fVar3)) && fVar2 < fVar3 != (fVar2 == fVar3)))
        {
          FUN_00681f40("Lego_Poo",&local_134);
          iVar4 = FUN_0054fa60();
          local_128 = ((float)iVar4 * 1.5259022e-05 - 0.5) -
                      (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x27a) >> 1];
          iVar4 = FUN_0054fa60();
          local_124 = (float)iVar4 * 1.5259022e-05 - 0.5;
          iVar4 = FUN_0054fa60();
          local_120 = ((float)iVar4 * 1.5259022e-05 - 0.5) -
                      (float)(&DAT_029899a0)
                             [(int)(*(ushort *)(param_1 + 0x27a) + 0x4000) >> 1 & 0x7fff];
          iVar4 = FUN_0056e160(9);
          if (iVar4 != 0) {
            FUN_005b3b30(local_11c,&local_128);
            iVar4 = FUN_0054fa60();
            if (0.2 <= (float)iVar4 * 1.5259022e-05) {
              uVar5 = 100;
              if (0.8 <= (float)iVar4 * 1.5259022e-05) {
                uVar5 = 10;
              }
            }
            else {
              uVar5 = 1000;
            }
            FUN_0046d270(uVar5,0,0,0,&local_134,local_11c,0,0xffffffff,0x3f800000,0x49f42400,0,0,0);
          }
          iVar4 = FUN_0056e160(1);
          if (iVar4 != 0) {
            puVar7 = &DAT_00810210;
            ppfVar8 = local_110;
            for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
              *ppfVar8 = (float *)*puVar7;
              puVar7 = puVar7 + 1;
              ppfVar8 = ppfVar8 + 1;
            }
            FUN_0054fa60();
            FUN_00497de0();
            FUN_0054fa60();
            FUN_00497f60();
            FUN_0054fa60();
            uVar5 = FUN_00498040();
            FUN_005b4900(uVar5,&local_134);
            local_110[2] = &local_128;
            local_110[0] = local_48;
            FUN_005d0260(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x180,local_11c,&local_fc);
            local_f8 = local_fc;
            local_e8 = 0x18;
            local_f4 = 0xc0c00000;
            local_84 = _DAT_00925018;
            local_ec = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x180;
            local_6c = 0x40a00000;
            local_e4 = 0x390;
            local_104 = param_1;
            local_c4 = FUN_00571c50;
            local_bc = FUN_00571c80;
            iVar4 = FUN_0064d270(local_110);
            if (iVar4 != 0) {
              *(int *)(iVar4 + 0xd4) = param_1;
              uVar6 = FUN_0058b720(param_1);
              *(uint *)(iVar4 + 0x218) = uVar6 & 0xffff;
            }
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      }
    }
    else if ((((((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280) != 0) &&
               ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x80000000) != 0)) &&
              (*(char *)(param_1 + 0x7b5) == -1)) &&
             ((*(char *)(param_1 + 0x281) != '\0' && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0))))
            && ((DAT_007f3dc0 != '\0' || (DAT_007f3ec0 != '\0')))) {
      *(undefined1 *)(param_1 + 0x7b5) = 0x37;
      *(undefined4 *)(param_1 + 0x77c) = 0;
      *(undefined2 *)(param_1 + 0x7aa) = 1;
      *(undefined4 *)(param_1 + 0x784) = 0x3f19999a;
    }
    if (((*(byte *)(param_1 + 0xef4) & 0x10) == 0) ||
       ((*(char *)(param_1 + 0x280) != '\0' && (*(char *)(param_1 + 0x280) != '\x01')))) {
      *(undefined4 *)(param_1 + 0xd94) = 0;
    }
    else {
      iVar4 = FUN_0064ad80(0,0xffffffff,param_1);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0x3f800000;
      }
      fVar9 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0xd94),uVar5,_DAT_00925018);
      *(float *)(param_1 + 0xd94) = (float)fVar9;
      if (0.0 < (float)fVar9) {
        iVar4 = *(char *)(param_1 + 0x280) * 0xc;
        *(float *)(&DAT_0087b8a0 + iVar4) = local_134;
        *(undefined4 *)(&DAT_0087b8a4 + iVar4) = local_130;
        *(float *)(&DAT_0087b8a8 + iVar4) = local_12c;
        FUN_00651470("FliesLp",&DAT_0087b8a0 + *(char *)(param_1 + 0x280) * 0xc,
                     *(undefined4 *)(param_1 + 0xd94));
        return;
      }
    }
  }
  return;
}

