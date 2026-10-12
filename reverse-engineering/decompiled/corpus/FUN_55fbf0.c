/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55fbf0; label: FUN_0055fbf0
 */

void FUN_0055fbf0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  
  *(undefined4 *)(param_1 + 0x46b0) = 0;
  *(undefined4 *)(param_1 + 0x46b4) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) &&
     (iVar1 = FUN_004fc900("equivalentobjects",param_2,0xffff), iVar1 != 0)) {
    psVar3 = (short *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(short **)(param_1 + 0x104) = psVar3;
    *(short **)(param_1 + 0x46b0) = psVar3;
    iVar2 = FUN_004fc5b0(iVar1);
    while (iVar2 != 0) {
      FUN_004f7fb0(iVar1);
      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"equivalentobjects");
      if (iVar2 == 0) {
        *psVar3 = 0;
        psVar3[1] = 4;
        iVar2 = FUN_004f7fb0(iVar1);
        while (iVar2 != 0) {
          iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),psVar3 + *psVar3 * 6 + 2,
                               *(undefined4 *)(iVar1 + 0x510),1);
          if (iVar2 != 0) {
            *psVar3 = *psVar3 + 1;
            psVar3[1] = psVar3[1] + 0xc;
          }
          iVar2 = FUN_004f7fb0(iVar1);
        }
        if (0 < *psVar3) {
          psVar3 = (short *)((int)psVar3 + (int)psVar3[1]);
          *(int *)(param_1 + 0x46b4) = *(int *)(param_1 + 0x46b4) + 1;
        }
      }
      iVar2 = FUN_004fc5b0(iVar1);
    }
    FUN_004fa300(iVar1);
    if (0 < *(int *)(param_1 + 0x46b4)) {
      *(uint *)(param_1 + 0x104) = (int)psVar3 + 0xfU & 0xfffffff0;
      return;
    }
    *(undefined4 *)(param_1 + 0x46b0) = 0;
  }
  return;
}

