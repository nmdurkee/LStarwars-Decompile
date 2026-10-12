/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504100; label: FUN_00504100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00504100(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0x0;
  puVar7 = (undefined4 *)0x0;
  iVar4 = FUN_004fc5b0(param_1);
  if (iVar4 == 0) {
    return (undefined4 *)0x0;
  }
  do {
    FUN_004f7fb0(param_1);
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"ENDSCRIPT");
    if (iVar4 == 0) {
      return local_4;
    }
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"STARTCUTSCENEINST");
    if (iVar4 == 0) {
      puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
      *param_2 = (int)(puVar8 + 3);
      *puVar8 = 0;
      puVar8[2] = 0;
      puVar8[1] = 0;
      puVar2 = puVar8;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = puVar8;
        puVar2 = local_4;
      }
      local_4 = puVar2;
      FUN_004f7fb0(param_1);
      puVar8[2] = *param_2;
      pcVar9 = *(char **)(param_1 + 0x510);
      pcVar5 = pcVar9;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
LAB_005041a9:
      *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)(pcVar9 + 1)));
      pcVar9 = *(char **)(param_1 + 0x510);
      pcVar5 = (char *)puVar8[2];
LAB_00504adb:
      _sprintf(pcVar5,pcVar9);
    }
    else {
      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"PLAYCUTSCENEINST");
      if (iVar4 != 0) {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"CHAINCUTSCENEINST");
        if (iVar4 == 0) {
          puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
          *param_2 = (int)(puVar8 + 4);
          *puVar8 = 0;
          puVar8[2] = 0;
          puVar8[3] = 0;
          puVar8[1] = 2;
          puVar2 = puVar8;
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = puVar8;
            puVar2 = local_4;
          }
          local_4 = puVar2;
          FUN_004f7fb0(param_1);
          puVar8[2] = *param_2;
          pcVar5 = *(char **)(param_1 + 0x510);
          pcVar9 = pcVar5 + 1;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
          _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
          FUN_004f7fb0(param_1);
          puVar8[3] = *param_2;
          pcVar5 = *(char **)(param_1 + 0x510);
          pcVar9 = pcVar5 + 1;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
          pcVar9 = *(char **)(param_1 + 0x510);
          pcVar5 = (char *)puVar8[3];
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"REPEATCUTSCENEINST");
          if (iVar4 == 0) {
            puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
            *param_2 = (int)(puVar8 + 4);
            *puVar8 = 0;
            puVar8[2] = 0;
            puVar8[3] = 0;
            puVar8[1] = 3;
            puVar2 = puVar8;
            if (puVar7 != (undefined4 *)0x0) {
              *puVar7 = puVar8;
              puVar2 = local_4;
            }
            local_4 = puVar2;
            FUN_004f7fb0(param_1);
            puVar8[2] = *param_2;
            pcVar5 = *(char **)(param_1 + 0x510);
            pcVar9 = pcVar5 + 1;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
            _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
            uVar6 = FUN_004f9e70(param_1);
            puVar8[3] = uVar6;
            goto LAB_00504ae3;
          }
          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"RESETCUTSCENEINST");
          if (iVar4 == 0) {
            puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
            *param_2 = (int)(puVar8 + 3);
            *puVar8 = 0;
            puVar8[2] = 0;
            puVar8[1] = 4;
            puVar2 = puVar8;
            if (puVar7 != (undefined4 *)0x0) {
              *puVar7 = puVar8;
              puVar2 = local_4;
            }
            local_4 = puVar2;
            FUN_004f7fb0(param_1);
            puVar8[2] = *param_2;
            pcVar9 = *(char **)(param_1 + 0x510);
            pcVar5 = pcVar9;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
LAB_00504449:
            *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)(pcVar9 + 1)));
            pcVar9 = *(char **)(param_1 + 0x510);
            pcVar5 = (char *)puVar8[2];
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"PAUSECUTSCENEINST");
            if (iVar4 == 0) {
              puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
              *param_2 = (int)(puVar8 + 3);
              *puVar8 = 0;
              puVar8[2] = 0;
              puVar8[1] = 0xc;
              puVar2 = puVar8;
              if (puVar7 != (undefined4 *)0x0) {
                *puVar7 = puVar8;
                puVar2 = local_4;
              }
              local_4 = puVar2;
              FUN_004f7fb0(param_1);
              puVar8[2] = *param_2;
              pcVar9 = *(char **)(param_1 + 0x510);
              pcVar5 = pcVar9;
              do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
              } while (cVar1 != '\0');
              goto LAB_005041a9;
            }
            iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"UNPAUSECUTSCENEINST");
            if (iVar4 != 0) {
              iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"SETTRIGGERFLAG");
              if (iVar4 == 0) {
                puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                *param_2 = (int)(puVar8 + 4);
                *puVar8 = 0;
                puVar8[2] = 0;
                puVar8[3] = 0;
                puVar8[1] = 5;
                puVar2 = puVar8;
                if (puVar7 != (undefined4 *)0x0) {
                  *puVar7 = puVar8;
                  puVar2 = local_4;
                }
                local_4 = puVar2;
                uVar3 = FUN_004f9e70(param_1);
                *(undefined1 *)(puVar8 + 2) = uVar3;
                FUN_004f7fb0(param_1);
                puVar8[3] = *param_2;
                pcVar5 = *(char **)(param_1 + 0x510);
                pcVar9 = pcVar5 + 1;
                do {
                  cVar1 = *pcVar5;
                  pcVar5 = pcVar5 + 1;
                } while (cVar1 != '\0');
                *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                _sprintf((char *)puVar8[3],*(char **)(param_1 + 0x510));
                FUN_004f7fb0(param_1);
                iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed9c);
                *(bool *)((int)puVar8 + 9) = iVar4 == 0;
              }
              else {
                iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"RESETTRIGGER");
                if (iVar4 == 0) {
                  puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                  *param_2 = (int)(puVar8 + 3);
                  *puVar8 = 0;
                  puVar8[2] = 0;
                  puVar8[1] = 6;
                  puVar2 = puVar8;
                  if (puVar7 != (undefined4 *)0x0) {
                    *puVar7 = puVar8;
                    puVar2 = local_4;
                  }
                  local_4 = puVar2;
                  FUN_004f7fb0(param_1);
                  puVar8[2] = *param_2;
                  pcVar5 = *(char **)(param_1 + 0x510);
                  pcVar9 = pcVar5 + 1;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                  pcVar5 = (char *)puVar8[2];
                  goto LAB_00504ad3;
                }
                iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"SETVISIBILITY");
                if (iVar4 == 0) {
                  puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                  *param_2 = (int)(puVar8 + 4);
                  *puVar8 = 0;
                  puVar8[2] = 0;
                  puVar8[3] = 0;
                  puVar8[1] = 7;
                  puVar2 = puVar8;
                  if (puVar7 != (undefined4 *)0x0) {
                    *puVar7 = puVar8;
                    puVar2 = local_4;
                  }
                  local_4 = puVar2;
                  FUN_004f7fb0(param_1);
                  puVar8[3] = *param_2;
                  pcVar5 = *(char **)(param_1 + 0x510);
                  pcVar9 = pcVar5 + 1;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                  *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                  _sprintf((char *)puVar8[3],*(char **)(param_1 + 0x510));
                  FUN_004f7fb0(param_1);
                  iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed9c);
                  *(bool *)(puVar8 + 2) = iVar4 == 0;
                }
                else {
                  iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"IFPARAM");
                  if (iVar4 == 0) {
                    puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                    *param_2 = (int)(puVar8 + 6);
                    *puVar8 = 0;
                    puVar8[2] = 0;
                    puVar8[3] = 0;
                    puVar8[4] = 0;
                    puVar8[5] = 0;
                    puVar8[1] = 8;
                    puVar2 = puVar8;
                    if (puVar7 != (undefined4 *)0x0) {
                      *puVar7 = puVar8;
                      puVar2 = local_4;
                    }
                    local_4 = puVar2;
                    uVar6 = FUN_004f9e70(param_1);
                    puVar8[2] = uVar6;
                    uVar6 = FUN_004f9e70(param_1);
                    puVar8[3] = uVar6;
                    uVar6 = FUN_00504100(param_1,param_2,param_3);
                    puVar8[4] = uVar6;
                    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed6c);
                    if (iVar4 == 0) {
                      uVar6 = FUN_00504100(param_1,param_2,param_3);
                      puVar8[5] = uVar6;
                    }
                  }
                  else {
                    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"SETPARAM");
                    if (iVar4 == 0) {
                      puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                      *param_2 = (int)(puVar8 + 4);
                      *puVar8 = 0;
                      puVar8[2] = 0;
                      puVar8[3] = 0;
                      puVar8[1] = 9;
                      puVar2 = puVar8;
                      if (puVar7 != (undefined4 *)0x0) {
                        *puVar7 = puVar8;
                        puVar2 = local_4;
                      }
                      local_4 = puVar2;
                      uVar6 = FUN_004f9e70(param_1);
                      puVar8[2] = uVar6;
                      uVar6 = FUN_004f9e70(param_1);
                      puVar8[3] = uVar6;
                    }
                    else {
                      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"IFTRIGGERPULLED");
                      if (iVar4 == 0) {
                        puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                        *param_2 = (int)(puVar8 + 5);
                        *puVar8 = 0;
                        puVar8[2] = 0;
                        puVar8[3] = 0;
                        puVar8[4] = 0;
                        puVar8[1] = 10;
                        puVar2 = puVar8;
                        if (puVar7 != (undefined4 *)0x0) {
                          *puVar7 = puVar8;
                          puVar2 = local_4;
                        }
                        local_4 = puVar2;
                        FUN_004f7fb0(param_1);
                        puVar8[2] = *param_2;
                        pcVar5 = *(char **)(param_1 + 0x510);
                        pcVar9 = pcVar5 + 1;
                        do {
                          cVar1 = *pcVar5;
                          pcVar5 = pcVar5 + 1;
                        } while (cVar1 != '\0');
                        *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                        _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
                        uVar6 = FUN_00504100(param_1,param_2,param_3);
                        puVar8[3] = uVar6;
                        iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed6c);
                        if (iVar4 == 0) {
                          uVar6 = FUN_00504100(param_1,param_2,param_3);
                          puVar8[4] = uVar6;
                        }
                      }
                      else {
                        iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"IFTRIGGERNOTPULLED");
                        if (iVar4 == 0) {
                          puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                          *param_2 = (int)(puVar8 + 5);
                          *puVar8 = 0;
                          puVar8[2] = 0;
                          puVar8[3] = 0;
                          puVar8[4] = 0;
                          puVar8[1] = 10;
                          puVar2 = puVar8;
                          if (puVar7 != (undefined4 *)0x0) {
                            *puVar7 = puVar8;
                            puVar2 = local_4;
                          }
                          local_4 = puVar2;
                          FUN_004f7fb0(param_1);
                          puVar8[2] = *param_2;
                          pcVar5 = *(char **)(param_1 + 0x510);
                          pcVar9 = pcVar5 + 1;
                          do {
                            cVar1 = *pcVar5;
                            pcVar5 = pcVar5 + 1;
                          } while (cVar1 != '\0');
                          *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                          _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
                          uVar6 = FUN_00504100(param_1,param_2,param_3);
                          puVar8[4] = uVar6;
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed6c);
                          if (iVar4 == 0) {
                            uVar6 = FUN_00504100(param_1,param_2,param_3);
                            puVar8[3] = uVar6;
                          }
                        }
                        else {
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"ENABLETRIGGER");
                          if (iVar4 == 0) {
                            puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                            *param_2 = (int)(puVar8 + 3);
                            *puVar8 = 0;
                            puVar8[2] = 0;
                            puVar8[1] = 0xb;
                            puVar2 = puVar8;
                            if (puVar7 != (undefined4 *)0x0) {
                              *puVar7 = puVar8;
                              puVar2 = local_4;
                            }
                            local_4 = puVar2;
                            FUN_004f7fb0(param_1);
                            puVar8[2] = *param_2;
                            pcVar9 = *(char **)(param_1 + 0x510);
                            pcVar5 = pcVar9;
                            do {
                              cVar1 = *pcVar5;
                              pcVar5 = pcVar5 + 1;
                            } while (cVar1 != '\0');
                            goto LAB_00504449;
                          }
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ed6c);
                          if (iVar4 == 0) {
                            return local_4;
                          }
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"ENDIF");
                          if (iVar4 == 0) {
                            return local_4;
                          }
                          iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"APPCOMMAND");
                          puVar8 = puVar7;
                          if (iVar4 == 0) {
                            puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
                            *param_2 = (int)(puVar8 + 4);
                            *puVar8 = 0;
                            puVar8[2] = 0;
                            puVar8[3] = 0;
                            puVar8[1] = 0xe;
                            puVar2 = puVar8;
                            if (puVar7 != (undefined4 *)0x0) {
                              *puVar7 = puVar8;
                              puVar2 = local_4;
                            }
                            local_4 = puVar2;
                            FUN_004f7fb0(param_1);
                            puVar8[2] = *param_2;
                            pcVar5 = *(char **)(param_1 + 0x510);
                            pcVar9 = pcVar5 + 1;
                            do {
                              cVar1 = *pcVar5;
                              pcVar5 = pcVar5 + 1;
                            } while (cVar1 != '\0');
                            *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                            _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
                            FUN_004f7fb0(param_1);
                            puVar8[3] = *param_2;
                            pcVar5 = *(char **)(param_1 + 0x510);
                            pcVar9 = pcVar5 + 1;
                            do {
                              cVar1 = *pcVar5;
                              pcVar5 = pcVar5 + 1;
                            } while (cVar1 != '\0');
                            *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
                            pcVar5 = (char *)puVar8[3];
                            goto LAB_00504ad3;
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_00504ae3;
            }
            puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
            *param_2 = (int)(puVar8 + 3);
            *puVar8 = 0;
            puVar8[2] = 0;
            puVar8[1] = 0xd;
            puVar2 = puVar8;
            if (puVar7 != (undefined4 *)0x0) {
              *puVar7 = puVar8;
              puVar2 = local_4;
            }
            local_4 = puVar2;
            FUN_004f7fb0(param_1);
            puVar8[2] = *param_2;
            pcVar5 = *(char **)(param_1 + 0x510);
            pcVar9 = pcVar5 + 1;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
            pcVar5 = (char *)puVar8[2];
LAB_00504ad3:
            pcVar9 = *(char **)(param_1 + 0x510);
          }
        }
        goto LAB_00504adb;
      }
      puVar8 = (undefined4 *)(*param_2 + 0xfU & 0xfffffff0);
      *param_2 = (int)(puVar8 + 4);
      *puVar8 = 0;
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[1] = 1;
      puVar2 = puVar8;
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = puVar8;
        puVar2 = local_4;
      }
      local_4 = puVar2;
      FUN_004f7fb0(param_1);
      puVar8[2] = *param_2;
      pcVar5 = *(char **)(param_1 + 0x510);
      pcVar9 = pcVar5 + 1;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      *param_2 = (int)(pcVar5 + *param_2 + (1 - (int)pcVar9));
      _sprintf((char *)puVar8[2],*(char **)(param_1 + 0x510));
      FUN_004f7fb0(param_1);
      iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"forward");
      if (iVar4 == 0) {
        puVar8[3] = 1;
      }
      else {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"backward");
        if (iVar4 == 0) {
          puVar8[3] = 0;
        }
        else {
          FUN_004fff10();
        }
      }
    }
LAB_00504ae3:
    iVar4 = FUN_004fc5b0(param_1);
    puVar7 = puVar8;
    if (iVar4 == 0) {
      return local_4;
    }
  } while( true );
}

