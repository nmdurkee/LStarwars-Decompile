/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c2d1; label: _GetPrimaryLen
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _GetPrimaryLen
   
   Library: Visual Studio 2005 Release */

int _GetPrimaryLen(void)

{
  char cVar1;
  int iVar2;
  char *in_EDX;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
    if (((cVar1 < 'A') || ('Z' < cVar1)) && (0x19 < (byte)(cVar1 + 0x9fU))) break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

