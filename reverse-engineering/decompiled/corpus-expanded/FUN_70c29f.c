/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c29f; label: _LcidFromHexString
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _LcidFromHexString
   
   Library: Visual Studio 2005 Release */

int _LcidFromHexString(void)

{
  char cVar1;
  char *in_EDX;
  int iVar2;
  
  iVar2 = 0;
  while (cVar1 = *in_EDX, cVar1 != '\0') {
    in_EDX = in_EDX + 1;
    if ((byte)(cVar1 + 0x9fU) < 6) {
      cVar1 = cVar1 + -0x27;
    }
    else if ((byte)(cVar1 + 0xbfU) < 6) {
      cVar1 = cVar1 + -7;
    }
    iVar2 = iVar2 * 0x10 + -0x30 + (int)cVar1;
  }
  return iVar2;
}

