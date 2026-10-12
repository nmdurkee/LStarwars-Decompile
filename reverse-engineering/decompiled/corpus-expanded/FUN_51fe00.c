/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x51fe00; label: FUN_0051fe00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051fe00(int param_1,int param_2,undefined4 param_3)

{
  FUN_004f1f40(param_2 + 8,param_3,0x20);
  if (*(int *)(param_1 + 0xc4) == 0) {
    *(int *)(param_1 + 0xc4) = param_2;
    *(undefined4 *)(param_2 + 0x2c) = 0;
    return;
  }
  *(int *)(param_2 + 0x2c) = *(int *)(param_1 + 0xc4);
  *(int *)(param_1 + 0xc4) = param_2;
  return;
}

