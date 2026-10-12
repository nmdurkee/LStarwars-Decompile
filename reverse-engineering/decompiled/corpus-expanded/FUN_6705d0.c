/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x6705d0; label: FUN_006705d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006705d0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (DAT_0292fc68 != 0) {
    piVar2 = (int *)(DAT_0292fc68 + 0x198);
    do {
      if (*piVar2 == param_1) {
        *(undefined4 *)(DAT_0292fc68 + (iVar1 * 3 + 0x33) * 8) = 0;
        return 1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 < 0x40);
  }
  return 0;
}

