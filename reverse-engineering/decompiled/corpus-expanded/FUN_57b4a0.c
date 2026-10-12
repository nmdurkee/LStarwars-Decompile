/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57b4a0; label: FUN_0057b4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057b4a0(int param_1)

{
  short *psVar1;
  undefined1 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_4;
  
  iVar5 = DAT_00951c4c;
  if (*(int *)(DAT_00951c4c + 0x184) == 0) {
    *(int *)(DAT_00951c4c + 0x184) = *DAT_00951c38;
  }
  uVar4 = (uint)*(ushort *)(iVar5 + 0x188);
  iVar5 = *(int *)(iVar5 + 0x184);
  *(undefined2 *)(iVar5 + uVar4 * 0x28) = 0xffff;
  psVar1 = (short *)(iVar5 + uVar4 * 0x28);
  *(undefined1 *)(psVar1 + 1) = DAT_00803e04;
  *(undefined1 *)((int)psVar1 + 3) = DAT_00803e05;
  *(undefined1 *)(psVar1 + 2) = DAT_00803e06;
  *(undefined1 *)((int)psVar1 + 5) = DAT_00803e07;
  uVar2 = DAT_00951c84;
  psVar1[4] = 0;
  psVar1[5] = 0;
  psVar1[6] = 0;
  psVar1[7] = 0;
  *(undefined1 *)(psVar1 + 3) = uVar2;
  *(undefined4 *)(psVar1 + 8) = _DAT_00951c88;
  *(undefined4 *)(psVar1 + 10) = _DAT_00803e08;
  *(undefined4 *)(psVar1 + 0xc) = _DAT_00803e0c;
  *(undefined4 *)(psVar1 + 0xe) = _DAT_00803e10;
  *(undefined4 *)(psVar1 + 0x10) = _DAT_00803e14;
  psVar1[0x12] = 0;
  psVar1[0x13] = 0;
  iVar5 = FUN_004f7fb0(param_1);
  while (iVar5 != 0) {
    iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"text_id");
    if (iVar5 == 0) {
      sVar3 = FUN_004f9e70(param_1);
      *psVar1 = sVar3;
    }
    else {
      iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"colour");
      if (iVar5 == 0) {
        fVar6 = (float10)FUN_004f8100(param_1);
        local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
        *(undefined1 *)(psVar1 + 1) = local_4;
        fVar6 = (float10)FUN_004f8100(param_1);
        local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
        *(undefined1 *)((int)psVar1 + 3) = local_4;
        fVar6 = (float10)FUN_004f8100(param_1);
        local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
        *(undefined1 *)(psVar1 + 2) = local_4;
        fVar6 = (float10)FUN_004f8100(param_1);
        local_4 = (undefined1)(int)ROUND(fVar6 * (float10)128.0);
        *(undefined1 *)((int)psVar1 + 5) = local_4;
      }
      else {
        iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076259c);
        if (iVar5 == 0) {
          fVar6 = (float10)FUN_004f8100(param_1);
          local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
          *(undefined1 *)(psVar1 + 1) = local_4;
        }
        else {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00762598);
          if (iVar5 == 0) {
            fVar6 = (float10)FUN_004f8100(param_1);
            local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
            *(undefined1 *)((int)psVar1 + 3) = local_4;
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758b40);
            if (iVar5 == 0) {
              fVar6 = (float10)FUN_004f8100(param_1);
              local_4 = (undefined1)(int)ROUND(fVar6 * (float10)255.0);
              *(undefined1 *)(psVar1 + 2) = local_4;
            }
            else {
              iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00762594);
              if (iVar5 == 0) {
                fVar6 = (float10)FUN_004f8100(param_1);
                local_4 = (undefined1)(int)ROUND(fVar6 * (float10)128.0);
                *(undefined1 *)((int)psVar1 + 5) = local_4;
              }
              else {
                iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"align");
                if (iVar5 == 0) {
                  iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"centre");
                  if (iVar5 == 0) {
                    *(undefined1 *)(psVar1 + 3) = 0;
                  }
                  else {
                    iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00762580);
                    if (iVar5 == 0) {
                      *(undefined1 *)(psVar1 + 3) = 1;
                    }
                    else {
                      iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"top_right");
                      if (iVar5 == 0) {
                        *(undefined1 *)(psVar1 + 3) = 9;
                      }
                      else {
                        iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"right");
                        if (iVar5 == 0) {
                          *(undefined1 *)(psVar1 + 3) = 8;
                        }
                        else {
                          iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"bottom_right");
                          if (iVar5 == 0) {
                            *(undefined1 *)(psVar1 + 3) = 0xc;
                          }
                          else {
                            iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"bottom");
                            if (iVar5 == 0) {
                              *(undefined1 *)(psVar1 + 3) = 4;
                            }
                            else {
                              iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"bottom_left");
                              if (iVar5 == 0) {
                                *(undefined1 *)(psVar1 + 3) = 6;
                              }
                              else {
                                iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075b86c)
                                ;
                                if (iVar5 == 0) {
                                  *(undefined1 *)(psVar1 + 3) = 2;
                                }
                                else {
                                  iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"top_left");
                                  if (iVar5 == 0) {
                                    *(undefined1 *)(psVar1 + 3) = 3;
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
                else {
                  iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"start_time");
                  if (iVar5 == 0) {
                    fVar6 = (float10)FUN_004f8100(param_1);
                    *(float *)(psVar1 + 4) = ABS((float)fVar6);
                  }
                  else {
                    iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"end_time");
                    if (iVar5 == 0) {
                      fVar6 = (float10)FUN_004f8100(param_1);
                      *(float *)(psVar1 + 6) = ABS((float)fVar6);
                    }
                    else {
                      iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_DAT_007624f8);
                      if (iVar5 == 0) {
                        fVar6 = (float10)FUN_004f8100(param_1);
                        *(float *)(psVar1 + 8) = (float)fVar6;
                        fVar6 = (float10)FUN_004f8100(param_1);
                        *(float *)(psVar1 + 10) = (float)fVar6;
                      }
                      else {
                        iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00757898);
                        if (iVar5 == 0) {
                          fVar6 = (float10)FUN_004f8100(param_1);
                          *(float *)(psVar1 + 8) = (float)fVar6;
                        }
                        else {
                          iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00757894);
                          if (iVar5 == 0) {
                            fVar6 = (float10)FUN_004f8100(param_1);
                            *(float *)(psVar1 + 10) = (float)fVar6;
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
    iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"scale");
    if (iVar5 == 0) {
      fVar6 = (float10)FUN_004f8100(param_1);
      *(float *)(psVar1 + 0xc) = (float)fVar6;
      *(float *)(psVar1 + 0xe) = (float)fVar6;
    }
    else {
      iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"x_scale");
      if (iVar5 == 0) {
        fVar6 = (float10)FUN_004f8100(param_1);
        *(float *)(psVar1 + 0xc) = (float)fVar6;
      }
      else {
        iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"y_scale");
        if (iVar5 == 0) {
          fVar6 = (float10)FUN_004f8100(param_1);
          *(float *)(psVar1 + 0xe) = (float)fVar6;
        }
        else {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"fit_width");
          if (iVar5 == 0) {
            fVar6 = (float10)FUN_004f8100(param_1);
            *(float *)(psVar1 + 0x10) = ABS((float)fVar6);
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"fade_time");
            if (iVar5 == 0) {
              fVar6 = (float10)FUN_004f8100(param_1);
              *(float *)(psVar1 + 0x12) = ABS((float)fVar6);
            }
          }
        }
      }
    }
    iVar5 = FUN_004f7fb0(param_1);
  }
  if (-1 < *psVar1) {
    sVar3 = *psVar1;
    iVar5 = FUN_0054b6c0();
    if (((sVar3 < iVar5) && (*(int *)(DAT_00926c20 + sVar3 * 4) != 0)) &&
       (*(float *)(psVar1 + 4) < *(float *)(psVar1 + 6))) {
      if ((0.0 < *(float *)(psVar1 + 0x12)) &&
         (*(float *)(psVar1 + 6) - *(float *)(psVar1 + 4) <
          *(float *)(psVar1 + 0x12) + *(float *)(psVar1 + 0x12))) {
        psVar1[0x12] = 0;
        psVar1[0x13] = 0;
      }
      *DAT_00951c38 = *DAT_00951c38 + 0x28;
      *(short *)(DAT_00951c4c + 0x188) = *(short *)(DAT_00951c4c + 0x188) + 1;
    }
  }
  return;
}

