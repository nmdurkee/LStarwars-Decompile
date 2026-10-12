/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403330; label: FUN_00403330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00403330(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_00854820 = PTR_s_Attracto_007ef210;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00854820;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00854834 = 0;
  _DAT_00854840 = 0;
  _DAT_00854858 = 0;
  _DAT_00854860 = 0;
  _DAT_00854868 = 0;
  _DAT_0085486c = 0;
  _DAT_00854870 = 0;
  _DAT_00854874 = 0;
  _DAT_00854890 = 0;
  _DAT_00854894 = 0;
  DAT_00854824 = &DAT_007516c0;
  _DAT_00854828 = 0x2c;
  _DAT_0085482c = FUN_00403100;
  _DAT_00854830 = FUN_00403120;
  _DAT_00854838 = FUN_00402ce0;
  _DAT_0085483c = FUN_00402eb0;
  _DAT_00854844 = FUN_00403190;
  _DAT_00854848 = FUN_004031a0;
  _DAT_0085484c = FUN_004031c0;
  _DAT_00854850 = FUN_004031d0;
  _DAT_00854854 = FUN_00402a80;
  _DAT_0085485c = FUN_00402aa0;
  _DAT_00854864 = FUN_004032f0;
  _DAT_00854878 = FUN_004031e0;
  _DAT_0085487c = FUN_00403200;
  _DAT_00854880 = FUN_00403240;
  _DAT_00854884 = FUN_00402c30;
  _DAT_00854888 = FUN_00402a30;
  _DAT_0085488c = FUN_00402910;
  return &DAT_00854820;
}

