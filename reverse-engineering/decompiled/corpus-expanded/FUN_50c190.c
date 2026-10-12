/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50c190; label: FUN_0050c190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050c190(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00921ec4 != (code *)0x0) {
    (*DAT_00921ec4)(param_1,param_1);
  }
  iVar1 = FUN_004f8b10(param_1,"accept");
  if (iVar1 == 0) {
    FUN_004f1f10(param_1,"cross");
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_0075f790);
  if (iVar1 == 0) {
    FUN_004f1f10(param_1,"circle");
  }
  iVar1 = FUN_004f8b10(param_1,&PTR_LAB_0075f78c);
  if (iVar1 == 0) {
    FUN_004f1f10(param_1,&DAT_0075f784);
  }
  iVar1 = FUN_004f8b10(param_1,"playstation");
  if (iVar1 == 0) {
    FUN_004f1f10(param_1,&DAT_0075f784);
  }
  FUN_004f1f10(param_2,param_1);
  uVar2 = 0xffffffff;
  iVar1 = FUN_004f8b10(param_1,"padup");
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = FUN_004f8b10(param_1,"padright");
    if (iVar1 == 0) {
      uVar2 = 9;
    }
    else {
      iVar1 = FUN_004f8b10(param_1,"paddown");
      if (iVar1 == 0) {
        uVar2 = 10;
      }
      else {
        iVar1 = FUN_004f8b10(param_1,"padleft");
        if (iVar1 == 0) {
          uVar2 = 0xb;
        }
        else {
          iVar1 = FUN_004f8b10(param_1,"triangle");
          if (iVar1 == 0) {
            uVar2 = 0xc;
          }
          else {
            iVar1 = FUN_004f8b10(param_1,"circle");
            if (iVar1 == 0) {
              uVar2 = 0xd;
            }
            else {
              iVar1 = FUN_004f8b10(param_1,"cross");
              if (iVar1 == 0) {
                uVar2 = 0xe;
              }
              else {
                iVar1 = FUN_004f8b10(param_1,"square");
                if (iVar1 == 0) {
                  uVar2 = 0xf;
                }
                else {
                  iVar1 = FUN_004f8b10(param_1,&DAT_0075f73c);
                  if (iVar1 == 0) {
                    uVar2 = 0x10;
                  }
                  else {
                    iVar1 = FUN_004f8b10(param_1,&DAT_0075f738);
                    if (iVar1 == 0) {
                      uVar2 = 0x11;
                    }
                    else {
                      iVar1 = FUN_004f8b10(param_1,&DAT_0075f734);
                      if (iVar1 == 0) {
                        uVar2 = 0x12;
                      }
                      else {
                        iVar1 = FUN_004f8b10(param_1,&DAT_0075f730);
                        if (iVar1 == 0) {
                          uVar2 = 0x13;
                        }
                        else {
                          iVar1 = FUN_004f8b10(param_1,&DAT_0075f72c);
                          if (iVar1 == 0) {
                            uVar2 = 0x14;
                          }
                          else {
                            iVar1 = FUN_004f8b10(param_1,&DAT_0075f728);
                            if (iVar1 == 0) {
                              uVar2 = 0x15;
                            }
                            else {
                              iVar1 = FUN_004f8b10(param_1,"select");
                              if (iVar1 == 0) {
                                uVar2 = 0x16;
                              }
                              else {
                                iVar1 = FUN_004f8b10(param_1,"start");
                                if (iVar1 == 0) {
                                  uVar2 = 0x17;
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
  iVar1 = FUN_006d6350();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  FUN_006da410(iVar1,uVar2,param_2);
  return;
}

