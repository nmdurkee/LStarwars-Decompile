/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd520; label: FUN_006bd520
 */

void FUN_006bd520(int param_1)

{
  int iVar1;
  char *pcVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
    pcVar2 = (char *)*in_ECX;
    if (pcVar2 != (char *)0x0) {
      FUN_006334d0(pcVar2,(int)*pcVar2);
      *in_ECX = 0;
    }
    return;
  }
  iVar1 = FUN_004f1ff0(param_1);
  pcVar2 = (char *)*in_ECX;
  if (pcVar2 != (char *)0x0) {
    if (iVar1 + 2 <= (int)*pcVar2) goto LAB_006bd57e;
    FUN_006334d0(pcVar2,(int)*pcVar2);
    *in_ECX = 0;
  }
  pcVar2 = (char *)FUN_00633440(iVar1 + 2,1);
  *in_ECX = (int)pcVar2;
  *pcVar2 = ((char)((int)(iVar1 + 1 + (iVar1 + 1 >> 0x1f & 0x1fU)) >> 5) + '\x01') * ' ';
LAB_006bd57e:
  FUN_004f1f40(*in_ECX + 1,param_1,0xfa);
  return;
}

