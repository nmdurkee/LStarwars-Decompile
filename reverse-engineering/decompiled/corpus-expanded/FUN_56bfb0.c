/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56bfb0; label: FUN_0056bfb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056bfb0(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 < 0x20) && ((*(uint *)(&DAT_008034cc + param_2 * 0xc) & 0x10000) != 0)) {
    if (param_2 != 5) {
      return 1;
    }
    if ((DAT_00950c4c != (code *)0x0) && (iVar1 = (*DAT_00950c4c)(param_1), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

