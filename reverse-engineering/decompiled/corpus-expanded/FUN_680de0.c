/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x680de0; label: FUN_00680de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00680de0(void)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  
  if (DAT_0292fc68 != (int *)0x0) {
    DAT_0292186c = FUN_006de8d0(0x948);
    psVar5 = (short *)(DAT_0292186c + 0x148);
    while( true ) {
      sVar2 = *psVar5;
      while (0 < sVar2) {
        psVar1 = psVar5;
        for (iVar4 = (int)*psVar5; psVar1 = psVar1 + 2, 0 < iVar4; iVar4 = iVar4 + -1) {
          if (*(int *)(*DAT_0292fc68 + 0x2c + psVar5[1] * 0x38) == 0) {
            FUN_0066d3a0();
          }
          else {
            FUN_0066da90(*(undefined4 *)psVar1,psVar5[1]);
          }
        }
        psVar5 = psVar1;
        sVar2 = *psVar1;
      }
      sVar2 = *psVar5;
      if (-1 < sVar2) break;
      do {
        uVar3 = (int)sVar2 >> 0x1f;
        psVar5 = psVar5 + (((int)sVar2 ^ uVar3) - uVar3) * 2 + 2;
        sVar2 = *psVar5;
      } while (sVar2 < 0);
    }
    FUN_006de960();
    return;
  }
  return;
}

