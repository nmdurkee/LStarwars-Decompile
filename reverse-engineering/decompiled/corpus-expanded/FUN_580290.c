/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x580290; label: FUN_00580290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"level");
    if (iVar1 == 0) {
      DAT_00951cb8 = *(undefined4 *)(DAT_00951cd4 + 0x13c);
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007626f0);
    if (iVar1 == 0) {
      DAT_00951cb8 = DAT_0092489c;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"vehicle");
    if (iVar1 == 0) {
      DAT_00951cb8 = DAT_00924898;
      return;
    }
    DAT_00951cb8 = DAT_00924880;
  }
  return;
}

