/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52b3f0; label: FUN_0052b3f0
 */

void FUN_0052b3f0(int param_1)

{
  uint *puVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  void *_Dst;
  float10 fVar9;
  
  cVar3 = '\0';
  iVar4 = FUN_004fc5b0(param_1);
  do {
    if (iVar4 == 0) {
      return;
    }
    FUN_004f7fb0(param_1);
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
    if (iVar4 == 0) {
      return;
    }
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760420);
    if (iVar4 == 0) {
      FUN_004f7fb0(param_1);
      iVar4 = FUN_00512ea0();
      if (iVar4 == 0) {
        if (DAT_00922248 == 1) {
          if (DAT_00922220 == 0) {
            puVar8 = &DAT_00755ba8;
          }
          else {
            puVar8 = *(undefined **)(DAT_00922220 + 0x18);
          }
          FUN_00512870(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(DAT_0092221c + 8),puVar8);
        }
        else {
LAB_0052b910:
          if (DAT_00922220 == 0) {
            puVar8 = &DAT_00755ba8;
          }
          else {
            puVar8 = *(undefined **)(DAT_00922220 + 0x18);
          }
          FUN_00512850(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(DAT_0092221c + 8),puVar8);
        }
      }
      else if (((DAT_00922214 == (int *)0x0) || (DAT_00922218 == (uint *)0x0)) ||
              (*DAT_00922218 <= *DAT_00922214 + 0x2cU)) {
        FUN_00512850();
      }
      else {
        uVar5 = *DAT_00922214 + 0xf;
        _Dst = (void *)(uVar5 & 0xfffffff0);
        *DAT_00922214 = (uVar5 & 0xfffffff0) + 0x2c;
        _memset(_Dst,0,0x2c);
        if (_Dst != (void *)0x0) {
          _memset(_Dst,0,0x2c);
          FUN_004f1310(DAT_00922230,_Dst);
          *(int *)((int)_Dst + 0x1c) = iVar4;
          FUN_004f7fb0(param_1);
          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758460);
          if ((iVar4 == 0) ||
             (iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076041c), iVar4 == 0)) {
LAB_0052b6b8:
            *(undefined1 *)((int)_Dst + 0xc) = 0;
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007533c8);
            if (iVar4 == 0) {
              *(undefined1 *)((int)_Dst + 0xc) = 1;
            }
            else {
              iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007533c4);
              if (iVar4 == 0) {
                *(undefined1 *)((int)_Dst + 0xc) = 2;
              }
              else {
                iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760418);
                if (iVar4 == 0) {
                  *(undefined1 *)((int)_Dst + 0xc) = 3;
                }
                else {
                  iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760414);
                  if (iVar4 == 0) {
                    *(undefined1 *)((int)_Dst + 0xc) = 4;
                  }
                  else {
                    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760410);
                    if (iVar4 == 0) {
                      *(undefined1 *)((int)_Dst + 0xc) = 5;
                    }
                    else {
                      uVar7 = FUN_00513100(*(undefined4 *)(param_1 + 0x510),DAT_00922218);
                      *(undefined4 *)((int)_Dst + 0x14) = uVar7;
                      FUN_004f7fb0(param_1);
                      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758460);
                      if ((iVar4 == 0) ||
                         (iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0076041c),
                         iVar4 == 0)) goto LAB_0052b6b8;
                      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007533c8);
                      if (iVar4 == 0) {
                        *(undefined1 *)((int)_Dst + 0xc) = 1;
                      }
                      else {
                        iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007533c4);
                        if (iVar4 == 0) {
                          *(undefined1 *)((int)_Dst + 0xc) = 2;
                        }
                        else {
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760418);
                          if (iVar4 == 0) {
                            *(undefined1 *)((int)_Dst + 0xc) = 3;
                          }
                          else {
                            iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760414);
                            if (iVar4 == 0) {
                              *(undefined1 *)((int)_Dst + 0xc) = 4;
                            }
                            else {
                              iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00760410);
                              if (iVar4 == 0) {
                                *(undefined1 *)((int)_Dst + 0xc) = 5;
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
          FUN_004f7fb0(param_1);
          if (*(int *)((int)_Dst + 0x28) == 0) {
            iVar4 = FUN_004f8a70(*(undefined4 *)(param_1 + 0x510),"param");
            if (iVar4 == 0) {
              cVar2 = '\0';
              iVar4 = 0x18;
              do {
                if ((*(int *)(iVar4 + DAT_0092221c) != 0) &&
                   (iVar6 = FUN_004f8b10(*(int *)(iVar4 + DAT_0092221c),
                                         *(undefined4 *)(param_1 + 0x510)), iVar6 == 0)) {
                  *(char *)((int)_Dst + 0xd) = cVar2;
                  goto LAB_0052b735;
                }
                iVar4 = iVar4 + 8;
                cVar2 = cVar2 + '\x01';
              } while (iVar4 < 0x38);
            }
            else {
              cVar2 = FUN_004f29a0(iVar4);
              *(char *)((int)_Dst + 0xd) = cVar2;
              if ((-1 < cVar2) && (cVar2 < '\x04')) {
LAB_0052b735:
                *(ushort *)((int)_Dst + 0xe) = *(ushort *)((int)_Dst + 0xe) | 4;
              }
            }
            if ((*(byte *)((int)_Dst + 0xe) & 4) == 0) {
              iVar4 = 0;
              if (0 < DAT_00922244) {
                puVar8 = &DAT_009220f0;
                do {
                  if ((puVar8 != (undefined *)0x0) &&
                     (iVar6 = FUN_004f8b10(puVar8,*(undefined4 *)(param_1 + 0x510)), iVar6 == 0)) {
                    *(undefined4 *)((int)_Dst + 8) = (&DAT_00922110)[iVar4 * 9];
                    break;
                  }
                  iVar4 = iVar4 + 1;
                  puVar8 = puVar8 + 0x24;
                } while (iVar4 < DAT_00922244);
              }
              if (iVar4 == DAT_00922244) {
                fVar9 = (float10)FUN_005132a0(*(undefined4 *)(param_1 + 0x510));
                *(float *)((int)_Dst + 8) = (float)fVar9;
                puVar1 = DAT_00922218;
                if (DAT_00922254 != 0) {
                  *(ushort *)((int)_Dst + 0xe) = *(ushort *)((int)_Dst + 0xe) | 8;
                  *(char *)((int)_Dst + 0xd) = cVar3;
                  cVar3 = cVar3 + '\x01';
                  uVar7 = FUN_00513100(*(undefined4 *)(param_1 + 0x510),puVar1);
                  *(undefined4 *)((int)_Dst + 0x10) = uVar7;
                }
              }
            }
          }
          FUN_005132f0(_Dst);
        }
      }
    }
    else {
      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"OnMacro");
      if (iVar4 == 0) {
        FUN_004f7fb0(param_1);
        for (iVar4 = FUN_004f1440(DAT_0092221c + 0x48); iVar4 != 0;
            iVar4 = FUN_004f1460(DAT_0092221c + 0x48,iVar4)) {
          iVar6 = FUN_004f8b10(*(undefined4 *)(iVar4 + 8),*(undefined4 *)(param_1 + 0x510));
          if (iVar6 == 0) {
            FUN_00513990(iVar4 + 0xc,DAT_00922230,DAT_00922214,DAT_00922218);
            uVar7 = FUN_004f1450(DAT_00922230);
            FUN_005132f0(uVar7);
            goto LAB_0052b99d;
          }
        }
        if (DAT_00922248 != 1) goto LAB_0052b910;
        if (DAT_00922220 == 0) {
          puVar8 = &DAT_00755ba8;
        }
        else {
          puVar8 = *(undefined **)(DAT_00922220 + 0x18);
        }
        FUN_00512860(*(undefined4 *)(param_1 + 0x510),*(undefined4 *)(DAT_0092221c + 8),puVar8);
      }
      else {
        iVar4 = FUN_004f1f90(*(undefined4 *)(param_1 + 0x510),0x7b);
        if (iVar4 == 0) {
          if (DAT_00922248 == 1) {
            if (DAT_00922220 == 0) {
              puVar8 = &DAT_00755ba8;
            }
            else {
              puVar8 = *(undefined **)(DAT_00922220 + 0x18);
            }
            FUN_00512870(*(undefined4 *)(DAT_0092221c + 8),puVar8);
          }
          else {
            if (DAT_00922220 == 0) {
              puVar8 = &DAT_00755ba8;
            }
            else {
              puVar8 = *(undefined **)(DAT_00922220 + 0x18);
            }
            FUN_00512850(*(undefined4 *)(DAT_0092221c + 8),puVar8);
          }
        }
      }
    }
LAB_0052b99d:
    iVar4 = FUN_004fc5b0(param_1);
  } while( true );
}

