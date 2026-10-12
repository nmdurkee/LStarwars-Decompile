/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559660; label: FUN_00559660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00559660(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int iStack_4;
  
  iVar6 = 0;
  if (DAT_0093b268 == (int *)0x0) {
    if ((param_3 != (int *)0x0) && (*param_3 != 0)) {
      do {
        iVar6 = iVar6 + 1;
      } while (param_3[iVar6] != 0);
      if ((iVar6 != 0) &&
         (DAT_0093b268 = (int *)FUN_00559610(param_1,param_2,0xc), DAT_0093b268 != (int *)0x0)) {
        DAT_0093b268[1] = param_4;
        iVar1 = FUN_00559610(param_1,param_2,iVar6 * 0x9c);
        DAT_0093b268[2] = iVar1;
        if (DAT_0093b268[2] != 0) {
          *DAT_0093b268 = iVar6;
          iVar6 = DAT_0093b268[2];
          local_8 = 0;
          if (0 < *DAT_0093b268) {
            do {
              puVar2 = (undefined4 *)(*(code *)param_3[local_8])(local_8);
              if ((*(char *)puVar2[1] != '\0') && (0 < local_8)) {
                iVar1 = 0;
                iStack_4 = local_8;
                do {
                  iVar5 = DAT_0093b268[2] + iVar1;
                  if ((*(char *)(iVar5 + 0x20) != '\0') &&
                     (iVar3 = FUN_004f8b10(puVar2[1],iVar5 + 0x20), iVar3 == 0)) {
                    FUN_00559570(*puVar2,iVar5);
                  }
                  iVar1 = iVar1 + 0x9c;
                  iStack_4 = iStack_4 + -1;
                } while (iStack_4 != 0);
              }
              FUN_004f1f10(iVar6,*puVar2);
              FUN_004f1f40(iVar6 + 0x20,puVar2[1],8);
              *(undefined2 *)(iVar6 + 0x28) = *(undefined2 *)(puVar2 + 2);
              *(undefined4 *)(iVar6 + 0x2c) = puVar2[3];
              *(undefined4 *)(iVar6 + 0x30) = puVar2[4];
              *(undefined4 *)(iVar6 + 0x34) = puVar2[5];
              *(undefined4 *)(iVar6 + 0x38) = puVar2[6];
              *(undefined4 *)(iVar6 + 0x3c) = puVar2[7];
              *(undefined4 *)(iVar6 + 0x40) = puVar2[8];
              *(undefined4 *)(iVar6 + 0x44) = puVar2[9];
              *(undefined4 *)(iVar6 + 0x48) = puVar2[10];
              *(undefined4 *)(iVar6 + 0x4c) = puVar2[0xb];
              *(undefined4 *)(iVar6 + 0x50) = puVar2[0xc];
              *(undefined4 *)(iVar6 + 0x54) = puVar2[0xd];
              *(undefined4 *)(iVar6 + 0x58) = puVar2[0xe];
              *(undefined4 *)(iVar6 + 0x5c) = puVar2[0xf];
              *(undefined4 *)(iVar6 + 0x60) = puVar2[0x10];
              *(undefined4 *)(iVar6 + 100) = puVar2[0x11];
              *(undefined4 *)(iVar6 + 0x68) = puVar2[0x12];
              *(undefined4 *)(iVar6 + 0x6c) = puVar2[0x13];
              *(undefined4 *)(iVar6 + 0x70) = puVar2[0x14];
              *(undefined4 *)(iVar6 + 0x74) = puVar2[0x15];
              *(undefined4 *)(iVar6 + 0x78) = puVar2[0x16];
              *(undefined4 *)(iVar6 + 0x7c) = puVar2[0x17];
              *(undefined4 *)(iVar6 + 0x80) = puVar2[0x18];
              *(undefined4 *)(iVar6 + 0x84) = puVar2[0x19];
              *(undefined4 *)(iVar6 + 0x88) = puVar2[0x1a];
              *(undefined4 *)(iVar6 + 0x8c) = puVar2[0x1b];
              *(undefined4 *)(iVar6 + 0x90) = puVar2[0x1c];
              *(undefined4 *)(iVar6 + 0x94) = puVar2[0x1d];
              if ((*(int *)(iVar6 + 0x78) != 0) && (DAT_0093b268[1] != 0)) {
                iVar1 = FUN_00559610(param_1,param_2,DAT_0093b268[1] * 4);
                *(int *)(iVar6 + 0x98) = iVar1;
                if ((iVar1 != 0) && (iVar1 = 0, 0 < DAT_0093b268[1])) {
                  do {
                    uVar4 = (**(code **)(iVar6 + 0x78))(param_1,param_2);
                    *(undefined4 *)(*(int *)(iVar6 + 0x98) + iVar1 * 4) = uVar4;
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < DAT_0093b268[1]);
                }
              }
              local_8 = local_8 + 1;
              iVar6 = iVar6 + 0x9c;
            } while (local_8 < *DAT_0093b268);
          }
        }
      }
    }
    return;
  }
  FUN_00559570();
  return;
}

