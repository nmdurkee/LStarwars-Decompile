/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c890; label: FUN_0067c890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067c890(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (((DAT_0292fc68 != (int *)0x0) && (-1 < param_1)) && (param_1 < DAT_0292fc68[0x2923])) {
    puVar1 = (undefined4 *)
             (*DAT_0292fc68 + *(short *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c) * 0x38);
    *param_2 = *puVar1;
    param_2[1] = puVar1[1];
    param_2[2] = puVar1[2];
  }
  return;
}

