/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2740; label: FUN_004f2740
 */

void FUN_004f2740(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  _vsprintf(param_1,param_2,&stack0x0000000c);
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  return;
}

