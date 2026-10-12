/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66e9b0; label: FUN_0066e9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066e9b0(int param_1)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  
  iVar4 = *(int *)(*DAT_0292fc68 + 0x2c + param_1 * 0x38);
  if (((iVar4 == 0) || (iVar4 == 1)) &&
     (psVar3 = *(short **)(*DAT_0292fc68 + param_1 * 0x38 + 0xc), psVar3 != (short *)0x0)) {
    sVar2 = *psVar3;
    while (-1 < sVar2) {
      psVar1 = psVar3 + 1;
      psVar3 = psVar3 + 10;
      for (iVar4 = (int)*psVar1; 0 < iVar4; iVar4 = iVar4 + -1) {
        FUN_0066d3a0(psVar3,param_1);
        psVar3 = psVar3 + 0x32;
      }
      sVar2 = *psVar3;
    }
  }
  return;
}

