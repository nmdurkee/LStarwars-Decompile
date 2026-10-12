/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70c20a; label: _ProcessCodePage
 */

/* Library Function - Single Match
    _ProcessCodePage
   
   Library: Visual Studio 2005 Release */

void _ProcessCodePage(void)

{
  int iVar1;
  CHAR *in_ECX;
  int unaff_EDI;
  LCTYPE LCType;
  CHAR local_10 [8];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if ((in_ECX == (char *)0x0) || (*in_ECX == '\0')) {
LAB_0070c252:
    LCType = 0x1004;
LAB_0070c25d:
    iVar1 = GetLocaleInfoA(*(LCID *)(unaff_EDI + 0x1c),LCType,local_10,8);
    if (iVar1 == 0) goto LAB_0070c274;
    in_ECX = local_10;
  }
  else {
    iVar1 = _strcmp(in_ECX,(char *)&PTR_DAT_00782340);
    if (iVar1 == 0) goto LAB_0070c252;
    iVar1 = _strcmp(in_ECX,(char *)&PTR_DAT_0078233c);
    if (iVar1 == 0) {
      LCType = 0xb;
      goto LAB_0070c25d;
    }
  }
  _atol(in_ECX);
LAB_0070c274:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

