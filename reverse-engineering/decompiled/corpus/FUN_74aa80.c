/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74aa80; label: FUN_0074aa80
 */

int FUN_0074aa80(int param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(in_ECX[1] + -1 + *in_ECX);
  param_1 = in_ECX[1] - param_1;
  iVar1 = 0;
  iVar2 = 1;
  if (0 < param_1) {
    do {
      iVar1 = iVar1 + (*pcVar3 + -0x30) * iVar2;
      pcVar3 = pcVar3 + -1;
      iVar2 = iVar2 * 10;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return iVar1;
}

