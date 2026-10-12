/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8690; label: FUN_005d8690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d8690(int param_1,int param_2)

{
  return *(undefined4 *)
          (*(int *)((&DAT_009716a4)[param_1] + 8 +
                   *(int *)(*(int *)((&DAT_009716a4)[param_1] + 0x20) + param_2 * 4) * 4) +
          param_2 * 4);
}

