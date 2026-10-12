/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55fbf0; label: FUN_0055fbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

