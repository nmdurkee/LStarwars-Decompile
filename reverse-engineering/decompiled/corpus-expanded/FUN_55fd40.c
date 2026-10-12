/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55fd40; label: FUN_0055fd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055fd40(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  
  if ((((param_2 != (undefined4 *)0x0) && (iVar1 = FUN_005cfac0(param_2), iVar1 != 0)) &&
      (psVar4 = *(short **)(param_1 + 0x46b0), psVar4 != (short *)0x0)) &&
     (iVar1 = 0, 0 < *(int *)(param_1 + 0x46b4))) {
    do {
      iVar5 = 0;
      if (0 < *psVar4) {
        psVar3 = psVar4 + 2;
        do {
          iVar2 = FUN_005d0450(param_2,psVar3);
          if (iVar2 != 0) {
            iVar1 = 0;
            if (*psVar4 < 1) {
              return 0;
            }
            psVar3 = psVar4 + 2;
            do {
              iVar5 = FUN_005cfd60(psVar3);
              if (iVar5 != 0) {
                *param_2 = *(undefined4 *)(psVar4 + iVar1 * 6 + 2);
                param_2[1] = *(undefined4 *)(psVar4 + iVar1 * 6 + 4);
                param_2[2] = *(undefined4 *)(psVar4 + iVar1 * 6 + 6);
                return 1;
              }
              iVar1 = iVar1 + 1;
              psVar3 = psVar3 + 6;
            } while (iVar1 < *psVar4);
            return 0;
          }
          iVar5 = iVar5 + 1;
          psVar3 = psVar3 + 6;
        } while (iVar5 < *psVar4);
      }
      iVar1 = iVar1 + 1;
      psVar4 = (short *)((int)psVar4 + (int)psVar4[1]);
    } while (iVar1 < *(int *)(param_1 + 0x46b4));
  }
  return 0;
}

