/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5570c0; label: FUN_005570c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005570c0(ushort *param_1,byte param_2)

{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar1 = param_1;
  if (param_1 != (ushort *)0x0) {
    puVar3 = *(ushort **)(param_1 + 0x12);
    if (puVar3 == (ushort *)0x0) {
      param_1 = puVar3;
      puVar3 = (ushort *)&param_1;
    }
    if (7 < param_2) {
      uVar2 = FUN_00621860();
      *puVar3 = uVar2;
      return;
    }
    if ((puVar1[0x10] & 2) != 0) {
      *puVar3 = *puVar3 | 1;
    }
  }
  return;
}

