/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5939a0; label: FUN_005939a0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005939a0(undefined4 param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,
                 undefined1 *param_6,undefined **param_7,code *param_8,undefined4 param_9,
                 undefined4 param_10)

{
  float fVar1;
  code cVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  undefined **ppuVar6;
  undefined1 *puVar7;
  code *pcVar8;
  uint *puVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  code *pcVar15;
  int *piVar16;
  uint uVar17;
  code *pcVar18;
  undefined2 *puVar19;
  uint uVar20;
  float10 fVar21;
  undefined **local_4720;
  undefined1 *local_471c;
  int local_4718;
  code *local_4714;
  uint *local_4710;
  int local_470c [9];
  float local_46e8 [9];
  int local_46c4 [9];
  float local_46a0 [9];
  undefined1 local_467c [12];
  undefined2 local_4670 [8794];
  byte abStack_1bc [440];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4720;
  local_4710 = param_2;
  local_4720 = param_7;
  local_4714 = param_8;
  if ((param_4 != -1) || (param_5 != -1)) {
    if (DAT_00955870 == (code *)0x0) {
      iVar12 = FUN_004fc860(param_1);
      if (iVar12 == 0) {
        __security_check_cookie(local_4 ^ (uint)&local_4720);
        return;
      }
      local_46a0[0] = 0.0;
      local_46e8[0] = 0.0;
      local_46a0[1] = 0.0;
      local_46e8[1] = 0.0;
      local_470c[0] = -1;
      local_46a0[2] = 0.0;
      local_46c4[0] = -1;
      local_46e8[2] = 0.0;
      local_470c[1] = 0xffffffff;
      local_46a0[3] = 0.0;
      local_46c4[1] = 0xffffffff;
      local_46e8[3] = 0.0;
      local_470c[2] = 0xffffffff;
      local_46a0[4] = 0.0;
      local_46c4[2] = 0xffffffff;
      local_46e8[4] = 0.0;
      local_470c[3] = 0xffffffff;
      local_46a0[5] = 0.0;
      local_46c4[3] = 0xffffffff;
      local_46e8[5] = 0.0;
      local_470c[4] = 0xffffffff;
      local_46a0[6] = 0.0;
      local_46c4[4] = 0xffffffff;
      local_46e8[6] = 0.0;
      local_470c[5] = 0xffffffff;
      local_46a0[7] = 0.0;
      local_46c4[5] = 0xffffffff;
      local_46e8[7] = 0.0;
      local_470c[6] = 0xffffffff;
      local_46a0[8] = 0.0;
      local_46c4[6] = 0xffffffff;
      local_46e8[8] = 0.0;
      local_470c[7] = 0xffffffff;
      local_46c4[7] = 0xffffffff;
      local_470c[8] = 0xffffffff;
      local_46c4[8] = 0xffffffff;
      _memset(local_467c,0,0x44c0);
      local_471c = (undefined1 *)*param_2;
      local_4718 = 0;
      puVar19 = local_4670;
      do {
        iVar13 = FUN_004fc5b0(iVar12);
        if ((iVar13 == 0) || (iVar13 = FUN_004f7fb0(iVar12), iVar13 == 0)) break;
        iVar13 = FUN_00592680();
        if ((iVar13 == -1) || (iVar14 = FUN_004f7fb0(iVar12), puVar7 = local_471c, iVar14 == 0)) {
          iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"locator");
          if (iVar13 == 0) {
            iVar13 = FUN_004f7fb0(iVar12);
            if ((iVar13 != 0) && (iVar13 = FUN_00592680(), iVar13 != -1)) {
              iVar14 = FUN_004f9e70(iVar12);
              piVar16 = local_470c + iVar13;
              *piVar16 = iVar14;
              if ((iVar14 < 0) || (0xf < iVar14)) {
LAB_00593fca:
                *piVar16 = -1;
              }
              else {
                iVar14 = FUN_004f7fb0(iVar12);
                while (iVar14 != 0) {
                  iVar14 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"xoffset");
                  if (iVar14 == 0) {
                    fVar21 = (float10)FUN_004f8100(iVar12);
                    local_46a0[iVar13] = (float)fVar21;
                  }
                  else {
                    iVar14 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"yoffset");
                    if (iVar14 == 0) {
                      fVar21 = (float10)FUN_004f8100(iVar12);
                      local_46e8[iVar13] = (float)fVar21;
                    }
                  }
                  iVar14 = FUN_004f7fb0(iVar12);
                }
              }
            }
          }
          else {
            iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"layer");
            if (((iVar13 == 0) && (iVar13 = FUN_004f7fb0(iVar12), iVar13 != 0)) &&
               (iVar13 = FUN_00592680(), iVar13 != -1)) {
              iVar14 = FUN_004f9e70(iVar12);
              piVar16 = local_46c4 + iVar13;
              *piVar16 = iVar14;
              if ((iVar14 < 0) || (0x1f < iVar14)) goto LAB_00593fca;
            }
          }
        }
        else {
          puVar19[-2] = 0xffff;
          puVar19[-4] = 0xffff;
          puVar19[-3] = 0xffff;
          puVar19[-1] = 0xffff;
          *puVar19 = 0xffff;
          puVar19[1] = 0xffff;
          *(undefined1 *)(puVar19 + 2) = 0xff;
          *(undefined1 *)((int)puVar19 + 5) = 0xff;
          *(undefined1 **)(puVar19 + -6) = local_471c;
          puVar19[3] = 0;
          *(undefined4 *)(puVar19 + 4) = 0;
          *(undefined4 *)(puVar19 + 6) = 0;
          uVar3 = *(undefined4 *)(iVar12 + 0x510);
          abStack_1bc[local_4718] = (byte)iVar13;
          FUN_004f1f10(local_471c,uVar3);
          iVar14 = FUN_004f1ff0(*(undefined4 *)(iVar12 + 0x510));
          local_471c = puVar7 + iVar14 + 1;
          FUN_004f1ff0(*(undefined4 *)(iVar12 + 0x510));
          if (((&PTR_s_hat_hair_00804ec8)[iVar13 * 3] == (undefined *)0x0) &&
             (local_4714 != (code *)0x0)) {
            uVar11 = (*local_4714)(*(undefined4 *)(puVar19 + -6));
            puVar19[-2] = uVar11;
          }
          iVar13 = FUN_004f7fb0(iVar12);
          ppuVar6 = local_4720;
          while (iVar13 != 0) {
            iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),&DAT_00757f40);
            if (iVar13 == 0) {
              iVar13 = FUN_004f7fb0(iVar12);
              if (iVar13 != 0) {
                uVar11 = FUN_0055b1c0(*(undefined4 *)(iVar12 + 0x510));
                puVar19[-4] = uVar11;
              }
            }
            else {
              iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"icon_from");
              if (iVar13 == 0) {
                iVar13 = FUN_004f7fb0(iVar12);
                if (iVar13 != 0) {
                  uVar11 = FUN_0055b1c0(*(undefined4 *)(iVar12 + 0x510));
                  puVar19[-3] = uVar11;
                }
              }
              else {
                iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"from_variant");
                if (iVar13 == 0) {
                  iVar13 = FUN_004f7fb0(iVar12);
                  if (iVar13 != 0) {
                    uVar10 = FUN_0055c0a0(*(undefined4 *)(iVar12 + 0x510));
                    *(undefined1 *)((int)puVar19 + 5) = uVar10;
                  }
                }
                else {
                  iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"no_hat");
                  if (iVar13 == 0) {
                    puVar19[3] = puVar19[3] | 1;
                  }
                  else {
                    iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"hat_off");
                    if (iVar13 == 0) {
                      puVar19[3] = puVar19[3] | 0x20;
                    }
                    else {
                      iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"cape_off");
                      if (iVar13 == 0) {
                        puVar19[3] = puVar19[3] | 0x40;
                      }
                      else {
                        iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"helmet");
                        if (iVar13 == 0) {
                          puVar19[3] = puVar19[3] | 2;
                        }
                        else {
                          iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"big_head");
                          if (iVar13 == 0) {
                            puVar19[3] = puVar19[3] | 4;
                          }
                          else {
                            iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"big_hat");
                            if (iVar13 == 0) {
                              puVar19[3] = puVar19[3] | 8;
                            }
                            else {
                              iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"not_demo");
                              if (iVar13 == 0) {
                                puVar19[3] = puVar19[3] | 0x10;
                              }
                              else {
                                iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"100_percent")
                                ;
                                if (iVar13 == 0) {
                                  iVar13 = FUN_004f7fb0(iVar12);
                                  if (iVar13 != 0) {
                                    iVar13 = FUN_004f29a0(*(undefined4 *)(iVar12 + 0x510));
                                    if (iVar13 == 1) {
                                      puVar19[3] = puVar19[3] | 0x80;
                                    }
                                    else if (iVar13 == 2) {
                                      puVar19[3] = puVar19[3] | 0x100;
                                    }
                                  }
                                }
                                else {
                                  iVar13 = FUN_004f8b10(*(undefined4 *)(iVar12 + 0x510),"default");
                                  if (iVar13 == 0) {
                                    iVar13 = FUN_004f7fb0(iVar12);
                                    if (iVar13 != 0) {
                                      iVar13 = FUN_004f29a0(*(undefined4 *)(iVar12 + 0x510));
                                      if (iVar13 == 1) {
                                        puVar19[3] = puVar19[3] | 0x200;
                                      }
                                      else if (iVar13 == 2) {
                                        puVar19[3] = puVar19[3] | 0x400;
                                      }
                                    }
                                  }
                                  else if (ppuVar6 != (undefined **)0x0) {
                                    (*(code *)ppuVar6)(puVar19 + -6,iVar12);
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
            }
            iVar13 = FUN_004f7fb0(iVar12);
          }
          local_4718 = local_4718 + 1;
          puVar19 = puVar19 + 0x14;
        }
      } while (local_4718 < 0x1b8);
      FUN_004fa300(iVar12);
      puVar9 = local_4710;
      if (0 < local_4718) {
        pcVar18 = (code *)((uint)(local_471c + 3) & 0xfffffffc);
        *local_4710 = (uint)pcVar18;
        local_4714 = pcVar18;
        _memset(pcVar18,0,0xc98);
        *puVar9 = *puVar9 + 0xc9b & 0xfffffffc;
        *(undefined2 *)(pcVar18 + 0x6c) = (undefined2)param_4;
        *(undefined2 *)(pcVar18 + 0x6e) = (undefined2)param_5;
        if (param_6 == (undefined1 *)0x0) {
          param_6 = &LAB_00592660;
        }
        *(undefined1 **)(pcVar18 + 0x170) = param_6;
        *(undefined4 *)(pcVar18 + 0x174) = param_9;
        *(undefined4 *)(pcVar18 + 0xa68) = param_10;
        local_4720 = &PTR_s_hat_hair_00804ec8;
        uVar20 = 0;
        pcVar18 = pcVar18 + 0x24;
        pcVar15 = local_4714;
        iVar12 = local_4718;
        do {
          fVar1 = local_46a0[uVar20];
          *(undefined ***)(pcVar18 + -0x24) = local_4720;
          *(uint *)pcVar18 = *local_4710;
          cVar2 = *(code *)(local_470c + uVar20);
          *(uint *)(pcVar18 + 0x24) = 0;
          pcVar15[uVar20 + 0x250] = cVar2;
          pcVar15[uVar20 + 0x25c] = *(code *)(local_46c4 + uVar20);
          uVar17 = *(uint *)pcVar18;
          *(float *)(pcVar18 + 0xc2c) = fVar1;
          iVar13 = 0;
          *(float *)(pcVar18 + 0xc50) = local_46e8[uVar20];
          if (0 < iVar12) {
            local_471c = local_467c;
            do {
              if (abStack_1bc[iVar13] == uVar20) {
                FUN_004ef660(uVar17,local_471c,0x28);
                *(uint *)(pcVar18 + 0x24) = *(uint *)(pcVar18 + 0x24) + 1;
                uVar17 = uVar17 + 0x28;
                pcVar15 = local_4714;
                iVar12 = local_4718;
              }
              local_471c = local_471c + 0x28;
              iVar13 = iVar13 + 1;
            } while (iVar13 < iVar12);
          }
          pcVar8 = local_4714;
          if (0 < (int)*(uint *)(pcVar18 + 0x24)) {
            *local_4710 = uVar17 + 3 & 0xfffffffc;
          }
          local_4720 = local_4720 + 3;
          uVar20 = uVar20 + 1;
          pcVar18 = pcVar18 + 4;
        } while ((int)local_4720 < 0x804f34);
        if (*(int *)(pcVar15 + 0x174) == 0) {
          *(uint *)(pcVar15 + 0x174) = *local_4710;
          *local_4710 = *local_4710 + 0x73 & 0xfffffffc;
        }
        pcVar18 = pcVar15 + 0xc3c;
        pcVar15 = pcVar15 + 0x24;
        local_4720 = (undefined **)0x9;
        do {
          iVar12 = 0;
          bVar5 = false;
          bVar4 = false;
          if (0 < *(int *)(pcVar15 + 0x24)) {
            iVar13 = 0;
            do {
              if ((bVar4) && (bVar5)) break;
              if ((*(ushort *)(iVar13 + 0x12 + *(int *)pcVar15) & 0x200) != 0) {
                *(short *)(pcVar18 + -0x14) = (short)iVar12;
                bVar4 = true;
              }
              if ((*(ushort *)(iVar13 + 0x12 + *(int *)pcVar15) & 0x400) != 0) {
                *(short *)pcVar18 = (short)iVar12;
                bVar5 = true;
              }
              iVar12 = iVar12 + 1;
              iVar13 = iVar13 + 0x28;
            } while (iVar12 < *(int *)(pcVar15 + 0x24));
          }
          pcVar15 = pcVar15 + 4;
          pcVar18 = pcVar18 + 2;
          local_4720 = (undefined **)((int)local_4720 + -1);
        } while (local_4720 != (undefined **)0x0);
        FUN_00593810(local_4714,0);
        DAT_00955870 = pcVar8;
      }
      __security_check_cookie(local_4 ^ (uint)&local_4720);
      return;
    }
    FUN_005925c0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_4720);
  return;
}

