/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c382; label: _TestDefaultLanguage
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _TestDefaultLanguage
   
   Library: Visual Studio 2005 Release */

void _TestDefaultLanguage(uint param_1,int param_2)

{
  char *_Str;
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  CHAR local_80 [120];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  iVar1 = GetLocaleInfoA(param_1 & 0x3ff | 0x400,1,local_80,0x78);
  if (((iVar1 != 0) && (uVar2 = _LcidFromHexString(), param_1 != uVar2)) && (param_2 != 0)) {
    _Str = (char *)*in_ECX;
    _GetPrimaryLen();
    _strlen(_Str);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

