/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66e930; label: FUN_0066e930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066e930(int param_1)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  if ((DAT_0292fc68 != (int *)0x0) && (-1 < param_1)) {
    iVar3 = (int)*(short *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c);
    iVar5 = *(int *)(*DAT_0292fc68 + 0x2c + iVar3 * 0x38);
    if ((iVar5 == 0) || (iVar5 == 1)) {
      psVar4 = *(short **)(*DAT_0292fc68 + iVar3 * 0x38 + 0xc);
      sVar2 = *psVar4;
      while (-1 < sVar2) {
        psVar1 = psVar4 + 1;
        psVar4 = psVar4 + 10;
        for (iVar5 = (int)*psVar1; 0 < iVar5; iVar5 = iVar5 + -1) {
          FUN_0066da90(psVar4,*(undefined2 *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c));
          psVar4 = psVar4 + 0x32;
        }
        sVar2 = *psVar4;
      }
    }
  }
  return;
}

