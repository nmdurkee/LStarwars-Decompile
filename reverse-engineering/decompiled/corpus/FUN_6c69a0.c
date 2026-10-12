/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c69a0; label: FUN_006c69a0
 */

int FUN_006c69a0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  do {
    if (iVar1 == 0) {
      return 0;
    }
    if ((int)*(uint *)(iVar1 + 0x1c) < 0) {
      if ((param_2 != 0) && (iVar2 = FUN_006c69a0(param_1,1), iVar2 != 0)) {
        return iVar2;
      }
    }
    else if ((param_1 & *(uint *)(iVar1 + 0x1c)) != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

