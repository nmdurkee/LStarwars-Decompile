/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594810; label: FUN_00594810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00594810(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (*(ushort *)((int)param_1 + 6) != 0) {
    psVar2 = (short *)*param_1;
    while (*psVar2 != param_2) {
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0xe;
      if ((int)(uint)*(ushort *)((int)param_1 + 6) <= iVar1) {
        return;
      }
    }
    *param_3 = *(undefined4 *)((short *)*param_1 + iVar1 * 0xe + 10);
    *param_4 = *(undefined4 *)(*param_1 + 0x18 + iVar1 * 0x1c);
  }
  return;
}

