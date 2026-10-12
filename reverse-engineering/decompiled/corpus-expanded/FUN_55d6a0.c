/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55d6a0; label: FUN_0055d6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055d6a0(int param_1,int param_2,int param_3,short param_4,int param_5)

{
  undefined2 uVar1;
  
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) & 0xffbfffff;
    return;
  }
  *(uint *)(param_1 + 0xeec) =
       (param_3 << 0x17 ^ *(uint *)(param_1 + 0xeec)) & 0x800000 ^ *(uint *)(param_1 + 0xeec) |
       0x400000;
  if (param_4 == -1) {
    if (param_5 != 0) {
      uVar1 = FUN_005d92b0(param_5,param_1 + 0x80);
      *(undefined2 *)(param_1 + 0x106a) = uVar1;
      return;
    }
    param_4 = -1;
  }
  *(short *)(param_1 + 0x106a) = param_4;
  return;
}

