/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x7414c0; label: FUN_007414c0
 */

int FUN_007414c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 0x79184);
  iVar3 = iVar1 + 1;
  if (iVar3 < 400) {
    piVar2 = (int *)(iVar3 * 0x4d8 + 8 + in_ECX);
    do {
      if (*piVar2 < 1) goto LAB_00741518;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x136;
    } while (iVar3 < 400);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = (int *)(in_ECX + 8);
    do {
      if (*piVar2 < 1) {
LAB_00741518:
        iVar1 = iVar3 * 0x4d8 + 4 + in_ECX;
        *(int *)(in_ECX + 0x79184) = iVar3;
        FUN_00744010(iVar1);
        *param_1 = iVar3;
        return iVar1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x136;
    } while (iVar3 < iVar1);
  }
  return 0;
}

