/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x4422c0; label: FUN_004422c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004422c0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if ((param_2 != 0) && (param_1 != 0)) {
    iVar1 = FUN_004f8a70(param_2,"throwable");
    bVar2 = iVar1 != 0;
    iVar1 = FUN_004f8a70(param_2,"inrange");
    if (iVar1 != 0) {
      bVar2 = bVar2 | 2;
    }
  }
  return bVar2;
}

