/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x70c714; label: _GetLcidFromLanguage
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

