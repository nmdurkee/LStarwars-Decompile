/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1c00; label: FUN_005a1c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1c00(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0x5034) = 0;
  *(undefined4 *)(param_1 + 0x5038) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar1 = FUN_004fc900("faders",param_2,0xffff), iVar1 != 0)) {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(undefined4 **)(param_1 + 0x104) = puVar4;
    *(undefined4 **)(param_1 + 0x5034) = puVar4;
    iVar2 = FUN_004fc5b0(iVar1);
    if (iVar2 != 0) {
      puVar3 = puVar4 + 3;
      do {
        FUN_004f7fb0(iVar1);
        iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"fader");
        if (iVar2 == 0) {
          *puVar4 = 0;
          puVar4[1] = 0;
          puVar4[2] = 0;
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          iVar2 = FUN_004f7fb0(iVar1);
          if ((iVar2 != 0) &&
             (iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar4,
                                   *(undefined4 *)(iVar1 + 0x510),1), iVar2 != 0)) {
            iVar2 = FUN_004f7fb0(iVar1);
            while (iVar2 != 0) {
              iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"while_animating");
              if ((iVar2 == 0) && (iVar2 = FUN_004f7fb0(iVar1), iVar2 != 0)) {
                FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar3,*(undefined4 *)(iVar1 + 0x510),
                             1);
              }
              iVar2 = FUN_004f7fb0(iVar1);
            }
            puVar4 = puVar4 + 6;
            puVar3 = puVar3 + 6;
            *(int *)(param_1 + 0x5038) = *(int *)(param_1 + 0x5038) + 1;
          }
        }
        iVar2 = FUN_004fc5b0(iVar1);
      } while (iVar2 != 0);
    }
    FUN_004fa300(iVar1);
    if (0 < *(int *)(param_1 + 0x5038)) {
      *(undefined4 **)(param_1 + 0x104) = puVar4;
      return;
    }
    *(undefined4 *)(param_1 + 0x5034) = 0;
  }
  return;
}

