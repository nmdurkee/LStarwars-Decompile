/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d6900; label: FUN_005d6900
 */

void FUN_005d6900(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != DAT_0097394c) && (DAT_0097394c == 0)) {
    puVar2 = &DAT_009736e8;
    puVar3 = &DAT_00971b00;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  if (param_1 != 0) {
    puVar2 = &DAT_009736e8;
    puVar3 = &DAT_00973760;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00603cc0(&DAT_00971b00);
  }
  DAT_0097394c = param_1;
  return;
}

