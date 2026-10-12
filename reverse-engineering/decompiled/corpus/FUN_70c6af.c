/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70c6af; label: _GetLcidFromLangCountry
 */

/* Library Function - Single Match
    _GetLcidFromLangCountry
   
   Library: Visual Studio 2005 Release */

void _GetLcidFromLangCountry(void)

{
  uint uVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 *unaff_ESI;
  
  sVar2 = _strlen((char *)*unaff_ESI);
  unaff_ESI[4] = (uint)(sVar2 == 3);
  sVar2 = _strlen((char *)unaff_ESI[1]);
  unaff_ESI[6] = 0;
  unaff_ESI[5] = (uint)(sVar2 == 3);
  if (unaff_ESI[4] == 0) {
    uVar3 = _GetPrimaryLen();
  }
  else {
    uVar3 = 2;
  }
  unaff_ESI[3] = uVar3;
  EnumSystemLocalesA(_LangCountryEnumProc_4,1);
  uVar1 = unaff_ESI[2];
  if ((((uVar1 & 0x100) == 0) || ((uVar1 & 0x200) == 0)) || ((uVar1 & 7) == 0)) {
    unaff_ESI[2] = 0;
  }
  return;
}

