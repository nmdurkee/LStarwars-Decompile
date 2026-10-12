/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41b420; label: FUN_0041b420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b420(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  float *pfVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  float10 fVar9;
  float local_14;
  undefined1 local_c [12];
  
  local_14 = 2e+06;
  if (param_1 != 0) {
    if ((*(char *)(param_1 + 0x280) == -1) || (bVar5 = true, *(char *)(param_1 + 0x7b5) != '+')) {
      bVar5 = false;
    }
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0xdc8) = 0;
    }
    else {
      if ((param_3 != (undefined4 *)0x0) ||
         (param_3 = (undefined4 *)FUN_0055e300(param_1), param_3 != (undefined4 *)0x0)) {
        *(undefined4 *)(param_1 + 0x5c) = *param_3;
        *(undefined4 *)(param_1 + 0x60) = param_3[1];
        *(undefined4 *)(param_1 + 100) = param_3[2];
      }
      if (*(char *)(param_1 + 0x280) != -1) {
        *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) | 0x40;
      }
      FUN_0041af70(param_1);
      *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x5c);
      *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 100);
      *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x5c);
      _DAT_0093d620 = *(undefined4 *)(param_1 + 0x80);
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x60);
      pfVar1 = (float *)(param_1 + 0x5c);
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 100);
      DAT_0093d624 = *(undefined4 *)(param_1 + 0x84);
      DAT_0093d628 = *(undefined4 *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
      *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0xdf8) = DAT_0093b0cc;
      *(undefined4 *)(param_1 + 0xdfc) = DAT_0093b0d0;
      uVar4 = DAT_0093b0d4;
      *(undefined4 *)(param_1 + 0xe00) = DAT_0093b0d4;
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0xdf8);
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0xdfc);
      *(undefined4 *)(param_1 + 0x70) = uVar4;
      FUN_0055cd20(param_1);
      FUN_0055cc40(param_1);
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xf7ffffff;
      *(undefined1 *)(param_1 + 0x1079) = 0;
      *(undefined1 *)(param_1 + 0x28c) = 0;
      FUN_0055d2b0(param_1);
      FUN_0054a7f0(*(int *)(param_1 + 0xca4) + 0x40);
      FUN_00595840(pfVar1,param_1 + 0x4d8,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab4));
      FUN_0062e690(param_1 + 2000,0xffffffff);
      *(undefined1 *)(param_1 + 0x671) = 0xff;
      *(undefined2 *)(param_1 + 0x672) = 0xffff;
      if (*(int *)(PTR_DAT_00802c54 + 0x2988) != 0) {
        if ((DAT_00803874 != -1) &&
           (*(char *)(DAT_00803874 * 0x13c + 0x32 + **(int **)(PTR_DAT_00802c54 + 0x2988)) != '\0'))
        {
          DAT_00801e38 = DAT_00803874;
          DAT_007f10f4 = DAT_00803874;
        }
        FUN_00541bc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),pfVar1,
                     (int)*(char *)(param_1 + 0x671),(int)*(short *)(param_1 + 0x672),
                     param_1 + 0x670);
        FUN_0053f380(param_1 + 0x7cc);
        if ((*(char *)(param_1 + 0x280) < '\x02') && (*(char *)(param_1 + 0x671) != -1)) {
          if ((DAT_0087b01c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b01c)) {
            if ((DAT_0087af80 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af80)) {
              iVar8 = *(char *)(param_1 + 0x671) * 0x13c;
              if ((*(byte *)(**(int **)(PTR_DAT_00802c54 + 0x2988) + 0x68 + iVar8) & 1) == 0) {
                *pfVar1 = *(float *)(param_1 + 0x678);
                *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x67c);
                *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x680);
                if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
                    (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
                  if (param_1 == DAT_0093d7f0) {
                    uVar4 = 0xbf800000;
                  }
                  else {
                    uVar4 = 0x3f800000;
                  }
                  FUN_005b3b30(local_c,*(int *)(**(int **)(PTR_DAT_00802c54 + 0x2988) + 0x34 + iVar8
                                               ) + 0x48 + *(short *)(param_1 + 0x672) * 0x80);
                  FUN_005b3830(local_c,local_c,uVar4);
                  FUN_005b37d0(pfVar1,pfVar1,local_c);
                }
                *(float *)(param_1 + 0x80) = *pfVar1;
                *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x60);
                *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 100);
                *(float *)(param_1 + 0x98) = *pfVar1;
                _DAT_0093d620 = *(undefined4 *)(param_1 + 0x80);
                *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x60);
                *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 100);
                DAT_0093d624 = *(undefined4 *)(param_1 + 0x84);
                DAT_0093d628 = *(undefined4 *)(param_1 + 0x88);
                *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
                *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
                *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
              }
              param_4 = 0;
            }
          }
          else {
            *pfVar1 = *(float *)(param_1 + 0x678);
            *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x67c);
            *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x680);
            fVar9 = (float10)FUN_004aa5a0(param_1);
            local_14 = (float)fVar9;
            param_4 = 0;
            if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0dc) && (DAT_0087aa20 != '\0')) {
              *pfVar1 = *pfVar1 + 12.0;
            }
          }
        }
      }
      cVar2 = *(char *)(param_1 + 0x280);
      if ((cVar2 < '\0') || (uVar7 = (uint)cVar2, '\a' < cVar2)) {
        uVar7 = (uint)*(byte *)(param_1 + 0x28d);
      }
      *(undefined2 *)(param_1 + 0x278) = 0;
      uVar3 = (&DAT_0093d5ac)[uVar7 * 8];
      *(undefined2 *)(param_1 + 0x5a) = uVar3;
      *(undefined2 *)(param_1 + 0x58) = uVar3;
      *(undefined2 *)(param_1 + 0x27a) = uVar3;
      *(undefined2 *)(param_1 + 0x27c) = 0;
      FUN_005b3710(param_1 + 0xf30,0x3f800000,uVar3);
      *(undefined4 *)(param_1 + 0xc44) = 0x3f800000;
      *(undefined4 *)(param_1 + 0xc48) = 0;
      FUN_00499ca0(param_1,0,1);
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xf7ffffff;
      *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfdfbffff;
      *(undefined1 *)(param_1 + 0x288) = 1;
      *(undefined1 *)(param_1 + 0x1079) = 0;
      *(undefined1 *)(param_1 + 0x28c) = 0;
      *(undefined1 *)(param_1 + 0x1078) = 0;
      FUN_005728a0(param_1);
      if (local_14 == 2e+06) {
        fVar9 = (float10)FUN_00498480(param_1);
        local_14 = (float)fVar9;
      }
      if ((param_4 == 0) || ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0)) {
        if (local_14 != 2e+06) {
          *(float *)(param_1 + 0x60) = local_14;
          *(float *)(param_1 + 0x80) = *pfVar1;
          *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 100);
          *(float *)(param_1 + 0x98) = *pfVar1;
          _DAT_0093d620 = *(undefined4 *)(param_1 + 0x80);
          *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 100);
          DAT_0093d624 = *(undefined4 *)(param_1 + 0x84);
          DAT_0093d628 = *(undefined4 *)(param_1 + 0x88);
          *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
          *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
          *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
        }
      }
      else {
        FUN_00572660(param_1,0);
      }
      FUN_00466820(param_1);
      FUN_0055d6a0(param_1,1,1,0xffffffff,*(undefined4 *)(PTR_DAT_00802c54 + 0x13c));
      cVar2 = DAT_00802bd4;
      if ((((DAT_0093b2ac & 2) != 0) || (*(char *)(param_1 + 0x28b) != '\0')) || (bVar5)) {
        *(char *)(param_1 + 0x107f) = DAT_00802bd4;
        if ((int)(uint)*(byte *)(param_1 + 0x107e) < (int)cVar2) {
          *(byte *)(param_1 + 0x107f) = *(byte *)(param_1 + 0x107e);
        }
        *(undefined1 *)(param_1 + 0xe39) = 4;
      }
      if ((DAT_0093b2ac & 8) != 0) {
        iVar8 = *(char *)(param_1 + 0x280) * 0x10;
        if ((&DAT_0093d51b)[iVar8] != '\0') {
          *(undefined1 *)(param_1 + 0xe32) = 1;
        }
        *(undefined1 *)(param_1 + 0xe39) = (&DAT_0093d519)[iVar8];
      }
      FUN_00414ad0(param_1);
      *(float *)(param_1 + 0x1b4) = *pfVar1;
      *(float *)(param_1 + 0x10bc) = *pfVar1;
      *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x10c0) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 100);
      *(undefined4 *)(param_1 + 0x10c4) = *(undefined4 *)(param_1 + 100);
      if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) {
        *(undefined4 *)(param_1 + 0xdc8) = 0;
      }
      else {
        uVar6 = FUN_0054a240(param_1,*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                             *(undefined4 *)(PTR_DAT_00802c54 + 0x11c));
        *(undefined1 *)(param_1 + 0xe3c) = uVar6;
        fVar9 = (float10)FUN_004999e0(param_1,0);
        *(float *)(param_1 + 0xdc8) = (float)fVar9;
      }
      if (0.0 < *(float *)(param_1 + 0xdc8)) {
        *(float *)(param_1 + 0x68) =
             (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x58) >> 1] * *(float *)(param_1 + 0xdc8);
        *(float *)(param_1 + 0x70) =
             (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x58) + 0x4000) >> 1 & 0x7fff] *
             *(float *)(param_1 + 0xdc8);
      }
    }
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xfffdfa83;
    *(undefined4 *)(param_1 + 0xff8) = 0x3f800000;
    *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) | 0x80;
    *(undefined4 *)(param_1 + 0x1010) = 0;
    *(undefined4 *)(param_1 + 0xda8) = 0;
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x8000;
    *(undefined4 *)(param_1 + 0xd78) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x28b) = 0;
    *(undefined1 *)(param_1 + 0xe37) = 0;
    *(undefined4 *)(param_1 + 0x218) = 0x49f42400;
    *(undefined1 *)(param_1 + 0x289) = 0;
    *(uint *)(param_1 + 0x1f8) = (*(uint *)(param_1 + 0x1f8) | 0x100) ^ 0x100;
    *(undefined4 *)(param_1 + 0xdbc) = 0;
    *(undefined4 *)(param_1 + 0xf10) = 0;
    *(undefined4 *)(param_1 + 0xc64) = 0xbf800000;
    *(undefined4 *)(param_1 + 0xde0) = 0;
  }
  return;
}

