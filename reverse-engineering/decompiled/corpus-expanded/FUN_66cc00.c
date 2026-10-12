/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66cc00; label: FUN_0066cc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066cc00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_02947d7c) {
    do {
      if ((&DAT_02921218)[iVar2 * 2] == param_1) {
        iVar1 = DAT_02947d7c * 8;
        DAT_02947d7c = DAT_02947d7c + -1;
        (&DAT_02921218)[iVar2 * 2] = *(undefined4 *)(&DAT_02921210 + iVar1);
        (&DAT_0292121c)[iVar2 * 2] = (&DAT_0292121c)[DAT_02947d7c * 2];
        iVar2 = iVar2 + -1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_02947d7c);
  }
  return;
}

