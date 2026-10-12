/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639670; label: FUN_00639670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639670(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_006378f0();
  iVar1 = DAT_02913538;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 0x460;
    *(float *)(iVar2 + 0x70 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x70 + DAT_0291389c);
    *(float *)(iVar2 + 0xfc + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0xfc + DAT_0291389c);
    *(float *)(iVar2 + 0x188 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x188 + DAT_0291389c);
    *(float *)(iVar2 + 0x214 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x214 + DAT_0291389c);
    *(float *)(iVar2 + 0x2a0 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x2a0 + DAT_0291389c);
    *(float *)(iVar2 + 0x32c + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x32c + DAT_0291389c);
    *(float *)(iVar2 + 0x3b8 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x3b8 + DAT_0291389c);
    *(float *)(iVar2 + 0x444 + DAT_0291389c) =
         *(float *)(iVar1 + 0x54) * *(float *)(iVar2 + 0x444 + DAT_0291389c);
    iVar2 = iVar3;
  } while (iVar3 < 0x4600);
  FUN_006279b0(param_1,DAT_02913534);
  iVar1 = DAT_02913534;
  *(int *)(DAT_02913534 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(iVar1 + 0x18) = *(int *)(param_1 + 0x18) + 10;
  FUN_006382a0();
  return;
}

