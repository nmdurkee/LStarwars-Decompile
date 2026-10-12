/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69ff20; label: FUN_0069ff20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069ff20(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  char *in_ECX;
  int unaff_EBX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < unaff_EBX) {
    iVar1 = in_EAX - (int)in_ECX;
    do {
      iVar2 = _toupper((int)in_ECX[iVar1]);
      iVar3 = _toupper((int)*in_ECX);
      if (iVar2 != iVar3) {
        return 1;
      }
      iVar4 = iVar4 + 1;
      in_ECX = in_ECX + 1;
    } while (iVar4 < unaff_EBX);
  }
  return 0;
}

