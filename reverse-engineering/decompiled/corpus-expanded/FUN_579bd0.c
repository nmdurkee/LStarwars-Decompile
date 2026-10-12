/* Ghidra pseudocode, not original source.
 * ev_9238a7d4a32c49ce947fe3ed44bc206dac4b982bd913cd0b1074936c5e6922ce
 * Entry: 0x579bd0; label: FUN_00579bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00579bd0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  DAT_00951bb0 = param_1;
  DAT_00951bb4 = 0;
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 + 4);
    iVar1 = *(int *)(param_1 + 4);
    while (iVar1 != 0) {
      if ((DAT_00803b68 == -1) && (iVar1 = FUN_004f8b10(*piVar2,"start"), iVar1 == 0)) {
        DAT_00803b68 = DAT_00951bb4;
      }
      else if ((DAT_00803b6c == -1) && (iVar1 = FUN_004f8b10(*piVar2,"start_cam"), iVar1 == 0)) {
        DAT_00803b6c = DAT_00951bb4;
      }
      DAT_00951bb4 = DAT_00951bb4 + 1;
      piVar2 = piVar2 + 4;
      iVar1 = *piVar2;
    }
  }
  return;
}

