/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c714; label: _GetLcidFromLanguage
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _GetLcidFromLanguage
   
   Library: Visual Studio 2005 Release */

void _GetLcidFromLanguage(void)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  sVar1 = _strlen((char *)*unaff_ESI);
  unaff_ESI[4] = (uint)(sVar1 == 3);
  if ((sVar1 == 3) == 0) {
    uVar2 = _GetPrimaryLen();
  }
  else {
    uVar2 = 2;
  }
  unaff_ESI[3] = uVar2;
  EnumSystemLocalesA(_LanguageEnumProc_4,1);
  if ((*(byte *)(unaff_ESI + 2) & 4) == 0) {
    unaff_ESI[2] = 0;
  }
  return;
}

