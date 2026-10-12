/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f39e0; label: thunk_FUN_005f3950
 */

void thunk_FUN_005f3950(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_009718a0 = FUN_005efff0();
  if ((DAT_009718d8 != 0) && (DAT_009718a0 != -1)) {
    if (*(int *)(DAT_009718dc + 0x808) == 0) {
      DAT_009718d8 = 0;
    }
    else {
      iVar1 = DAT_009718e0 * 0x380 + DAT_009718dc;
      *(int *)(iVar1 + 0x354 + *(int *)(iVar1 + 0x374) * 4) = DAT_009718a0;
      *(int *)(iVar1 + 0x374) = *(int *)(iVar1 + 0x374) + 1;
    }
    DAT_009718a0 = -1;
  }
  puVar2 = &DAT_009718a0;
  puVar3 = &DAT_009640f0 + DAT_0095fbb8 * 0x86;
  for (iVar1 = 0x86; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  DAT_0095fbb8 = DAT_0095fbb8 + 1;
  return;
}

