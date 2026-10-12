/* REA806 native PC pseudocode, not original source. */

void FUN_006516a0(int param_1)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_4;
  
  FUN_00651530(DAT_0296201c);
  iVar3 = FUN_004f7fb0(param_1);
  do {
    if (iVar3 == 0) {
      iVar3 = DAT_0296201c * 0x40;
      puVar1 = (uint *)(iVar3 + 4 + DAT_02947b74);
      *puVar1 = *puVar1 & 0xffefffff;
      puVar1 = (uint *)(iVar3 + 4 + DAT_02947b74);
      *puVar1 = *puVar1 | 0x200000;
      FUN_004ef660(iVar3 + DAT_0292fda4,iVar3 + DAT_02947b74,0x40);
      DAT_0296201c = DAT_0296201c + 1;
      return;
    }
    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"disable");
    if (iVar3 == 0) {
      puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
      *puVar1 = *puVar1 | 0x40000;
    }
    else {
      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"comment");
      if (iVar3 == 0) {
        puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
        *puVar1 = *puVar1 | 0x80000;
      }
      else {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075782c);
        if (iVar3 == 0) {
          FUN_004f7fb0(param_1);
          FUN_004f1f40(&DAT_0293b318 + DAT_0296201c * 0x20,*(undefined4 *)(param_1 + 0x510),0x20);
          iVar3 = DAT_0296201c;
          iVar6 = DAT_0296201c * 0x20;
          iVar7 = DAT_0296201c * 0x40;
          *(undefined **)(iVar7 + DAT_02947b74) = &DAT_0293b318 + iVar6;
          uVar4 = FUN_00650430(&DAT_0293b318 + iVar6);
          uVar4 = uVar4 & 0xff;
          sVar2 = *(short *)(DAT_0292fda0 + uVar4 * 2);
          if (sVar2 == -1) {
            *(short *)(DAT_0292fda0 + uVar4 * 2) = (short)iVar3;
            *(undefined2 *)(iVar7 + 0x10 + DAT_02947b74) = 0xffff;
          }
          else {
            *(short *)(iVar7 + 0x10 + DAT_02947b74) = sVar2;
            *(short *)(DAT_0292fda0 + uVar4 * 2) = (short)iVar3;
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"fname");
          if (iVar3 == 0) {
            FUN_004f7fb0(param_1);
            FUN_004f1e80(*(undefined4 *)(param_1 + 0x510),&DAT_0075eaf8);
            puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
            uVar4 = 0;
            if ((*puVar1 & 0xc0000) == 0) {
              if (0 < (int)DAT_02962014) {
                iVar3 = 0;
                do {
                  iVar6 = FUN_004f8b10(*(undefined4 *)(iVar3 + DAT_02947d70),
                                       *(undefined4 *)(param_1 + 0x510));
                  if (iVar6 == 0) {
                    iVar3 = DAT_0296201c * 0x40;
                    puVar1 = (uint *)(iVar3 + 4 + DAT_02947b74);
                    *puVar1 = *puVar1 ^ (*(uint *)(iVar3 + 4 + DAT_02947b74) ^ uVar4) & 0x7fff;
                    *(undefined4 *)(iVar3 + 0x3c + DAT_02947b74) =
                         *(undefined4 *)(DAT_02947d70 + uVar4 * 0x1c);
                    (&DAT_02921888)[uVar4] = (&DAT_02921888)[uVar4] + 1;
                    break;
                  }
                  uVar4 = uVar4 + 1;
                  iVar3 = iVar3 + 0x1c;
                } while ((int)uVar4 < (int)DAT_02962014);
              }
              if (uVar4 == DAT_02962014) {
                iVar6 = DAT_02962018 * 0x40;
                iVar3 = DAT_02962014 * 0x1c;
                *(undefined **)(iVar3 + DAT_02947d70) = &DAT_02948f10 + iVar6;
                *(undefined4 *)(iVar3 + 4 + DAT_02947d70) = 0x75a;
                *(uint *)(iVar3 + 0xc + DAT_02947d70) = (uVar4 - DAT_0296202c) + 0x1000;
                *(undefined4 *)(iVar3 + 8 + DAT_02947d70) = 0;
                DAT_02962018 = DAT_02962018 + 1;
                FUN_004f1f40(&DAT_02948f10 + iVar6,*(undefined4 *)(param_1 + 0x510),0x40);
                iVar6 = DAT_0296201c;
                iVar3 = DAT_02947d70;
                (&DAT_02921888)[DAT_02962014] = 1;
                iVar6 = iVar6 * 0x40;
                *(undefined4 *)(iVar6 + 0x3c + DAT_02947b74) =
                     *(undefined4 *)(iVar3 + DAT_02962014 * 0x1c);
                puVar1 = (uint *)(iVar6 + 4 + DAT_02947b74);
                *puVar1 = *puVar1 ^ (*(uint *)(iVar6 + 4 + DAT_02947b74) ^ DAT_02962014) & 0x7fff;
                DAT_02962014 = DAT_02962014 + 1;
              }
            }
            else {
              *puVar1 = *puVar1 | 0x7fff;
              if (0 < (int)DAT_02962014) {
                iVar3 = 0;
                do {
                  iVar6 = FUN_004f8b10(*(undefined4 *)(iVar3 + DAT_02947d70),
                                       *(undefined4 *)(param_1 + 0x510));
                  if (iVar6 == 0) {
                    *(undefined4 *)(DAT_0296201c * 0x40 + 0x3c + DAT_02947b74) =
                         *(undefined4 *)(DAT_02947d70 + uVar4 * 0x1c);
                    (&DAT_02921888)[uVar4] = (&DAT_02921888)[uVar4] + 1;
                    break;
                  }
                  uVar4 = uVar4 + 1;
                  iVar3 = iVar3 + 0x1c;
                } while ((int)uVar4 < (int)DAT_02962014);
              }
              if (uVar4 == DAT_02962014) {
                iVar3 = DAT_02962018 * 0x40;
                DAT_02962018 = DAT_02962018 + 1;
                FUN_004f1f40(&DAT_02948f10 + iVar3,*(undefined4 *)(param_1 + 0x510),0x40);
                *(undefined4 **)(DAT_0296201c * 0x40 + 0x3c + DAT_02947b74) =
                     &DAT_02948ed0 + DAT_02962018 * 0x10;
              }
            }
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"pitch");
            if (iVar3 == 0) {
              uVar5 = FUN_004f9e70(param_1);
              *(undefined4 *)(DAT_0296201c * 0x40 + 8 + DAT_02947b74) = uVar5;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076d280);
              if (iVar3 == 0) {
                fVar8 = (float10)FUN_004f8100(param_1);
                local_4 = (float)fVar8;
                if (-1.0 <= local_4) {
                  if (1.0 < local_4) {
                    local_4 = 1.0;
                  }
                }
                else {
                  local_4 = -1.0;
                }
                *(float *)(DAT_0296201c * 0x40 + 0x18 + DAT_02947b74) = local_4;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076d27c);
                if (iVar3 == 0) {
                  iVar3 = FUN_004f9e70(param_1);
                  if (iVar3 < -0x80) {
                    iVar3 = -0x80;
                  }
                  else if (0x7f < iVar3) {
                    iVar3 = 0x7f;
                  }
                  *(char *)(DAT_0296201c * 0x40 + 0xc + DAT_02947b74) = (char)iVar3;
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00763b84);
                  if (iVar3 == 0) {
                    puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
                    *puVar1 = *puVar1 | 0x8000;
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"pitch_rnd");
                    if (iVar3 == 0) {
                      fVar8 = (float10)FUN_004f8100(param_1);
                      local_4 = (float)fVar8;
                      if (0.0 <= local_4) {
                        if (1.0 < local_4) {
                          local_4 = 1.0;
                        }
                      }
                      else {
                        local_4 = 0.0;
                      }
                      *(float *)(DAT_0296201c * 0x40 + 0x1c + DAT_02947b74) = local_4;
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"volume");
                      if (iVar3 == 0) {
                        iVar3 = FUN_004f9e70(param_1);
                        if (iVar3 < 0) {
                          iVar3 = 0;
                        }
                        else if (0x3fff < iVar3) {
                          iVar3 = 0x3fff;
                        }
                        *(short *)(DAT_0296201c * 0x40 + 0x12 + DAT_02947b74) = (short)iVar3;
                      }
                      else {
                        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"nofade");
                        if (iVar3 == 0) {
                          puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
                          *puVar1 = *puVar1 | 0x400000;
                        }
                        else {
                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"volume_rnd");
                          if (iVar3 == 0) {
                            fVar8 = (float10)FUN_004f8100(param_1);
                            local_4 = (float)fVar8;
                            if (-1.0 <= local_4) {
                              if (0.0 < local_4) {
                                local_4 = 0.0;
                              }
                            }
                            else {
                              local_4 = -1.0;
                            }
                            *(float *)(DAT_0296201c * 0x40 + 0x20 + DAT_02947b74) = local_4;
                          }
                          else {
                            iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076d254);
                            if (iVar3 == 0) {
                              fVar8 = (float10)FUN_004f8100(param_1);
                              local_4 = (float)fVar8;
                              if (local_4 < 0.0) {
                                local_4 = 0.0;
                              }
                              if (250.0 < local_4) {
                                local_4 = 250.0;
                              }
                              *(float *)(DAT_0296201c * 0x40 + 0x24 + DAT_02947b74) = local_4;
                            }
                            else {
                              iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                   &PTR_DAT_0076d250);
                              if (iVar3 == 0) {
                                fVar8 = (float10)FUN_004f8100(param_1);
                                local_4 = (float)fVar8;
                                if (local_4 < 0.0) {
                                  local_4 = 0.0;
                                }
                                if (250.0 < local_4) {
                                  local_4 = 250.0;
                                }
                                *(float *)(DAT_0296201c * 0x40 + 0x28 + DAT_02947b74) = local_4;
                              }
                              else {
                                iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"global");
                                if (iVar3 == 0) {
                                  puVar1 = (uint *)(DAT_0296201c * 0x40 + 4 + DAT_02947b74);
                                  *puVar1 = *puVar1 | 0x20000;
                                }
                                else {
                                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"rumble");
                                  if (iVar3 == 0) {
                                    fVar8 = (float10)FUN_004f8100(param_1);
                                    local_4 = (float)fVar8;
                                    iVar3 = FUN_004f9e70(param_1);
                                    if (0.0 <= local_4) {
                                      if (5.0 < local_4) {
                                        local_4 = 5.0;
                                      }
                                    }
                                    else {
                                      local_4 = 0.0;
                                    }
                                    iVar6 = DAT_0296201c * 0x40;
                                    *(float *)(iVar6 + 0x2c + DAT_02947b74) = local_4;
                                    if (iVar3 < 0) {
                                      iVar3 = 0;
                                    }
                                    else if (0xff < iVar3) {
                                      iVar3 = 0xff;
                                    }
                                    *(int *)(iVar6 + 0x30 + DAT_02947b74) = iVar3;
                                    fVar8 = (float10)FUN_004f8100(param_1);
                                    local_4 = (float)fVar8;
                                    if (0.0 <= local_4) {
                                      if (5.0 < local_4) {
                                        local_4 = 5.0;
                                      }
                                    }
                                    else {
                                      local_4 = 0.0;
                                    }
                                    *(float *)(DAT_0296201c * 0x40 + 0x34 + DAT_02947b74) = local_4;
                                    fVar8 = (float10)FUN_004f8100(param_1);
                                    local_4 = (float)fVar8;
                                    if (0.0 <= local_4) {
                                      if (5.0 < local_4) {
                                        local_4 = 5.0;
                                      }
                                    }
                                    else {
                                      local_4 = 0.0;
                                    }
                                    *(float *)(DAT_0296201c * 0x40 + 0x38 + DAT_02947b74) = local_4;
                                  }
                                  else {
                                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                                                         &DAT_0076d240);
                                    if (iVar3 == 0) {
                                      iVar3 = FUN_004f9e70(param_1);
                                      if (iVar3 < 0) {
                                        iVar3 = 0;
                                      }
                                      else if (0xffff < iVar3) {
                                        iVar3 = 0xffff;
                                      }
                                      *(short *)(DAT_0296201c * 0x40 + 0x16 + DAT_02947b74) =
                                           (short)iVar3;
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
            }
          }
        }
      }
    }
    iVar3 = FUN_004f7fb0(param_1);
  } while( true );
}

