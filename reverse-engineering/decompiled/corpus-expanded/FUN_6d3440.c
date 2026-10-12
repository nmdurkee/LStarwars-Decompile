/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d3440; label: FUN_006d3440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3440(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_02974d2c = param_2;
  if ((param_1 != 0) && (0 < param_2)) {
    iVar2 = 0;
    if (0 < param_2) {
      do {
        uVar1 = FUN_004fc2b0(*(undefined4 *)(param_1 + iVar2 * 4),param_3,0);
        (&DAT_02974cf4)[iVar2] = uVar1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_02974d2c);
    }
    FUN_004f0d40(DAT_02974cf4);
    FUN_006986d0(DAT_02974cf4);
  }
  return;
}

