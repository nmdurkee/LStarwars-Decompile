/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x442270; label: FUN_00442270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442270(void)

{
  uint *puVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  if (0 < DAT_0093d500) {
    puVar1 = (uint *)(DAT_0093d504 + 0x1fc);
    iVar2 = DAT_0093d500;
    do {
      if ((((*puVar1 & 1) != 0) && ((*puVar1 & 0x1000) != 0)) && ((puVar1[-1] & 1) != 0)) {
        local_4 = local_4 + 1;
      }
      puVar1 = puVar1 + 0x436;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return (float10)local_4;
}

