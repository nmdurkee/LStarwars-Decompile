/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x5930c0; label: FUN_005930c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005930c0(int param_1)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  int *piVar4;
  int iVar5;
  
  if ((param_1 != 0) && (DAT_00955874 == 1)) {
    piVar2 = &DAT_00955630;
    psVar3 = (short *)(param_1 + 0x6c);
    do {
      if (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + *psVar3 * 2) != -1) {
        iVar5 = 0;
        piVar4 = piVar2;
        do {
          if (**(int **)(param_1 + iVar5 * 4) != 0) {
            if (*piVar4 == 0) {
              if (piVar4[5] != 0) {
                iVar1 = piVar4[6];
                *(short *)(*(int *)(*(int *)(*(int *)(piVar4[7] + 4) + 0xc) + iVar1 * 4) + 0x74) =
                     (short)piVar4[4];
                FUN_005e4b00(*(undefined4 *)(*(int *)(*(int *)(piVar4[7] + 4) + 0xc) + iVar1 * 4));
                FUN_005e5630(piVar4[5]);
              }
            }
            else {
              FUN_005ef880(*piVar4);
              *piVar4 = 0;
            }
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 8;
        } while (iVar5 < 9);
      }
      piVar2 = piVar2 + 0x48;
      psVar3 = psVar3 + 1;
    } while ((int)piVar2 < 0x955870);
  }
  return;
}

