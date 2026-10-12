/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x423b70; label: FUN_00423b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00423b70(int param_1,int param_2)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_s_bountyhunter_007f3820;
  if (PTR_s_bountyhunter_007f3820 != (undefined *)0x0) {
    while (iVar1 = FUN_004f8b10(*(undefined4 *)(param_2 + 0x510),*ppuVar2), iVar1 != 0) {
      ppuVar2 = ppuVar2 + 3;
      if (*ppuVar2 == (undefined *)0x0) {
        return;
      }
    }
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | (uint)ppuVar2[1];
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | (uint)ppuVar2[2];
  }
  return;
}

