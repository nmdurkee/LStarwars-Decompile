/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x5684f0; label: FUN_005684f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005684f0(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x50bc)) {
      pbVar2 = (byte *)(*(int *)(param_1 + 0x50c4) + 0xfc);
      do {
        iVar1 = FUN_005cfac0(pbVar2 + -0xcc);
        if (((iVar1 != 0) && (iVar1 = FUN_005d0420(pbVar2 + -0xcc), iVar1 != 0)) &&
           ((*pbVar2 & 1) != 0)) {
          *pbVar2 = *pbVar2 & 0xfe;
        }
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + 0x100;
      } while (iVar3 < *(int *)(param_1 + 0x50bc));
    }
  }
  return;
}

