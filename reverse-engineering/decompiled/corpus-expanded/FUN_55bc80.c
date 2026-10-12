/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55bc80; label: FUN_0055bc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055bc80(int param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < DAT_0093b26c)) {
    iVar1 = DAT_0093b280 + param_2 * 0xc;
    if (((*(uint *)(iVar1 + 4) == 0) ||
        ((((*(uint *)(iVar1 + 4) & 8) == 0 ||
          ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x8000) == 0)) &&
         ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & *(uint *)(iVar1 + 4)) == *(uint *)(iVar1 + 4)))
        )) && ((*(int *)(iVar1 + 8) == 0 ||
               ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & *(uint *)(iVar1 + 8))
                == *(uint *)(iVar1 + 8))))) {
      return 1;
    }
  }
  return 0;
}

