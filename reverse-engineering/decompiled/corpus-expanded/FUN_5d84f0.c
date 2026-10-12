/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d84f0; label: FUN_005d84f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d84f0(int param_1,int param_2,undefined4 param_3)

{
  if (DAT_0097396c != 0) {
    *(undefined4 *)
     (*(int *)((&DAT_009716a4)[param_1] +
              (3 - *(int *)(*(int *)((&DAT_009716a4)[param_1] + 0x20) + param_2 * 4)) * 4) +
     param_2 * 4) = param_3;
  }
  return;
}

