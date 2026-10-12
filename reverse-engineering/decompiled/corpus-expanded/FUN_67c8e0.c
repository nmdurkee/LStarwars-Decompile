/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c8e0; label: FUN_0067c8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067c8e0(int param_1,int param_2)

{
  int iVar1;
  
  if (((DAT_0292fc68 != (int *)0x0) && (-1 < param_1)) && (param_1 < DAT_0292fc68[0x2923])) {
    iVar1 = (int)*(short *)(DAT_0292fc68[0x1a] + 0x48 + param_1 * 0x6c);
    if (param_2 != 0) {
      *(undefined4 *)(*DAT_0292fc68 + 0x2c + iVar1 * 0x38) = 1;
      return;
    }
    *(undefined4 *)(*DAT_0292fc68 + 0x2c + iVar1 * 0x38) = 0xffffffff;
  }
  return;
}

