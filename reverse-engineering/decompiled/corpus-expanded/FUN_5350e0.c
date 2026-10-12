/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x5350e0; label: FUN_005350e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005350e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float10 fVar7;
  undefined1 auStack_c [12];
  
  if (((param_3 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x138c) != 0)) {
    if (param_6 != 0) {
      iVar5 = 0;
      if (0 < param_5) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar3 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar5 * 4),param_3 + 0x13f),
             iVar3 == 0)) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"ANTICLOCKWISE");
            if (iVar3 == 0) {
              *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"CLOCKWISE");
              if (iVar3 == 0) {
                *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"REVERSE");
                if (iVar3 == 0) {
                  *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) ^ 0x200;
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"facing");
                  if (iVar3 == 0) {
                    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"currentdist");
                    if (iVar3 == 0) {
                      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
                    }
                    else {
                      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"locator=");
                      if (iVar3 == 0) {
                        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"current_position"
                                            );
                        if (iVar3 == 0) {
                          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"origin");
                          if (iVar3 == 0) {
                            if (*(char *)(param_3 + 0x138) != -1) {
                              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 0x20;
                            }
                          }
                          else {
                            fVar7 = (float10)FUN_00514920(param_3,param_2,
                                                          *(undefined4 *)(param_4 + iVar5 * 4));
                            *(float *)(param_3 + 0x180) = (float)fVar7;
                          }
                        }
                        else {
                          *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 8;
                          *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_3 + 0x14c);
                          *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(param_3 + 0x150);
                          *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_3 + 0x154);
                        }
                      }
                      else {
                        iVar3 = FUN_0051ac10(param_1,iVar3 + 8);
                        *(int *)(param_2 + 0x6c) = iVar3;
                        if (iVar3 != 0) {
                          *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 0x10;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_5);
      }
      if ((*(byte *)(param_2 + 0x68) & 0x38) == 0) {
        *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 8;
        *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_3 + 0x14c);
        *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(param_3 + 0x150);
        *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_3 + 0x154);
      }
    }
    bVar1 = *(byte *)(param_2 + 0x68);
    if ((bVar1 & 8) == 0) {
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x20) == 0) {
          return 0;
        }
        iVar5 = (uint)*(byte *)(param_3 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if ((DAT_00923908 == (code *)0x0) ||
           (puVar4 = (undefined4 *)(*DAT_00923908)(param_1,param_3), puVar4 == (undefined4 *)0x0)) {
          puVar4 = (undefined4 *)(iVar5 + 0x20);
        }
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(param_2 + 0x6c) + 0x20);
        puVar4 = (undefined4 *)(*(int *)(param_2 + 0x6c) + 0x10);
      }
    }
    else {
      puVar6 = (undefined4 *)(param_3 + 0x158);
      puVar4 = (undefined4 *)(param_2 + 0x78);
    }
    if ((puVar6 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0x0)) {
      if ((*(byte *)(param_2 + 0x68) & 4) != 0) {
        fVar7 = (float10)FUN_005bed80(param_3 + 0x14c,puVar4,auStack_c);
        *(float *)(param_3 + 0x180) = (float)fVar7;
      }
      *(undefined4 *)(param_3 + 0x1b4) = *puVar4;
      *(undefined4 *)(param_3 + 0x1b8) = puVar4[1];
      *(undefined4 *)(param_3 + 0x1bc) = puVar4[2];
      *(undefined4 *)(param_3 + 0x1cc) = *puVar6;
      *(undefined4 *)(param_3 + 0x1d0) = puVar6[1];
      *(undefined4 *)(param_3 + 0x1d4) = puVar6[2];
      *(undefined4 *)(param_3 + 0x1d8) = puVar6[3];
      *(undefined4 *)(param_3 + 0x1dc) = puVar6[4];
      uVar2 = puVar6[5];
      *(undefined4 *)(param_3 + 0x1c0) = 0;
      *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_3 + 0x180);
      *(undefined4 *)(param_3 + 0x1e0) = uVar2;
      *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffffb | 3;
      if ((*(byte *)(param_2 + 0x68) & 1) != 0) {
        *(undefined4 **)(param_3 + 0x1e4) = puVar4;
      }
    }
    return 0;
  }
  return 1;
}

