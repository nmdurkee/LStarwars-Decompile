/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c930; label: FUN_0067c930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0067c930(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  short *psVar5;
  
  if (((param_1 < 0) || (DAT_0292fc68[0x2923] <= param_1)) ||
     (iVar1 = param_1 * 0x6c, *(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar1) == 0)) {
    return 0;
  }
  *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + -1;
  DAT_0292fc68[0x54] = DAT_0292fc68[0x54] + -1;
  *(undefined2 *)
   (*(short *)(*DAT_0292fc68 + 0x30 + (short)DAT_0292fc68[0x53] * 0x38) * 0x6c + 0x48 +
   DAT_0292fc68[0x1a]) = *(undefined2 *)(DAT_0292fc68[0x1a] + 0x48 + iVar1);
  puVar3 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
  puVar4 = (undefined4 *)(*DAT_0292fc68 + *(short *)(DAT_0292fc68[0x1a] + 0x48 + iVar1) * 0x38);
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(*DAT_0292fc68 + 0x2c + (short)DAT_0292fc68[0x53] * 0x38) = 0xffffffff;
  iVar2 = 0;
  *(undefined4 *)(DAT_0292fc68[0x1a] + 0x40 + iVar1) = 0;
  iVar1 = (int)(short)DAT_0292fc68[0x6e6];
  if (0 < *(short *)((int)DAT_0292fc68 + 0x1b9a)) {
    psVar5 = (short *)(DAT_0292fc68[0x6ed] + iVar1 * 2);
    do {
      if (*psVar5 == (short)DAT_0292fc68[0x53]) {
        *(undefined2 *)(DAT_0292fc68[0x6ed] + iVar1 * 2) =
             *(undefined2 *)(DAT_0292fc68[0x6ed] + DAT_0292fc68[0x54] * 2);
        break;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 1;
      psVar5 = psVar5 + 1;
    } while (iVar2 < *(short *)((int)DAT_0292fc68 + 0x1b9a));
  }
  *(short *)((int)DAT_0292fc68 + 0x1b9a) = *(short *)((int)DAT_0292fc68 + 0x1b9a) + -1;
  FUN_00670560(param_1);
  return 1;
}

