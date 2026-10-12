/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55bc80; label: FUN_0055bc80
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

