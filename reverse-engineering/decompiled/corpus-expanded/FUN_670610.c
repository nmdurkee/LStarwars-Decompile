/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x670610; label: FUN_00670610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00670610(void)

{
  int iVar1;
  
  if (DAT_0292fc68 != 0) {
    iVar1 = 0x198;
    do {
      *(undefined4 *)(iVar1 + DAT_0292fc68) = 0;
      iVar1 = iVar1 + 0x18;
    } while (iVar1 < 0x798);
  }
  return;
}

