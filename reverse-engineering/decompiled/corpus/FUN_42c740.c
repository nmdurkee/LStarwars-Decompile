/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42c740; label: FUN_0042c740
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c740(int param_1)

{
  float fVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int unaff_EDI;
  bool bVar11;
  float local_64;
  undefined4 local_60;
  int local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  uint local_40;
  float local_3c [2];
  float local_34;
  undefined1 local_30 [22];
  undefined1 local_1a;
  undefined1 local_b;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_64;
  local_58 = *(float *)(unaff_EDI + 0x30) - *(float *)(unaff_EDI + 0xe4);
  local_4c = *(float *)(unaff_EDI + 0xe4) + *(float *)(unaff_EDI + 0x30);
  local_54 = *(float *)(unaff_EDI + 0x34) - *(float *)(unaff_EDI + 0xe4);
  local_40 = (uint)(unaff_EDI - DAT_0291f664) / 0x220;
  local_48 = *(float *)(unaff_EDI + 0xe4) + *(float *)(unaff_EDI + 0x34);
  local_5c = 0;
  local_50 = *(float *)(unaff_EDI + 0x38) - *(float *)(unaff_EDI + 0xe4);
  local_44 = *(float *)(unaff_EDI + 0xe4) + *(float *)(unaff_EDI + 0x38);
  iVar10 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      uVar9 = *(uint *)(iVar10 + 0x1fc);
      if (((((uVar9 & 1) != 0) && ((uVar9 & 0x1000) != 0)) && (*(char *)(iVar10 + 0x28b) == '\0'))
         && ((cVar2 = *(char *)(iVar10 + 0x7b5),
             (*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000) == 0 &&
             ((*(byte *)(iVar10 + 0xe20) & 0x20) == 0)))) {
        if (*(char *)(unaff_EDI + 0x206) == '\0') {
          if (iVar10 == *(int *)(unaff_EDI + 0xd4)) {
            bVar11 = *(float *)(unaff_EDI + 0xfc) < 0.5;
          }
          else {
            if (*(char *)(iVar10 + 0x280) == -1) goto LAB_0042c87f;
            bVar11 = *(float *)(unaff_EDI + 0xfc) < 0.25;
          }
LAB_0042c879:
          if (bVar11) goto LAB_0042cec6;
        }
        else if ((*(uint *)(unaff_EDI + 0x108) & 0x8000) == 0) {
          bVar11 = *(int *)(unaff_EDI + 0xd4) == iVar10;
          goto LAB_0042c879;
        }
LAB_0042c87f:
        if (((((cVar2 != ';') && (cVar2 != '9')) &&
             ((cVar2 != '<' &&
              ((uVar5 = *(uint *)(unaff_EDI + 0x108), (uVar5 & 0x4000) == 0 ||
               ((int)*(char *)(unaff_EDI + 0x207) != (uint)*(byte *)(iVar10 + 0x28d))))))) &&
            (((uVar5 & 4) == 0 || ((char)uVar9 < '\0')))) &&
           ((((local_58 <= *(float *)(iVar10 + 0x184) && (*(float *)(iVar10 + 0x178) <= local_4c))
             && (local_50 <= *(float *)(iVar10 + 0x18c))) &&
            (*(float *)(iVar10 + 0x180) <= local_44)))) {
          if (param_1 == 0) {
LAB_0042c971:
            if ((uVar5 & 0x40) == 0) {
              if ((*(uint *)(*(int *)(*(int *)(iVar10 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) {
                iVar7 = FUN_0054fce0((float *)(unaff_EDI + 0x30),*(undefined4 *)(unaff_EDI + 0xe4),
                                     *(undefined4 *)(unaff_EDI + 0xe4),iVar10 + 0x80,
                                     *(undefined4 *)(iVar10 + 0xac),*(undefined4 *)(iVar10 + 0x1e0))
                ;
                if (iVar7 != 0) {
                  if (((*(byte *)(unaff_EDI + 0x144) & 2) == 0) ||
                     ((undefined *)(*(uint *)(unaff_EDI + 0x108) & 0x1000008) != &DAT_01000008)) {
                    FUN_0064ac90();
                  }
                  uVar9 = *(uint *)(unaff_EDI + 0x108);
                  if ((((uVar9 & 8) != 0) &&
                      (((uVar9 & 0x1000000) == 0 || ((*(byte *)(unaff_EDI + 0x144) & 2) == 0)))) &&
                     (((*(byte *)(iVar10 + 0x1fc) & 0x80) != 0 || ((uVar9 & 0x800000) == 0)))) {
                    iVar7 = *(char *)(iVar10 + 0x7b5) * 0x10;
                    local_60 = *(undefined4 *)(PTR_PTR_007fb0e4 + iVar7 + 0xc);
                    if (((*(uint *)(PTR_PTR_007fb0e4 + iVar7 + 8) & 0x4000000) == 0) &&
                       (((*(uint *)(PTR_PTR_007fb0e4 + iVar7 + 8) & 0xc000000) == 0 ||
                        ((*(uint *)(iVar10 + 0x7bc) & 0x20000) == 0)))) {
                      FUN_00549de0(PTR_DAT_008021b4,0x3e4ccccd,0,0);
                      FUN_0058ff10(iVar10,0);
                      FUN_0059cb00(iVar10);
                      fVar1 = *(float *)(iVar10 + 0xd30);
                      if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
                        iVar7 = FUN_0058b7f0(iVar10);
                        if (iVar7 == 0) {
                          if ((*(uint *)(unaff_EDI + 0x108) & 0x10000) == 0) {
                            uVar8 = *(undefined4 *)(unaff_EDI + 0xd4);
                          }
                          else {
                            uVar8 = 0;
                          }
                          FUN_00438230(uVar8,iVar10,*(undefined2 *)(unaff_EDI + 0x204),
                                       *(undefined2 *)(unaff_EDI + 0x218),0,1);
                        }
                        else {
                          FUN_0054a850(**(undefined4 **)(*(int *)(unaff_EDI + 0xd4) + 0xca4),
                                       0x3f000000,0);
                          FUN_0054a850(**(undefined4 **)(iVar10 + 0xca4),0x3f000000,0);
                        }
                      }
                      else {
                        FUN_00433be0(*(undefined4 *)(unaff_EDI + 0xd4),iVar10,
                                     *(undefined1 *)(iVar10 + 0xe38),0);
                      }
                    }
                    else {
                      FUN_0042c500();
                    }
                  }
                  if ((*(char *)(iVar10 + 0x28b) == '\0') && ((*(byte *)(iVar10 + 0x1fc) & 2) == 0))
                  {
                    if ((*(byte *)(unaff_EDI + 0x144) & 1) == 0) {
                      local_64 = *(float *)(*(int *)(*(int *)(iVar10 + 0x54) + 0x24) + 0x1c);
                      if (1.0 < *(float *)(iVar10 + 0xa4)) {
                        local_64 = local_64 / *(float *)(iVar10 + 0xa4);
                      }
                      FUN_005b3b30(local_3c,unaff_EDI + 0x80);
                      *(float *)(iVar10 + 0x68) = *(float *)(iVar10 + 0x68) + local_64 * local_3c[0]
                      ;
                      *(float *)(iVar10 + 0x70) = local_64 * local_34 + *(float *)(iVar10 + 0x70);
                    }
                    if (((*(uint *)(unaff_EDI + 0x108) & 0x2000000) != 0) &&
                       (((*(uint *)(unaff_EDI + 0x108) & 0x4000000) == 0 ||
                        ((*(byte *)(unaff_EDI + 0x144) & 2) != 0)))) {
                      local_64 = *(float *)(iVar10 + 0x5c) - *(float *)(unaff_EDI + 0x30);
                      uVar9 = FUN_005be2d0(local_64,*(float *)(iVar10 + 100) -
                                                    *(float *)(unaff_EDI + 0x38));
                      *(float *)(iVar10 + 0x200) =
                           (float)(&DAT_029899a0)[(uVar9 & 0xffff) >> 1] *
                           *(float *)(*(int *)(*(int *)(iVar10 + 0x54) + 0x24) + 0x1c);
                      *(float *)(iVar10 + 0x208) =
                           (float)(&DAT_029899a0)[(int)((uVar9 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                           *(float *)(*(int *)(*(int *)(iVar10 + 0x54) + 0x24) + 0x1c);
                    }
                  }
                }
              }
              goto LAB_0042cec6;
            }
          }
          else if (((*(uint *)(*(int *)(iVar10 + 0x54) + 4) & 0x2000) == 0) || ((uVar5 & 0x40) == 0)
                  ) {
            if ((*(float *)(iVar10 + 0x188) < local_54) || (local_48 < *(float *)(iVar10 + 0x17c)))
            goto LAB_0042cec6;
            goto LAB_0042c971;
          }
          if ((((*(byte *)(unaff_EDI + 0x144) & 2) != 0) ||
              (((*(short *)(unaff_EDI + 0x13e) == 0xcb &&
                (fVar1 = *(float *)(unaff_EDI + 0xfc), !NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5))
                ) && ((DAT_00951288 != 0 ||
                      (('\0' < *(char *)(iVar10 + 0x107f) &&
                       ((int)*(char *)(iVar10 + 0x107f) < (int)(uint)*(byte *)(iVar10 + 0x107e))))))
               ))) || ((*(short *)(unaff_EDI + 0x13e) != 0xcb &&
                       (local_64 = (float)((int)local_40 % 0xb),
                       fVar1 = (float)(int)local_64 * 0.05 + 0.75,
                       fVar1 < *(float *)(unaff_EDI + 0xfc) !=
                       (fVar1 == *(float *)(unaff_EDI + 0xfc)))))) {
            if ((*(uint *)(iVar10 + 0x1f8) & 0x40000) == 0) {
              sVar4 = *(short *)(unaff_EDI + 0x13e);
              if (sVar4 == 0xcb) {
                FUN_0046c400(iVar10,unaff_EDI + 0x30,1);
                FUN_0064ac90();
              }
              else if (sVar4 == 0xd0) {
                FUN_0046aad0(iVar10,unaff_EDI + 0x30,*(undefined2 *)(unaff_EDI + 0x13a),1);
                FUN_0064ac90();
              }
              else if (*(char *)(unaff_EDI + 0x206) == '\x03') {
                if (((*(uint *)(*(int *)(iVar10 + 0x54) + 4) & 0x2000) != 0) &&
                   (*(int *)(iVar10 + 0xcc4) != 0)) {
                  pbVar6 = *(byte **)(iVar10 + 0xcc4);
                  bVar3 = *pbVar6;
                  iVar7 = FUN_004d23e0(iVar10);
                  if ((int)(uint)bVar3 < iVar7) {
                    iVar7 = (uint)bVar3 * 3 + 0xf;
                    *(undefined4 *)(pbVar6 + iVar7 * 4) = *(undefined4 *)(unaff_EDI + 0x30);
                    *(undefined4 *)(pbVar6 + iVar7 * 4 + 4) = *(undefined4 *)(unaff_EDI + 0x34);
                    *(undefined4 *)(pbVar6 + iVar7 * 4 + 8) = *(undefined4 *)(unaff_EDI + 0x38);
                    *(undefined4 *)
                     (*(byte **)(iVar10 + 0xcc4) + (uint)**(byte **)(iVar10 + 0xcc4) * 4 + 0x14) =
                         *(undefined4 *)(unaff_EDI + 0x10c);
                    *(undefined4 *)
                     (*(byte **)(iVar10 + 0xcc4) + (uint)**(byte **)(iVar10 + 0xcc4) * 4 + 0x28) =
                         *(undefined4 *)(unaff_EDI + 0x110);
                    **(char **)(iVar10 + 0xcc4) = **(char **)(iVar10 + 0xcc4) + '\x01';
                    *(undefined4 *)(*(int *)(iVar10 + 0xcc4) + 8) = 0;
                    *(undefined1 *)(*(int *)(iVar10 + 0xcc4) + 3) = 0;
                    FUN_0064ac90();
                  }
                }
              }
              else {
                FUN_0046c610((int)sVar4,local_30);
                FUN_0046b1d0(PTR_DAT_00802c54,unaff_EDI + 0x30,local_b,local_1a,iVar10,1);
                FUN_0064ac90();
              }
            }
            else {
              FUN_0064ac90();
            }
          }
        }
      }
LAB_0042cec6:
      local_5c = local_5c + 1;
      iVar10 = iVar10 + 0x10d8;
    } while (local_5c < DAT_0093d500);
  }
  __security_check_cookie(local_4 ^ (uint)&local_64);
  return;
}

