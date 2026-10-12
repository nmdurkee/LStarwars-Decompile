/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x670560; label: FUN_00670560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00670560(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = DAT_0292fc68;
  do {
    if (*(short *)(iVar1 + 0x19c + iVar2) == param_1) {
      *(undefined4 *)(iVar1 + 0x198 + iVar2) = 0;
      iVar2 = DAT_0292fc68;
    }
    iVar1 = iVar1 + 0x18;
  } while (iVar1 < 0x600);
  return;
}

