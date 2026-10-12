/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x693f50; label: FUN_00693f50
 */

void FUN_00693f50(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = 0;
  piVar4 = (int *)(in_ECX + 0xc);
  do {
    *piVar4 = 0;
    iVar1 = 0;
    if (0 < *(int *)(in_ECX + 8)) {
      piVar3 = (int *)(*(int *)(in_ECX + 4) + 0x14);
      do {
        if (*piVar3 == 1 << ((byte)iVar2 & 0x1f)) {
          *piVar4 = *(int *)(in_ECX + 4) + iVar1 * 0x3c;
          break;
        }
        iVar1 = iVar1 + 1;
        piVar3 = piVar3 + 0xf;
      } while (iVar1 < *(int *)(in_ECX + 8));
    }
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
    if (5 < iVar2) {
      return;
    }
  } while( true );
}

