/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fee80; label: FUN_005fee80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fee80(undefined4 *param_1,undefined4 param_2,undefined2 param_3)

{
  int iVar1;
  
  iVar1 = FUN_005d6710(param_1,1,0);
  if ((iVar1 == 0) && (DAT_02854c84 < 0x80)) {
    (&DAT_0280c740)[DAT_02854c84 * 6] = *param_1;
    (&DAT_0280c744)[DAT_02854c84 * 6] = param_1[1];
    (&DAT_0280c748)[DAT_02854c84 * 6] = param_1[2];
    (&DAT_0280c74c)[DAT_02854c84 * 6] = param_2;
    (&DAT_0280c750)[DAT_02854c84 * 0xc] = param_3;
    DAT_02854c84 = DAT_02854c84 + 1;
  }
  return;
}

