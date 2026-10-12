/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f960; label: FUN_0055f960
 */

void FUN_0055f960(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(param_1 + 0x5048) = 0;
  *(undefined4 *)(param_1 + 0x504c) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar2 = FUN_004fc900("portaldoors",param_2,0xffff), iVar2 != 0)) {
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(undefined4 **)(param_1 + 0x104) = puVar4;
    *(undefined4 **)(param_1 + 0x5048) = puVar4;
    iVar3 = FUN_004fc5b0(iVar2);
    while (iVar3 != 0) {
      FUN_004f7fb0(iVar2);
      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"portaldoor");
      if (iVar3 == 0) {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        iVar3 = FUN_004f7fb0(iVar2);
        if ((iVar3 != 0) &&
           (iVar3 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar4,
                                 *(undefined4 *)(iVar2 + 0x510),1), iVar3 != 0)) {
          uVar1 = FUN_004f9e70(iVar2);
          *(undefined1 *)((int)puVar4 + 0xe) = uVar1;
          iVar3 = FUN_004f7fb0(iVar2);
          while (iVar3 != 0) {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"trigger_at_end");
            if (iVar3 == 0) {
              *(ushort *)(puVar4 + 3) = *(ushort *)(puVar4 + 3) | 1;
            }
            iVar3 = FUN_004f7fb0(iVar2);
          }
          *(int *)(param_1 + 0x504c) = *(int *)(param_1 + 0x504c) + 1;
          puVar4 = puVar4 + 4;
        }
      }
      iVar3 = FUN_004fc5b0(iVar2);
    }
    FUN_004fa300(iVar2);
    if (0 < *(int *)(param_1 + 0x504c)) {
      *(uint *)(param_1 + 0x104) = (int)puVar4 + 0xfU & 0xfffffff0;
      return;
    }
    *(undefined4 *)(param_1 + 0x5048) = 0;
  }
  return;
}

