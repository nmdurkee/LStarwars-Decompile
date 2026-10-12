/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x637fc0; label: FUN_00637fc0
 */

void FUN_00637fc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = param_1;
  if (param_1 < (undefined4 *)(DAT_0291389c + 0x4f84)) {
    do {
      if (param_1[5] == 0) break;
      puVar3 = puVar1 + 0x13;
      puVar4 = param_1;
      for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      param_1 = param_1 + 0x13;
      puVar1 = puVar1 + 0x13;
    } while (param_1 < (undefined4 *)(DAT_0291389c + 0x4f84));
  }
  param_1[-0xe] = 0;
  return;
}

