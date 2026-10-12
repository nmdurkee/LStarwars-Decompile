/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x4015e0; label: FUN_004015e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004015e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_004f8b10(param_1,"[TAG]");
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(param_1,"[TRIANGLE]");
    if (iVar1 != 0) {
      iVar1 = FUN_004f8b10(param_1,&DAT_00751620);
      if (iVar1 != 0) {
        iVar1 = FUN_004f8b10(param_1,"[ACTION]");
        if (iVar1 != 0) {
          iVar1 = FUN_004f8b10(param_1,"[SQUARE]");
          if (iVar1 != 0) {
            iVar1 = FUN_004f8b10(param_1,&DAT_00751604);
            if (iVar1 != 0) {
              iVar1 = FUN_004f8b10(param_1,"[SPECIAL]");
              if (iVar1 != 0) {
                iVar1 = FUN_004f8b10(param_1,"[CIRCLE]");
                if (iVar1 != 0) {
                  iVar1 = FUN_004f8b10(param_1,&DAT_007515e8);
                  if (iVar1 != 0) {
                    iVar1 = FUN_004f8b10(param_1,"[JUMP]");
                    if (iVar1 != 0) {
                      iVar1 = FUN_004f8b10(param_1,"[CROSS]");
                      if (iVar1 != 0) {
                        iVar1 = FUN_004f8b10(param_1,&DAT_007515d4);
                        if (iVar1 != 0) {
                          iVar1 = FUN_004f8b10(param_1,"[TOGGLELEFT]");
                          if (iVar1 == 0) {
                            uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
                            uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
                            uVar3 = 0x10;
                          }
                          else {
                            iVar1 = FUN_004f8b10(param_1,"[TOGGLERIGHT]");
                            if (iVar1 != 0) {
                              return 0;
                            }
                            uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
                            uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
                            uVar3 = 0x12;
                          }
                          goto LAB_00401794;
                        }
                      }
                    }
                    uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
                    uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
                    uVar3 = 0xe;
                    goto LAB_00401794;
                  }
                }
              }
              uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
              uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
              uVar3 = 0xd;
              goto LAB_00401794;
            }
          }
        }
        uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
        uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
        uVar3 = 0xf;
        goto LAB_00401794;
      }
    }
  }
  uVar2 = *(undefined4 *)(DAT_00926c20 + 0xcc4);
  uVar4 = *(undefined4 *)(DAT_00926c20 + 0xcc0);
  uVar3 = 0xc;
LAB_00401794:
  uVar2 = FUN_0050ed50(uVar3,uVar4,uVar2);
  FUN_004f1f10(param_2,uVar2);
  return 1;
}

