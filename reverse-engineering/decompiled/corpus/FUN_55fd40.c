/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55fd40; label: FUN_0055fd40
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

