/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x442000; label: FUN_00442000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442000(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    uint param_5)

{
  if (param_5 == 0xffffffff) {
    param_5 = (uint)*(byte *)(param_2 + 0xb0);
  }
  if (param_5 != 0) {
    return (float10)(byte)(&DAT_00876847)[param_5];
  }
  return (float10)0;
}

