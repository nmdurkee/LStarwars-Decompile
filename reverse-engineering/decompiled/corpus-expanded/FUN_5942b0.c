/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x5942b0; label: FUN_005942b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005942b0(undefined4 param_1,int *param_2)

{
  short *psVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  undefined4 local_4;
  
  iVar4 = FUN_004fc860(param_1);
  if (iVar4 == 0) {
    FUN_00594220(param_1);
    return;
  }
  psVar7 = (short *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)psVar7;
  _DAT_00955878 = 0;
  DAT_00955880 = 0;
  DAT_0095587c = psVar7;
  iVar5 = FUN_004fc5b0(iVar4);
  while (iVar5 != 0) {
    iVar5 = FUN_004f7fb0(iVar4);
    if (((iVar5 != 0) &&
        (iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"collect"), iVar5 == 0)) &&
       (iVar5 = FUN_004f7fb0(iVar4), iVar5 != 0)) {
      sVar3 = FUN_0055b1c0(*(undefined4 *)(iVar4 + 0x510));
      *psVar7 = sVar3;
      if (sVar3 != -1) {
        iVar5 = FUN_00594250((int)sVar3,DAT_0095587c,_DAT_00955878);
        if (iVar5 == -1) {
          psVar1 = psVar7 + 6;
          *(undefined1 *)(psVar7 + 1) = 0;
          *(undefined1 *)((int)psVar7 + 3) = 0xff;
          *(undefined1 *)(psVar7 + 4) = 0;
          psVar7[2] = 0;
          psVar7[3] = 0;
          psVar7[5] = 0;
          *(undefined1 *)((int)psVar7 + 9) = 0;
          *(undefined1 *)psVar1 = 0;
          iVar5 = FUN_004f7fb0(iVar4);
          while (iVar5 != 0) {
            iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"story");
            if (iVar5 == 0) {
              *(undefined1 *)(psVar7 + 1) = 1;
            }
            else {
              iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"area_complete");
              if (iVar5 == 0) {
                iVar5 = FUN_004f7fb0(iVar4);
                if ((iVar5 != 0) &&
                   (iVar5 = FUN_00573430(*(undefined4 *)(iVar4 + 0x510),&local_4), iVar5 != 0)) {
                  *(undefined1 *)(psVar7 + 1) = 2;
                  *(undefined1 *)((int)psVar7 + 3) = (undefined1)local_4;
                }
              }
              else {
                iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"all_episodes_complete");
                if (iVar5 == 0) {
                  *(undefined1 *)(psVar7 + 1) = 3;
                }
                else {
                  iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"100_percent");
                  if (iVar5 == 0) {
                    *(undefined1 *)(psVar7 + 1) = 7;
                  }
                  else {
                    iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"gold_bricks");
                    if (iVar5 == 0) {
                      *(undefined1 *)(psVar7 + 1) = 6;
                      uVar6 = FUN_004f9e70(iVar4);
                      uVar2 = (ushort)((int)uVar6 >> 0x1f);
                      psVar7[5] = ((ushort)uVar6 ^ uVar2) - uVar2;
                    }
                    else {
                      iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"all_minikits_complete");
                      if (iVar5 == 0) {
                        *(undefined1 *)(psVar7 + 1) = 4;
                      }
                      else {
                        iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"minikit");
                        if (iVar5 == 0) {
                          *(undefined1 *)(psVar7 + 1) = 5;
                        }
                        else {
                          iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"buy_in_shop");
                          if (iVar5 == 0) {
                            *(undefined1 *)(psVar7 + 4) = 1;
                            uVar6 = FUN_004f9e70(iVar4);
                            *(undefined4 *)(psVar7 + 2) = uVar6;
                          }
                          else {
                            iVar5 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x510),"cheat_code");
                            if (((iVar5 == 0) && (iVar5 = FUN_004f7fb0(iVar4), iVar5 != 0)) &&
                               (iVar5 = FUN_004f1ff0(*(undefined4 *)(iVar4 + 0x510)), iVar5 == 6)) {
                              FUN_004f1f10(psVar1,*(undefined4 *)(iVar4 + 0x510));
                              FUN_004f8c20(psVar1,psVar1);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            iVar5 = FUN_004f7fb0(iVar4);
          }
          if ((((char)psVar7[1] != '\0') || ((char)psVar7[4] != '\0')) && ((char)psVar7[1] != '\a'))
          {
            *(undefined1 *)((int)psVar7 + 9) = 1;
            DAT_00955880 = DAT_00955880 + 1;
          }
          psVar7 = psVar7 + 0xe;
          _DAT_00955878 = _DAT_00955878 + 1;
        }
        else {
          FUN_00594220(param_1,*(undefined4 *)(iVar4 + 0x510));
        }
      }
    }
    iVar5 = FUN_004fc5b0(iVar4);
  }
  FUN_004fa300(iVar4);
  if (0 < _DAT_00955878) {
    *param_2 = (int)psVar7;
    return;
  }
  DAT_0095587c = (short *)0x0;
  FUN_00594220(param_1);
  return;
}

